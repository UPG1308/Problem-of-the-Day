class Solution {
    public void printArr(int n, int arr[]) {
        // code here
        for(int num: arr)System.out.print(num+" ");
        System.out.println();
    }

    public void setToZero(int n, int arr[]) {
        // code here
        Arrays.fill(arr, 0);
    }

    public void xor1ToN(int n, int arr[]) {
        // code here
        for(int i = 0; i < n; i++) arr[i] = arr[i] ^ i;
    }
}
