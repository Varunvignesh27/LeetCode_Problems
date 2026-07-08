class Solution {
public:
    long long sumAndMultiply(int n) {

        long long x = 0;
        long long sum = 0;
        
        while(n){
            sum += n % 10;
            if(n%10 != 0)
                x = (x * 10)  + (n % 10);
            n /= 10;
        }

        int y = 0;

        while(x){
            y = y * 10 + (x % 10);
            x /= 10;
        }

        return y * sum;
    }
};