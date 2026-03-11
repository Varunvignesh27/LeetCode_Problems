class Solution {
public:
    int bitwiseComplement(int n) {
        string s;

        if(n < 1){
            return 1;
        }

        while(n > 0){
            s += (n % 2) + '0';
            n/= 2;
        }
        reverse(s.begin(),s.end());

        for(int i=0;i<s.length();i++){
            if(s[i] == '1')
                s[i] = '0';
            else
                s[i] = '1';
        }

        int b = 1;
        int ans=0;
        for(int i=s.length()-1;i >= 0;i--){
            ans += (s[i]-'0') * b;
            b *= 2;
        }

        return ans;
    }
};