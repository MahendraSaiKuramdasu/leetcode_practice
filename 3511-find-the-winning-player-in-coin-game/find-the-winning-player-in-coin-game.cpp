class Solution {
public:
    string winningPlayer(int x, int y) {
        // x/=2;
        y/=4;
        int mini = min(x,y);
        return mini%2 ? "Alice" : "Bob";
    }
};