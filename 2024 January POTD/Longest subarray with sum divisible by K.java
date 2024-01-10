class Solution{
    int longSubarrWthSumDivByK(int a[], int n, int k)
    {
        // Complete the function
        int[] remList = new int[n];
        for(int i = 0; i<n; i++){
            int mod = ((a[i] % k) + k)%k;
            remList[i] = mod;
        }
        a = remList;
        Map<Integer, Integer> map = new HashMap<>();
        int sum = 0, res = 0;
        for(int i = 0; i< n; i++){
            sum += a[i];
            sum = sum % k;
            int mod = sum;
            if (map.containsKey(mod)){
                res = Math.max(res, i - map.get(mod));
            }else{
                if(mod == 0){
                    res = Math.max(res, i+1);
                }else{
                    map.put(mod, i);
                }
            }
        }
        return res;
    }
 
}
