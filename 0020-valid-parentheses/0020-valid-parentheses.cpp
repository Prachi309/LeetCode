class Solution {
public:
    bool isValid(string s) {
        deque<char> stack; 
        for(char c: s) {
            if (c == '(' || c == '{' || c == '[')
                stack.push_back(c);
            else {
                if (stack.empty()) return false;
                if (c == ')') {
                    if (stack.back() == '(') stack.pop_back();
                    else return false;
                } else if (c == '}') {
                    if (stack.back() == '{') stack.pop_back();
                    else return false;
                } else if (c == ']') {
                    if (stack.back() == '[') stack.pop_back();
                    else return false;
                }
            }
        }
        return stack.empty();
    }
};