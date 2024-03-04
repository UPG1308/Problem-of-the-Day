class Solution
{
    public void swapElements(int[] arr, int n)
    {
        for(int i = 2; i < n; i++){
            swap(i - 2, i, arr);
        }
    }
    public void swap(int i, int j, int[] arr){
        arr[i] ^= arr[j];
        arr[j] ^= arr[i];
        arr[i] ^= arr[j];
    }
}
