class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans = n;

        while(1){
            if(valid(ans,t))
                break;
            else
                ans++;
        }

        return ans;
    }

    bool valid(int ans,int t){
        int sum = 1;

        while(ans){
            sum *= ans%10;
            ans /= 10;
        }

        if(sum % t == 0)
            return true;
        return false;
    }
};