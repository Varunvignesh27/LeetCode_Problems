class Solution {
public:
    string trimTrailingVowels(string s) {

        string vowels = "aeiouAEIOU";

        for(int i=s.length()-1;i>=0;i--){
            if(vowels.contains(s[i])){
                s.pop_back();
            }
            else{
                break;
            }
        }

        return s;

    }
};