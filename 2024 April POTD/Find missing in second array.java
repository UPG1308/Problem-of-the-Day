class Solution
{
    ArrayList<Integer> findMissing(int a[], int b[], int n, int m)
    {
        HashSet<Integer> set = new HashSet<>();
        for(int num: b) set.add(num);
        
        ArrayList<Integer> list = new ArrayList<>();
        for(int num: a){
            if(!set.contains(num)) list.add(num);
        }
        return list;
    }
}
