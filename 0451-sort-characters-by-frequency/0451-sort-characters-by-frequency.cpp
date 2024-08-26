class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        priority_queue<pair<int,char>>pq;
        
        for(auto it : s){
            mpp[it]++;
        }
        for(auto it: mpp){
            pq.push({it.second, it.first});
        }
        string ans="";
        while(!pq.empty()){
            auto temp= pq.top();
            int freq= temp.first;
            char ch= temp.second;
            
            ans+=string(freq,ch);
            pq.pop();
        }
        return ans;
    }
};