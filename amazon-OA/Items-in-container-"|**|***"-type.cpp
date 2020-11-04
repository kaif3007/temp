s = '|**|*|*'

startIndices = [1, 1]

endIndices = [5, 6]

The string has a total of 2 closed compartments, one with 2 items and one with 1 item. For the first pair of
indices, (1, 5), the substring is '|**|*'. There are 2 items in a compartment.

For the second pair of indices, (1, 6), the substring is '|**|*|' and there are 2 + 1 = 3 items in compartments.

Both of the answers are returned in an array, [2, 3].


#########################################################3
#include <bits/stdc++.h>
using namespace std;

 
int main()
{

    string s;
    cin>>s;

    int n=s.length();
    int pre[n];
    memset(pre,0,sizeof(pre));

    int cnt=0,flag=0;
    for(int i=0;i<n;i++)
    {
        if(flag)
        {
            if(s[i]=='*')
                cnt++;
             else
             {
                pre[i]=cnt;
                cnt=0;
             }
        }
        else if(s[i]=='|')
            flag=1;
    }

    for(int i=1;i<n;i++)
        pre[i]+=pre[i-1];

    int q;
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;

        int ans=pre[b-1];
        if(a>1)
            ans-=pre[a-2];

        cout<<ans<<endl;
    }


    return 0;
}
