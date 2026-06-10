import java.util.PriorityQueue;
import static java.lang.Math.max;
import static java.lang.Math.min;

class SparseTable{
    static int K = 25;
    int[][] mn,mx;

    SparseTable(int[] nums){
        int n = nums.length;
        mx = new int[K][n];
        mn = new int[K][n];

        for(int i=0;i<n;i++){
            mn[0][i] = nums[i];
            mx[0][i] = nums[i];
        }

        for(int i=1;i<K;i++){
            for(int j=0;j+(1 << (i-1)) < n;j++){
                mn[i][j] = min(mn[i-1][j],mn[i-1][j + (1 << (i-1))]);
                mx[i][j] = max(mx[i-1][j],mx[i-1][j + (1 << (i-1))]);
            }
        }
    }

    // int min(int a , int  b){
    //     if(a < b)
    //         return a;
    //     return b;
    // }
    // int max(int a,int b){
    //     if(a > b)
    //         return a;
    //     return b;
    // }

    public int rangeQuery(int l,int r){
        int mini = (int)1e9;
        int maxi = 0;
        for(int i = K-1;i>=0;i--){
            if(r-l+1 >= (1 << i)){
                mini = min(mini,mn[i][l]);
                maxi = max(maxi,mx[i][l]);
                l += (1 << i);
            }
        }

        return maxi - mini;
    }
}

class Solution {
    public long maxTotalValue(int[] nums, int k) {
        long ans = 0;
        int n = nums.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) ->b[0] - a[0]);
        SparseTable st = new SparseTable(nums);

        for(int l=0;l<n;l++){
            int val = st.rangeQuery(l,n-1);
            int[] temp = {val,l,n-1};
            pq.add(temp);
        }

        while(k-- > 0){
            int[] temp = pq.poll();
            ans += temp[0];
            int l = temp[1];
            int r = temp[2] - 1;
            if(r >= l) {
                int val = st.rangeQuery(l,r);
                pq.add(new int[]{val, l, r});
            }

        }

        return ans;
    }
}