//problem link: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Reference link:
// stack: https://www.youtube.com/watch?v=elQcrJrfObg&t=213s&ab_channel=TusharRoy-CodingMadeSimple
// morriss: inorder wale me hi h dono last me
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
// recusive
void pot(TreeNode *head, vector<int> &result)
{
    if (!head)
        return;
    result.push_back(head->val);
    pot(head->left, result);
    pot(head->right, result);
}
vector<int> preorderTraversal(TreeNode *root)
{
    // recursive
    //root, left, right
    vector<int> result;
    pot(root, result); // to need resursion for base case we need to return to calling node
                       // without returning ans. only possible with void return type function.
    return result;
}
// Iterative: using stack
vector<int> PreOrderTraversalUsingStack(TreeNode *root)
{
    vector<int> result;

    stack<TreeNode *> st;
    TreeNode *curr = root;
    TreeNode *temp;
    st.push(curr);
    while (curr)
    {
        temp = st.top();
        result.push_back(temp->val);
        st.pop();
        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
        if (st.empty())
            curr = nullptr;
        else
            curr = st.top();
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
vector<int> MorrisPreOrderTraversal(TreeNode *root)
{
    vector<int> result;
    TreeNode *curr = root;
    while (curr)
    {
        result.pb(curr->val); // visit current

        if (!curr->left) // only right subtree exists.
        {
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
                pred->right = curr->right; // ! threaded to current's next node
                curr = curr->left;
            }
            else // means we are revisiting
            {
                pred->right = nullptr;
                //result.pb(curr->val); // root node of inorder travrsal
                curr = curr->right;
            }
        }
    }
    return result;
}
int main()
{
    struct TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    // root->left->left = new TreeNode(4);
    // root->left->left->right = new TreeNode(6);
    // root->left->right = new TreeNode(5);

    cout << "\nPreorder traversal of binary tree is \n";
    //vector<int> result = preorderTraversal(root);
    // vector<int> result = PreOrderTraversalUsingStack(root);
    vector<int> result = MorrisPreOrderTraversal(root);

    for (auto x : result)
        cout << x << " ";

    return 0;
}