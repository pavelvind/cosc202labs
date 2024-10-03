#include "hash_202.hpp"
using namespace std;

string Hash_202::Set_Up(size_t table_size, const std::string &fxn, const std::string &collision)
{
  (void) table_size;
  (void) fxn;
  (void) collision;
  return "";
  /*
 You must call Set_Up() to set up the table before using it.  This method 
       takes the hash table size, a name of a hash function (either "Last7" or "XOR"), and
       the name of a collision resolution strategy (either "Linear" or "Double").  
 
       You should error check your input, and look for the following errors, in the following
       order.  If you see one of these errors, return the string specified:

       - Table already set up:                "Hash table already set up"
       - Bad table size:                      "Bad table size"
       - Bad hash function:                   "Bad hash function"
       - Bad collision resolution strategy:   "Bad collision resolution strategy"
 */

  // Error check
  if(!Keys.empty()){
    return "Hash table already set up";
  }
  if(table_size < 0){
    return "Bad table size";
  }
  if(fxn != "Last7" && fxn != "XOR"){
    return "Bad hash function";

  }
  if(collision != "Linear" && collision != "Double"){
    return "Bad collision resolution strategy";
  }
  // Setup
  Keys.resize(table_size);
  Vals.resize(table_size);

    if (fxn == "Last7") {
        Fxn = 1;  // Using 1 for Last7
    } else {
        Fxn = 0;  // Using 0 for XOR
    }

    if (collision == "Linear") {
        Coll = 'L';  // L for Linear
    } else {
        Coll = 'D';  // D for Double
    }

    // If no errors
    return "";
}



string Hash_202::Add(const string &key, const string &val)
{
  (void) key;
  (void) val;

  // Error check
  
  // Last7 and linear probing
  if(Fxn == 1 && Coll == 'L'){
    
    // Extract
    string last7 = key.substr(key.length()-7, 7);
    // Convert to int
    int last7int;

    // Create ss object to store the hex val
    stringstream ss;
    ss << last7;
    ss >> hex >> last7int;

    int index = last7int % Keys.size();

    // Linear probing
    
      while(!Keys[index].empty()){
        if(Keys[index] == key){
          return "Key already in the table";
        }
        index = (index + 1) % table_size; // This ensures i dont go out of bounds of the table
      }
    
      Keys[index] = key;
      Vals[index] = val;
      Nkeys++;
  }

  // Last7 and XOR
  if(Fxn == 1 && Coll == 'D'){

    
  }
  return "";
}

string Hash_202::Find(const string &key)
{
  (void) key;
  return "";
}

void Hash_202::Print() const
{
  // Use printf 
}

size_t Hash_202::Total_Probes()
{
  return 0;
}
