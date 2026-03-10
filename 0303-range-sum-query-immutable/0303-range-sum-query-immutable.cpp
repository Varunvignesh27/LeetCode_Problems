class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n);

        for(int i=0;i<n;i++){
            if(i==0){
                prefix[i] = nums[i];
            }else{
                prefix[i] = prefix[i-1] + nums[i];
            }
        }
    }
    
    int sumRange(int left, int right) {
        int ans;
        if(left==0){
            ans = prefix[right];
        }else{
            ans = prefix[right] - prefix[left-1];
        }

        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */