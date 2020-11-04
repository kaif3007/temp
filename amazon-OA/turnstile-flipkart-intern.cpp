
There is a gate in an amusement park. There is an entrance queue and an exit queue.
Given two arrays of length n, time[] and direction[] such that time[i] represents 
the time when person_i reaches the gate and direction[i] represents whether the 
person is joining the entrance queue or exit queue, output an array timestamp[] 
of length n such that timestamp[i] represents the time when person_i crosses the 
gate. The gate operates as follows:
If the gate was used at time t - 1 for entrance, then entry queue will be preferred.
Else If the gate was used at time t - 1 for exit, then exit queue will be preferred.
Else exit queue will be preferred.
1 <= n <= 10^5
1 <= time[i] <= 10^9
time[i] <= time[i+1]
direction[i] = 0 means entrance, direction[i] = 1 means exit.


#############################################################################
#include <bits/stdc++.h>
using namespace std;


int main()
{
     
    queue<int> q[2];

    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    arr[n]=1e9;

    int dept[n];
    for(int i=0;i<n;i++)
        cin>>dept[i];

    int t=arr[0];

    int flag=-1;

    int ans[n];
    
    for(int i=0;i<n;i++)
    {
        q[dept[i]].push(i);

        while( t<arr[i+1])
        {
            if(flag!=0)
            {
                if(!q[1].empty())
                {
                    ans[q[1].front()]=t++;
                    q[1].pop();
                    flag=1;
                }
                else if(!q[0].empty())
                {
                    ans[q[0].front()]=t++;
                    q[0].pop();
                    flag=0;
                }
                else
                {
                    flag=-1;
                    t=arr[i+1];
                }
            }
            else
            {
                 if(!q[0].empty())
                {
                    ans[q[0].front()]=t++;
                    q[0].pop();
                    flag=0;
                }
                else if(!q[1].empty())
                {
                    ans[q[1].front()]=t++;
                    q[1].pop();
                    flag=1;
                }
                else
                {
                    flag=-1;
                    t=arr[i+1];
                }
            }
            //cout<<i<<" ";
        }
    }
    

    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";

    return 0;
}
