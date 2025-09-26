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
    Node* insert_helper(Node* node, string name, int ufid);

public:
    Node*& get_root() { return root; }
    void check_commands(string commands);
    void insert(string name, int ufid);
    Node* balance_tree(Node* node, int ufid);
    Node* remove(Node* node, int ufid);
    void search_id(int ufid);
    void search_name(string name);
    void traverse_subtree(Node* node, string name);
    void print_inorder(Node* node);
    void print_preorder(Node* node);
    void print_postorder(Node* node);
    void print_level_count();
    void remove_inorder(int nth_node);
    void inorder_ufid_vector(Node* node, vector<int>& inorder_vec);
    void inorder_names_vector(Node* node, vector<string>& inorder_vec);
    void preorder_names_vector(Node* node, vector<string>& preorder_vec);
    void postorder_names_vector(Node* node, vector<string>& postorder_vec);
    int get_height(Node* node);
    int get_balance(Node* node);
    ~AVLTree(); //use postorder to delete each node
};