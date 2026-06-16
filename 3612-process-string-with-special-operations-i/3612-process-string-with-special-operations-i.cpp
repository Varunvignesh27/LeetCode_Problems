class Solution {
public:
    string processStr(string s) {
        string res;
        for(char i : s){
            if(islower(i))
                res.push_back(i);
            else if(i == '*' && !res.empty())
                res.pop_back();
            else if(i == '#')
                res = res + res;
            else if(i == '%')
                reverse(res.begin(),res.end());
        }
        return res;
    }
};