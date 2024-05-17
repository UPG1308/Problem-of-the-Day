class Solution {
    public int findPair(int n, int x, int[] arr) {
        // code here
        HashSet<Integer> set = new HashSet<>();
        for(int i  = 0; i < n; i++){
            if(set.contains(arr[i] + x) || set.contains(arr[i] - x)) return 1;
            set.add(arr[i]);
        }
        return -1;
    }
}
