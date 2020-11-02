 
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
