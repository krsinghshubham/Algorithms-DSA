//problem link: https://leetcode.com/problems/binary-tree-inorder-traversal/
// tutorial linK:
//! morriss: (ALSO CALLED THREADED BINARY TREE) https://www.youtube.com/watch?v=9ChGER8A3Ps&ab_channel=KarthikChennupati
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
// recursion
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
// Iterative: using stack
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
// * Iteratvie : using morris
// TreeNode *predecessor(TreeNode *root) // lengthy to use it outside , because we need to pass current also.
// {
//     while (root->right)
//     root = root->right;
//     return root;
// }
vector<int> morrisInorderTraversal(TreeNode *root)
{
    vector<int> result;
    TreeNode *curr = root;
    while (curr)
    {
        if (!curr->left) // only right subtree exists.
        {
            result.pb(curr->val); // visit current
            curr = curr->right;
        }
        else
        {
            TreeNode *pred = curr->left; // rightmost node of left subtree; Making a function and using outide will be lengthy coz it will need to pass curr also.
            // while(pred->right || (pred->right!=curr)) // better way
            while (pred->right && pred->right != curr) // confused at first time... thinking pred->right as pred->right->right
                pred = pred->right;
            // predecesoor updated
            // cout << "pred seq " << pred->val << endl;
            // cout << endl;
            if (!pred->right) // 1st time me nahi karega, but after re visiting that node, it will exist;
            {
                pred->right = curr; // threaded to current node
                curr = curr->left;
            }
            else // means we are revisiting
            {
                pred->right = nullptr;
                result.pb(curr->val); // root node of inorder travrsal
                curr = curr->right;
            }
        }
    }
    return result;
}
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