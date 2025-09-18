#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "../src/AVL.h"

//Name: Martina Delger
//UFID: 1977 4238

// uncomment and replace the following with your own headers
#include <algorithm>

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
    tree.insert("Martina Delger", "00000030");
	tree.insert("Alice Smith", "00000020");
	tree.insert("Bob Johnson", "00000010");

    tree.insert("Max Smith", "00000040");
	tree.insert("Bryan Johnson", "00000050");

    tree.insert("Martina Smith", "00000025");
	tree.insert("Robert Johnson", "00000022");

    tree.insert("Michael Smith", "00000060");
	tree.insert("Josh Johnson", "00000055");

	Node* root = tree.get_root();
	tree.print_inorder(root);
    REQUIRE(root->ufid == "00000030");
    REQUIRE(root->left->ufid == "00000020");
    REQUIRE(root->right->ufid == "00000050");
    REQUIRE(root->left->left->ufid == "00000010");
    REQUIRE(root->left->right->ufid == "00000025");
    REQUIRE(root->left->right->left->ufid == "00000022");
    REQUIRE(root->right->left->ufid == "00000040");
    REQUIRE(root->right->right->ufid == "00000060");
    REQUIRE(root->right->right->left->ufid == "00000055");
}

// TEST_CASE("Test 3: Insert 100 Test", "[avl][insert]"){
//     AVLTree inputTree;
//     vector<int> expectedOutput, actualOutput;

//     for(int i = 0; i < 100000; i++)
//     {
//         int randomInput = rand();
//         if (count(expectedOutput.begin(), expectedOutput.end(), randomInput) == 0)
//         {
//             expectedOutput.push_back(randomInput);
//             inputTree.insert(randomInput);
//         }
//     }

//     actualOutput = inputTree.print_inorder();
//     REQUIRE(expectedOutput.size() == actualOutput.size());
//     REQUIRE_FALSE(expectedOutput == actualOutput);    //This assertion can be wrong. Don't use
//     sort(expectedOutput.begin(), expectedOutput.end());
//     REQUIRE(expectedOutput == actualOutput);

// }