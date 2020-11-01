 int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];

    int mark[n];
    memset(mark,0,sizeof(mark));

    int x;
    cin>>x;

    int ans=0,idx=0,cnt=0,sz=n;

    while(sz>1)
    {
        if(mark[idx]==0)
            cnt++;
        
        if(cnt==x)
        {
            sz--;
            mark[idx]=1;
            cnt=0;
        }

        idx++;
        if(idx==n)
            ans++;

        idx%=n;
    }

    cout<<ans<<"\n";
    #############################################################################################
    
vector<vector<int> > mul(vector<vector<int>>& m1,vector<vector<int>> & m2)
{
    int n=m1.size();
    vector<vector<int> > arr(n,vector<int>(n,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
                arr[i][j]+=(m1[i][k]*m2[k][j]);
        }
    }

    return arr;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int> > arr(n,vector<int>(n,0));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];

    vector< vector<int> > v=mul(arr,arr);


    v=mul(arr,v);


    int ans=0;
    for(int i=0;i<n;i++)
        ans+=v[i][i];

    cout<<ans/6<<endl;
}
###########################################################################################

#include "bits/stdc++.h"
#define ll long long int

using namespace std;


int discovered[100000],low[100000],mark[100000];

int timee=0;
int cnt=0;

void dfs(vector<int> arr[],int n,int p)
{
    mark[n]=true;
    discovered[n]=low[n]=++timee;
    
    for(int i=0;i<arr[n].size();i++)
    {  
        if(p==arr[n][i])
          continue;
        
        if(mark[arr[n][i]]==false)
        {  
            dfs(arr,arr[n][i],n);
            low[n]=min(low[n],low[arr[n][i]]);
            if( low[arr[n][i]]>discovered[n])
             cnt++;
        }
        else 
         low[n]=min(low[n],discovered[arr[n][i]]);
       
    }
}


int main()
{
    int n;
    cin>>n;
    vector<vector<int> > marr(n,vector<int>(n,0));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>marr[i][j];

     vector<int> arr[n];

     for(int i=0;i<n;i++)
     {
        for(int j=0;j<n;j++)
        {
            if(marr[i][j])
            arr[i].push_back(j);
        }
     }
     
    for(int i=0;i<n;i++)
    {
       low[i]=INT_MAX;
       mark[i]=0;
       discovered[i]=INT_MAX;
    }
    
      for(int i=0;i<n;i++)
        if(mark[i]==false)
           dfs(arr,i,-1);

    cout<<cnt+1;

    return 0;
}
###########################################################################################
