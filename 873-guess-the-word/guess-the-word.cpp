/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:

    int giveMatches(string w1, string w2){
        int c = 0;
        for(int i=0; i<6; i++){
            if(w1[i] == w2[i]){
                c++;
            }
        }
        return c;
    }

    void findSecretWord(vector<string>& words, Master& master) {
        unordered_set<string> st(words.begin(), words.end());
        while(!st.empty()){
            string word = *st.begin();
            int matchesCnt = master.guess(word);
            st.erase(word);
            if(matchesCnt == 6) return;
            for(auto i=st.begin(); i!= st.end();){
                int currMatches = giveMatches(word, *i);
                if(currMatches != matchesCnt){
                    i = st.erase(i);
                }
                else{
                    i++;
                }
            }
        }
    }
};