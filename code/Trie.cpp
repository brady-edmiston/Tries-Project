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
    node* new_root = init_node("");
    this->root_ptr = new_root;
    this->size = 0;
};

// Destructor
Trie::~Trie() {};


void Trie::insert(string word) {
    return;
};


bool Trie::contains(string word) {
    return false;
};


bool Trie::remove(string word) {
    return false;
};


node* Trie::get_root() {
    return this->root_ptr;
}


int Trie::get_size() {
    return 0;
};


node* Trie::init_node(string word) {
    node* new_node = new node;
    new_node->value = word;
    return new_node;
};


trie_link* Trie::init_link(char value) {
    trie_link* new_link = new trie_link;
    new_link->value = value;
    return new_link;
};


void Trie::insert_node(node* new_node) {
    return;
};

