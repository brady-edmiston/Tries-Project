//  Trie.cpp
//      <TODO: Describe the data structure here >
//
//  Author: Brady Edmiston
//  CU ID: bred9604 
//  GitHub Username: brady-edmiston
//  Hours to complete lab:
//

#include "Trie.h"

// Constructor
Trie::Trie() {
    this->root_ptr = new node;
    this->size = 0;
};

// Destructor
Trie::~Trie() {};


void Trie::insert(string word) {
    node* n_cursor = this->root_ptr;
    for (char ch : word) {
        if (n_cursor->children.find(ch) == n_cursor->children.end()) {
            n_cursor->children[ch] = new node();
        }
        n_cursor = n_cursor->children[ch];
    }
    n_cursor->end_of_word = true;
    this->size++;
};


bool Trie::contains(string word) {
    node* current = this->root_ptr;
    for (char ch : word) {
        if (current->children.find(ch) == current->children.end()) {
            return false;
        }
        current = current->children[ch];
    }
    return current != nullptr && current->end_of_word;
}


bool Trie::remove(const string& word) {
    return this->remove_helper(this->root_ptr, word, 0);
};


node* Trie::get_root() {
    return this->root_ptr;
}


int Trie::get_size() {
    return this->size;
}

// Helper function for removing a word from the trie
bool Trie::remove_helper(node* current, const string& word, int depth) {
    // base case: we're past the length of the word
    if (depth == word.length()) {
        if (!current->end_of_word) {
            return false;
        }
        current->end_of_word = false;
        this->size--;
        return current->children.empty();
    }

    char ch = word[depth];
    // base case: next char isn't in trie
    if (current->children.find(ch) == current->children.end()) {
        return false;
    }

    bool delete_current_node = remove_helper(current->children[ch], word, depth + 1);
    // base case: we've found the node to delete
    if (delete_current_node) {
        delete current->children[ch];
        current->children.erase(ch);
        return current->children.empty();
    }

    // Base case: recursion exited without finding 
    return false;
}

