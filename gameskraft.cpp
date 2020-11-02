Given three strings A, B, C where A and B have the same length n.
Find no of strings alphabetically greater than A and alphabetically less than B whose length is n such that C is not a substring.??
########################################################################
https://leetcode.com/problems/maximum-profit-in-job-scheduling/
https://leetcode.com/problems/count-vowels-permutation/

//dsu use kr lena. greater than g ke sbko combine // a kinda seive
https://leetcode.com/discuss/interview-question/202553/Traveling-is-Fun/
#######################################################################################

int dp[100008][5];
#define ll long long int
#define mod 1000000007

int recurse(int i,int n,int j)
{
    if(i==n)
        return 1;
    
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    ll cnt=0;
    
    if(j==0)
        cnt=recurse(i+1,n,1)%mod;
    else if(j==4)
        cnt=recurse(i+1,n,0)%mod;
    else if(j==1)
        cnt=(recurse(i+1,n,0)+recurse(i+1,n,2))%mod;   
    else if(j==3)
         cnt=(recurse(i+1,n,2)+recurse(i+1,n,4))%mod;
    else
    {
        cnt=recurse(i+1,n,0)%mod;
        cnt+=recurse(i+1,n,1);
        cnt%=mod;
        cnt+=recurse(i+1,n,3);
        cnt%=mod;
        cnt+=recurse(i+1,n,4);
        cnt%=mod;
    }
        
    return dp[i][j]=cnt;
    
}
class Solution 
{
public:
    int countVowelPermutation(int n) 
    {
        memset(dp,-1,sizeof(dp));
        
        ll ans=0;
        
        for(int i=0;i<5;i++)
        {
            ans+=recurse(1,n,i);
            ans%=mod;
        }
        return ans;
    }
};

#####################################################################
PATH TO A GOAL
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
#define mod 1000000007
 
int dp[1001][2501][2];
 
ll recurse( string str, int n, int s, int e, int i, bool f )
{
 
    if( s< 0 || s >n )
        return 0;
    
 
    if( i== str.size() )
        return s==e;
    
 
    if( dp[i][s][f] != -1 )
        return dp[i][s][f];
    
 
    ll ans=0;
    if( str[i] == 'l' && f) 
    {

        ans+=recurse( str, n, s-1, e, i+1, f );
        ans%=mod;
        ans+=recurse( str, n, s-1, e, i+1, !f);
        ans%=mod;
    }
    else if(str[i] == 'r' && !f) 
    {
        ans+=recurse( str, n, s+1, e, i+1, f );
        ans%=mod;
        ans+=recurse( str, n, s+1, e, i+1, !f);
        ans%=mod;
    }
    else
       ans= recurse( str, n, s, e, i+1, f);

    return dp[i][s][f]=ans;

}
 

 
int main()
 {
    string step;
    cin >> step;
    int n,s,e;
    cin >> n >> s >> e;

    memset(dp,-1,sizeof(dp));

    ll ans=(recurse( step, n, s, e ,0,0)+recurse( step, n, s, e ,0,1))%mod;

    if(s==e)
         ans++;

    cout << ans << "\n";
    return 0;
}
######################################################################################################
SQUARE MATRIX

 int n=matrix.size();
        
         if(n==0)
             return 0;
        
         int m=matrix[0].size();
         int sol=0;
        
         int ans[n][m];
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                 if(i==0 or j==0)
                     ans[i][j]=matrix[i][j]-'0';
                 else if(matrix[i][j]=='1')
                     ans[i][j]=min({ans[i][j-1],ans[i-1][j],ans[i-1][j-1]})+1;
                 else
                     ans[i][j]=0;
                 
                 sol=max(sol,ans[i][j]*ans[i][j]);
             }
         }
        
     
        return sol;
 ##########################################################################################################
 RECONSTRUCT ARRAY
 #include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007

using namespace std;

ll dp[55][102][55];

int n,m,c;

int recurse(int i,int prevmax,int j)
{
   if(i==n)
     return j==c+1;

   if(dp[i][prevmax][j]!=-1)
     return dp[i][prevmax][j];

   ll cnt=0;
   for(int k=1;k<=m;k++)
   {
     if(k>prevmax)
      cnt+=recurse(i+1,k,j+1);
     else
      cnt+=recurse(i+1,prevmax,j);

     cnt%=mod;
   }

   return dp[i][prevmax][j]=cnt;
}
 
int main()
{  
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>c;

    memset(dp,-1,sizeof(dp));
    cout<<recurse(0,0,0);

    return 0;
} 
############################################################################################
BITWISE XORR
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{  
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

  
    int n,k;
     cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];

    cin>>k;
    int ans=1;

    map<int,int> mm;
    for(int i=0;i<n;i++)
    {
       int l=mm[arr[i]^k]+1;
       mm[arr[i]]=l;
       ans=max(ans,l);
    }

    coût<<ans<<"\n";


    return 0;
} 
############################################################################################
SORTED ARRANGEMENT
 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
#define mod 1000000007
 
int bit[100006];

void update(int idx,int val)
{
    while(idx<=100000)
    {
        bit[idx]+=val;
        idx+=((idx&(-idx)));
    }
}

int query(int idx)
{
    int ans=0;
    while(idx>0)
    {
        ans+=bit[idx];
        idx-=(idx&(-idx));
    }

    return ans;
}
 
int main()
 {
    memset(bit,0,sizeof(bit));

    int n;
    cin>>n;

    int ans=0;
    for(int i=0;i<n;i++)
    {
        int u;
        cin>>u;

        int y=query(u-1);
        int x=i-y;

        ans+=(2*min(x,y)+1);

        update(u,1);
    }


    cout<<ans;

    return 0;
}
