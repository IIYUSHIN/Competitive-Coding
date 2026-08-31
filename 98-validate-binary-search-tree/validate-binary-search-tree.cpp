class Solution {
public:
    bool check(TreeNode* root, long long minValue, long long maxValue) {
        if (root == NULL)
            return true;

        if (root->val <= minValue || root->val >= maxValue)
            return false;

        return check(root->left, minValue, root->val) &&
               check(root->right, root->val, maxValue);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};