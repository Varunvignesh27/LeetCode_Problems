class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n),ls(n),rs(n);

        ls[0] = nums[0];
        for(int i=1;i<n;i++){
            ls[i] = ls[i-1] + nums[i];
        }

        rs[n-1] = nums[n-1];
        ans[n-1] = abs(ls[n-1] - rs[n-1]);
        for(int i=n-2;i>=0;i--){
            rs[i] = rs[i+1] + nums[i];
            ans[i] = abs(ls[i]-rs[i]);
        }

        return ans;
    }
};