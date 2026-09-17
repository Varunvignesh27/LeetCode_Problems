class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set;

        for(int i=0;i<n-1;i++){
            int curr = nums[i] + nums[i+1];

            if(set.contains(curr))
                return true;
            
            set.insert(curr);
        }

        return false;
    }
};