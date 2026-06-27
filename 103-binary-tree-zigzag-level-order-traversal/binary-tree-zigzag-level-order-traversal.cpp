class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool reverseFlag = false;
        while(!q.empty()){
            int size = q.size();
            
            vector<int> temp;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(reverseFlag){
                reverse(temp.begin() , temp.end());
            }
            ans.push_back(temp);
            reverseFlag = !reverseFlag;
        }
        return ans;
    }
};