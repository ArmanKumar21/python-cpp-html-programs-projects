#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int t, n, m, i, j, parent[30005], sum[30005], ans,ans1;
int a, b;
int find(int x)
{
    if (x == parent[x])
        return parent[x];
    else
        return parent[x]=find(parent[x]);
}
int main()
{
        //ifstream inp;
        //ofstream out;
        ans = 2,ans1=200000000;
        cin>>n;
        assert(n<=15000);
        for (i = 1; i <= 2*n; i ++)
        {
            parent[i] = i;
            sum[i] = 1;
        }
        for (i = 0; i < n; i++)
        {
            cin>>a>>b;
            assert(a<=n&&a>=1);
            assert(b>=(n+1)&&b<=2*n);
            int pa = find(a);
            int pb = find(b);
            if (pa != pb)
            {
                parent[pa] = pb;
                sum[pb] += sum[pa];
            }
        }
        for (i = 1; i <= 2*n; i ++)
        {
            if(sum[i]!=1){
            int ind=find(i);
            ans1=min(sum[ind],ans1);
            }
        }
        for (i = 1; i <= 2*n; i ++)
        {
            if(sum[i]!=1){
            int ind1=find(i);
            ans=max(sum[ind1],ans);
            }
        }
        cout<<ans1<<" "<<ans<<endl;

        //printf("%d\n", ans);
    return 0;
}
