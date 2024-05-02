#ifndef TRIE_H__
#define TRIE_H__

#include <memory>
#include <string>
#include <vector>

using namespace std;

struct trie_link;

struct node {
  vector<trie_link*> links;
  string value;
};

struct trie_link {
  node* next_node = nullptr;
  char value;
};

// Linked List Invariant: following the 'next' links must eventually lead to a
// NULL reference signifying the end of the list. (E.g. no circular references
// are allowed.)
class Trie {
public:
  // constructor; should set the root node and size to 0.
  Trie();

  ~Trie();
  // inserts a word (or any combination of ASCII characters, could be numbers) into the trie
  void insert(string word);
  // Returns true if the word is stored in the trie.
  bool contains(string word);
  // If the word is in the trie, its node is deleted along with any hanging links as a result
  // and true is returned. Otherwise, false is returned.
  bool remove(string word);
  // Returns the number of nodes in the trie. Does not count the root node ''.
  int get_size();
  // Returns the value of the root node
  node* get_root();
  // Sets the root pointer of the list
  void set_root_node(node* new_root) {this->root_ptr = new_root;}

private:
  // root node is always ''.
  node* root_ptr;
  // number of nodes in the trie.
  int size;
  // Initialzes a node with a nullptr in links and the word value.
  node* init_node(string word);
  // Initializes a link with the char value.
  trie_link* init_link(char value);
  // Inserts a given node into the trie.
  void insert_node(node* new_node);
};

#endif // TRIE_H_