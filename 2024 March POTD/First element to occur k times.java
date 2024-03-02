class Solution
{
    public int firstElementKTime(int n, int k, int[] a) { 
        int frequency[] = new int[202];
        for(int i = 0 ; i < n; i++){
            // frequency[a[i]]++;
            if(++frequency[a[i]] == k) return a[i];
        }
        return -1;
    } 
}
