class Solution {
public:
    unordered_map<long long, int> mp;
    int dfs(TreeNode* root, long long current, int target){
        if(root == NULL){
            return 0;
        }
        current += root->val;
        int count = mp[current - target];
        mp[current]++;
        count += dfs(root->left, current, target);
        count += dfs(root->right, current, target);
        mp[current]--;
        return count;

    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        return dfs(root, 0 , targetSum);
    }
};