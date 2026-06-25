class Codec {
public:
    void preorder(TreeNode* root, string &s){
        if(root == NULL){
            s += "N,";
            return;
        }
        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right,s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        preorder(root , s);
        return s;
    }
    TreeNode* build(vector<string>& nodes, int &index){
        if(nodes[index] == "N"){
            index++;
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(nodes[index]));
        index++;

        root->left = build(nodes , index);
        root->right = build(nodes, index);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp = "";
        for(char ch : data){
            if(ch == ','){
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }
        int index = 0;
        return build(nodes , index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;