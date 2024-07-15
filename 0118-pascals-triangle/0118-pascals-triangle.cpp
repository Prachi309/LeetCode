class Solution {
public:
vector<int> generateRow(int row){
    long long ans=1;
    vector<int>list;
    list.push_back(1);
    for(int i=1;i<row;i++){
        ans=ans*(row-i);
        ans=ans/i;
        list.push_back(ans);
    }
    return list;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};