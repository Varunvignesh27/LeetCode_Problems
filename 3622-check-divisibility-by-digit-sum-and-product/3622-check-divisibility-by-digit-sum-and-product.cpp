class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0,product = 1;
        digit(n,sum,product);

        if(n % (sum + product) == 0)
            return true;
        return false;
    }

    void digit(int n,int& sum,int& product){
        while(n){
            sum += n%10;
            product *= n%10;
            n /= 10;
        }
    }
};