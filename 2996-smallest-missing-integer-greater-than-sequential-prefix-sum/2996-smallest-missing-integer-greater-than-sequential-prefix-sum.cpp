class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        unordered_set<int> s(nums.begin(),nums.end());
        int n = nums.size();

        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1] + 1)
                sum += nums[i];
            else
                break;
        }
        
        while(s.count(sum))
            sum++;

        return sum;
    }
};