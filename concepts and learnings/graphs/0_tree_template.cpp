//problem link: 
// tutorial link:
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FASTIO_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// void iot(TreeNode *root, vector<int> &ans)
// {
// 
//     if (!root)
//         return;
//     iot(root->left, ans);
//     ans.push_back(root->val);
//     iot(root->right, ans);
// }
// vector<int> inorderTraversal(TreeNode *root)
// {
//     vector<int> v;
//     iot(root, v);
//     return v;
// }

// Iterative Solution
int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "\nInorder traversal of binary tree is \n";
    vector<int> result = fuction(root);

    for (auto x : result)
        cout << x << " ";

    return 0;
}