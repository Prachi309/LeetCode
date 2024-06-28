class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> freq;
        
        for (int i = 0; i < roads.size(); ++i) {
            freq[roads[i][0]]++;
            freq[roads[i][1]]++;
        }
        
        vector<int> result;
        for (const auto& entry : freq) {
            result.push_back(entry.second);
        }
        
        sort(result.rbegin(), result.rend());
        
        long long sum = 0;
        for (int i = 0; i < result.size(); ++i) {
            sum += static_cast<long long>(result[i]) * (n - i);
        }
        
        return sum;
    }
};