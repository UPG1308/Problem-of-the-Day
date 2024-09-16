class Solution{
    public:
    int maxLength(string& str) {
        int n=str.length(),op=0,cl=0,sum=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='(')
            op++;
            else
            cl++;
            if(cl>op)
            op=cl=0;
            if(cl==op)
            sum=max(sum,cl*2);
        }
        op=cl=0;
        for(int i=n-1;i>=0;i--)
        {
            if(str[i]=='(')
            op++;
            else
            cl++;
            if(cl<op)
            op=cl=0;
            if(cl==op)
            sum=max(sum,cl*2);
        }
        return sum;
    }
};
