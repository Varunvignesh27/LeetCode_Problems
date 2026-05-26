class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int c = 1;
        
        for(int i=n-1;i>=0;i--){
            int t = digits[i] + c;
            digits[i] = t % 10;
            c = t/10;
        }

        vector<int> ans;
        if(c)
            ans.push_back(c);

        for(int i : digits)
            ans.push_back(i);

        return ans;
    }
};