class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;
        queue<pair<TreeNode*  ,long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            long long first = q.front().second;
            long long last = q.back().second;
            ans = max(ans, last-first+1);
            for(int i=0; i<size; i++){
                auto front = q.front();
                q.pop();
                TreeNode* node = front.first;
                long long index = front.second - first;
                if(node->left){
                    q.push({node->left , 2*index+1});
                }
                if(node->right){
                    q.push({node->right, 2*index+2});
                }
            }
        }
        return ans;
    }
};