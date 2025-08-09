/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

Node* dfs(Node*& node, unordered_map<int, Node*>& st){
    Node* curr = new Node(node->val);
    st[node->val] = curr;
    int n = node->neighbors.size();
    for(int i=0; i<n; i++){
        if (!node->neighbors[i]){
            curr->neighbors.push_back(NULL);
        }
        int temp_val = node->neighbors[i]->val;       
        if (st.find(temp_val) == st.end()){
            Node* n_node = dfs(node->neighbors[i], st);
            curr->neighbors.push_back(n_node);
        }
        else{
            curr->neighbors.push_back(st[temp_val]);
        }
    }
    return curr;
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        unordered_map<int, Node*> st;
        return dfs(node, st);
    }
};
















