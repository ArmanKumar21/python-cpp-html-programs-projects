class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int c = 0;
        while (i >= 0 || j >= 0 || c == 1)
        {
            if (i >= 0)
            {
                if(a[i] == '1') c++;
                i--;
            }
            if (j >= 0)
            {
                if(b[j] == '1') c++;
                j--;
            }
            if(c == 2)
            {
                s = '0' + s;
                c = 1;
            }
            else if(c == 1)
            {
                s = '1' +s;
                c = 0;
            }
            else  if(c == 0)
            {
                s = '0' + s;
                c = 0;
            }
            else if(c == 3)
            {
                s = '1' + s;
                c = 1;
            }
        }
        
        return s;

        
        
    }
};
