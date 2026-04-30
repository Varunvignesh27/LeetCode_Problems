class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<string> res;
        vector<map<char,int>> v(n);

        for(int i=0;i<n;i++){
            for(int j : words[i]){
                v[i][j]++;
            }
        }

        for(auto i : v[0]){
            char f = i.first;
            int s = i.second;
            int cnt = 1;
            for(int j=1;j<n;j++){
                for(auto m : v[j]){
                    if(m.first == f){
                        s = min(s,m.second);
                        cnt++;
                    }
                }
            }
            if(cnt == n){
                for(int i=0;i<s;i++){
                    string t;
                    t += f;
                    res.push_back(t);
                }
            }
        }

        return res;
    }
};