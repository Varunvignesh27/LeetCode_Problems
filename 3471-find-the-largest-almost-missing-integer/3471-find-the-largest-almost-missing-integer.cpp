class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i : nums){
            mp[i]++;
        }

        if(k == n)
            return *max_element(nums.begin(),nums.end());

        if(k == 1){
            int maxval = -1;
            for(int i : nums){
                if(mp[i] == 1 && i > maxval)
                    maxval = i;
            }
            return maxval;
        }

        if(nums[0] == nums[n-1])
            return -1;

        if(mp[nums[0]] == 1 && mp[nums[n-1]] == 1)
            return max(nums[0],nums[n-1]);

        if(mp[nums[0]] == 1 && mp[nums[n-1]] > 1)
            return nums[0];

        if(mp[nums[n-1]] == 1 && mp[nums[0]] > 1)
            return nums[n-1];

        return -1;
    }
};