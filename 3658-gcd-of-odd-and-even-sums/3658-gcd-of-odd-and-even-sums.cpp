class Solution {
public:
    int gcdOfOddEvenSums(int n) {
      int oddsum = 0,evensum = 0;
      for(int i=1;i<=2*n;i++){
        if(i%2 == 1){
            oddsum += i;
        }
        else if (i%2 == 0){
            evensum += i;
        }
      }  
      return __gcd(oddsum,evensum);
    }
};