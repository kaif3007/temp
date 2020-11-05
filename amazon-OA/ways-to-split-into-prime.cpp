#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int


bool isprime[1000009];

void seive()
{
    for(int i=0;i<=1000000;i++)
    isprime[i]=true;

    isprime[0]=false;
    isprime[1]=false;

    for(int i=2;i*i<=1000000;++i)
    {
        if(isprime[i]==true)
        {
            for(int j=i*i;j<=1000000;j+=i)
            isprime[j]=false;
        }
    }
}

int dp[100006];

int recurse(int i,string& s)
{
    if(i==s.length())
        return 1;

    if(dp[i]!=-1)
        return dp[i];

    int cnt=0;
    int num=0;
    for(int j=i;j<s.length();j++)
    {
        num*=10;
        num+=(s[j]-'0');

        if(num>1e6)
            break;

        if(isprime[num])
            cnt+=recurse(j+1,s);
    }

    return dp[i]=cnt;
}


int main()
{
    seive();

    memset(dp,-1,sizeof(dp));

    string s;
    cin>>s;

    cout<<recurse(0,s);

    return 0;
}
