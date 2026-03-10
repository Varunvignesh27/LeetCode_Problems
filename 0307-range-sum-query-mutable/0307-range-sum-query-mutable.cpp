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
    
    void update(int index, int val) {
        int n = prefix.size();
        int diff=0;

        for(int i=index;i<n;i++){
            if(i==0 && i==index){
                diff = prefix[index];
                prefix[index] = val;
                diff -= prefix[i];
            }else if(i ==index){
                diff = prefix[index];
                prefix[i] = prefix[i-1]+val;
                diff -= prefix[i];
            }else{
                prefix[i] = prefix[i] - diff;
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
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */