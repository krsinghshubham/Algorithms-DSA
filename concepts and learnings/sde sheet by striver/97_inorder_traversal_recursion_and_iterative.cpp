//problem link: https://leetcode.com/problems/binary-tree-inorder-traversal/
// tutorial linK:
// morriss: https://www.youtube.com/watch?v=9ChGER8A3Ps&ab_channel=KarthikChennupati
// stack: https://www.youtube.com/watch?v=nzmtCFNae9k
// stack wale ka video se keval idea, code mera. video wale code is not that much optimised.just understand the flow from it.
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
Morris traversal: O(2n) time and O(1) space.Although linear its significantyly slower than recursive one

*/

//* recursive soln:

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

void iot(TreeNode *root, vector<int> &ans)
{

    if (!root)
        return;
    iot(root->left, ans);
    ans.push_back(root->val);
    iot(root->right, ans);
}
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> v;
    iot(root, v);
    return v;
}
vector<int> inorderTraversalUsingStack(TreeNode *root)
{
    vector<int> result;

    stack<TreeNode *> st;

    while (1)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }               // reached left most node and root is now having null
        if (st.empty()) // if any point stack is empty break.
            break;
        // we have to go right of last node, which is stored in stack but only if exists.
        TreeNode *temp = st.top();
        st.pop();                    // remove from top.
        result.push_back(temp->val); //left node.
        if (temp->right)
            root = temp->right;
    }
    return result;
}
vector<int> morrisInorderTraversal(TreeNode *root)
{
    vector<int> result;

    return result;
}
// Iterative Solution
int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "\nInorder traversal of binary tree is \n";
    // vector<int>result=inorderTraversal(root);
    // vector<int> result = inorderTraversalUsingStack(root);
    vector<int> result = morrisInorderTraversal(root);
    for (auto x : result)
        cout << x << " ";

    return 0;
}