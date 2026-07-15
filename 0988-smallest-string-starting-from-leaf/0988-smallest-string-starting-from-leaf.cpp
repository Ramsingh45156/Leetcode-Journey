/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string ans = "";
    void dfs(TreeNode* root, string path) {
        if (root == NULL)
            return;
        // Current character
        path.push_back(root->val + 'a');
        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            string temp = path;
            reverse(temp.begin(), temp.end());

            if (ans == "" || temp < ans)
                ans = temp;
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};