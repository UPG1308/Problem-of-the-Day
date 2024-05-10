class Solution {
    int sum = 0;
    
    public List<List<Integer>> CombinationSum2(int arr[], int n, int k) {
        // Code Here.
        List<List<Integer>> list = new ArrayList<>();
        List<Integer> l = new ArrayList<>();
        Arrays.sort(arr);
        sol(arr,n,k,list,l,0);
        return list;
    }
    public void sol(int arr[],int n,int k,  List<List<Integer>> list,List<Integer> l ,int m)
    {
        if(sum == k)
        {
            list.add(l);
            return;
        }
        if(sum > k)
        return;
        
        for(int i = m;i <n;i++)
        {
            if(i > m && arr[i] == arr[i -1]) continue;
            l.add(arr[i]);
            sum += arr[i];
            sol(arr,n,k,list,new ArrayList<>(l),i + 1);
            l.remove(l.size() - 1);
            sum -= arr[i];
            
        }
    }
}
