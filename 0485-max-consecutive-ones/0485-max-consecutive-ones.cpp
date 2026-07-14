class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0,maxcnt = 0;

        for(int i=0;i<n;i++){
            if(nums[i] != 1){
                cnt = 0;
                continue;
            }
            cnt++;
            maxcnt = max(maxcnt,cnt);
        }
        return maxcnt;
    }
};