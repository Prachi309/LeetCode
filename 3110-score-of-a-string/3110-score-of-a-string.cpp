class Solution {
public:
    int scoreOfString(string s) {
        int score=0;
        for(int i=1;i<s.length();i++){
          int dif= abs(int(s[i-1])-int (s[i]));
          score+=dif;
        }
        return score;
    }
};