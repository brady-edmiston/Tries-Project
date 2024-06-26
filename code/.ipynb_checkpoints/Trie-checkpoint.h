#ifndef TRIE_H__
#define TRIE_H__

#include <memory>
#include <string>
#include <vector>

using namespace std;

struct node {
  vector<link*> links ;   // value of this node
  string word;
};

struct link {
    node* next;
    char value;
};

// Linked List Invariant: following the 'next' links must eventually lead to a
// NULL reference signifying the end of the list. (E.g. no circular references
// are allowed.)
class trie {
public:
  // constructor; should set the root node and size to 0.
  trie();

  ~trie();
  // inserts a word (or any combination of ASCII characters, could be numbers) into the trie
  void insert(string word);
  // Returns true if the word is stored in the trie.
  bool contains(string word);
  // If the word is in the trie, its node is deleted along with any hanging links as a result
  // and true is returned. Otherwise, false is returned.
  bool delete(string word);
  // Returns the number of nodes in the trie. Does not count the root node ''.
  int get_size();

private:
  // root node is always ''.
  node* root_node;
  // number of nodes in the trie.
  int size;
  // Initialzes a node with a nullptr in links and the word value.
  node* init_node(string word);
  // Initializes a link with the char value.
  link* init_link(char value);
  // Inserts a given node into the trie.
  void insert_node(node* new_node);
  // Sets the root node to be ''.
  void set_root_node();
};

#endif // TRIE_H_