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
    } else if (cmd == "printInorder") {
        if (size != 1) {
            throw invalid_argument("Error: Invalid number of arguments for print_inorder");
        }
        print_inorder(this->root);
    } else if (cmd == "printPreorder") {
        if (size != 1) {
            throw invalid_argument("Error: Invalid number of arguments for print_preorder");
        }
        print_preorder(this->root);
    } else if (cmd == "printPostorder") {
        if (size != 1) {
            throw invalid_argument("Error: Invalid number of arguments for print_postorder");
        }
        print_postorder(this->root);
    } else if (cmd == "print_level_count") {
        if (size != 1) {
            throw invalid_argument("Error: Invalid number of arguments for print_level_count");
        }
        print_level_count();
    } else if (cmd == "removeInorder") {
        if (size != 2) {
            throw invalid_argument("Error: Invalid number of arguments for removeInorder");
        }
        int n;
        try {
            n = stoi(commandList[1]);
        } catch (const exception& e) {
            throw invalid_argument("Error: Argument for removeInorder must be an integer");
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
        return node;
    }
    //for syntax under this i used https://www.geeksforgeeks.org/dsa/insertion-in-an-avl-tree/ and the class slides for Balanced BSTs
    node->height = 1 + max(get_height(node->left), get_height(node->right));
    int balance = get_balance(node);

    //left left rotation = right rotation
    if (balance > 1 && ufid < node->left->ufid) {
        Node* new_root = node->left;
        node->left = new_root->right;
        new_root->right = node;
        return new_root;
    }
    //right right rotation = left rotation
    if (balance < -1 && ufid > node->right->ufid) {
        Node* new_root = node->right;
        node->right = new_root->left;
        new_root->left = node;
        return new_root;
    }
    //left right rotation
    if (balance > 1 && ufid > node->left->ufid) {
        Node* new_root = node->left->right;
        node->left->right = new_root->left;
        new_root->left = node->left;
        node->left = new_root->right;
        new_root->right = node;
        return new_root;
    }

    //right left rotation
    if(balance < -1 && ufid < node->right->ufid) {
        Node* new_root = node->right->left;
        node->right->left = new_root->right;
        new_root->right = node->right;
        node->right = new_root->left;
        new_root->left = node;
        return new_root;
    }
    //to here

    return node;
}

void AVLTree::remove(string ufid) { 

}

void AVLTree::search_id(string ufid) {

}

void AVLTree::search_name(string name) {

}

void AVLTree::print_inorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    print_inorder(node->left);
    cout << node->name << " " << node->ufid << endl;
    print_inorder(node->right);
}

void AVLTree::print_preorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->name << " " << node->ufid << endl;
    print_preorder(node->left);
    print_preorder(node->right);
}

void AVLTree::print_postorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    print_postorder(node->left);
    print_postorder(node->right);
    cout << node->name << " " << node->ufid << endl;
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

int AVLTree::get_height(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

int AVLTree::get_balance(Node* node) {
    if (node == nullptr) return 0;
    return get_height(node->left) - get_height(node->right);
}