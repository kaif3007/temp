 
#include <bits/stdc++.h>
using namespace std;

string lowercase(string h)
{
    string p="";
    for(int i=0;i<h.length();i++)
    {
        if(h[i]>='a' and h[i]<='z')
            p+=h[i];
        else
            p+=(h[i]-'A'+'a');
    }

    return p;
}

struct comp
{
bool operator()(pair<int,string> p1,pair<int,string> p2)
{
    if(p1.first!=p2.first)
        return p1.first<p2.first;
    else
        return p1.second>p2.second;
}
};


int main()
{
    
    int k;
    cin>>k;
    int n=3;

    vector<string> v;
    v.push_back("anacell");
    v.push_back("cetracular");
    v.push_back("betacellular");
    

    int m;
    m=3;

    vector<string> text(m);
    text[0]="Anacell provides the best services in the city";
    text[1]="betacellular has awesome services";
    text[2]="Best services provided by anacell, everyone should use anacell";

    map<int,unordered_set<string> >mm;

    for(int i=0;i<m;i++)
    {
        string s=text[i];

        int j=0,k;
        while(j<s.length())
        {
            k=j;
            string p="";
            while((s[k]>='a' and s[k]<='z') or (s[k]>='A' and s[k]<='Z'))
            {
                p+=s[k];
                k++;
            }

            if(p.length()>0)
                mm[i].insert(lowercase(p));
               

           j=k+1;
        }
    }

    priority_queue< pair<int,string> , vector< pair<int,string> > ,comp> pq;
  
    for(int i=0;i<n;i++)
    {
        string x=v[i];
        string y=lowercase(x);

        int cnt=0;
        for(auto it=mm.begin();it!=mm.end();it++)
        {
            if(it->second.find(y)!=it->second.end())
                cnt++;
        }

       // cout<<cnt<<endl;

        pq.push({cnt,x});
    }

    for(int i=0;i<k;i++)
    {
        cout<<pq.top().second<<" ";
        pq.pop();
    }


    return 0;
}
