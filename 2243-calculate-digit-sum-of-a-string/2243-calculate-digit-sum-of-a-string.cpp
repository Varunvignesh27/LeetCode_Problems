class Solution {
public:
    string digitSum(string s, int k) {
        
        while(s.size() > k){
            string temp;

            for(int i=0;i<s.size();i+=k){
                int num = 0;
                for(int j=i;j < min((int)s.size(),i+k);j++){
                    num += s[j] - '0';
                }
                temp += to_string(num);
            }
            s = temp;
        }

        return s;
    }
};