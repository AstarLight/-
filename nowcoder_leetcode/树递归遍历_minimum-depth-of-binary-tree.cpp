/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

#if 0
class Solution {
public:
    int run(TreeNode *root) {
        if(!root)
            return 0;
        int minDepth = 10000000;
        int curDepth = 0;
        run(root, minDepth, curDepth);
        return minDepth;
    }
    
    void run(TreeNode *root, int &minDepth, int& curDepth)
    {
        if(root == NULL)
            return;
        
        curDepth++;
        if(!root->left && !root->right)
        {
            if(minDepth > curDepth)
            {
                minDepth = curDepth;
            }
        }
        
        run(root->left, minDepth, curDepth);
        run(root->right, minDepth, curDepth);
        curDepth--;
    }
    
};
#endif

class Solution {
public:
    int run(TreeNode *root) {
        if(!root) 
            return 0;

        if(!root->left)
            return 1 + run(root->right);
        
        if(!root->right)
             return 1 + run(root->left);
        
        return 1 + min(run(root->left), run(root->right));
    }
};
