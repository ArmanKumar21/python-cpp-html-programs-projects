
class Solution{
public:
    int maxLength(string s){
        // code here
        stack<int>st;
        int c=0;
        st.push(-1);
        int n=s.length();
        if(n==0) return c;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if(st.size()>0) c=max(c,i-st.top());
                else st.push(i);
            }
        }
        return c;
        
    }
};
