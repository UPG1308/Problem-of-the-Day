class Solution
{
    int atoi(String s) {
	// Your code here
	    int val = 0, hyphenCount = 0;
	    int n = s.length();
	    for(int i = 0; i < n; i++){
	        char c = s.charAt(i);
	        if(isNegative(c)) hyphenCount++;
	        if(hyphenCount >= 2) return -1;
	        if(isDigit(c))  val = val * 10 + number(c);
	        else if(c != '-' || (c == '-' && i != 0)) return -1;
	    }
	    return (hyphenCount == 1)? (-1 * val) : val;
    }
    
    boolean isNegative(char c){
        return c == '-';
    }
    
    boolean isDigit(char c){
        return (c >= '0' && c <= '9');
    }
    
    int number(char c){
        return c - '0';
    }
}
