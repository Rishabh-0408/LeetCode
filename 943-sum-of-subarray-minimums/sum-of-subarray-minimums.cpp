class Solution {
public:
    vector<int> findnse(vector<int>& arr){
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            // we want to store index not the value
            //any value greater than arr[i] pop them
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findpsee(vector<int>& arr){
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            // we want to store index not the value
            //any value greater than arr[i] pop them
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findnse(arr);
        vector<int> pse = findpsee(arr);
        int total = 0;
        int mod = 1e9 + 7;
        for(int i = 0; i < n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            total  = (total + (right* left * 1LL* arr[i]) % mod) % mod;
        }
        return total;
    }
};