class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // Initialize the diameter to be updated during DFS
        int ans = 0;
        
        // Recursive DFS function
        dfs(root, ans);

        // Return the final diameter of the binary tree
        return ans;
    }

private:
    int dfs(TreeNode* root, int &ans) {
        // Base case: If the node is null, return -1 as height
        if (root == NULL) {
            return -1;
        }

        // Recursive DFS for left and right subtrees
        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);

        // Update diameter using the current node
        ans = max(ans, 2 + left + right);

        // Return height of the current subtree
        return 1 + max(left, right);
    }
};