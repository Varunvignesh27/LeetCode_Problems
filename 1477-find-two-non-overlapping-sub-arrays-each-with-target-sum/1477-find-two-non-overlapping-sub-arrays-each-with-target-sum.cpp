class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int tar) {
        int n = nums.size();
        int l=0,r=0;
        int curr = 0,ans =INT_MAX;
        vector<int> best(n,INT_MAX);

        while(r < n){
            curr += nums[r];

            while(curr > tar){
                curr -= nums[l];
                l++;
            }

            if(curr == tar){

                int len = r-l+1;
                if(l > 0 && best[l-1] != INT_MAX){
                    ans = min(ans,best[l-1] + len);
                }
                best[r] = len;
            }

            if(r > 0){
                best[r] = min(best[r],best[r-1]);
            }

            r++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};