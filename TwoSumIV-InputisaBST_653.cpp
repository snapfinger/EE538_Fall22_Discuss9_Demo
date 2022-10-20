// Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

// Example 1:
// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true

// Example 2:
// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false


#include "common_headers.h"

// Sol 2: BST to sorted array with inorder traversal
// Time: O(n)
// Space: O(n)
bool findTarget(TreeNode* root, int k) {
        vector<int> vals;
        inorderTraversal(root, vals);
        int i = 0, j = vals.size() - 1;
        while(i < j){
            if(vals[i] + vals[j] == k) return true;
            if(vals[i] + vals[j] < k) i++;
            else j--;
        }
        
        return false;
}
    
void inorderTraversal(TreeNode* root, vector<int>& rst){
    if(root == nullptr)return;
    inorderTraversal(root->left, rst);
    rst.push_back(root->val);
    inorderTraversal(root->right, rst);
}