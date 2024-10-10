#include "hash_202.hpp"
using namespace std;

/*
Pavel Vinduska - lab 5 (hashing)
Used formating addon (Pretier)
https://www.programiz.com/cpp-programming/library-function/cctype/isxdigit#:~:text=int%20isxdigit(int%20ch)%3B,by%20the%20current%20C%20locale.
dr. Scott hints: https://www.youtube.com/watch?v=GOoyxoDsjeM
*/

size_t Hash_202::hashLast7(const string &key)
{
  string last7;
  if (key.length() > 7)
  {
    last7 = key.substr(key.length() - 7, 7);
  }
  else
  {
    last7 = key;
  }

  size_t hashValue = 0;

  stringstream ss;
  ss << last7;
  if (!(ss >> hex >> hashValue))
  {
    hashValue = 0; // If the conversion fails
  }

  return hashValue;
}

size_t Hash_202::hashXOR(const string &key)
{
  // Create ss object to store the hex val
  stringstream ss;
  int smallKey;
  size_t xorResult = 0;
  // Check if the key is smaller than 7
  if (key.length() <= 7)
  {
    ss << key;
    ss >> hex >> smallKey;
    xorResult = smallKey;
  }
  // Split into chunks of 7
  else
  {
    for (size_t i = 0; i < key.size(); i += 7)
    {
      string chunk = key.substr(i, 7);

      // Convert the chunk into an integer
      stringstream ssChunk;
      int chunkValue;
      ssChunk << chunk;
      ssChunk >> hex >> chunkValue;
      xorResult ^= chunkValue;
    }
  }
  return xorResult;
}

/*This method takes the hash table size, a name of a hash function (either "Last7" or "XOR"), and
the name of a collision resolution strategy (either "Linear" or "Double").  */
string Hash_202::Set_Up(size_t table_size, const std::string &fxn, const std::string &collision)
{
  (void)table_size;
  (void)fxn;
  (void)collision;

  // Error check
  if (!Keys.empty())
  {
    return "Hash table already set up";
  }
  if (table_size <= 1)
  {
    return "Bad table size";
  }
  if (fxn != "Last7" && fxn != "XOR")
  {
    return "Bad hash function";
  }
  if (collision != "Linear" && collision != "Double")
  {
    return "Bad collision resolution strategy";
  }

  // NEW
  if (Nkeys == Keys.size())
  {
    return "Hash table full";
  }
  // Setup
  Keys.resize(table_size);
  Vals.resize(table_size);

  if (fxn == "Last7")
  {
    Fxn = 1; // Using 1 for Last7
  }
  else
  {
    Fxn = 0; // Using 0 for XOR
  }

  if (collision == "Linear")
  {
    Coll = 'L'; // L for Linear
  }
  else
  {
    Coll = 'D'; // D for Double
  }

  // If no errors
  return "";
}

string Hash_202::Add(const string &key, const string &val)
{
  (void)key;
  (void)val;
  int attempts = 0;
  int increment = 0;
  size_t index;

  if (Keys.empty())
  {
    return "Hash table not set up";
  }
  if (key.empty())
  {
    return "Empty key";
  }
  for (size_t i = 0; i < key.length(); ++i)
  {
    if (!isxdigit(key[i]))
    {
      return "Bad key (not all hex digits)";
    }
  }
  if (val.empty())
  {
    return "Empty val";
  }

  // Hash functions:

  // Last 7
  if (Fxn == 1)
  {
    int last7int = hashLast7(key);
    index = last7int % Keys.size();
  }

  // XOR hashing
  else
  {
    index = hashXOR(key) % Keys.size();
  }

  // Collisions:

  // Linear probing
  if (Coll == 'L') // Linear Probing
  {
    increment = 1; // Linear probing increment is always 1

    while (attempts < (int)Keys.size())
    {
      if (Keys[index].empty())
      {
        // Found empty slot, insert key and value
        Keys[index] = key;
        Vals[index] = val;
        Nkeys++;
        return "";
      }
      else if (Keys[index] == key)
      {
        return "Key already in the table";
      }

      index = (index + increment) % Keys.size(); // Move to next slot
      attempts++;
    }
    return "Hash table full"; // All slots have been checked
  }
  // Double hashing
  else if (Coll == 'D')
  {

    if (Fxn == 1)
    {
      increment = hashXOR(key) % Keys.size();
    }
    else
    {
      increment = hashLast7(key) % Keys.size();
    }
    if (increment == 0)
    {
      increment = 1;
    }
    // Probing loop
    while (!Keys[index].empty() && attempts < (int)Keys.size())
    {
      if (Keys[index] == key)
      {
        return "Key already in the table";
      }
      index = (index + increment) % Keys.size();
      attempts++;
    }
    if (attempts == (int)Keys.size())
    {
      return "Hash table full";
    }

    // Add the key and value
    Keys[index] = key;
    Vals[index] = val;
    Nkeys++;
  }
  return "";
}
/* Find() returns the val associated with the given key. */
string Hash_202::Find(const string &key)
{
  (void)key;
  int increment = 0;
  int attempts = 0;
  size_t index;
  Nprobes = 0;

  // Error check
  if (Keys.empty())
  {
    return "";
  }
  if (key.empty())
  {
    return "";
  }
  for (size_t i = 0; i < key.length(); ++i)
  {
    if (!isxdigit(key[i]))
    {
      return "";
    }
  }

  // Calculate hash value to determine "starting position"
  if (Fxn == 1)
  {
    int last7int = hashLast7(key);
    index = last7int % Keys.size();
  }

  else
  {
    index = hashXOR(key) % Keys.size();
  }

  // Calculate the increment

  if (Coll == 'D')
  {
    if (Fxn == 1)
    {
      increment = hashXOR(key) % Keys.size();
    }
    else
    {
      increment = hashLast7(key) % Keys.size();
    }
    // Avoid infinte loop
    if (increment == 0)
    {
      increment = 1;
    }
  }
  // Probe till program finds the key

  if (Keys[index] == key)
  {
    return Vals[index];
  }
  // Start probing (Linear / Double)
  while (attempts < (int)Keys.size())
  {

    // If slot empty key isnt there
    if (Keys[index].empty())
    {
      return "";
    }
    if (Keys[index] != key)
    {

      if (Coll == 'D')
      {
        index = (index + increment) % Keys.size();
      }
      else if (Coll == 'L')
      {
        index = (index + 1) % Keys.size();
      }
    }
    else
    {
      return Vals[index];
    }
    Nprobes++;
    attempts++;
  }
  return "";
}

void Hash_202::Print() const
{
  // Do nothing if the hash table has not been set up
  if (Keys.empty())
  {
    return;
  }

  // Iterate through the hash table
  for (size_t i = 0; i < Keys.size(); i++)
  {
    if (!Keys[i].empty())
    {

      printf("%5i %s %s\n", (int)i, Keys[i].c_str(), Vals[i].c_str());
    }
  }
}
/* Total_Probes() should traverse the hash table, and for every key, caculcate how many probes
       it takes find that key. */
size_t Hash_202::Total_Probes()
{
  if (Keys.empty())
  {
    return 0;
  }

  size_t totalProbes = 0;
  for (size_t i = 0; i < Keys.size(); i++)
  {
    if (!Keys[i].empty())
    {
      Find(Keys[i]);
      totalProbes += Nprobes;
    }
  }
  return totalProbes;
}