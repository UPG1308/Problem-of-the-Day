class Solution{
    static int findSingle(int n, int arr[]){
        // code here
        int xor = 0;
        for(int num: arr) xor = xor ^ num;
        return xor;
    }
}
