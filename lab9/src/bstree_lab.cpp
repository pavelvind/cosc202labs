// I used some of the dr. Planks notes here: https://web.eecs.utk.edu/~jplank/plank/classes/cs202/Notes/Trees/index.html

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
  sentinel = new BSTNode;
  sentinel->parent = NULL;
  sentinel->left = NULL;
  sentinel->right = sentinel;
  sentinel->key = "---SENTINEL---"; 
  sentinel->val = NULL;
  size = 0;
  *this = t;
}

BSTree& BSTree::operator= (const BSTree &t) 
{
  if (this != &t)
  {
    // Clear the existing tree
    Clear();

    vector<string> keys = t.Ordered_Keys();
    vector<void *> values = t.Ordered_Vals();

    BSTNode *newTree = make_balanced_tree(keys, values, 0, keys.size());
    sentinel->right = newTree;

    if (newTree != sentinel)
    {
      newTree->parent = sentinel;
    }
    size = t.size;
  }
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

BSTNode *BSTree::make_balanced_tree(const vector<string> &sorted_keys, const vector<void *> &vals, size_t first_index, size_t num_indices) const
{
  // Recursive function
  // Base case
  if (num_indices == 0)
  {
    return sentinel;
  }

  size_t middleElement = first_index + num_indices / 2;

  BSTNode *temp = new BSTNode; // Temporary pointer of type BSTNode*
  temp->key = sorted_keys[middleElement];
  temp->val = vals[middleElement];
  temp->left = sentinel;
  temp->right = sentinel;
  temp->parent = sentinel;

  // Recursive case
  temp->left = make_balanced_tree(sorted_keys, vals, first_index, middleElement - first_index);
  if (temp->left != sentinel)
  {
    temp->left->parent = temp;
  }
  temp->right = make_balanced_tree(sorted_keys, vals, middleElement + 1, num_indices - (middleElement - first_index) - 1);
  if (temp->right != sentinel)
  {
    temp->right->parent = temp;
  }
  return temp;
}
