string longestCommonPrefix(vector<string> arr) {
        // your code here
        string prefix=arr[0];
        
        if(arr.size()==1)
        {
            return prefix;
        }
        for(int i=1;i<arr.size();i++)
        {
            int j=0;
            for(j;j<arr[i].length();j++)
            {
                if(arr[i][j]!=prefix[j])
                {
                    break;
                }
            }
            prefix=arr[i].substr(0,j);
        }
        if(prefix=="")return "-1";
        return prefix;
    }
