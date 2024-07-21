class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        while (start < s.size() && s[start] == ' ') start++;
        
        int end = s.size() - 1;
        while (end >= 0 && s[end] == ' ') end--;
        
        // Step 2: Reduce multiple spaces to a single space between words
        string result;
        while (start <= end) {
            if (s[start] != ' ') {
                result += s[start];
            } else if (result.back() != ' ') {
                result += ' ';
            }
            start++;
        }
        
        // Step 3: Reverse the entire string
        reverse(result.begin(), result.end());
        
        // Step 4: Reverse each word in the reversed string
        start = 0;
        for (end = 0; end <= result.size(); end++) {
            if (end == result.size() || result[end] == ' ') {
                reverse(result.begin() + start, result.begin() + end);
                start = end + 1;
            }
        }
        
        return result;
    }
};