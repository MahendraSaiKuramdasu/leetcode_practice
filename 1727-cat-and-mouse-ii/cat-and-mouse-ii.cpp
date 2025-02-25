// struct custom_hash {
//     template <typename T>
//     size_t operator()(const T& key) const {
//         return hash<T>{}(key);
//     }

//     template <typename T1, typename T2>
//     size_t operator()(const pair<T1, T2>& p) const {
//         size_t h1 = operator()(p.first);
//         size_t h2 = operator()(p.second);
//         return h1 ^ (h2 << 1);  // Combine hashes
//     }
// };



class Solution {
public:
    pair<int, int> dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};
    int dp[9][9][9][9][1001];
    // unordered_map<pair<pair<pair<int,int>, pair<int,int>>,int>, bool, custom_hash> mp;

    bool solve(pair<int,int> mouse, pair<int,int> cat, pair<int,int>& food, vector<string>& grid, int moves, int& catJump, int& mouseJump, int& n, int& m){
        if(moves > 1000) return false;
        if(mouse.first == food.first && mouse.second == food.second) return true;
        if(cat == food) return false;
        if(cat == mouse) return false;
        // if(mp.find({{mouse, cat}, moves}) != mp.end()) return mp[{{mouse, cat}, moves}];
        // mp[{{mouse, cat}, moves}] = false;
        if(dp[mouse.first][mouse.second][cat.first][cat.second][moves] != -1) return dp[mouse.first][mouse.second][cat.first][cat.second][moves];

        bool thisState = false;
        if(moves%2 == 0){
            for(auto &d : dir){
                for(int jump = 0; jump <= mouseJump; ++jump){
                    int x = mouse.first + jump * d.first;
                    int y = mouse.second + jump * d.second;
                    if(x >= 0 && y >= 0 && x < n && y < m){
                        if(grid[x][y] == '#') break;
                        bool curr = solve({x,y}, cat, food, grid, moves+1, catJump, mouseJump, n, m);
                        if(curr == true){
                            dp[mouse.first][mouse.second][cat.first][cat.second][moves] = 1;
                            return true;
                        }
                    }
                }
            }
        }
        else{
            thisState = true;
            for(auto &d : dir){
                for(int jump = 0; jump <= catJump; ++jump){
                    int x = cat.first + jump * d.first;
                    int y = cat.second + jump * d.second;
                    if(x >= 0 && y >= 0 && x < n && y < m){
                        if(grid[x][y] == '#') break;
                        bool curr = solve(mouse, {x,y}, food, grid, moves+1, catJump, mouseJump, n, m);
                        if(curr == false){
                            dp[mouse.first][mouse.second][cat.first][cat.second][moves] = 0;
                           return false; 
                        }
                    }
                }
            }
        }
        dp[mouse.first][mouse.second][cat.first][cat.second][moves] = thisState ? 1 : 0;
        return thisState;   
    }

    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        int n = grid.size();
        int m = grid[0].length();
        pair<int,int> mouse;
        pair<int,int> cat;
        pair<int,int> food;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 'M'){
                    mouse = {i,j};
                }
                if(grid[i][j] == 'C'){
                    cat = {i,j};
                }
                if(grid[i][j] == 'F'){
                    food = {i,j};
                }
            }
        }
        return solve(mouse, cat, food, grid, 0, catJump, mouseJump, n, m);
    }

};