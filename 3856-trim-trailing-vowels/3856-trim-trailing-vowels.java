class Solution {
    public String trimTrailingVowels(String s) {
        String vowels = "AEIOUaeiou";

        int i = s.length()-1;

        while(i >= 0){
            if(vowels.indexOf(s.charAt(i)) != -1){
                i--;
            }else
                break;
        }

        return s.substring(0, i+1);
    }
}