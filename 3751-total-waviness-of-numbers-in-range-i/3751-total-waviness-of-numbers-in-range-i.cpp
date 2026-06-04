class Solution {
public:

    int solve(int n){
        string s = to_string(n);
        int l = s.size(),cnt = 0;

        for(int i=1;i<s.size()-1;i++){
            if((s[i] > s[i-1] && s[i] > s[i+1]) || (s[i] < s[i-1] && s[i] < s[i+1]))
                cnt++;
        }
        return cnt;
    }

    int totalWaviness(int num1, int num2) {

        int waviness = 0;
        
        for(int i=num1;i<=num2;i++){
            if(i > 99)
                waviness += solve(i);
        }

        return waviness;
    }
};