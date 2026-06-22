class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> mp;

        for(char c : text)
            mp[c]++;

        string str = "balon";
        int ans = 1e9;
        int cnt = 0;

        for(char c : str){
            if(c == 'l' || c == 'o'){
                ans = min(ans,mp[c]/2);
                continue;
            }
            ans = min(ans,mp[c]);
        }

        return (ans == 1e9 )? 0 : ans;
    }
};