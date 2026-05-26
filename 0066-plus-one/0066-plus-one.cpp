class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int c = 0;
        
        for(int i=n-1;i>=0;i--){
            if(i == n-1 && digits[i] < 9 ){
                digits[i]++;
                break;
            }
            else{
                if(i == n-1){
                    int t = digits[i] + c + 1;
                    digits[i] = t%10;
                    c = t/10;
                }else{
                    int t = digits[i] + c;
                    digits[i] = t%10;
                    c = t/10;
                }
            }
        }
        if(c == 0)
            return digits;

        vector<int> ans;
        ans.push_back(c);
        for(int i : digits)
            ans.push_back(i);

        return ans;
    }
};