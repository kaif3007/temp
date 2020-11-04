 
#include <bits/stdc++.h>
using namespace std;

int arr[100005];


int root(int i)
{
    return arr[i]==i?arr[i]:arr[i]=root(arr[i]);
}

int main()
{
     
    set<string> ss;
    int n;
    cin>>n;
    
    vector<pair<string,string>> v;

    for(int i=0;i<n;i++)
    {
        string a,b;
        cin>>a>>b;

        v.push_back({a,b});
        ss.insert(a);
        ss.insert(b);
    }

    vector<string> nodes;
    for(auto it=ss.begin();it!=ss.end();it++)
        nodes.push_back(*it);

    sort(nodes.begin(),nodes.end());

    int m=nodes.size();

    for(int i=0;i<m;i++)
        arr[i]=i;

    map<string,int> mp;

    for(int i=0;i<m;i++)
        mp[nodes[i]]=i;

    for(int i=0;i<n;i++)
    {
          int a=root(mp[v[i].first]);
          int b=root(mp[v[i].second]);

          if(a!=b)
            arr[a]=b;
    }

    map<int,vector<int> > mm;

      int sz=0;
      for(int i=0;i<m;i++)
       {
          int u=root(i);
          mm[u].push_back(i);
          sz=max(sz,(int)mm[u].size());       
       }

       map< int,set<string> > ms;

       for(int i=0;i<m;i++)
       {
            int u=root(i);
            if(mm[u].size()==sz)
            {
                for(int j=0;j<mm[u].size();j++)
                    ms[u].insert(nodes[mm[u][j]]);
            }
       }

        int ans=0;
       for(int i=0;i<nodes.size();i++)
       {
          for(auto it=ms.begin();it!=ms.end();it++)
          {
             if((it->second).find(nodes[i])==(it->second).end())
             {
                ans=it->first;
                break;
             }
          }
       }

       for(auto it=ms[ans].begin();it!=ms[ans].end();it++)
         cout<<*it<<" ";

    return 0;
}
