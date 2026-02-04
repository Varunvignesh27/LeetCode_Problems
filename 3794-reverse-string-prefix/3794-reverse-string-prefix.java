class Solution {
    public String reversePrefix(String s, int k) {

        char[] arr = s.toCharArray();
        int j = 0;

        for (int i = k - 1; i >= j; i--) {
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }

        return new String(arr);
    }
}
