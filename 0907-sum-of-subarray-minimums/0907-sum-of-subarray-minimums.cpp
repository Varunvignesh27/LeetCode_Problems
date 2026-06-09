#define mod ((int)1e9+7)

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> s;
        int n = arr.size();
        long long ans = 0;
        vector<int> prev(n,-1),next(n,n);
        
        
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()] > arr[i]){
                next[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        
        while(!s.empty())
            s.pop();
        
        for(int i = n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                prev[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        
        for(int i=0;i<n;i++){
            ans +=((next[i] - i)*(i - prev[i]) * (long long)arr[i])% mod;
        }
        return ans % mod;
    }
};