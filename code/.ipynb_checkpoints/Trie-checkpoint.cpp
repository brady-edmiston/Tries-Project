//  LinkedList.cpp
//      <TODO: Describe the data structure here >
//
//  Author: Brady Edmiston
//  CU ID: bred9604 
//  GitHub Username: brady-edmiston
//  Hours to complete lab: 2.5
//

#include "LinkedList.h"

// constructor, initialize class variables and pointers here if need.
LinkedList::LinkedList() {
  top_ptr_ = nullptr;
}

// deconstructor,
LinkedList::~LinkedList() {}

node* LinkedList::init_node(int data) {
  node* ret(new node);
  ret->data = data;
  ret->next = nullptr;
  return ret;
}

string LinkedList::report() {
  string ret;
  node* currNode = this->top_ptr_;
  while (currNode != nullptr) {
    string data = to_string(currNode->data);
    ret.append(data + " ");
    currNode = currNode->next;
  }
  return ret;
}

void LinkedList::append_data(int data) {
  node* currNode = this->top_ptr_;
  node* newNode = init_node(data);

  while (currNode->next != nullptr) {
    currNode = currNode->next;
  }
  
  currNode->next = newNode;
}

void LinkedList::append(node* new_node) {
  // Your code here
  node* currNode = this->top_ptr_;

  if (currNode == nullptr) {
    this->top_ptr_ = new_node;
    return;
  }

  while (currNode->next != nullptr){
    currNode = currNode->next;
  }

  currNode->next = new_node;
}

void LinkedList::insert_data(int offset, int data) {
  int counter = 0;
  node* currNode = this->top_ptr_;
  node* newNode = init_node(data);

  // Cases:
  // list is empty
    // offset is 0
    // offset isn't 0
  // list is not empty
    // offset is zero
    // offset is outside of list
    // offset is inside list and not the end
    // offset is inside the list and is the end

  if (offset == 0) { // Beginning of list
    if (currNode == nullptr) { // list is empty
      this->top_ptr_ = newNode;
      return;
    }
    else { // list is not empty
      newNode->next = currNode;
      this->top_ptr_ = newNode;
      return;
    }
  }

  while (counter+1 != offset) {
    counter+=1;
    currNode = currNode->next;

    // if offset is greater than the length of the list, return
    if (currNode == nullptr) { 
      return;
    }
  }

  // if we've made it here, we found counter and are inside the list
  // i.e. currNode != NULL

  // Check if we're at the end of the list
  if (currNode->next == nullptr) { 
    currNode->next = newNode;
    return;
  }

  // currNode -- nextNode
  // currNode -- newNode -- nextNode

  node* nextNode = currNode->next;
  currNode->next = newNode;
  newNode->next = nextNode;
  return;
}

void LinkedList::insert(int offset, node* new_node) {
    int counter = 0;
  node* currNode = this->top_ptr_;

  // Cases:
  // list is empty
    // offset is 0
    // offset isn't 0
  // list is not empty
    // offset is zero
    // offset is outside of list
    // offset is inside list and not the end
    // offset is inside the list and is the end

  if (offset == 0) { // Beginning of list
    if (currNode == nullptr) { // list is empty
      this->top_ptr_ = new_node;
      return;
    }
    else { // list is not empty
      new_node->next = currNode;
      this->top_ptr_ = new_node;
      return;
    }
  }

  while (counter+1 != offset) {
    counter+=1;
    currNode = currNode->next;

    // if offset is greater than the length of the list, return
    if (currNode == nullptr) { 
      return;
    }
  }

  // if we've made it here, we found counter and are inside the list
  // i.e. currNode != NULL

  // Check if we're at the end of the list
  if (currNode->next == nullptr) { 
    currNode->next = new_node;
    return;
  }

  // currNode -- nextNode
  // currNode -- new_node -- nextNode

  node* nextNode = currNode->next;
  currNode->next = new_node;
  new_node->next = nextNode;
  return;
}

void LinkedList::remove(int offset) {
  int counter = 0;
  node* currNode = this->top_ptr_;
  node* nextNode = currNode->next;

  // check if list is empty
  if (currNode == nullptr) {
    return;
  }

  // removing first node
  if (offset == 0) {
    this->top_ptr_ = nextNode;
    return;
  }

  while (counter+1 != offset) {

    if (nextNode == nullptr) { 
      // offset is outside list
      return;
    }

    counter+=1;
    currNode = nextNode;
    nextNode = currNode->next;
  }

  if (nextNode == nullptr) {
    // offset is last node in list
    currNode->next = nullptr;
    return;
  }

  // currNode -- nextNode -- afterNode
  // currNode -- afterNode
  currNode->next = nextNode->next;
  return;
}

int LinkedList::size() {
  int ret = 0;
  node* currNode = this->top_ptr_;

  while (currNode != nullptr) {
    ret+=1;
    currNode = currNode->next;
  }
  return ret;
}

bool LinkedList::contains(int data) {
  bool ret;
  // Your code here
  node* currNode = this->top_ptr_;

  while (currNode != nullptr) {
    if (currNode->data == data) {
      ret = true;
      return ret;
    }
    currNode = currNode->next;
  }

  ret = false;
  return ret;
}

// This function is implemented for you
// It returns the top pointer
node* LinkedList::get_top() { return top_ptr_; }

// This function is implemented for you
// It sets a given pointer as the top pointer
void LinkedList::set_top(node* top_ptr) { top_ptr_ = top_ptr; }
