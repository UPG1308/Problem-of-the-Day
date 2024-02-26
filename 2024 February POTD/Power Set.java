class Solution
{
    public List<String> AllPossibleStrings(String s)
    {
        int n = s.length();
        ArrayList<String>res=new ArrayList<>();
        for (int m = 1; m < (1 << n); m++) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                if ((m & (1 << i))!=0) sb.append(s.charAt(i));
            }
            res.add(sb.toString());
        }
        Collections.sort(res);
        return res;
    }
}
