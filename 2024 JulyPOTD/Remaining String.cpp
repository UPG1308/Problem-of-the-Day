class Solution {
    public:
    string printString(string s, char ch, int count) {
        while(count--){
            int pos = s.find(ch);
            if(pos == string::npos)
                return "";
            s = s.substr(pos + 1);
        }
        return s;
    }
};
