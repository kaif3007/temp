#######################################################################
CANDY SHOPS

#include "bits/stdc++.h"
#define ll  long long int
#define BUCKET_SIZE (int)sqrt(100000*1.0)+1
#define MAX = 100000;
#define mod 1e9+7



using namespace std;


class Node
{
public:
    ll wt,val,csum;

     Node(ll wt,ll val)
      {
        this->wt = wt;
        this->val = val;
        csum = 0;
    }

};

bool comp(Node* n1,Node* n2)
{
    return n1->wt<n2->wt;
}

 void build_bucket(int i, vector<vector<Node*>> buckets) 
 {

    sort(buckets[i].begin(),buckets[i].end(),comp);

    for(int j=0;j<buckets[i].size();++j) 
    {
        if (j > 0) 
            buckets[i][j]->csum = buckets[i][j]->val + buckets[i][j-1]->csum;
        else 
            buckets[i][j]->csum = buckets[i][j]->val;
    }
}

 ll upperBound(vector<Node*> bucket, int low, ll w) 
 {

    int high=bucket.size();
    while (low<high){
        int mid=(low+high)>>1;
        if(bucket[mid]->wt<=w){
            low=mid+1;
        }else{
            high=mid;
        }
    }

    low--;
    if(low>-1)
        return bucket[low]->csum;
    return 0L;
}


 int main()
 {

    int n,q;
    cin>>n>>q;

    ll* wt=new ll[n];
    ll* val=new ll[n];
    ll* wt_copy=new ll[n];

    for(int i=0;i<n;++i)
    {
        cin>>wt[i];
        wt_copy[i]=wt[i];
    }

    for(int i=0;i<n;++i)
        cin>>val[i];
    

    vector<vector<Node*> > buckets(BUCKET_SIZE);

    for(int i=0;i<n;++i)
        buckets[i/BUCKET_SIZE].push_back(new Node(wt[i],val[i]));
    


    for(int i=0;i<BUCKET_SIZE;++i)
        build_bucket(i,buckets);
    
    while (q>0)
    {
        int t; 
        cin>>t;
        if(t==1)
        {
            ll ans=0;
            int l, r;
            ll w;
            cin>>l>>r>>w;
            l-=1;r-=1;

            int RL=l/BUCKET_SIZE,RR=r/BUCKET_SIZE;
            if(RL==RR)
            {
                for(int i=l;i<=r;++i)
                    if(wt[i]<=w)
                        ans+=val[i];
            }
            else
            {
                int end=(RL+1)*BUCKET_SIZE-1;
                for(int i=l;i<=min(end,n-1);++i)
                {
                    if(wt[i]<=w)
                        ans+=val[i];
                }
                for(int i=RL+1;i<RR;++i)
                    ans+=upperBound(buckets[i],0,w);
                
                for(int i=RR*BUCKET_SIZE;i<=r;++i)
                {
                    if(wt[i]<=w)
                        ans+=val[i];
                }
            }
            cout<<ans<<endl;
        }
        else
        {
            int idx,type;
            cin>>idx>>type;

            idx-=1;

            int BB=idx/BUCKET_SIZE;
            int end=(BB+1)*BUCKET_SIZE-1;
            int start=end-(BUCKET_SIZE-1);
            if(type==0)
                wt[idx]=INT_MAX;
            else
                wt[idx]=wt_copy[idx];
            

            for(int i=start;i<=min(end,n-1);++i)
                buckets[BB].push_back(new Node(wt[i],val[i]));
            
            build_bucket(BB,buckets);
        }

        q--;
    }

}
#########################################################################################################
https://leetcode.com/discuss/interview-question/684944/walmart-labs-oa-question

string s;
     cin>>s;

     int n=s.length();
     int dp[n][n];

     for(int i=0;i<n;i++)
        dp[i][i]=1;

    for(int l=2;l<=n;l++) 
    {
        for(int i=0;i<=n-l;i++)
         {
            int j = i+l-1;
            string substr = s.substr(i,l);
            
                dp[i][j]=l;
               
                for(int k = i; k<j;k++) 
                {
                    if(dp[i][k] + dp[k+1][j]< dp[i][j])
                        dp[i][j] = dp[i][k] + dp[k+1][j];
                    
                }
                
                for(int k=1;k<l;k++)
                {
                    string repeatStr = substr.substr(0,k);
                    
                    if(l%k == 0)
                    {
                          string kaif="";
                          int cnt= l/k;
                          for(int g=0;g<cnt;g++)
                            kaif+=repeatStr;

                        if(kaif==substr)
                        {
                           int ss = dp[i][i+k-1];
                          if(ss< dp[i][j]) 
                            dp[i][j] = ss;
                        }
                          
                    }
                }
            }
        }
    
    
    cout<<dp[0][s.length()-1];
############################################################################################################
FAKE PALINDROME

    string s;
    cin>>s;

    map<int,int> mm;
    mm[0]=1;

    int mask=0;
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        int idx=s[i]-'a';
        if(mask&(1<<idx))
            mask&=(~(1<<idx));
        else
            mask|=(1<<idx);
        
        ans+=mm[mask];
        for(int j=0;j<26;j++)
        {
            int val=(1<<j);
            ans+=mm[val^mask];
        }

        mm[mask]++;
    }

    cout<<ans<<endl;
################################################################################################################
