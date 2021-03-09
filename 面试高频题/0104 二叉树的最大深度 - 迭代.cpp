class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int res=0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode * t = q.front();
                q.pop();
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            ++res;
        }
        return res;
    }
};