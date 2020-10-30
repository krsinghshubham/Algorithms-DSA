//problem link: https://leetcode.com/problems/minimum-depth-of-binary-tree/
// tutorial linK: https://www.youtube.com/watch?v=_pnqMz5nrRs and also in placement notes.
// learning: using recursion, can be done easily via iteratively too.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FASTIO_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
Algorithm ITERATIVE : EASY, NOT IMPLEMENTED BY MYSELF, KABHI TIME MILE TO I HAVE TO IMPLEMENT THIS AND UNCOMMENT THE CODE.

                                                       Create a queue.Push root into the queue.height = 0 Loop nodeCount = size of queue

                                                       // If the number of nodes at this level is 0, return height
                                                       if nodeCount is 0 return Height;
else increase Height

    // Remove nodes of this level and add nodes of
    // next level
    while (nodeCount > 0)
        pop node from front
            push its children to queue
                decrease nodeCount
    // At this point, queue has nodes of next level
    // CODE:
    //* Time: O(n), Space: O(1) same as level order traversal. space is of algorithm and not in between.

    // Iterative method to find the height of Binary Tree
    int
    treeHeight(node *root)
{
    // Base Case
    if (root == NULL)
        return 0;

    // Create an empty queue for level order tarversal
    queue<node *> q;

    // Enqueue Root and initialize height
    q.push(root);
    int height = 0;

    while (1)
    {
        // nodeCount (queue size) indicates number of nodes
        // at current lelvel.
        int nodeCount = q.size();
        if (nodeCount == 0)
            return height;

        height++;

        // Dequeue all nodes of current level and Enqueue all
        // nodes of next level
        while (nodeCount > 0)
        {
            node *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
    }
}
int main()
{
    FASTIO_TEMPLATE;
    int tc;
    cin >> tc;
    while (tc--)
    {
    }
    return 0;
}