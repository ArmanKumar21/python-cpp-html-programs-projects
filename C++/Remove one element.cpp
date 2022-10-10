//Author -> Samkit Jain
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll t;
    cin>>t;
    for(ll test=1;test<=t;test++)
    {
        ll n;
        cin>>n;
        ll x[n+1];
        ll sum1=0,sum2=0;
        map<ll,ll>m;
        for(ll i=1;i<=n;i++)
        {
            cin>>x[i];
            sum1+=x[i];
        }

        for(ll i=1;i<n;i++)
        {
            ll temp;
            cin>>temp;
            sum2+=temp;
            m[temp]++;
        }

        ll ans = 10e9+10;
        for(ll i=1;i<=n;i++)
        {
            ll sum = sum1-x[i];
            if(sum2-sum>0 && (sum2-sum)%(n-1)==0)
            {
                ll lol=(sum2-sum)/(n-1);
                ll sure=1;
                if(n>2)
                {
                    for(ll j=1;j<=3;j++)
                    {
                        if(i!=j && m[x[j]+lol]==0)
                        {
                            sure=0;
                            break;
                        }
                    }
                }
                if(sure)
                {
                    ans = min(ans,(sum2-sum)/(n-1));
                }
            }
        }

        cout<<ans<<"\n";

    }
    return 0;
}
