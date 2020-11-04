 
#include <bits/stdc++.h>
using namespace std;


int main()
{
    
    string s;
    cin>>s;

    int n=s.length();

    map<char,int> mm;

    int k;
    cin>>k;

    for(int i=0;i<k;i++)
        mm[s[i]]++;

    for(int i=k;i<n;i++)
    {
        if(mm.size()==k-1)
           cout<<s.substr(i-k,k)<<" ";

        mm[s[i]]++;
        if(mm[s[i-k]]==1)
           mm.erase(s[i-k]);
        else
            mm[s[i-k]]--;
    }

    if(mm.size()==k-1)
           cout<<s.substr(n-k,k)<<" ";


    return 0;
}
