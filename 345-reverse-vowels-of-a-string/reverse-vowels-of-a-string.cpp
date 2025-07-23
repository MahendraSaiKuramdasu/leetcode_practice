
class Solution {
public:

    bool vowel_check(char x){
        if(x == 'a' || x == 'e' || x == 'i' || x =='o' || x == 'u' ||
            x == 'A' || x == 'E' || x == 'I' || x =='O' || x == 'U'){
            return  true;
        }
        return false;
    }

    string reverseVowels(string& s) {
        int n = s.length();
        int i = 0;
        int j = n-1;
        while(i < j){
            while(i < j && !(vowel_check(s[i]))){
                i++;
            }
            while(j > i && !(vowel_check(s[j]))){
                j--;
            }
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};