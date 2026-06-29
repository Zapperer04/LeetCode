class Solution {
public:
    void buildParent(
        TreeNode* root,
        unordered_map<TreeNode*,TreeNode*>& parent,
        TreeNode*& target,
        int start)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start){
                target = node;
            }
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        TreeNode* target = NULL;
        buildParent(root,parent,target,start);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int time = -1;
        while(!q.empty()){
            int size = q.size();
            time++;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left &&
                   !visited[node->left]){
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node->right &&
                   !visited[node->right]){
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(parent[node] &&
                   !visited[parent[node]]){
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }
        return time;
    }
};