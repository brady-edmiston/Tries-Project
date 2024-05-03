// If you change anything in this file, your changes will be ignored
// in your homework submission.
// Chekout TEST_F functions bellow to learn what is being tested.
#include "../code/Trie.h"
#include <gtest/gtest.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class test_Trie : public ::testing::Test {
protected:
  // This function runs only once before any TEST_F function
  static void SetUpTestCase() {
    std::ofstream outgrade("./total_grade.txt");
    if (outgrade.is_open()) {
      outgrade.clear();
      outgrade << (int)0;
      outgrade.close();
    }
  }

  // This function runs after all TEST_F functions have been executed
  static void TearDownTestCase() {
    std::ofstream outgrade("./total_grade.txt");
    if (outgrade.is_open()) {
      outgrade.clear();
      outgrade << (int)std::ceil(100 * total_grade / max_grade);
      outgrade.close();
      std::cout << "Total Grade is : "
                << (int)std::ceil(100 * total_grade / max_grade) << std::endl;
    }
  }

  void add_points_to_grade(double points) {
    if (!::testing::Test::HasFailure()) {
      total_grade += points;
    }
  }

  // this function runs before every TEST_F function
  void SetUp() override {}

  // this function runs after every TEST_F function
  void TearDown() override {
    std::ofstream outgrade("./total_grade.txt");
    if (outgrade.is_open()) {
      outgrade.clear();
      outgrade << (int)std::ceil(100 * total_grade / max_grade);
      outgrade.close();
    }
  }

  static double total_grade;
  static double max_grade;
};

double test_Trie::total_grade = 0;
double test_Trie::max_grade = 38;

/* Helper function to return a trie structure
by giving the pointer to the root node
                 ""
                /  \
               c     a
              / \      \
             o   a      s
            /    |      
           o     t
           |     |
           p     c
                 |
                 h
*/
node* helper_build_trie() {
  // Nodes
  node* root_node = new node;
  node* _c = new node;
  node* co = new node;
  node* coo = new node;
  node* coop = new node;
  node* ca = new node;
  node* cat = new node;
  node* catc = new node;
  node* _catch = new node; // catch is reserved
  node* _a = new node;
  node* _as = new node;

  // Now build up the trie structure
  root_node->children.insert({'c', _c});
  _c->children.insert({'o', co});
  co->children.insert({'o', coo});
  coo->children.insert({'p', coop});
  coop->end_of_word = true;

  _c->children.insert({'a', ca});
  ca->children.insert({'t', cat});
  cat->end_of_word = true;
  cat->children.insert({'c', catc});
  catc->children.insert({'h', _catch});
  _catch->end_of_word = true;

  root_node->children.insert({'a', _a});
  _a->children.insert({'s', _as});
  _as->end_of_word = true;

  return root_node;
}


TEST_F(test_Trie, TestInitialization) {
  Trie mytrie;
  // Expect root node to exist and be empty string
  node* root_node = mytrie.get_root();
  ASSERT_TRUE(root_node->children.empty());
  //Expect size to be 0 
  ASSERT_EQ(0, mytrie.get_size());
}

TEST_F(test_Trie, TestInsert) {
  Trie mytrie;
  node* root_node = helper_build_trie();
  mytrie.set_root_node(root_node);

  mytrie.insert("ash");
  node* n_cursor = mytrie.get_root()->children['a']->children['s']; // go to node "as"
  ASSERT_FALSE(n_cursor->children.empty()); // Make sure links vector isn't empty
  n_cursor = n_cursor->children['h']; // Go to node "ash"
  ASSERT_TRUE(n_cursor->children.empty()); // Make sure links vector is now empty, we should be at a leaf!

  mytrie.insert("coat");
  n_cursor = mytrie.get_root()->children['c']->children['o']; // go to node "co"
  ASSERT_FALSE(n_cursor->children.empty()); // Make sure links vector isn't empty

  n_cursor = n_cursor->children['a']; // go to node "coa"
  ASSERT_FALSE(n_cursor->children.empty()); // Make sure links vector isn't empty

  n_cursor = n_cursor->children['t']; // go to node "coat"
  ASSERT_TRUE(n_cursor->children.empty()); // Make sure links vector is now empty, we should be at a leaf!

}


TEST_F(test_Trie, TestRemove) {
  Trie mytrie;
  node* root_node = helper_build_trie();
  mytrie.set_root_node(root_node);
  bool result = mytrie.remove("yellow");
  ASSERT_FALSE(result);
  result = mytrie.remove("coop");
  ASSERT_FALSE(result); // method still returns false
  node* n_cursor = mytrie.get_root()->children['c']; // go to node "c"
  ASSERT_EQ(1, n_cursor->children.size()); // Links should only have 'a'

  result = mytrie.remove("cat");
  ASSERT_FALSE(result);

}

TEST_F(test_Trie, TestSize) {
  Trie mytrie;
  mytrie.insert("hi");
  mytrie.insert("there");
  mytrie.insert("prof");
  mytrie.insert("!");
  int result = mytrie.get_size();
  ASSERT_EQ(result, 4);

  mytrie.insert("yell");
  result = mytrie.get_size();
  ASSERT_EQ(result, 5);

  mytrie.remove("prof");
  result = mytrie.get_size();
  ASSERT_EQ(result, 4);
}

TEST_F(test_Trie, TestContains) {
  Trie mytrie;
  mytrie.insert("I");
  mytrie.insert("really");
  mytrie.insert("data");
  mytrie.insert("structures!");

  bool result = mytrie.contains("structures!");
  ASSERT_TRUE(result);

  result = mytrie.contains("structures");
  ASSERT_FALSE(result);

  mytrie.remove("data");
  result = mytrie.contains("data");
  ASSERT_FALSE(result);

  mytrie.insert("thigh");
  result = mytrie.contains("thigh");
  ASSERT_TRUE(result);
}
