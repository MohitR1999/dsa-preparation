#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
public:
    vector <int> printBoundary(Node *root)
    {
        //Your code here
        vector<int> r;
        r.push_back(root->data);
        helperLeft(root->left, r);
        helperLeaves(root, r);
        helperRight(root->right, r);
        return r;
    }
    
    void helperLeft(Node *root, vector<int>& res) {
        if (!root) return;
        if (!root->left && !root->right) return;
        if (root->left) {
            res.push_back(root->data);
            helperLeft(root->left, res);
        }
        else if (root->right) {
            res.push_back(root->data);
            helperLeft(root->right, res);
        }
    }
    
    void helperLeaves(Node *root, vector<int>& res) {
        if (!root) return;
        helperLeaves(root->left, res);
        if (!root->left && !root->right) {
            res.push_back(root->data);
        }
        helperLeaves(root->right, res);
    }
    
    void helperRight(Node *root, vector<int>& res) {
        if (!root) return;
        if (!root->left && !root->right) return;
        if (root->right) {
            helperRight(root->right, res);
            res.push_back(root->data);
        }
        else if (root->left) {
            helperRight(root->left, res);
            res.push_back(root->data);
        }
    }
};