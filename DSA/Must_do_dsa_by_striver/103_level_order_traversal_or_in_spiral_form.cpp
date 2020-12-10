//problem link:  https://practice.geeksforgeeks.org/problems/level-order-traversal/1 // print in in one single line
// * https://leetcode.com/problems/binary-tree-level-order-traversal/ // print level by level
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/ // print zig zag
// ! tutorial link: way to add into vector<vector<int>>
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
//* in one line.
vector<int> levelOrderInOneline(TreeNode *node)
{
    //Your code here
    vector<int> result;
    deque<TreeNode *> q;
    TreeNode *curr = node;
    q.push_back(curr);
    TreeNode *temp = nullptr;
    while (!q.empty())
    {
        if (curr->left)
            q.push_back(curr->left);
        if (curr->right)
            q.push_back(curr->right);
        temp = q.front();
        result.push_back(temp->val);
        q.pop_front();
        curr = q.front();
    }
    return result;
}
//* level by level in new line
//! one new learning after this
//* this commented code is complex and gives wrong answer for few in  LC , better way is implemented below.
//
// vector<vector<int>> levelOrder(TreeNode *root)
// {
//     vector<vector<int>> result;
//     if (!root)
//         return result;
//     //
//     TreeNode *curr = root, *temp = nullptr;
//     deque<TreeNode *> q;
//     q.push_back(curr);
//     q.push_back(nullptr);
//     //
//     vector<int> tvec;
//
//     while (!q.empty())
//     {
//         if (curr)
//             q.push_back(curr->left);
//         if (curr)
//             q.push_back(curr->right);
//         q.push_back(nullptr);
//         //
//         temp = q.front();
//         if (temp)
//             tvec.push_back(temp->val); //
//         q.pop_front();
//         temp = q.front();
//
//         if (!temp) // null,new line
//         {
//             // new line or new inside vector
//             if (tvec.size() > 0)
//                 result.push_back(tvec);
//             tvec.resize(0); // new inside vector allocated.
//             q.pop_front();
//         }
//
//         curr = q.front();
//     }
//
//     return result;
// }

// * THIS MEDTHOD IS TWICE FASTER, BECASUE OF NO RESIZING AND ALL AND HEREAFTER OUR WAY TO GO.
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (!root)
        return {};
    // technique using null pointer can work too, but we will go with queue size.
    TreeNode *curr = root, *temp;
    int size = 0;
    deque<TreeNode *> q;
    q.push_back(curr);
    //vector<int>vec;
    while (!q.empty())
    {
        // jtinna q ka size utna baar front ke left right ko push kar ke kpop karo
        size = q.size();
        result.push_back({});
        while (size--)
        {
            temp = q.front();
            //vec.push_back(temp->val);
            result.back().push_back(temp->val);
            q.pop_front();
            if (temp->left)
                q.push_back(temp->left);
            if (temp->right)
                q.push_back(temp->right);
        } // A smaller trick here will give us height of tree too. think and go to next question.
        // result.push_back(vec);
        //vec.resize(0);
    }

    return result;
}

// * spiral
/*
flag ko alternate, say 1 and 0;
when 1, samne se nikalo,  pich add karo left and then right. (usual)
when 0 , back se nikalo, aage se addd karo, right and then left.

*/
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (!root)
        return {};
    vector<vector<int>> result;
    int flag = 1;
    deque<TreeNode *> q;
    TreeNode *curr = root, *temp = nullptr;
    q.push_back(curr); // usual for flag==1;
    int size = 0;
    while (!q.empty())
    {
        result.push_back({});
        size = q.size();
        if (flag)   // 1st time usual, we are visting inside 1st while loop only.
        {
            while (size--)
            {
                temp = q.front();
                q.pop_front();
                result.back().push_back(temp->val);
                if (temp->left)
                    q.push_back(temp->left);
                if (temp->right)
                    q.push_back(temp->right);
            }
        }
          
        else
        {        // reverse for 0 
             while (size--)
            {
                temp = q.back();
                q.pop_back(); // piche se nikala
                result.back().push_back(temp->val);
                if (temp->right) // pehle right
                    q.push_front(temp->right);
                if (temp->left) // then left
                    q.push_front(temp->left);
            }
        }
        flag ^= 1;
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

    cout << "\nLevel order traversal of binary tree is \n";
    vector<int> result = levelOrderInOneline(root);
    vector<vector<int>> results2 = levelOrder(root);
    vector<vector<int>> results = zigzagLevelOrder(root);

    for (auto x : result)
        cout << x << " ";
    cout << endl;
    cout << "finished" << endl;
    for (auto x : results2)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    cout << "finished" << endl;

    for (auto x : results)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}