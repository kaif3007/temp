
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{

    ll fibo[20];
    fibo[0]=2;
    fibo[1]=2;
    ll sum=0;

    for(int i=2;i<20;i++)
        fibo[i]=fibo[i-1]+fibo[i-2];

    for(int i=0;i<20;i++)
        sum+=fibo[i]%10;

    cout<<sum<<endl;
    for(int i=0;i<20;i++)
        cout<<fibo[i]%10<<" ";
    cout<<endl;

    int q;
    cin>>q;
    while(q--)
    {
        ll l,r;
        cin>>l>>r;

        l--;
        r--;

        ll ans=0;

        while(l<r and l%20!=0 and l!=0)
        {
            ans+=fibo[l%20]%10;
            ans%=mod;
            l++;
        }

            ll k=(r-l+1)/20;
            ans=(ans+(k*sum))%mod;
            l+=k*20;
        

        while(l<=r)
        {
             ans+=fibo[l%20]%10;
             ans%=mod;
             l++;
        }

        cout<<ans<<endl;
    }


    return 0;
}
########################################################################################################################
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007

using namespace std;

struct node
{
    string ip;
    int msk,id;
};

string bin(string s)
{
    int y=stoi(s);
    string p="";
    while(y)
    {
        if(y%2)
            p+="1";
        else
            p+="0";

        y/=2;
    }

    while(p.length()<8)
        p+="0";

    reverse(p.begin(),p.end());
    return p;
}

int main()
{

    vector<node> v;
    int n;
    cin>>n;

    for(int k=0;k<n;k++)
    {
        string y;
        cin>>y;
        int idx;
        cin>>idx;

        string h="";

        int i=0;
        while(i<y.length())
        {
             int j=i;
             string kaif="";

             while(j<y.length() and y[j]!='.' and y[j]!='/')
             {
                kaif+=y[j];
                j++;
             }

             i=j+1;


             if(i>=y.length())
            {
               node p;
               p.id=idx;
               p.ip=h;
               p.msk=stoi(kaif);
               v.push_back(p);
            }
            else
                h+=bin(kaif);
        }
    }

    //for(int i=0;i<v.size();i++)
     //   cout<<v[i].ip<<" "<<v[i].msk<<" "<<v[i].id<<endl;


        string q;
        cin>>q;
        int ans=0;
        int len=0;
        string salman="";

        int i=0;
        while(i<q.length())
        {
             int j=i;
             string kaif="";

             while(j<q.length() and q[j]!='.')
             {
                kaif+=q[j];
                j++;
             }

             i=j+1;
             
             salman+=bin(kaif);
        }


        for(int i=0;i<v.size();i++)
        {
            int l=v[i].msk;
            string ss=v[i].ip;
            int j=0;
            while(j<l)
            {
                if(ss[j]!=salman[j])
                    break;

                j++;
            }


            if(j>len)
            {
                len=j;
                ans=v[i].id;
            }
        }

        cout<<ans;


    
    return 0;
}

##################################################################################################
#include <bits/stdc++.h> 
using namespace std; 


vector<int> g[100005];
int par[100005],cont[100005];
int dis[100005];

void dfs(int x,int& t) 
{
  cont[x] = t;
  for(int i=0;i<g[x].size();i++) 
    if(cont[g[x][i]]==100005) 
        dfs(g[x][i],t);
  
}

void distanc(int x,int d)
{
  dis[x] = d;
  for(int i=0;i<g[x].size();i++) 
    if(dis[g[x][i]]==-1) 
        distanc(g[x][i],d+1);
  
}

int root(int a) 
{
    return (a==par[a])?a:par[a]=root(par[a]);
}

void unite(int x,int y,int t)
{
    int xp=root(x);
    int yp=root(y);

    if(xp==yp) 
     return;


  int u = max(x,y);
  int v = min(x,y);

  if(v==0) 
    dfs(u,t);

  par[u] = v;
}


int main() 
{ 
    iota(par,par+100005-3,0);
    fill(cont,cont + 100005,100005);

    vector<pair<int,int> > v;

    int t,m; 
    cin>>t>>m;
    for(int ct=1;ct<=t;ct++)
    {
      int ty;
      cin>>ty;
      if(ty==1) 
      {
          int x,y; 
          cin>>x>>y;
          unite(x,y,ct);
          g[x].push_back(y);
          g[y].push_back(x);
      } 
      else
    {
        int x,y; 
        cin>>x>>y;
        v.push_back({ct,y});
      }

    }

    memset(dis,-1,sizeof(dis));
    distanc(0,0);

    for(int i=0;i<v.size();i++) 
    {
      int ct = v[i].first, 
      x = v[i].second;
      if(cont[x]<ct) 
       {
         if(dis[x]%2)
         cout<<-1<<endl;
         else
         cout<<1<<endl;
       }
      else 
        cout<<0<<endl;
    }

    
    return 0; 
}
/*


-1
0
0
1
-1

--
6 3
1 1 2
1 0 1
1 3 4
2 0 1
2 0 2
2 0 4

-1
1
0

*/

