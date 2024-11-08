#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include "bstree.hpp"
using namespace std;
using CS140::BSTree;
using CS140::BSTNode;

/* ---------------------------------------------- */
/* You'll write all of these as part of your lab. */

int BSTree::Depth(const string &key) const
{
  int depth = 0;
  BSTNode *n;
  n = sentinel->right;
  // Traverse the tree
  while (n != sentinel && key != n->key)
  {
    n = (key < n->key) ? n->left : n->right; // If key < node go left | If key > node go right
    depth++;
  }
  if(n == sentinel){
    return -1;
  }
  else{
    return depth;
  }

}

int BSTree::Height() const
{
  
  // Call recursive function from top of the tree
  return recursive_find_height(sentinel->right);
}

vector <string> BSTree::Ordered_Keys() const
{
  vector <string> rv;
  make_key_vector(sentinel->right, rv);
  return rv;
}
    
BSTree::BSTree(const BSTree &t)        
{
  (void) t;
}

BSTree& BSTree::operator= (const BSTree &t) 
{
  (void) t;
  return *this;
}

int BSTree::recursive_find_height(const BSTNode *n) const
{

  // base case
  if (n == sentinel)
  {
    return 0;
  }
  // Recursive case
  int left_height = recursive_find_height(n->left);
  int right_height = recursive_find_height(n->right);

  return 1 + max(left_height, right_height);
}

void BSTree::make_key_vector(const BSTNode *n, vector<string> &v) const
{
  if (n == sentinel) return;
  make_key_vector(n->left, v);
  v.push_back(n->key);
  make_key_vector(n->right, v);
  (void) n;
  (void) v;
}

BSTNode *BSTree::make_balanced_tree(const vector<string> &sorted_keys, 
                            const vector<void *> &vals,
                            size_t first_index,
                            size_t num_indices) const
{
  (void) sorted_keys;
  (void) vals;
  (void) first_index;
  (void) num_indices;
  return NULL;
}
