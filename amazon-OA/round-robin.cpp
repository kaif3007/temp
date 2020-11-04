 
#include <bits/stdc++.h>
using namespace std;


int main()
{
     
    int n;
    cin>>n;
    int tq;
    cin>>tq;

    int arr[n],bt[n],rt[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int i=0;i<n;i++)
     {
         cin>>bt[i];
         rt[i]=bt[i];
     }

    int r=n;
    int idx=0;

    int en[n];
    int t=arr[0];

    while(r)
    {
        if(rt[idx]>0 and rt[idx]<=tq)
        {
            t+=rt[idx];
            en[idx]=t;
            rt[idx]=0;
            r--;
        }
        else if(rt[idx]>0)
        {
            t+=tq;
            rt[idx]-=tq;
        }

        if(idx==n-1)
            idx=0;
        else if(t>=arr[idx+1])
            idx++;
        else
            idx=0;
    }

    for(int i=0;i<n;i++)
        cout<<en[i]<<" ";

    return 0;
}
