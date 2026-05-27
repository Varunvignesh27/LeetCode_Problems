class Solution {
public:
    int countKthRoots(int l, int r, int k) {

        if(k == 1){
            return r-l+1;
        }

        int res = 0;
        int i=0;

        while(true){
            int p = pow(i,k);

            if(l <= p && p <= r)
                res++;
            else if(p > r)
                break;

            i++;
        }

        return res;
    }
};