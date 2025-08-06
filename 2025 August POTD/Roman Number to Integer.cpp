class Solution {
    public int romanToDecimal(String s) {
        // code here
        int  result=0; 
        int i=1;
        int v=5;
        int x=10;
        int l=50;
        int c=100;
        int d=500;
        int m=1000;
        
        for(int i=s.length-1;i>=0;i--){
            if(s[i]=='I'){
                if(s[i-1]=='X'){
                    result=result+x+i;
                }
                else{
                    result=reslt+x-i;
                }
            }
            else if (s[i]=='V'){
                 if(s[i-1]=='I'){
                     result=result+v-i;
                    else{
                        re
                    }
                 }
                 if(s[i+1]=='I'){
                  result=result+v+i;
            }
             else if (s[i]=='X'){
                s[i]=10;
            }
             else if (s[i]=='L'){
                s[i]=50;
            }
             else if (s[i]=='C'){
                s[i]=100;
            }
             else if (s[i]=='D'){
                s[i]=500;
            } else if (s[i]=='M'){
                s[i]=1000;
            }
    }
}
