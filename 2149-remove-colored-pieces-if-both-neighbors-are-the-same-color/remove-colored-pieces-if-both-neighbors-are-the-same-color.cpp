class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int a = 0;
        int b = 0;
        int alice = 0;
        int bob = 0;
        for(int i=0; i<=n; i++){
            if(i == n){
                if(a >= 3){
                    alice += (a-2);
                }
                else if(b >= 3){
                    bob += (b - 2);
                }
                continue;
            }
            if(colors[i] == 'A'){
                if(b >= 3){
                    bob += (b - 2);
                }
                b = 0;
                a++;
            }
            else{
                if(a >= 3){
                    alice += (a-2);
                }
                a = 0;
                b++;
            }
        }
        return alice > bob;
    }
};