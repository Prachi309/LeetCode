class Solution {
public:
    char findTheDifference(string s, string t) {
        int i=0;
        string a="";
        int hash[26]={0};
        for(int i=0;i<t.length();i++){
            hash[t[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
            hash[s[i]-'a']--;
        }
        for(int i=0;i<26;i++){
           if(hash[i]){
         return i+'a';
           }
        } 
       return 0;
    }
};