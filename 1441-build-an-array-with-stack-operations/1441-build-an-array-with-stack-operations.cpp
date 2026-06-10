class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        stack<int> s;
        int j = 0;
        for(int i=1;i<=n;i++){
            s.push(i);
            res.push_back("Push");
            
            if(target[j] != s.top()){
                s.pop();
                res.push_back("Pop");
                continue;
            }
            j++;
            if(j >= target.size())
                break;
        }
        
        return res;
    }
};