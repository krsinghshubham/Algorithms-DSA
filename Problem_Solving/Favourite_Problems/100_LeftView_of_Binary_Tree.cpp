//problem link: https://leetcode.com/problems/binary-tree-right-side-view/
// tutorial link: no need , just apply bfs, visit 1st node only
// * CAN BE SOLVED BY BFS AND DFS BOTH, IMPLEMENT BOTH
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
/*
 *FOR LEFT VIEW, FORM GEEKS FOR GEEKS. // https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#
vector<int> leftView(Node *root)
{
    
    vector<int> result;
    if (!root)
        return {};
    Node *curr = root, *temp;
    int size = 0;
    deque<Node *> q;
    q.push_back(curr);
    while (!q.empty())
    {
        // jtinna q ka size utna baar front ke left right ko push kar ke kpop karo
        size = q.size();
        temp = q.back();
        result.push_back(temp->data);
        while (size--)
        {
            q.pop_front();
            if (temp->left)
                q.push_back(temp->left);
            if (temp->right)
                q.push_back(temp->right);
        }
    }
    return result;
}
*/
//* For right view, leetcode, as link posted above.
vector<int> rightSideViewUsingBFS(TreeNode *root)
{ // ! using BFS
    vector<int> result;
    if (!root)
        return {};
    TreeNode *curr = root, *temp;
    int size = 0;
    deque<TreeNode *> q;
    q.push_back(curr);
    while (!q.empty())
    {
        // jtinna q ka size utna baar front ke left right ko push kar ke kpop karo
        size = q.size();
        temp = q.back();
        result.push_back(temp->val);

        while (size--)
        {
            temp = q.front();
            q.pop_front();
            if (temp->left)
                q.push_back(temp->left);
            if (temp->right)
                q.push_back(temp->right);
        }
    }
    return result;
}
// using DFS....
class Solution
{
public:
    vector<int> rightSideViewUsingDFS(TreeNode *root)
    { // ! using DFS IMPORTANT TO VISUALIZE AND UNDERSTAND.
        vector<int> result;
        rightSideUsingDFS(root, result, 0);
        return result;
    }

private:
    void rightSideUsingDFS(TreeNode *root, vector<int> &results, int level) // so if root at
    {
        if (!root)
            return;
        if (results.size() == level) //  * most important step... so if vector ka size 0, means level 0, 1 means 1, after each iteration level will increase.
            results.push_back(root->val);
        rightSideUsingDFS(root->right, results, level + 1); // 1st right.
        rightSideUsingDFS(root->left, results, level + 1);
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "\n traversal of binary tree is \n";
    vector<int> result = rightSideViewUsingBFS(root);

    for (auto x : result)
        cout << x << " ";
    cout << "\nfinished" << endl;
    Solution obj;
    vector<int> results = obj.rightSideViewUsingDFS(root);
    for (auto x : results)
        cout << x << " ";
    return 0;
}
