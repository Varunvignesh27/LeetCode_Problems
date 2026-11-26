class Solution {
public:
    bool canAliceWin(int n) {
        int t = 10;
        bool ans = true;

        while(n >= t){
             n -= t;
             t--;
             ans = !ans;
        }

        return !ans;
    }
};