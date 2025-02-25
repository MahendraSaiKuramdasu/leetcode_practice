class Solution {
public:

    void mergeArray(int s, int mid, int e, vector<vector<int>>& pairWithIndex, vector<int>& nums){
        int i = s;
        int j = mid+1;
        int k = 0;
        vector<vector<int>> res(e-s+1);
        while(i <= mid && j <= e){
            if(pairWithIndex[i][0] > pairWithIndex[j][0]){
                nums[pairWithIndex[i][1]] += (e-j+1);
                res[k++] = pairWithIndex[i++];
            }
            else{
                res[k++] = pairWithIndex[j++];
            }
        }
        while(i <= mid){
            res[k++] = pairWithIndex[i++];
        }
        while(j <= e){
            res[k++] = pairWithIndex[j++];
        }
        for(int t=s; t<=e; t++){
            pairWithIndex[t] = res[t-s];
        }
        return;
    }
  
    void mergeSort(int s, int e, vector<vector<int>>& pairWithIndex, vector<int>& nums){
        if(s >= e){
            return;
        }
        int mid = (s+e)/2;
        mergeSort(s, mid, pairWithIndex, nums);
        mergeSort(mid+1, e, pairWithIndex, nums);
        mergeArray(s, mid, e, pairWithIndex, nums);
        return;
    }


    vector<int> countSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> pairWithIndex(n);
        for(int i=0; i<n; i++){
            pairWithIndex[i] = {arr[i], i};
        }
        vector<int> nums(n, 0);
        mergeSort(0, n-1, pairWithIndex, nums);
        return nums;
    }
};