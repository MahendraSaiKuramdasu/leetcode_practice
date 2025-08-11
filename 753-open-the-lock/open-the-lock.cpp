vector<string> get_new_locks(string& lock){
    vector<string> arr;
    for(int i=0; i<4; i++){
        int val = lock[i] - '0';
        int up = (val+1)%10;
        int down = ((val-1)+10)%10;
        string temp = lock;
        temp = temp.substr(0,i) + to_string(up) + temp.substr(i+1);
        arr.push_back(temp);
        temp = temp.substr(0,i) + to_string(down) + temp.substr(i+1);
        arr.push_back(temp);
    }
    return arr;
}

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(), deadends.end());
        queue<string> q;
        q.push("0000");
        if (st.find("0000") != st.end()){
            return -1;
        }
        int vis[10000];
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        while(!q.empty()){
            int n = q.size();
            while(n > 0){
                n--;
                string curr = q.front();
                q.pop();
                if(curr == target){
                    return cnt;
                }
                vector<string> new_locks = get_new_locks(curr);
                for(auto& i: new_locks){
                    if (vis[stoi(i)] != 1 && st.find(i) == st.end()){
                        q.push(i);
                        vis[stoi(i)] = 1;
                    }
                } 
            }
            cnt++;
        }
        return -1;
    }
};