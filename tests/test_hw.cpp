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

TEST_F(test_Trie, TestInitialization) {
  // LinkedList mylist;
  // ASSERT_FALSE(mylist.get_top()); // expect top to be NULL
  // add_points_to_grade(1);
  // node* root = mylist.init_node(42);
  // ASSERT_TRUE(root); // expect root itself to have a pointer (not NULL)
  // add_points_to_grade(1);
  // ASSERT_EQ(42, root->data);
  // add_points_to_grade(1);
  // ASSERT_FALSE(root->next); // expect next pointer to be null
  // add_points_to_grade(1);
}

TEST_F(test_Trie, TestInsert) {
  // LinkedList mylist;
  // node* top = build_three_node_list_helper(42, 74, 51);
  // mylist.set_top(top);
  // mylist.append_data(10);

  // // get a cursor for appended data
  // node* cursor = mylist.get_top()->next->next->next;
  // ASSERT_TRUE(cursor);
  // add_points_to_grade(1);

  // ASSERT_FALSE(cursor->next); // expect to be NULL
  // add_points_to_grade(1);

  // ASSERT_EQ(10, cursor->data);
  // add_points_to_grade(1);

  // // try appending one more node
  // mylist.append_data(102);
  // // update cursor to point to fifth member
  // cursor = mylist.get_top()->next->next->next->next;
  // ASSERT_TRUE(cursor); // expect not to be NULL
  // add_points_to_grade(1);

  // ASSERT_FALSE(cursor->next); // expect to be NULL
  // add_points_to_grade(1);

  // ASSERT_EQ(102, cursor->data);
  // add_points_to_grade(1);
}


TEST_F(test_Trie, TestRemove) {
  // LinkedList mylist;

  // node* threenode = build_three_node_list_helper(7, 86, 210);
  // mylist.set_top(threenode);

  // int vals[] = {7, 86, 210};
  // ASSERT_TRUE(expect_all_helper(vals, 3, mylist.get_top()));

  // // remove start
  // mylist.remove(0);
  // int vals2[] = {86, 210};
  // ASSERT_TRUE(expect_all_helper(vals2, 2, mylist.get_top()));
  // add_points_to_grade(1);

  // // reset and remove mid
  // threenode = build_three_node_list_helper(7, 86, 210);
  // mylist.set_top(threenode);
  // mylist.remove(1);
  // int vals3[] = {7, 210};
  // ASSERT_TRUE(expect_all_helper(vals3, 2, mylist.get_top()));
  // add_points_to_grade(1);

  // // reset and remove end
  // threenode = build_three_node_list_helper(7, 86, 210);
  // mylist.set_top(threenode);
  // mylist.remove(2);
  // int vals4[] = {7, 86};
  // ASSERT_TRUE(expect_all_helper(vals4, 2, mylist.get_top()));
  // add_points_to_grade(1);

  // // reset and remove beyond list
  // threenode = build_three_node_list_helper(7, 86, 210);
  // mylist.set_top(threenode);
  // mylist.remove(3);
  // int vals5[] = {7, 86, 210};
  // ASSERT_TRUE(expect_all_helper(vals5, 3, mylist.get_top()));
}

TEST_F(test_Trie, TestSize) {
  // LinkedList mylist;
  // ASSERT_EQ(0, mylist.size());
  // add_points_to_grade(2);

  // node* threenode = build_three_node_list_helper(76, 12, 423);
  // mylist.set_top(threenode);
  // ASSERT_EQ(3, mylist.size());
  // add_points_to_grade(2);
}

TEST_F(test_Trie, TestContains) {
  // LinkedList mylist;
  // node* threenode = build_three_node_list_helper(7, 0, -210);
  // mylist.set_top(threenode);

  // ASSERT_TRUE(mylist.contains(-210));
  // add_points_to_grade(0.8);
  // ASSERT_TRUE(mylist.contains(0));
  // add_points_to_grade(0.8);
  // ASSERT_TRUE(mylist.contains(7));
  // add_points_to_grade(0.8);
  // ASSERT_FALSE(mylist.contains(12));
  // add_points_to_grade(0.8);
  // ASSERT_FALSE(mylist.contains(-120));
  // add_points_to_grade(0.8);
}
