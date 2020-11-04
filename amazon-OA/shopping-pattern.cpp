#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
   int n,m;
   cin>>n>>m;

   vector<pair<int,int> > edges;

   vector<int> arr[n+1];

   for(int i=0;i<m;i++)
   {
     int a,b;
     cin>>a>>b;
     edges.push_back({a,b});
     arr[a].push_back(b);
     arr[b].push_back(a);
   }

   int ans=0;
   for(int i=0;i<m;i++)
   {
       int a=edges[i].first;
       int b=edges[i].second;

       for(int i=1;i<=n;i++)
       {
         if(i==a or i==b)
            continue;

          int flag=0;
          for(int j=0;j<arr[a].size();j++)
          {
             if(arr[a][j]==i)
             {
                flag++;
                break;
             }
          }

           for(int j=0;j<arr[b].size();j++)
          {
             if(arr[b][j]==i)
             {
                flag++;
                break;
             }
          }

          if(flag>=2)
            ans=max(ans,(int)arr[a].size()+(int)arr[b].size()+(int)arr[i].size()-6);

       }

      
   }

    cout<<ans<<endl;


    
}
