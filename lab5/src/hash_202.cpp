#include "hash_202.hpp"
using namespace std;

size_t Hash_202::hashLast7(const string &key){
    string last7;
    if (key.length() > 7) {
        last7 = key.substr(key.length() - 7, 7);
    } else {
        last7 = key;
    }

    size_t hashValue = 0;

    stringstream ss;
    ss << last7;
    if (!(ss >> hex >> hashValue)) {
        hashValue = 0;  // If the conversion fails
    }

    return hashValue;
    }

size_t Hash_202::hashXOR(const string &key){
    // Create ss object to store the hex val
    stringstream ss;
    int smallKey;
    size_t xorResult;
    // Check if the key is smaller than 7
    if(key.length() <= 7){
      ss << key;
      ss >> hex >> smallKey;
      xorResult = smallKey;
    }
    // Split into chunks of 7 
    for(size_t i = 0; i < key.size(); i += 7){
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
  (void) table_size;
  (void) fxn;
  (void) collision;


  // Error check
  if(!Keys.empty()){
    return "Hash table already set up";
  }
  if(table_size <= 1){
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

  // Error check COMPLETE ->
  
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

    size_t index = last7int % Keys.size();

    // Linear probing
    
      while(!Keys[index].empty()){
        if(Keys[index] == key){
          return "Key already in the table";
        }
        index = (index + 1) %  Keys.size(); // This ensures i dont go out of bounds of the table
      }
    
      Keys[index] = key;
      Vals[index] = val;
      Nkeys++;
  }

  // XOR and linear probing
  else if(Fxn == 0 && Coll == 'L'){
    
    unsigned int xorResult = 0;

    // Create ss object to store the hex val
    stringstream ss;
    int smallKey;
    // Check if the key is smaller than 7
    if(key.length() <= 7){
      ss << key;
      ss >> hex >> smallKey;
      xorResult = smallKey;
    }
    // Split into chunks of 7 
    for(size_t i = 0; i < key.size(); i += 7){
      string chunk = key.substr(i, 7);

      // Convert the chunk into an integer
            stringstream ss;
            int chunkValue;
            ss << chunk;              
            ss >> hex >> chunkValue; 
            xorResult ^= chunkValue;
    }
    size_t index = xorResult % Keys.size();

    // Linear probing
    
      while(!Keys[index].empty()){
        if(Keys[index] == key){
          return "Key already in the table";
        }
        index = (index + 1) %  Keys.size(); // This ensures i dont go out of bounds of the table
      }
    
      Keys[index] = key;
      Vals[index] = val;
      Nkeys++;

  }
  // Last7 and Double
  else if(Fxn == 1 && Coll == 'D'){
    // Last7
    // Extract
    string last7 = key.substr(key.length()-7, 7);
    // Convert to int
    int last7int;

    // Create ss object to store the hex val
    stringstream ssFirst;
    ssFirst << last7;
    ssFirst >> hex >> last7int;

    size_t index = last7int % Keys.size();
  

  // XOR for double hash
  unsigned int xorResult = 0;

    // Create ss object to store the hex val
    stringstream ssSecond;
    int smallKey;
    // Check if the key is smaller than 7
    if(key.length() <= 7){
      ssSecond << key;
      ssSecond >> hex >> smallKey;
      xorResult = smallKey;
    }
    // Split into chunks of 7 
    for(size_t i = 0; i < key.size(); i += 7){
      string chunk = key.substr(i, 7);

      // Convert the chunk into an integer
            stringstream ssChunk;
            int chunkValue;
            ssChunk << chunk;              
            ssChunk >> hex >> chunkValue; 
            xorResult ^= chunkValue;
    }
    size_t increment = xorResult % Keys.size();
    if(increment == 0) increment = 1;

  // Collision resolution
  while(!Keys[index].empty()){
    if(Keys[index] == key){
          return "Key already in the table";
        }
    index = (index + increment) % Keys.size();
    
  }
  Keys[index] = key;
  Vals[index] = val;
  Nkeys++;
  
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
  for(size_t i = 0; i < Keys.size(); i++){
    if (!Keys[i].empty()) { // To print only the occupied entries
      printf("%s %s\n", Keys[i].c_str(), Vals[i].c_str());
    }
  }
}

size_t Hash_202::Total_Probes()
{
  return 0;
}
