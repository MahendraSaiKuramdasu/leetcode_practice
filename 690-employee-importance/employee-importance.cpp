/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

void dfs(Employee*& e, unordered_map<int, Employee*>& adj, vector<int> &vis, int& imp_cnt){
    vis[e->id] = 1;
    imp_cnt += e->importance;
    for(auto& n : e->subordinates){
        if(adj[n] != NULL && vis[adj[n]->id] != 1){
            dfs(adj[n], adj, vis, imp_cnt);
        }
    }
}
    

class Solution {
public:
    int getImportance(vector<Employee*> emp, int id) {
        int n = emp.size();
        unordered_map<int, Employee*> adj;
        Employee* start = NULL;
        for(int i=0; i<n; i++){
            int e_id = emp[i]->id;
            adj[e_id] = emp[i];
            if(e_id == id){
                start = emp[i];
            }
        }
        vector<int> vis(2001, 0);
        int imp_cnt = 0;
        dfs(start, adj, vis, imp_cnt);
        return imp_cnt;
    }
};