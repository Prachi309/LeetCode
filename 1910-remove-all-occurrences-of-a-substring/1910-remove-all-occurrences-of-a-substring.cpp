class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part)<s.length())
        // first condition- there is no character in the string
        //second- jump into the string only when the "part" string is present in it and its first index
        //is less than the length.
        {
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};