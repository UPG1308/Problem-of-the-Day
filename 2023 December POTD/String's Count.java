class Solution 
{ 
    static long countStr(long n)
	{
	    // code here
	    if(n == 1) return 3;
	    if(n == 2) return 8;
	    long ans = (n - 1)*(n) + 2*n + 1 + n*(n - 1)/2 + n*(n-1)*(n-2)/2;
	    return ans;
	}
} 
