
class Solution{
    //Function to count the frequency of all elements from 1 to N in the array.
    public static void frequencyCount(int arr[], int N, int P)
    {
        // code here
        int []ans = new int[N + 1];
        for(int i = 0; i < N; i++){
            if(arr[i] > N)continue;
            ans[arr[i]]++;
        }
        for(int i = 1; i <= N; i++){
            arr[i - 1] = ans[i];
        }
    }
}
