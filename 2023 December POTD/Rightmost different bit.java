class Solution
{
    //Function to find the first position with different bits.
    public static int posOfRightMostDiffBit(int m, int n)
    {
            
        // Your code here  
        
             int xor = m^n;
        if(xor == 0) return -1;
        int cnt = 1;
        while(xor > 0) {
           if((xor&1) != 0) return cnt;
           xor>>=1;
           cnt++;
        }
        return -1;
    }
}
