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
    tree.insert("Martina", 00000030);
	tree.insert("Alice", 00000020);
	tree.insert("Bob", 00000010);

    tree.insert("Max", 00000040);
	tree.insert("Bryan", 00000050);

    tree.insert("Martin", 00000025);
	tree.insert("Robert", 00000022);

    tree.insert("Michael", 00000060);
	tree.insert("Josh", 00000055);

	Node* root = tree.get_root();
	tree.print_inorder(root);
    REQUIRE(root->ufid == 00000030);
    REQUIRE(root->left->ufid == 00000020);
    REQUIRE(root->right->ufid == 00000050);
    REQUIRE(root->left->left->ufid == 00000010);
    REQUIRE(root->left->right->ufid == 00000025);
    REQUIRE(root->left->right->left->ufid == 00000022);
    REQUIRE(root->right->left->ufid == 00000040);
    REQUIRE(root->right->right->ufid == 00000060);
    REQUIRE(root->right->right->left->ufid == 00000055);
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

TEST_CASE("Test 4: Level Order Test", "[avl][LevelOrder]") {
    AVLTree tree;
    tree.insert("Martina", 00000030);
	tree.insert("Alice", 00000020);
	tree.insert("Bob", 00000010);

    tree.insert("Max", 00000040);
	tree.insert("Bryan", 00000050);

    tree.insert("Martin", 00000025);
	tree.insert("Robert", 00000022);

    tree.insert("Michael", 00000060);
	tree.insert("Josh", 00000055);

	tree.print_level_count();
    REQUIRE(tree.get_height(tree.get_root()) == 4);
}

TEST_CASE("Test 5: Search Test", "[avl][search]") {
    AVLTree tree;
    tree.insert("Martina", 00000030);
    tree.insert("Alice", 00000020);
    tree.insert("Bob", 00000010);

    tree.insert("Max", 00000040);
    tree.insert("Bryan", 00000050);

    tree.insert("Martin", 00000025);
    tree.insert("Robert", 00000022);

    tree.insert("Michael", 00000060);
    tree.insert("Josh", 00000055);

    //search id tests
    tree.search_id(00000025); //should print 25
    tree.search_id(12345678); //should print unsuccessful

    //search name tests
    tree.search_name("Robert"); //should print 22
    tree.search_name("NotAName"); //should print unsuccessful
}