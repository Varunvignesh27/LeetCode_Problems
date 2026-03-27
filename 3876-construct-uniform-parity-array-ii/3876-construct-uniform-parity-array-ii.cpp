class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        int oddmin=INT_MAX, evenmin = INT_MAX;
        int sum = 0;

        for(int i : nums){
            if(i%2){
                sum += 1;
                oddmin = min(oddmin,i);
            }else{
                evenmin = min(evenmin,i);
            }
        }

        if(sum == n)
            return true;
        if(!sum)
            return true;

        return oddmin < evenmin;

    }
};