class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        int num1 = 1, num2 = 1, deno1 = 1, deno2 = 1;
        int spaceFound = 0, sindex = 0;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == ' ')spaceFound = i;
            if(str[i] == '/')sindex = i;
            if(str[i] == '/' && spaceFound){
                num2 = stoi(str.substr(spaceFound+1, i - spaceFound + 1));
            }
            else if(str[i] == '/' && !spaceFound){
                num1 = stoi(str.substr(0, i));
            }
            else if(str[i] == ','){
                deno1 = stoi(str.substr(sindex + 1, i - sindex + 1));
            }
        }
        deno2 = stoi(str.substr(sindex + 1));
        // cout<<num1<<" "<<num2<<" "<<deno1<<" "<<deno2;
        // if(num1 / deno1) > (num2 / deno2)cout<<"yes";
        // cout<<num1+deno1;
        if((num1 *1.0/ deno1) > (num2 *1.0/ deno2)) return to_string(num1)+"/"+to_string(deno1);
        else if((num1*1.0 / deno1) < (num2*1.0 / deno2)) return to_string(num2) +"/"+to_string(deno2);
        return "equal";
    }
};
