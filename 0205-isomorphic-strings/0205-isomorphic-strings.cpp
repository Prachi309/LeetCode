class Solution {
public:
    bool isIsomorphic(string s, string t) {
      
            
            
        if (s.length() != t.length()) {
        return false;
    }

    // Create a hashmap to store character mappings
   unordered_map<char, char> charMappingMap;

    for (int i = 0; i < s.length(); i++) {
        char original = s[i];
        char replacement = t[i];

        if (charMappingMap.find(original) == charMappingMap.end()) {
            if (
                find_if(charMappingMap.begin(), charMappingMap.end(),
                        [replacement](const pair<char, char>& pair) { 
                            return pair.second == replacement; }) == charMappingMap.end()) {
                charMappingMap[original] = replacement;
            } 
            else {
                return false;
            }
        } else {
            char mappedCharacter = charMappingMap[original];
            if (mappedCharacter != replacement) {
                return false;
            }
        }
    }

    return true;


    }
};