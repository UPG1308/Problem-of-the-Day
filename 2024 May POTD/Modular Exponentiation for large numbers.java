public long PowMod(long x, long n, long m)
    {
        long result=1;
        if(m==1)
        return 0;
        x=x%m;
        while(n>0){
            if((n&1)==1){
                result = (result*x)%m;
            }
            n=n/2;
            x=(x*x)%m;
        }
        return result;
    }
