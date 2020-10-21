#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int mark[100][100];
int n;

bool issafe(int i,int j)
{
    return i>=0 and i<n and j>=0 and j<n and mark[i][j]==0;
}

int dx[8]={1,1,1,0,0,-1,-1,-1};
int dy[8]={0,1,-1,1,-1,0,1,-1};


int bfs(vector<string>&v,pair<int,int>st,pair<int,int>en)
{
    queue<pair<int,int>> q;
    q.push(st);

    int cnt=0;

    while(!q.empty())
    {
          int u=q.size();
          for(int i=0;i<u;i++)
          {
             pair<int,int> p=q.front();
             q.pop();

             if(p==en)
                return cnt;

             for(int k=0;k<8;k++)
             {
                 int x=dx[k]+p.first;
                 int y=dy[k]+p.second;
                 if(issafe(x,y) and v[x][y]!='#')
                 {
                    mark[x][y]=1;
                    q.push({x,y});
                 }
             }
          }
          cnt++;
    }
    return -1;
}


int dp[19][1000006];
int dist[100][100];

int recurse(int i,int mask,int n)
{
    if(mask==(1<<n)-1)
        return dist[i][0];

    if(dp[i][mask]!=-1)
        return dp[i][mask];

    int ans=INT_MAX;
    for(int j=0;j<n;j++)
    {
         if( dist[i][j]!=INT_MAX and (mask&(1<<j))==0)
            ans=min(ans,dist[i][j]+recurse(j,mask|(1<<j),n));
    }

    return dp[i][mask]=ans;
}


int main()
{

    cin>>n;
    vector<string> v;

    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        v.push_back(s);      
    }

    pair<int,int> m;
    vector< pair<int,int> > b;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]=='m')
            {
                m.first=i;
                m.second=j;
            }
            else if(v[i][j]=='b')
                b.push_back({i,j});
        }
    }

    b.insert(b.begin(),m);

    for(int i=0;i<b.size();i++)
    {
        for(int j=0;j<b.size();j++)
            dist[i][j]=INT_MAX;
    }


    for(int i=0;i<b.size();i++)
    {
        for(int j=i+1;j<b.size();j++)
        {
             memset(mark,0,sizeof(mark));
             int dst=bfs(v,b[i],b[j]);

             if(dst==-1 and i==0)
             {
                 cout<<-1;
                 return 0;
             }

             dist[i][j]=dst;
             dist[j][i]=dst;
        }
    }

     for(int i=0;i<b.size();i++)
         dist[i][i]=0;

   /*
   for(int i=0;i<b.size();i++)
   {
    for(int j=0;j<b.size();j++)
         cout<<dist[i][j]<<" ";
     cout<<endl;
   }
   */


    memset(dp,-1,sizeof(dp));
    cout<<recurse(0,0,b.size());


    return 0;
}
