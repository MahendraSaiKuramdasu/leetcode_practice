/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inorder(TreeNode*& root, unordered_map<int,vector<int>>& adj){
    if(!root) return;
    if(root->left){
        adj[root->val].push_back(root->left->val);
        adj[root->left->val].push_back(root->val);
        inorder(root->left, adj);
    }
    if(root->right){
        adj[root->val].push_back(root->right->val);
        adj[root->right->val].push_back(root->val);
        inorder(root->right, adj);
    }
}

void dfs(int node, int curr, unordered_map<int,vector<int>>& adj, unordered_set<int>& st, int& k, vector<int>& ans){

    if (curr == k){
        ans.push_back(node);
        return;
    }

    st.insert(node);

    for(int i=0; i<adj[node].size(); i++){
        if(st.find(adj[node][i]) == st.end()){
            dfs(adj[node][i], curr+1, adj, st, k, ans);
        }
    }

    st.erase(node);
}

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>> adj;
        inorder(root, adj);
        // for(auto &i: adj){
        //     cout << i.first << ": ";
        //     for(auto &j: i.second){
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        unordered_set<int> st;
        vector<int> ans;
        dfs(target->val, 0, adj, st, k, ans);
        return ans;
    }
};


// 8: 1 
// 0: 1 
// 1: 3 0 8 
// 4: 2 
// 7: 2 
// 2: 5 7 4 
// 6: 5 
// 5: 3 6 2 
// 3: 5 1 















