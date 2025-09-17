#include "AVL.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void AVLTree::check_commands(string commands) {
    istringstream iss(commands);
    vector<string> commandList;
    string command;
    if (commands == "") {
        throw invalid_argument("Error: No command provided");
    }
    while (iss >> command) {
        commandList.push_back(command);
    }
    int size = commandList.size();
    string cmd = commandList[0];
    if (cmd == "insert") {
        if (size != 3) {
            throw invalid_argument("Error: Invalid number of arguments for insert");
        }
        if (commandList[1].empty() || commandList[2].empty()) {
            throw invalid_argument("Error: Name and UFID cannot be empty");
        }
        if (!all_of(commandList[1].begin(), commandList[1].end(), [](char c){ return isalpha(c) || c == ' '; })) {
            throw invalid_argument("Error: Name must contain only alphabetic characters and spaces");
        }
        if (commandList[2].length() != 8 || !all_of(commandList[2].begin(), commandList[2].end(), ::isdigit)) {
            throw invalid_argument("Error: UFID must be an 8-digit number");
        }
    } else if (cmd == "remove") {
        if (size != 2) {
            throw invalid_argument("Error: Invalid number of arguments for remove");
        }
    } else if (cmd == "search_id") {
        if (size != 2) {
            throw invalid_argument("Error: Invalid number of arguments for search_id");
        }
        string ufid = commandList[1];
        search_id(ufid);
    } else if (cmd == "search_name") {
        if (size != 2) {
            throw invalid_argument("Error: Invalid number of arguments for search_name");
        }
        string name = commandList[1];
        search_name(name);
    } else if (cmd == "print_inorder") {
        if (size != 1) {
            throw invalid_argument("Error: Invalid number of arguments for print_inorder");
        }
        print_inorder();
    } else if (cmd == "print_preorder") {
        if (size != 1) {
            throw invalid_argument("Error: Invalid number of arguments for print_preorder");
        }
        print_preorder();
    } else if (cmd == "print_postorder") {
        if (size != 1) {
            throw invalid_argument("Error: Invalid number of arguments for print_postorder");
        }
        print_postorder();
    } else if (cmd == "print_level_count") {
        if (size != 1) {
            throw invalid_argument("Error: Invalid number of arguments for print_level_count");
        }
        print_level_count();
    } else if (cmd == "remove_inorder") {
        if (size != 2) {
            throw invalid_argument("Error: Invalid number of arguments for remove_inorder");
        }
        int n;
        try {
            n = stoi(commandList[1]);
        } catch (const exception& e) {
            throw invalid_argument("Error: Argument for remove_inorder must be an integer");
        }
        remove_inorder(n);
    } else {
        throw invalid_argument("Error: Unknown command");
    }
}

void AVLTree::insert(string name, string ufid) {
    this->root = insertHelper(this->root, name, ufid);
}

Node* AVLTree::insertHelper(Node* node, string name, string ufid) {
    if (node == nullptr) {
        return new Node(name, ufid);
    }
    if (ufid < node->ufid) {
        node->left = insertHelper(node->left, name, ufid);
    } else if (ufid > node->ufid) {
        node->right = insertHelper(node->right, name, ufid);
    } else {
        throw invalid_argument("Error: Duplicate UFID");
    }
    // Note: AVL balancing logic should be implemented here
    return node;        
}

void AVLTree::remove(string ufid) { 

}

void AVLTree::search_id(string ufid) {

}
void AVLTree::search_name(string name) {

}
void AVLTree::print_inorder() {

}
void AVLTree::print_preorder() {

}
void AVLTree::print_postorder() {

}
void AVLTree::print_level_count() {

}
void AVLTree::remove_inorder(int n) {

}

AVLTree::~AVLTree() {
    //use postorder to delete each node
    if (this->root != nullptr) {
        delete(this->root);
    }
}
