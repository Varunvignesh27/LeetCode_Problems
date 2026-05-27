class Solution {
public:
    int numberOfSpecialChars(string w) {
        int n = w.size();
        int res = 0;
        vector<int> lower(26,-1);
        vector<int> upper(26,-1);

        for(int i=0;i<n;i++){
            if(islower(w[i]))
                lower[w[i] - 'a'] = i;
            else if(upper[w[i] - 'A'] == -1)
                upper[w[i] - 'A'] = i;
        }

        for(int i = 0;i < 26;i++){
            if(lower[i] != -1 && upper[i] != -1 && lower[i] < upper[i])
                res++;
        }

        return res;
    }
};