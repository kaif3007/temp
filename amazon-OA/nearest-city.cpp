#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    int n;
    cin>>n;

    vector<string> v(n);
    for(int i=0;i<n;i++)
     cin>>v[i];


    int x[n],y[n];
    for(int i=0;i<n;i++)
        cin>>x[i];

    for(int i=0;i<n;i++)
        cin>>y[i];

    map<string,pair<int,int> > mm;
    for(int i=0;i<n;i++)
        mm[v[i]]={x[i],y[i]};

    map<int,vector<pair<int,int> >> mx,my;

    for(int i=0;i<n;i++)
    {
         mx[x[i]].push_back({y[i],i});
         my[y[i]].push_back({x[i],i});
    }

    for(auto it=mx.begin();it!=mx.end();it++)
        sort((it->second).begin(),(it->second).end());

    for(auto it=my.begin();it!=my.end();it++)
        sort((it->second).begin(),(it->second).end());
    
    int q;
    cin>>q;
    while(q--)
    {
        string s;
        cin>>s;

        int x=mm[s].first;
        int y=mm[s].second;

        //cout<<x<<" "<<y<<endl;

        vector< pair<int,string> > vv;
        vector< pair<int,int> >v1=mx[x];


        auto it=upper_bound(v1.begin(),v1.end(),make_pair(y,100000));

        
        if(it!=v1.end())
            vv.push_back({it->first-y,v[it->second]});

        it--;
        if(it!=v1.begin())
         {
            it--;
            vv.push_back({y-it->first,v[it->second]});
         }


        v1=my[y];

         it=upper_bound(v1.begin(),v1.end(),make_pair(x,100000));
        if(it!=v1.end())
            vv.push_back({it->first-x,v[it->second]});

        it--;
        if(it!=v1.begin())
         {
            it--;
            vv.push_back({x-it->first,v[it->second]});
         }

        if(vv.size()>0)
        { 
            sort(vv.begin(),vv.end());
            cout<<vv[0].second<<" ";
        } 
        else
            cout<<"None"<<" ";


    }

    return 0;
}
