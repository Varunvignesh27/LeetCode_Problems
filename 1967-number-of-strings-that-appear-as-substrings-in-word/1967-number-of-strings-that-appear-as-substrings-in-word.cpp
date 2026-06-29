class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.size();
        int res = 0;

        for(int i=0;i<n;i++){
            string temp = "";
            for(int j=i;j<n;j++){
                temp += word[j];
                for(int k=0;k<patterns.size();k++)
                    if(patterns[k] == temp){
                        res++;
                        patterns[k] = " ";
                    }
            }
        }

        return res;
    }
};