#pragma once
#include <string>
#include <vector>
using namespace std;

struct Node {
    string name;
    string ufid;
    Node* left;
    Node* right;
    int height;

    Node(string name, string ufid) {
        this->name = name;
        this->ufid = ufid;
        this->left = nullptr;
        this->right = nullptr;  
        this->height = 1;
    }
};

class AVLTree {

private:
    Node* root = nullptr;
    Node* insertHelper(Node* node, string name, string ufid);

public:
    Node* get_root() { return root; }
    int get_height(Node* node);
    int get_balance(Node* node);
    void check_commands(string commands);
    void insert(string name, string ufid);
    void remove(string ufid);
    void search_id(string ufid);
    void search_name(string name);
    void print_inorder(Node* node);
    void print_preorder(Node* node);
    void print_postorder(Node* node);
    void print_level_count();
    void remove_inorder(int n);
    ~AVLTree(); //use postorder to delete each node
};