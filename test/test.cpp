// #include <catch2/catch_test_macros.hpp>
// #include <iostream>
// #include "../src/AVL.h"

// //Name: Martina Delger
// //UFID: 1977 4238

// // uncomment and replace the following with your own headers
// #include <algorithm>
// #include <vector>
// #include <string>
// using namespace std;

// // you must write 5 unique, meaningful tests for credit on the testing portion of this project!

// // the provided test from the template is below.
// //Test at least five incorrect commands. Ex: insert "A11y" 45679999 [0.5 points]
// TEST_CASE("Test 1: Commands Testing", "[avl][command_error]") {
// 	AVLTree tree;   
//     tree.check_commands(""); //should print unsuccessful
//     tree.check_commands("insert"); //should print unsuccessful
//     tree.check_commands("insert A11y 45679999"); //should print unsuccessful
//     tree.check_commands("John insert 1234567"); //should print unsuccessful
//     tree.check_commands("insert 12345678 John"); //should print unsuccessful
// }

// //Test all four rotation cases [1 point]
// TEST_CASE("Test 2: Insert Testing", "[avl][rotations]"){
//     AVLTree tree;
//     vector<int> expectedOutput, actualOutput;
//     //left left case
//     tree.insert("Martina", 100000040);
//     tree.insert("Alice", 100000030);
//     tree.insert("Bob", 100000020);

//     //right right case
//     tree.insert("Max", 100000060);
//     tree.insert("Bryan", 100000070);

//     //left right case
//     tree.insert("Martin", 100000010);
//     tree.insert("Robert", 100000015);

//     //right left case
//     tree.insert("Michael", 100000080);
//     tree.insert("Josh", 100000075);

//     Node* root = tree.get_root();
//     tree.inorder_ufid_vector(root, actualOutput);
//     expectedOutput = {100000010, 100000015, 100000020, 100000030, 100000040, 100000060, 100000070, 100000075, 100000080};
//     REQUIRE(expectedOutput.size() == actualOutput.size());
//     REQUIRE(actualOutput == expectedOutput);
// }

// //Insert at least 100 nodes, remove ten random nodes using any delete operation, and check in order. Hint: Use a loop to verify the 100 insertions and the 90 nodes after removal.
// TEST_CASE("Test 3: Insert 100/remove 10 Test", "[avl][insert]"){
//     AVLTree inputTree;
//     vector<int> expectedOutput, actualOutput;
//     string test_name = "Test User";
//     Node* &inputtree_root = inputTree.get_root();

//     //create the 100
//     for(int i = 0; i < 100; i++) {
//         int randomInput = rand();
//         if (count(expectedOutput.begin(), expectedOutput.end(), randomInput) == 0) {
//             expectedOutput.push_back(randomInput);
//             inputTree.insert(test_name, randomInput);
//         }
//     }

//     //remove 10 random 
//     for (int i=0; i<10; i++) {
//         int removed_node = expectedOutput.back();
//         expectedOutput.pop_back();
//         inputtree_root = inputTree.remove(inputtree_root, removed_node);
//     }

//     inputTree.inorder_ufid_vector(inputtree_root, actualOutput);
//     REQUIRE(expectedOutput.size() == actualOutput.size());
//     sort(expectedOutput.begin(), expectedOutput.end());
//     REQUIRE(expectedOutput == actualOutput);
// }

// //Test at least three edge cases for various functions. Ex: removing a node that doesn’t exist [0.5 points]
// TEST_CASE("Test 4: Edge Cases Test", "[avl][edge_cases]") {
//     AVLTree tree;
//     tree.insert("Martina", 11111111);
//     tree.insert("Alice", 22222222);
//     tree.insert("Bob", 33333333);

//     //remove a node that doesn't exist
//     tree.remove(tree.get_root(), 44444444); //should print unsuccessful

//     //remove inorder with an invalid index
//     tree.remove_inorder(-1); //should print unsuccessful
//     tree.remove_inorder(5); //should print unsuccessful since there are only 3 nodes

//     //search for a node that doesn't exist
//     tree.search_id(55555555); //should print unsuccessful
//     tree.search_name("Charlie"); //should print unsuccessful
// }

// //Test all three deletion cases (no children, one child, two children) [1 point]
// TEST_CASE("Test 5: Deletion Cases Test", "[avl][deletion]") {
//     AVLTree tree;
//     tree.insert("Martina", 11111111);
//     tree.insert("Alice", 22222222);
//     tree.insert("Bob", 33333333);

//     tree.insert("Max", 44444444);
//     tree.insert("Bryan", 55555555);

//     tree.insert("Martin", 66666666);
//     tree.insert("Robert", 77777777);

//     tree.insert("Michael", 88888888);
//     tree.insert("Josh", 99999999);

//     //deleting with no children
//     tree.remove(tree.get_root(), 99999999); //removing Josh
//     vector<string> expectedOutput1 = {"Martina", "Alice", "Bob", "Max", "Bryan", "Martin", "Robert", "Michael"};
//     vector<string> actualOutput1;
//     tree.inorder_names_vector(tree.get_root(), actualOutput1);
//     REQUIRE(expectedOutput1 == actualOutput1);

//     //deleting with one child
//     tree.remove(tree.get_root(), 88888888); //removing Michael
//     vector<string> expectedOutput2 = {"Martina", "Alice", "Bob", "Max", "Bryan", "Martin", "Robert"};
//     vector<string> actualOutput2;
//     tree.inorder_names_vector(tree.get_root(), actualOutput2);
//     REQUIRE(expectedOutput2 == actualOutput2);

//     //deleting with two children
//     tree.remove(tree.get_root(), 22222222); //removing Alice
//     vector<string> expectedOutput3 = {"Martina", "Bob", "Max", "Bryan", "Martin", "Robert"};
//     vector<string> actualOutput3;
//     tree.inorder_names_vector(tree.get_root(), actualOutput3);
//     REQUIRE(expectedOutput3 == actualOutput3);
// }

// TEST_CASE("Test 6: Level Order Test", "[avl][LevelOrder]") {
//     AVLTree tree;
//     tree.insert("Martina", 11111111);
// 	tree.insert("Alice", 22222222);
// 	tree.insert("Bob", 33333333);

//     tree.insert("Max", 44444444);
// 	tree.insert("Bryan", 55555555);

//     tree.insert("Martin", 66666666);
// 	tree.insert("Robert", 77777777);

//     tree.insert("Michael", 88888888);
// 	tree.insert("Josh", 99999999);

// 	tree.print_level_count();
//     REQUIRE(tree.get_height(tree.get_root()) == 4);
// }

// TEST_CASE("Test 7: Search Test", "[avl][search]") {
//     AVLTree tree;
//     tree.insert("Martina", 11111111);
// 	tree.insert("Alice", 22222222);
// 	tree.insert("Bob", 33333333);

//     tree.insert("Max", 44444444);
// 	tree.insert("Bryan", 55555555);

//     tree.insert("Martin", 66666666);
// 	tree.insert("Robert", 77777777);

//     tree.insert("Michael", 88888888);
// 	tree.insert("Josh", 99999999);

//     //search id tests
//     tree.search_id(66666666); //should print Martin
//     tree.search_id(12345678); //should print unsuccessful

//     //search name tests
//     tree.search_name("Robert"); //should print 77777777
//     tree.search_name("Martin"); //should print 66666666
// }