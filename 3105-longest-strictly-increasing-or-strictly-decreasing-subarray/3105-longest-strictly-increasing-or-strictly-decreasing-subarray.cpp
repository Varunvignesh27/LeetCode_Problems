class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;

        for(int i=0;i<n;i++){
            int len = 1;
            for(int j=i+1;j<n;j++){
                if(nums[j] < nums[j-1]){
                    len++;
                }else 
                    break;
            }
            maxlen = max(len,maxlen);
        }

        for(int i=0;i<n;i++){
            int len = 1;
            for(int j=i+1;j<n;j++){
                if(nums[j] > nums[j-1]){
                    len++;
                }else 
                    break;
            }
            maxlen = max(len,maxlen);
        }
        return maxlen;
    }
};