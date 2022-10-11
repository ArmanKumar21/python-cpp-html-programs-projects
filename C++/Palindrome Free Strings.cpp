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

bool result = false;

bool check(string s)
{
    int n = s.length();
    for(ll i=0;i<=n-5;i++)
    {
        ll sure=1;
        for(ll l=i,r=i+4 ; l<r ; l++,r--)
        {
            if(s[l]!=s[r])
            {
                sure=0;
            }
        }
        if(sure)
        {
            //got a palindrome
            return false;
        }
    }

    for(ll i=0;i<=n-6;i++)
    {
        ll sure=1;
        for(ll l=i,r=i+5 ; l<r ; l++,r--)
        {
            if(s[l]!=s[r])
            {
                sure=0;
            }
        }
        if(sure)
        {
            //got a palindrome
            return false;
        }
    }

    //no palindrome found
    return true;
}

void fill(int index,string s,int n)
{
    if(result)
    {
        return;
    }
    if(index==n)
    {
        result = ((result)|(check(s)));
        return;
    }

    if(s[index]!='?')
    {
        fill(index+1,s,n);
    }
    else
    {
        s[index] = '1';
        fill(index+1,s,n);
        
        s[index] = '0';
        fill(index+1,s,n);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll t;
    cin>>t;
    for(ll test=1;test<=t;test++)
    {
        result=false; 
        ll n;
        cin>>n;
        string s;
        cin>>s;

        fill(0,s,n);

        if(result)
        {
            cout<<"Case #"<<test<<": "<<"POSSIBLE"<<"\n";
        }
        else
        {
            cout<<"Case #"<<test<<": "<<"IMPOSSIBLE"<<"\n";
        }
    }
    return 0;
}
