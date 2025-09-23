#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "../src/AVL.h"

//Name: Martina Delger
//UFID: 1977 4238

// uncomment and replace the following with your own headers
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// you must write 5 unique, meaningful tests for credit on the testing portion of this project!

// the provided test from the template is below.
TEST_CASE("Test 1: Commands Testing", "[avl][command_error]") {
	AVLTree tree;   
	REQUIRE_THROWS(tree.check_commands("")); 
    REQUIRE_THROWS(tree.check_commands("insert"));
    REQUIRE_THROWS(tree.check_commands("insert A11y 45679999"));
    REQUIRE_THROWS(tree.check_commands("John insert 1234567")); 
    REQUIRE_THROWS(tree.check_commands("insert 12345678 John")); 
}

TEST_CASE("Test 2: Insert Testing", "[avl][rotations]"){
    AVLTree tree;
    tree.insert("Martina", 11111111);
	tree.insert("Alice", 22222222);
	tree.insert("Bob", 33333333);

    tree.insert("Max", 44444444);
	tree.insert("Bryan", 55555555);

    tree.insert("Martin", 66666666);
	tree.insert("Robert", 77777777);

    tree.insert("Michael", 88888888);
	tree.insert("Josh", 99999999);

	Node* root = tree.get_root();
	tree.print_inorder(root);
    cout << endl;
    tree.print_preorder(root);
    cout << endl;
    tree.print_postorder(root);
    REQUIRE(root->ufid == 44444444);
    REQUIRE(root->left->ufid == 22222222);
    REQUIRE(root->right->ufid == 66666666);
    REQUIRE(root->left->left->ufid == 11111111);
    REQUIRE(root->left->right->ufid == 33333333);
    REQUIRE(root->right->left->ufid == 55555555);
    REQUIRE(root->right->right->ufid == 88888888);
    REQUIRE(root->right->right->left->ufid == 77777777);
    REQUIRE(root->right->right->right->ufid == 99999999);
}

TEST_CASE("Test 3: Insert 100/remove 10 Test", "[avl][insert]"){
    AVLTree inputTree;
    vector<int> expectedOutput, actualOutput;
    string test_name = "Test User";
    Node* &inputtree_root = inputTree.get_root();

    for(int i = 0; i < 100; i++) {
        int randomInput = rand();
        if (count(expectedOutput.begin(), expectedOutput.end(), randomInput) == 0) {
            expectedOutput.push_back(randomInput);
            inputTree.insert(test_name, randomInput);
        }
    }

    for (int i=0; i<10; i++) {
        int removed_node = expectedOutput.back();
        expectedOutput.pop_back();
        inputtree_root = inputTree.remove(inputtree_root, removed_node);
    }

    inputTree.inorder_ufid_vector(inputtree_root, actualOutput);
    REQUIRE(expectedOutput.size() == actualOutput.size());
    sort(expectedOutput.begin(), expectedOutput.end());
    REQUIRE(expectedOutput == actualOutput);
}

TEST_CASE("Test 6: Level Order Test", "[avl][LevelOrder]") {
    AVLTree tree;
    tree.insert("Martina", 11111111);
	tree.insert("Alice", 22222222);
	tree.insert("Bob", 33333333);

    tree.insert("Max", 44444444);
	tree.insert("Bryan", 55555555);

    tree.insert("Martin", 66666666);
	tree.insert("Robert", 77777777);

    tree.insert("Michael", 88888888);
	tree.insert("Josh", 99999999);

	tree.print_level_count();
    REQUIRE(tree.get_height(tree.get_root()) == 4);
}

TEST_CASE("Test 7: Search Test", "[avl][search]") {
    AVLTree tree;
    tree.insert("Martina", 11111111);
	tree.insert("Alice", 22222222);
	tree.insert("Bob", 33333333);

    tree.insert("Max", 44444444);
	tree.insert("Bryan", 55555555);

    tree.insert("Martin", 66666666);
	tree.insert("Robert", 77777777);

    tree.insert("Michael", 88888888);
	tree.insert("Josh", 99999999);

    //search id tests
    tree.search_id(66666666); //should print Martin
    tree.search_id(12345678); //should print unsuccessful

    //search name tests
    tree.search_name("Robert"); //should print 77777777
    tree.search_name("Martin"); //should print 66666666
}