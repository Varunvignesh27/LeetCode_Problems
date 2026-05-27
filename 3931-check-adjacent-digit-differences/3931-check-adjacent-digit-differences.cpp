class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.size();

        for(int i=0;i<n-1;i++){
            int f = s[i] - '0';
            int e = s[i+1] - '0';
            if(abs(f-e) > 2)
                return false;
        }

        return true;
    }
};