class Solution{
    public static boolean areRotations(String s1, String s2 ){
        s1 = s1 + s1;
        return s1.contains(s2);
    }
}
