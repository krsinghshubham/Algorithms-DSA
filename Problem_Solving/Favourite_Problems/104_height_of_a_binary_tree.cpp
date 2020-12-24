//problem link: https://leetcode.com/problems/minimum-depth-of-binary-tree/
// tutorial linK: https://www.youtube.com/watch?v=_pnqMz5nrRs and also in placement notes.
// for iterative here only.
// learning: using recursion, can be done easily via iteratively too.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// SAME AS MAXIMUM DEPTH OF A BINARY TREE. 2 VARIATION, MAX EDGES AND MAX NODES. IMPLEMENTING MAX NODES HERE, IN PLACEMNET DOC IMPL. WRT TO MAX EDGES.

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0; // for leaf it will hold 1, because we are returning +1;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0; // for leaf it will hold 1, because we are returning +1;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
        //return !root ? 0 : max(maxDepth(root->left), max depth(root->right)) + 1;
    }
};
__________________________________________________________________________________________________________
//! Algorithm ITERATIVE
//* same as BFS, just for each level increase height, thats it(just return height when size of queue becomes zero coz thats when all levels traversed.)
//* CODE:
//* Time: O(n), Space: O(1) same as level order traversal. space is of algorithm and not in between.

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        // iterative,max depth is same as height of tree. will be no of levels possible
        if (!root)
            return 0;
        deque<TreeNode *> q;
        int size = 0, height = 1; // min 1 height will be there since for null tree we handled already.
        TreeNode *temp, *curr = root;
        q.push_back(root);
        while (!q.empty())
        {
            size = q.size();
            while (size--)
            {
                temp = q.front();
                q.pop_front();
                if (temp->left)
                    q.push_back(temp->left);
                if (temp->right)
                    q.push_back(temp->right);
            }
            if (q.size() > 0)
                height++;
        }
        return height;
    }
};
int main()
{
    FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE;
    int tc;
    cin >> tc;
    while (tc--)
    {
    }
    return 0;
}