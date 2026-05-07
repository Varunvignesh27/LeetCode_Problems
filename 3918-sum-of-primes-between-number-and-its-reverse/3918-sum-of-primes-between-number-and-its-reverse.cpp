class Solution {
public:

    bool isprime(int n){
        if(n < 2)
            return false;

        for(int i=2;i*i <= n;i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }

    int reverse_num(int n){
        int t = 0;
        while(n){
            t = t*10 + n%10;;
            n /= 10;
        }
        return t;
    }

    int sumOfPrimesInRange(int n) {
        int s = reverse_num(n);
        int sum = 0;

        for(int i=min(s,n);i<=max(n,s);i++){
            if(isprime(i))
                sum += i;
        }

        return sum;
    }
};