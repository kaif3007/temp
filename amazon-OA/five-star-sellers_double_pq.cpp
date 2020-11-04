Before we add more five star reviews, the percentage
for this seller is ((4/4) + (1/2) + (3/6))/3 = 66.66%
If we add a five star review to 2nd product, ((4/4) + (2/3) + (3/6))/3 = 72.22%
If we add another five star review to 2nd product, ((4/4) + (3/4) + (3/6))/3 = 75%
If we add a five star review to 3rd product, ((4/4) + (3/4) + (4/7))/3 = 77.38%
At this point, 77% (threshold) is met. Therefore, answer is 3 (because that is the minimum five 
star reviews we need to add, to get the seller reach the threshold).
################################################################################################################

 
#include <bits/stdc++.h>
using namespace std;

double gain(vector<pair<int,int> >& rating,int p)
{
     int n=rating.size();

     double a=rating[p].first,b=rating[p].second;
     return (a*1.0+1.0)/((b+1.0)*n*1.0)-(a*1.0)/(b*n*1.0);

}

int main()
{
    double thresh;
    cin>>thresh;

    thresh/=100.0;
    priority_queue< pair<double,int> > pq;
    int n;
    cin>>n;

    vector< pair<int,int> > ratings(n);

    for(int i=0;i<n;i++)
    {
         int a,b;
         cin>>a>>b;
         ratings[i]={a,b};
    }

    double ans=0.0;

    for(int i=0;i<n;i++)
    {
        pq.push({gain(ratings,i),i});
        ans+=(ratings[i].first*1.0)/(ratings[i].second*1.0);
    }

    int cnt=0;
    ans/=n;


    while(ans<thresh)
    {
        pair<double,int> p=pq.top();
        ans+=p.first;
        pq.pop();

        cnt++;
        ratings[p.second].first++;
        ratings[p.second].second++;
        //cout<<ans<<endl;

        pq.push({gain(ratings,p.second),p.second});
    }

    cout<<cnt;



    return 0;
}
