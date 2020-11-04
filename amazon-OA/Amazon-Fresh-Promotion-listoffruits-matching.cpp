Input: codeList = [[apple, apple], [banana, anything, banana]] shoppingCart = [orange, apple, apple, banana, orange, banana]
Output: 1
Explanation:
codeList contains two groups - [apple, apple] and [banana, anything, banana].
The second group contains 'anything' so any fruit can be ordered in place of 'anything' in the shoppingCart. 
The customer is a winner as the customer has added fruits in the order of fruits in the groups and the order of groups in the codeList is also 
maintained in the shoppingCart.


#################################################################################
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
#define mod 1000000007
int main()
{

    vector<vector<string> > list;

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        vector<string> v(m);
        for(int j=0;j<m;j++)
            cin>>v[j];

        list.push_back(v);
    }

    if(n==0)
    {
        cout<<1;
        return 0;
    }


    int y;
    cin>>y;

    if(y==0)
    {
        cout<<0;
        return 0;
    }

    vector<string> cart(y);
    for(int i=0;i<y;i++)
        cin>>cart[i];

    int i=0,j=0;
    while(j<y and i<n)
    {
          int k=0,l=j;
          while(k<list[i].size() and ((list[i][k]==cart[l]) or list[i][k]=="anything"))
          {
             k++;
             l++;
          }

          if(k==list[i].size())
          {
                j=l;
                i++;
          }
          else
          {
             j++;
          }

    }

    if(i==n)
        cout<<1;
    else
        cout<<0;


    return 0;
}
