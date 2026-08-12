class Solution {
public:

    vector<string> str;

    void dfs(int open,int close,string s,int n){
        if(open == close && open+close == n*2){
            str.push_back(s);
            return ;
        }

        if(open < n)
            dfs(open+1, close, s+'(', n);
        if(close < open)
            dfs(open, close+1, s +')', n);

    }

    vector<string> generateParenthesis(int n) {
        dfs(0,0,"",n);

        return str;
    }
};