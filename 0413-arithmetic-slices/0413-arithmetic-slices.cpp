class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        if(n < 2){
            return 0;
        }

        int l = 1,cnt = 0,d=0;

        for(int i=0;i<=n-3;i++){
            l=1;
            d= nums[i] - nums[i+1];

            for(int j=i;j<n-1;j++){
                if(nums[j] - nums[j+1] == d){
                    l++;
                    if(l >= 3){
                        cnt++;
                    }
                }
                else{
                    l = 1;
                    d = nums[j]-nums[j+1];
                }
            }

        }
        return cnt;
    }
};