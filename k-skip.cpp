#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ff first
#define ss second
#define  P pair <ll,ll>


int main() 
{
	int n,m,k;
    cin>>n>>m>>k;

	vector<P>graph[n+1];
	ll cost[n+1][20];
	int vis[n+1][20];

    
    for (int i=0; i<m; i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    	for(int j=0;j<20;j++)
    		cost[i][j]=INT_MAX;

    priority_queue<pair<ll, P > ,vector<pair<ll, P > >,greater<pair<ll, P > > >pq;
    pq.push({0,{1, 0}});
    cost[1][0]=0;

    while (!pq.empty())
    {
        pair<ll, P >curr=pq.top();
        pq.pop();

        int c_n=curr.ss.ff;
        int c_s=curr.ss.ss;
        int cst=cost[c_n][c_s];

        for (int i=0; i<graph[c_n].size(); i++) 
        {
            if(graph[c_n][i].ff==c_n) 
               continue;

            int c_cst=cst+graph[c_n][i].ss;

            if( cost[graph[c_n][i].ff][c_s]>c_cst)
            {
                pq.push({c_cst,{graph[c_n][i].ff, c_s}});
                cost[graph[c_n][i].ff][c_s]=c_cst;
            }
           
            c_cst=cst;
            if(c_s==k)   
            	continue;

            if( cost[graph[c_n][i].ff][c_s+1]>c_cst )
             {
                pq.push({c_cst,{graph[c_n][i].ff, c_s+1}});
                cost[graph[c_n][i].ff][c_s+1]=c_cst;
            }
          
        }
    }
    
    
    for (int i=1; i<=n; i++)
    {
        long long ret=2e18;
        for (int j=0;j<=k;j++)
        {
            if(cost[i][j]==-1)  
            	continue;
            ret=min(ret,cost[i][j]);
        }
        cout<<ret<<" ";
    }
   
}
