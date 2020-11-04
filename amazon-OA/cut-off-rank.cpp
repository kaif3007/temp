#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
   int r;
   cin>>r;

   int n;
   cin>>n;

   int arr[n];
   for(int i=0;i<n;i++)
     cin>>arr[i];

    int freq[101]={0};
    for(int i=0;i<n;i++)
        freq[arr[i]]++;

    int ans=0,rnk=1;
    for(int i=100;i>=1;i--)
    {
        if(rnk>r)
            break;

        rnk+=freq[i];
        ans+=freq[i];
    }

    cout<<ans<<endl;

    return 0;
}
