class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
         if(hand.size() % groupSize) return false;

        map<int,int>mp;
        for(auto val:hand) mp[val]++;

        int n = hand.size();
        while(n--)
        {
            for(auto [a, b]:mp)
            {
                for(int i=a;i<a+groupSize;i++)
                {
                    if(mp[i] == 0) return false;
                    mp[i]--;
                    if(mp[i]==0) mp.erase(i);
                }
                break;
            }
        }
        return true;
    }
};