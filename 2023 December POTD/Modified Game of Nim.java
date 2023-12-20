class Solution{
    static int findWinner(int n, int A[]){
        // code here
        int sum = 0;
        for(int i=0; i<n;i++)
            sum ^= A[i];
        if (sum == 0 || n%2 == 0)
            return 1;
        else return 2;
}
};
