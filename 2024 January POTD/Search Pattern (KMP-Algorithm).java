class Solution
{
    
    ArrayList<Integer> search(String pat, String txt)
    {
        ArrayList<Integer> ans = new ArrayList<>();
        int len = txt.length()-pat.length();
        for(int i=0;i<=len;i++){
            if(txt.charAt(i)!=pat.charAt(0)){
                continue;
            }else{
                //check first and last character of the substring if it match then enter 
                //nested if condition.
                if(txt.charAt(i) == pat.charAt(0) && 
                        txt.charAt(i+pat.length()-1) == pat.charAt(pat.length()-1)){
                    if(txt.substring(i,i+pat.length()).equals(pat)){
                        ans.add(i+1);
                    }
                }
            }
        }
        if(ans==null){
            ans.add(-1);
        }
        return ans;
    }
}
