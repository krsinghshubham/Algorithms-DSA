//problem link: https://leetcode.com/problems/binary-tree-inorder-traversal/
// tutorial linK: reseach
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FASTIO_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
/*
Algorithm:
There are three solutions to this problem.

Iterative solution using stack: O(n) time and O(n) space;
Recursive solution: O(n) time and O(n) space (function call stack);
Morris traversal: O(n) time and O(1) space.

*/

//* recursive soln: 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void iot(TreeNode  *root, vector<int> &ans){
        
        if(!root) return ;    
         iot(root-> left, ans);
         ans.push_back(root-> val);
         iot(root-> right,ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) 
    {
         vector<int> v;
         iot(root, v);
         return v;
    
       
        
    }
};
// Iterative Solution
