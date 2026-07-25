class Solution {
public:
    void build(vector<int>& nums,int n){

        while(n){
            nums.push_back(n%10);
            n /= 10;
        }
    }

    int maxProduct(int n) {
        vector<int> nums;
        build(nums,n);

        sort(nums.begin(),nums.end());
        int s = nums.size();

        return nums[s-1] * nums[s-2];
    }
};