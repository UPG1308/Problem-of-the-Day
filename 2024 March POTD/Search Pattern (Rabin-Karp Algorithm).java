class Solution
{
    // d is the number of characters in the input alphabet
    public final static int d = 256, q = 101;
    ArrayList<Integer> indices = new ArrayList<>();
    ArrayList<Integer> search(String pattern, String txt)
    {
        int m = pattern.length();
        int n = txt.length();
        int i, j;
        int p = 0;
        int t = 0;
        int h = 1;
    
        for (i = 0; i < m - 1; i++)
          h = (h * d) % q;
    
        // Calculate hash value for pattern and text
        for (i = 0; i < m; i++) {
          p = (d * p + pattern.charAt(i)) % q;
          t = (d * t + txt.charAt(i)) % q;
        }
    
        // Find the match
        for (i = 0; i <= n - m; i++) {
          if (p == t) {
            for (j = 0; j < m; j++) {
              if (txt.charAt(i + j) != pattern.charAt(j))
                break;
            }
    
            if (j == m)
              indices.add(i + 1);
          }
    
          if (i < n - m) {
            t = (d * (t - txt.charAt(i) * h) + txt.charAt(i + m)) % q;
            if (t < 0)
              t = (t + q);
          }
        }
        return indices;
    }
}
