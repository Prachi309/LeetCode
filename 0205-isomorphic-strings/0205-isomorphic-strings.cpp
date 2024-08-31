class Solution {
public:
    bool isIsomorphic(string s, string t) {
       if (s.length() != t.length()) return false;

    unordered_map<char, char> mapST, mapTS;

    for (int i = 0; i < s.length(); ++i) {
        char c1 = s[i];
        char c2 = t[i];

        // Check if there's a conflicting mapping
        if ((mapST.find(c1) != mapST.end() && mapST[c1] != c2) || 
    (mapTS.find(c2) != mapTS.end() && mapTS[c2] != c1)) {
            return false;
        }

        // Create the mapping
        mapST[c1] = c2;
        mapTS[c2] = c1;
    }

    return true;  
    }
};