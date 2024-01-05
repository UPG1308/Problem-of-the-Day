
class Solution
{
    public int TotalWays(int N)
    {
        // Base case
        long mod = (int) 1e9 + 7, a = 2, b = 3, c = 0;
        if (N == 1)
            return 4;  // 2 for one side and 4 for two sides
        if(N == 2) return 9;
        // countB is count of ways with a building at the end
        // countS is count of ways with a space at the end
        // prev_countB and prev_countS are previous values of
        // countB and countS respectively.
      
        // Initialize countB and countS for one side
        // int countB=1, countS=1, prev_countB, prev_countS;
      
        // Use the above recursive formula for calculating
        // countB and countS using previous values
        for (int i=3; i<=N; i++)
        {
            c = (a + b) % mod;
            a = b;
            b = c;
        }
      
        // Result for one side is sum of ways ending with building
        // and ending with space
       return (int) ((c * c) % mod);
    }
}
