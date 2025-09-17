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

// TEST_CASE("Test 2: Insert Testing", "[flag]"){
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

// TEST_CASE("Test 3: Insert 100 Test", "[flag]"){
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