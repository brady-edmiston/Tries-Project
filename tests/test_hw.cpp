// If you change anything in this file, your changes will be ignored
// in your homework submission.
// Chekout TEST_F functions bellow to learn what is being tested.
#include "../code/Trie.h"
#include <gtest/gtest.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

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
  root_node->value = "";
  node* _c = new node;
  _c->value = "c";
  node* co = new node;
  co->value = "co";
  node* coo = new node;
  coo->value = "coo";
  node* coop = new node;
  coop->value = "coop";
  node* ca = new node;
  ca->value = "ca";
  node* cat = new node;
  cat->value = "cat";
  node* catc = new node;
  catc->value = "catc";
  node* _catch = new node; // catch is reserved
  _catch->value = "catch";
  node* _a = new node;
  _a->value = "a";
  node* _as = new node;
  _as->value = "as";

  // Links
  trie_link* c_link = new trie_link;
  c_link->value = 'c';
  trie_link* o1_link = new trie_link;
  o1_link->value = 'o';
  trie_link* o2_link = new trie_link;
  o2_link->value = 'o';
  trie_link* p_link = new trie_link;
  p_link->value = 'p';
  trie_link* a1_link = new trie_link;
  a1_link->value = 'a';
  trie_link* t_link = new trie_link;
  t_link->value = 't';
  trie_link* c2_link = new trie_link;
  c2_link->value = 'c';
  trie_link* h_link = new trie_link;
  h_link->value = 'h';
  trie_link* a2_link = new trie_link;
  a2_link->value = 'a';
  trie_link* s_link = new trie_link;
  s_link->value = 's';

  // Now build up the trie structure
  root_node->links.push_back(c_link);
  c_link->next_node = _c;
  _c->links.push_back(o1_link);
  o1_link->next_node = co;
  co->links.push_back(o2_link);
  o2_link->next_node = coo;
  coo->links.push_back(p_link);
  p_link->next_node = coop;

  _c->links.push_back(a1_link);
  a1_link->next_node = ca;
  ca->links.push_back(t_link);
  t_link->next_node = cat;
  cat->links.push_back(c2_link);
  c2_link->next_node = catc;
  catc->links.push_back(h_link);
  h_link->next_node = _catch;

  root_node->links.push_back(a2_link);
  a2_link->next_node = _a;
  _a->links.push_back(s_link);
  s_link->next_node = _as;

  return root_node;
}


TEST_F(test_Trie, TestInitialization) {
  Trie mytrie;
  // Expect root node to exist and be empty string
  node* root_node = mytrie.get_root();
  ASSERT_EQ("", root_node->value);
  ASSERT_TRUE(root_node->links.empty());
  //Expect size to be 0 
  ASSERT_EQ(0, mytrie.get_size());
}

TEST_F(test_Trie, TestInsert) {
  Trie mytrie;
  node* root_node = helper_build_trie();
  mytrie.set_root_node(root_node);
  node* c_ursor = mytrie.get_root()->links[1]->next_node->links[0]->next_node; // go to node "as"
  ASSERT_FALSE(c_ursor->links.empty()); // Make sure links vector isn't empty
  trie_link* v_ursor = c_ursor->links[0];
  ASSERT_TRUE(v_ursor->next_node); // Make sure next node is populated
  ASSERT_EQ(v_ursor->value, 'h'); // Should have value of 'h'

  c_ursor = c_ursor->links[0]->next_node; // Go to node "ash"
  ASSERT_TRUE(c_ursor->links.empty()); // Make sure links vector is now empty, we should be at a leaf!
  ASSERT_EQ(c_ursor->value, "ash"); // Should have value of "ash"

  mytrie.insert("coat");
  c_ursor = mytrie.get_root()->links[0]->next_node->links[0]->next_node; // go to node "co"
  ASSERT_FALSE(c_ursor->links.empty()); // Make sure links vector isn't empty
  v_ursor = c_ursor->links[1];
  ASSERT_TRUE(v_ursor->next_node); // Make sure next node is populated
  ASSERT_EQ(v_ursor->value, 'a'); // Should have value of 'a'

  c_ursor = c_ursor->links[0]->next_node; // go to node "coa"
  ASSERT_EQ(c_ursor->value, "coa"); // should have value of "coa"
  ASSERT_FALSE(c_ursor->links.empty()); // Make sure links vector isn't empty
  v_ursor = c_ursor->links[0];
  ASSERT_TRUE(v_ursor->next_node); // Make sure next node is populated
  ASSERT_EQ(v_ursor->value, 't'); // Should have value of 't'

  c_ursor = c_ursor->links[0]->next_node; // go to node "coat"
  ASSERT_TRUE(c_ursor->links.empty()); // Make sure links vector is now empty, we should be at a leaf!
  ASSERT_EQ(c_ursor->value, "coat"); // Should have value of "coat"

}


TEST_F(test_Trie, TestRemove) {
  Trie mytrie;
  node* root_node = helper_build_trie();
  mytrie.set_root_node(root_node);
  bool result = mytrie.remove("yellow");
  ASSERT_FALSE(result);
  result = mytrie.remove("coop");
  ASSERT_TRUE(result);
  node* c_ursor = mytrie.get_root()->links[0]->next_node; // go to node "c"
  ASSERT_EQ(1, c_ursor->links.size()); // Links should only have 'a'

  result = mytrie.remove("cat");
  ASSERT_FALSE(result);

}

TEST_F(test_Trie, TestSize) {
  Trie mytrie;
  node* root_node = helper_build_trie();
  mytrie.set_root_node(root_node);
  int result = mytrie.get_size();
  ASSERT_EQ(result, 4);

  mytrie.insert("yell");
  result = mytrie.get_size();
  ASSERT_EQ(result, 5);

  mytrie.remove("cat");
  result = mytrie.get_size();
  ASSERT_EQ(result, 4);
}

TEST_F(test_Trie, TestContains) {
  Trie mytrie;
  node* root_node = helper_build_trie();
  mytrie.set_root_node(root_node);

  bool result = mytrie.contains("coop");
  ASSERT_TRUE(result);

  mytrie.remove("as");
  result = mytrie.contains("as");
  ASSERT_FALSE(result);

  mytrie.insert("thigh");
  result = mytrie.contains("thigh");
  ASSERT_TRUE(result);
}
