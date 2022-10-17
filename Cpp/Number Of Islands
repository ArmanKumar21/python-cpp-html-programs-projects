class Solution {
  public:
   vector<int> vc;
  int fun(int i,int j,vector<vector<int>> &op)
  {
      int row=op.size();int col=op[0].size();
      if(i<0 || j<0 || i>=row || j>=col || op[i][j]==0)
        return 0;
        if(op[i][j]==1)
        {
            op[i][j]=0;
            fun(i+1,j,op);
            fun(i-1,j,op);
            fun(i,j+1,op);
            fun(i,j-1,op);
        }

  }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {
        // code here
        vector<vector<int>> grid(n,vector<int> (m,0));
        vector<vector<int>> gd(n,vector<int> (m,0));
        for(int i=0;i<op.size();i++)
        {
            grid[op[i][0]][op[i][1]]=1;
            int cnt=0;
            gd=grid;
            for(int a=0;a<n;a++)
            {
                for(int b=0;b<m;b++)
                {
                    if(gd[a][b]==1)
                    {
                      fun(a,b,gd);
                      cnt++;
                    }
                }
            }
            vc.push_back(cnt);

        }
        return vc;
    }
};
