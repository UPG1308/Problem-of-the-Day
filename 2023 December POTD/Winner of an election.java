class Solution
{
    //Function to return the name of candidate that received maximum votes.
    public static String[] winner(String arr[], int n)
    {
        // add your code
        HashMap <String,Integer> hm = new HashMap<>();
        for(int i=0; i<n; i++)
        {
            hm.put(arr[i], hm.getOrDefault(arr[i],0)+1);
        }
        Integer m = (Collections.max(hm.values()));
        List<String> sl = new ArrayList<String>();
        String s1[] = new String[2];
        int j=0;
        for(Map.Entry <String,Integer> e: hm.entrySet())
        {
            if(e.getValue()==m)
            {
                sl.add(e.getKey());
            }
        }
            
        Collections.sort(sl);
        s1[j] = sl.get(j);
        s1[j+1] = Integer.toString(m);
        return s1;
    }
}
