class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int l = 0;
        long long ans=0,curr=0;
        unordered_map<int,int> mp;

        for(int r=0;r<n;r++){

            curr += nums[r];
            mp[nums[r]]++;

            if(r-l+1 > k){
                curr -= nums[l];
                mp[nums[l]]--;
                if(mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }

            if(r-l+1 == k && mp.size() == k)
                ans = max(ans,curr);

        }

        return ans;
    }
};