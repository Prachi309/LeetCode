class Solution {
public:
  void findNSE(vector<int>& arr, vector<int>& nse) {
        int n = arr.size();
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top(); // If empty, set to n
            st.push(i);
        }
    }

    void findPSE(vector<int>& arr, vector<int>& pse) {
        int n = arr.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top(); // If empty, set to -1
            st.push(i);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> nse(n, 0); 
        vector<int> pse(n, 0);  

        findNSE(arr, nse);  
        findPSE(arr, pse);  

        long long total = 0;  
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];     // Distance to previous smaller element
            long long right = nse[i] - i;    // Distance to next smaller element
            long long contribution = ((left * right % mod) * arr[i] % mod) % mod;
            total = (total + contribution) % mod;
        }
        
        return (int)total;
    
    }
};