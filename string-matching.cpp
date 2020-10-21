#include<bits/stdc++.h>
#define pb push_back 
#define ff first
#define ss second
#define MOD 1000000007
#define ll long long int

using namespace std;


string arr[1005];

void process(string &s) 
{
    for(char &c: s) 
    {
        if(c=='o' )  
          c = 'a';
        else if(c=='l')
          c = 't';
    }
}


int dp[205][205][2];


int main()
{

    int N;
    cin>>N;
    string t; 
    cin>>t; 
    process(t);

    for(int i=0;i<N;i++)  
    {
      cin>>arr[i];
      process(arr[i]);
    }

    int K; 
    cin>>K;

    int m = t.length();
    int ans = 0;

    for(int k=0;k<N;k++) 
    {
        string s = arr[k];
        int n = s.length();
            //base case
        for(int j=0;j<=m;j++)
         dp[0][j][0] = dp[0][j][1] = j;

        for(int i=0;i<=n;i++)
         dp[i][0][0] = dp[i][0][1] = MOD;

         dp[1][0][1] = 0;
        //bottom up
        for(int i=1;i<=n;i++)
        { 
           for(int j=1;j<=m;j++) 
           {
            if(s[i-1]==t[j-1])
            {
                dp[i][j][0] =  dp[i-1][j-1][0];
                dp[i][j][1] =  dp[i-1][j-1][1];
            } 
            else
            {
                dp[i][j][0] =  dp[i][j-1][0] + 1;
                dp[i][j][1] =  min(dp[i-1][j][0],dp[i][j-1][1] + 1);
            }
          }
        }

      

        bool poss = 0;
        for(int k=1;k<=m;k++)
        {
             if(dp[n][k][1]<MOD) 
             {
                int i = n, j = k;
                while(i!=0)
                 {
                    if(s[i-1]==t[j-1]) 
                        i = i-1, j = j-1;
                    else 
                    {
                        if(dp[i-1][j][0]<=dp[i][j-1][1] + 1)
                            i = i-1;
                          else 
                            j = j-1;
                        
                    }
                }
                if(dp[n][k][1]-j<=K)
                {
                    
                    poss = 1; 
                    break;
                }
            }
        }

        ans+=poss;
    }

    cout<<ans<<endl;
 
    return 0;
}
