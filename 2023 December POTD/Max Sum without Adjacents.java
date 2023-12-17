
class Solution {
    int findMaxSum(int a[], int n) {
       int p1=a[0];
        int p2 = 0;
        for(int i=1; i<n; i++){
            int pi = p1;
            int np = p2+a[i];
            int m = Math.max(pi,np);
            p2 = p1;
            p1 = m;
        }
        return p1;
    }
}
