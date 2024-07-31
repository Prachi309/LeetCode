class Solution {
public:
    bool isAnswer(vector<int>&position,int mid,int m)
{
    int cnt=1;
    int prev=position[0];
    for(int i=1; i<position.size(); i++)
    {
        if(position[i]-prev>=mid)
        {
            prev=position[i];
            cnt+=1;
            if(cnt==m) return true;
        }
    }
    if(cnt<m) return false;
    return true;
}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low=0;
        int n=position.size();
        int high=position[n-1];
        int ans;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isAnswer(position,mid,m))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};