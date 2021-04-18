//*  slower, 4 ms, 1st run.
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {

        string osf = "";
        vector<string> ans;
        if (!root)
            return ans;
        printPaths(osf, root, ans);
        return ans;
    }

private:
    void printPaths(string osf, TreeNode *root, vector<string> &ans)
    {
        if (!root)
        {
            ans.push_back(osf.substr(0, osf.size() - 2)); // substr is expensive, tweak to get rid of it.
            return;
        }
        osf += to_string(root->val) + "->";
        if (root->left) // if not left, then go right
            printPaths(osf, root->left, ans);
        if (root->right)
            printPaths(osf, root->right, ans);
        if (!root->left && !root->right)
            printPaths(osf, nullptr, ans);
    }
};
// * faster, 0ms, without substr.
private:
void printPaths(string osf, TreeNode *root, vector<string> &ans)
{
    osf += to_string(root->val);
    if (!root->left && !root->right)
    {
        ans.push_back(osf);
        return;
    }
    if (root->left) // if not left, then go right
        printPaths(osf + "->", root->left, ans);
    if (root->right)
        printPaths(osf + "->", root->right, ans);
}
