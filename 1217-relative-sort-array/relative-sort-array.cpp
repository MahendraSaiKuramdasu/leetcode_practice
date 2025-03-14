class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        int maxi = *max_element(arr1.begin(), arr1.end());
        vector<int> freq(maxi+1, 0);
        for(auto& i:arr1){
            freq[i]++;
        }
        int curr = 0;
        for(int i=0; i<m; i++){
            while(freq[arr2[i]] != 0){
                arr1[curr] = arr2[i];
                freq[arr2[i]]--;
                curr++;
            }
        }
        for(int i=0; i<maxi+1; i++){
            while(freq[i] != 0){
                arr1[curr] = i;
                curr++;
                freq[i]--;
            }
        }
        return arr1;
    }
};