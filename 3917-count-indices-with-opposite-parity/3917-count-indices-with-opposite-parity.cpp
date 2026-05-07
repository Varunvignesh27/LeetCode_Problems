class Solution {
public:

    bool parity(int n){
        if(n%2 == 0)
            return false;
        
        return true;
    }

    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for(int i=0;i<n-1;i++){
            int t = 0;
            for(int j=i+1;j<n;j++){
                if(parity(nums[i]) != parity(nums[j]))
                    t++;
            }
            ans[i] = t;
        } 

        return ans;
    }
};