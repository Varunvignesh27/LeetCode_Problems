class Solution {
public:
    bool check(long long n,int x){
        int f  = n%10;
        while(n >= 10){
            n /= 10;
        }

        if(f == x && n == x)
            return true;
        return false;
    }

    int countValidSubarrays(vector<int>& nums, int x) {
        int cnt=0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            long long sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                if(check(sum,x))
                    cnt++;
            }
        }
        return cnt;
    }
};