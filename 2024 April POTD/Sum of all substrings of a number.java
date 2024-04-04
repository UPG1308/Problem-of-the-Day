class Solution
{
    //Function to find sum of all possible substrings of the given string.
    public static long sumSubstrings(String s)
    {
    //Your code here
    int MOD=1000000007;
    long prev=0, curr = 0, sum = 0;
    
    for(int i=0; i<s.length(); i++){
        curr=((s.charAt(i)-'0')*(i+1))%MOD + (prev*10)%MOD;
        sum=(sum+curr)%MOD;
        prev=curr;
    }
    return sum; 
    
    }
    
}
