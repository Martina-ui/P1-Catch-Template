#pragma once
#include <string>
#include <vector>
using namespace std;

//for syntax for lines 7-27 i got from project 1 video walkthrough
struct Node {
    string name;
    int ufid;
    Node* left;
    Node* right;
    int height;

    Node(string name, int ufid) {
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
    Node* insertHelper(Node* node, string name, int ufid);

public:
    Node*& get_root() { return root; }
    void check_commands(string commands);
    void insert(string name, int ufid);
    Node* remove(Node* node, int ufid);
    void search_id(string ufid);
    void search_name(string name);
    void print_inorder(Node* node);
    void print_preorder(Node* node);
    void print_postorder(Node* node);
    void print_level_count();
    void remove_inorder(int n);
    void inorder_ufid_vector(Node* node, vector<int>& inorder_vec);
    int get_height(Node* node);
    int get_balance(Node* node);
    Node* balance_tree(Node* node, int ufid);
    ~AVLTree(); //use postorder to delete each node
};