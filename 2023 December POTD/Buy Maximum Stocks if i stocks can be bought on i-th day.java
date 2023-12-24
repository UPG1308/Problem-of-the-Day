class pair{
    int amt;
    int idx;
    pair(int amt,int idx)
    {
        this.amt=amt;
        this.idx=idx;
    }
}
class mCom implements Comparator<pair>
{
    public int compare(pair o1,pair o2)
    {
        if(o1.amt<o2.amt)
        {
            return -1;
        }
        else if(o1.amt>o2.amt)
        {
            return 1;
        }
        else if(o1.idx>o2.idx)
        {
           return 1;
        }return -1;
    }
}
class Solution {
    public static int buyMaximumProducts(int n, int k, int[] price) {
       ArrayList<pair> arr=new ArrayList<>();
       int c=0;
       for(int i=0;i<n;i++)
       {
           arr.add(new pair(price[i],i+1));
       }
       Collections.sort(arr,new mCom());
       for(pair i:arr)
       {
           int amt=i.amt;
           int idx=i.idx;
           if(k==0)break;
            for(int j=idx;j>=1;j--)
            {
                if(amt*j<=k)
                {
                    k=k-(amt*j);
                    c=c+j;
                    break;
                }
            }
       }return c;
       
    }
}
  
