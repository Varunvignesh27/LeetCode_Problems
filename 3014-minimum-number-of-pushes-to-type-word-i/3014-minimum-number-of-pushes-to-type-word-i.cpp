class Solution {
public:
    int minimumPushes(string word) {
        int s = word.size();
        int ans = 0;
        int i = 1;

        while(s){
            if(s >= 8){
                ans += 8*i;
                s -= 8;
            }else{
                ans += s*i;
                s -= s;
            }
            i++;
        }

        return ans;
    }
};