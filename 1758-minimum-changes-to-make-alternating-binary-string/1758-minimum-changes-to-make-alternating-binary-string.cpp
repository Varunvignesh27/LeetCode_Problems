class Solution {
public:
    int minOperations(string s) {
        
        int op = 0;
        int c = 0;
        int n =s.length();

        for(int i=0;i<n;i++){
            if(s[i] - '0' == c)
                op++;

            c ^= 1;
            
        }

        return min(op,n-op);
    }
};