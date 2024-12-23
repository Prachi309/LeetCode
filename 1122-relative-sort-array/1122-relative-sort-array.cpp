class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
         int freq[1001] = {0}, m = 0, i = 0;
        for (int num : arr1){
            freq[num]++;
            m = max(m, num);
        }
        for (int num : arr2)
            while (freq[num]--)
                arr1[i++] = num;
        for (int j = 0; j <= m; j++)
            while (freq[j]-- > 0)
                arr1[i++] = j;
        return arr1;
    }
};