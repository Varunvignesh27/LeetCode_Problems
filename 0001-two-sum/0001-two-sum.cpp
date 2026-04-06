class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int curr = 0;
        unordered_map<int,int> mp;
        vector<int> ans(2);

        for(int i=0;i<n;i++){
            
            if(mp.find( target - nums[i]) != mp.end()){
                ans[0] = mp[target - nums[i]];
                ans[1] = i;
                break;
            }

            mp[nums[i]] = i;
        }

        return ans;
    }
};