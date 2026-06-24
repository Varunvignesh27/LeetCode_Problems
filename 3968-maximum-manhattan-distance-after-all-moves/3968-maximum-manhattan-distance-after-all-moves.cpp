class Solution {
public:
    int maxDistance(string moves) {
        int x = 0,y = 0;
        int cnt = 0;
        for(char c : moves){
            if(c == 'U')
                y++;
            if(c == 'D')
                y--;
            if(c == 'L')
                x--;
            if(c == 'R')
                x++;
            if(c == '_'){
                cnt++;
            }
        }
        return (abs(x) + abs(y))+cnt;
    }
};