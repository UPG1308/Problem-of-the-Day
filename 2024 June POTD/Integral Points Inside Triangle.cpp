class Solution {
  public:
    long long int InternalCount(long long int p[], long long int q[],
                                long long int r[]) {
        // code here
        long long int A=abs((p[0]*(q[1]-r[1]) + q[0]*(r[1]-p[1]) + r[0]*(p[1]-q[1]))/2);
        long long int B1 =__gcd(abs(p[0]-q[0]),abs(p[1]-q[1]))+1;
        long long int B2 =__gcd(abs(q[0]-r[0]),abs(q[1]-r[1]))+1;
        long long int B3 =__gcd(abs(r[0]-p[0]),abs(r[1]-p[1]))+1;
        long long int B=(B1+B2+B3-3)/2;
        return (A-B+1);
    }
};
