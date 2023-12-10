class Solution{

    static boolean findsum(int a[],int n)
    {
        Set<Integer> s = new HashSet<Integer>();
     
        for(int i=1;i<n;i++){
            a[i] = a[i] + a[i-1];
        }
       
       for(int i=0;i<n;i++){
           s.add(a[i]);
           
           if(a[i] == 0){
               return true;
               
           }
       }
       
       
       
        if(s.size() != a.length){
            return true;
        }
        else{
            return false;
        }
        
    }
}
