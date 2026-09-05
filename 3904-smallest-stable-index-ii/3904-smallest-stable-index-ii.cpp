class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> p(n),s(n);
        int ans = -1;

        for(int i=0;i<n;i++){
            if(i==0)
                p[i] = nums[i];
            else
                p[i] = max(p[i-1],nums[i]);
        }

        for(int i=n-1;i>=0;i--){
            if(i == n-1)
                s[i] = nums[i];
            else
                s[i] = min(nums[i],s[i+1]);
        }

        for(int i=0;i<n;i++){
            if(p[i] - s[i] <= k){
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};