// recursive solution
class Solution {
public:
   TreeNode* searchBST(TreeNode* root, int val) 
    {
        // base condios: 
         if(!root) // will come before next if , otherwise exception.
            return NULL;
        if(root->val==val)
            return root;
        // if( val > root->val) // recursive intuition
        {
           return searchBST(root->right, val);// self work
        }
        if(val < root->val)
        {
          return  searchBST(root->left,val);
        }
        return root; // for sake of return type , although control wont reach here.
    }
};

// Iterative Solution. 
class Solution {
public:
   TreeNode* searchBST(TreeNode* root, int val) 
    {
       // Iterative Solution. given contains atleast one node.
       while(root)
       {
           if(val==root->val)
               return root;
           if(val > root->val)
               root=root->right;
           else
               root=root->left;
       }
       return root;
    }
};