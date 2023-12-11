class Solution{
    static long maximumSumSubarray(int K, ArrayList<Integer> Arr,int N){
        // code here
        long sum = 0;
        for(int i = 0; i < K; i++) sum += Arr.get(i);
        long maxSum = sum;
        for(int i = K; i < N ; i++){
            sum = sum - Arr.get(i - K) + Arr.get(i);
            maxSum = Math.max(maxSum, sum);
        }
        return maxSum;
    }
}
