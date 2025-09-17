#pragma once
#include <string>
#include <vector>
using namespace std;

struct Node {
    string name;
    string ufid;
    Node* left;
    Node* right;

    Node(string name, string ufid) {
        this->name = name;
        this->ufid = ufid;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class AVLTree {

private:
    Node* root = nullptr;
    Node* insertHelper(Node* node, string name, string ufid);

public:
    void check_commands(string commands);
    void insert(string name, string ufid);
    void remove(string ufid);
    void search_id(string ufid);
    void search_name(string name);
    void print_inorder();
    void print_preorder();
    void print_postorder();
    void print_level_count();
    void remove_inorder(int n);
    ~AVLTree(); //use postorder to delete each node
};