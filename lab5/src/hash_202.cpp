
#include "hash_202.hpp"
using namespace std;

/*
Pavel Vinduska - lab 5 (hashing)
Used formating addon (Pretier)
https://www.programiz.com/cpp-programming/library-function/cctype/isxdigit#:~:text=int%20isxdigit(int%20ch)%3B,by%20the%20current%20C%20locale.
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
  size_t xorResult;
  // Check if the key is smaller than 7
  if (key.length() <= 7)
  {
    ss << key;
    ss >> hex >> smallKey;
    xorResult = smallKey;
  }
  // Split into chunks of 7
  for (size_t i = 0; i < key.size(); i += 7)
  {
    string chunk = key.substr(i, 7);

    // Convert the chunk into an integer
    stringstream ss;
    int chunkValue;
    ss << chunk;
    ss >> hex >> chunkValue;
    xorResult ^= chunkValue;
  }
  return xorResult;
}
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
    index = hashXOR(key);
  }

  // Collisions:

  // Linear probing
  if (Coll == 'L')
  {
    while (!Keys[index].empty())
    {
      if (Keys[index] == key)
      {
        return "Key already in the table";
      }
      index = (index + 1) % Keys.size(); // This ensures i dont go out of bounds of the table
    }

    Keys[index] = key;
    Vals[index] = val;
    Nkeys++;
  }
  // Double hashing
  else
  {
    // When 1st function is last7
    if (Fxn == 1)
    {
      increment = hashXOR(key) % Keys.size();
      if (increment == 0)
      {
        increment = 1;
      }
      while (!Keys[index].empty() && attempts < (int)Keys.size())
      {
        if (Keys[index] == key)
        {
          return "Key already in the table";
        }
        index = (index + increment) % Keys.size();
        attempts++;
      }

      Keys[index] = key;
      Vals[index] = val;
      Nkeys++;
    }
    // When 1st function is xor
    else
    {
      int increment = hashLast7(key) % Keys.size();
      while (!Keys[index].empty() && attempts < (int)Keys.size())
      {
        if (Keys[index] == key)
        {
          return "Key already in the table";
        }
        index = (index + increment) % Keys.size();
        attempts++;
      }
    }
  }
  if (attempts == (int)Keys.size())
  {
    return "Hash table full";
  }

  Keys[index] = key;
  Vals[index] = val;
  Nkeys++;
  return "";
}
/* Find() returns the val associated with the given key.  If the hash table has not been
       set up yet, or if the key is not in the hash table, or if the key is not composed of
       all hex digits, it should return an empty string.

       Find() is not const, because it sets the variable Nprobes to equal the number of
       probes that it took to find the answer. */
string Hash_202::Find(const string &key)
{
  (void)key;
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

  // Find

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
       it takes find that key.  It should return the total number of probes.  It should
       return 0 if the hash table has not been set up yet.  It is not const, because it
       uses Find() to find the number of probes for each key. */
size_t Hash_202::Total_Probes()
{
  return 0;
}
