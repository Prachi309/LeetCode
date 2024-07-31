class Solution {
public:
    int num_days(vector<int>& weights, int mid){
        int days=1;
        int w=0;
        for(int i=0;i<weights.size();i++){
            if(w+weights[i]>mid){
                days++;
                w=weights[i];
            }
            else{
                w+=weights[i];
            }
        }
        return days;
    }

    int Sum(vector<int>& weights){
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        return sum;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=Sum(weights);
        while(low<=high){
            int mid=(low+high)/2;
            int ans=num_days(weights,mid);
            if(ans>days){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};