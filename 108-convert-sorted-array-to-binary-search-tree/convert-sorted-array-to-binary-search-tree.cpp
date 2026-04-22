class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* build(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;  // Base case

        int mid = left + (right - left) / 2;  // Avoid overflow

        TreeNode* node = new TreeNode(nums[mid]);         // Root = middle element
        node->left  = build(nums, left, mid - 1);         // Left subtree
        node->right = build(nums, mid + 1, right);        // Right subtree

        return node;
    }
};