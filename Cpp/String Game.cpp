//Author -> Samkit Jain
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long int
#define mod 10e8 + 7


ll sort(const void *a,const void *b) //qsort(x,n,sizeof(ll),sort)
{
   return(*(ll*)a - *(ll*)b);
}
ll gcd(ll a,ll b)
{
    ll a1,b1;
    if(b!=0)
    {
        a1=b;
        b1=a%b;
        return gcd(a1,b1);
    }
    return a;
}
ll binary(ll n)
{
    ll binary=0,temp=1;
    while(n>0)
    {
        binary=binary+((n%2)*temp);
        n=n/2;
        temp=temp*10;
    }
    return binary;
}
ll no_of_bits(ll n)
{
    return (int)log2(n)+1;
}
ll prime(ll n)
{
    if(n==0 || n==1)
    {
        return 0;
    }
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {return 0;}
    }
    return 1;
}

class DSU
{
    public:
    vector<ll>v;

    DSU(ll n)
    {
        v = vector<ll>(n+1);
        for(ll i=0;i<=n;i++)
        {
            v[i]=i;
        }
    }

    ll find(ll n)
    {
        if(v[n]==n)
        {
            return n;
        }
        v[n] = find(v[n]);
        return  v[n];
    }
    
    void merge(ll a,ll b)
    {
        ll a1 = find(a);
        ll b1 = find(b);
        if(a1==b1)
        {
            return;
        }
        v[b1]=a1;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n;
    cin>>n;
    DSU d(n);

    vector<int>v;
    v.push_back(0);
    for(int i=1;i<=n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    ll n1;
    cin>>n1;
    for(ll i=1;i<=n1;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a>b)
        {
            swap(a,b);
        }
        d.merge(a,b);    
    }

    vector<int>dp(n+1,0);
    int ans = 0;
    for(ll i=0;i<=n;i++)
    {
        int parent  = d.find(i);
        dp[parent] += v[i];
        ans = max(ans,dp[parent]);
    }

    cout<<ans<<"\n";
    return 0;
}
