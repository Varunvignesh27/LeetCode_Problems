class Solution {
public:

    int digitsum(int n){
        int s = 0;

        while(n){
            s = s + n % 10;
            n /= 10;
        }

        return s;
    }

    int minElement(vector<int>& nums) {
        int res = 1e5;

        for(int i : nums){
            res = min(res,digitsum(i));
        }

        return res;
    }
};