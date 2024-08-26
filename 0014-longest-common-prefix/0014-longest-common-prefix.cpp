class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        sort(strs.begin(),strs.end());
        
        string start = strs[0];
        string end= strs[strs.size()-1];
        
        for(int i=0;i<start.length();i++){
            if(start[i]==end[i]){
                res+=start[i];
            }
            else{
               break;
            }
        }
        return res;
    }
};