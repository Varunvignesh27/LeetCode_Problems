class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sum=0,max=0,n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                sum = (nums[i]-1)*(nums[j]-1);
                if(max < sum)
                max = sum;
            }
        }
        return max;
    }
};