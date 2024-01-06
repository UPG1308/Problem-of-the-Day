
class Solution {
    public static long sumOfPowers(long a, long b) {
        // code here 
        long ans=0;
    for(long i=a;i<=b;i++)
    { long n=i;
        for(long j=2;j*j<=n;j++)
        {
            while(n%j==0)
            {
                ans++;
                n/=j;
            }
        }
            if(n!=1)
            ans++;
        
    }
  return ans;
    }
}
        
