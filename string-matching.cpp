###################
Brute force
###################

#include<bits/stdc++.h>
#define ll long long int

using namespace std;


string arr[1005];

void process(string &s) 
{
    for(char &c: s) 
    {
        if(c=='o')  
          c = 'a';
        else if(c=='l')
          c = 't';
    }
}

bool match_subsequence(string& h,string& t)
{
	int p=0,q=0;
	while(p<h.length() and q<t.length())
	{
		if(h[p]==t[q])
		{
			p++;
			q++;
		}
		else
			p++;
	}

	if(q==t.length())
		 return true;

    return false;
}


int main()
{

    int n;
    cin>>n;
    string s;
    cin>>s;

    process(s);

    for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		process(arr[i]);
	}

    int k;
    cin>>k;

    int ans=0;
    for(int i=0;i<n;i++)
    {
    	
    	vector<string> v;
    	//erase 1 char at every pos and store in vector v
    	v.push_back(arr[i]);
    	for(int j=0;j<arr[i].length();j++)
    	{   
    		string h=arr[i];
    		v.push_back(h.erase(j,1));
    	}

   
    	bool flag=0;
    	for(int j=0;j<v.size();j++)
    	{
    		string t=v[j];
    		//cout<<t<<endl;
    		//matched
    		if(k>=t.length())
    		{
    			flag=1;
    			break;
    		}

    		for(int x=0;x<=s.length()-(t.length()+k);x++)
    		{
    			
    			string h=s.substr(x,k+t.length());
    			//cout<<i<<" "<<h<<" "<<t<<endl;
    			
    			if(match_subsequence(h,t))
                   {
                   	 flag=1;
                   	 break;
                   }
    		}

    		if(flag)
    			break;
    	}

    	if(flag)
    		ans++;
    }
    	
    

    cout<<ans<<"\n";
    
    return 0;
}



######################################################################################################################################
#include<bits/stdc++.h>
#define pb push_back 
#define ff first
#define ss second
#define MOD 1000000007
#define ll long long int

using namespace std;


string arr[1005];

void process(string &s) 
{
    for(char &c: s) 
    {
        if(c=='o' )  
          c = 'a';
        else if(c=='l')
          c = 't';
    }
}


int dp[205][205][2];


int main()
{

    int N;
    cin>>N;
    string t; 
    cin>>t; 
    process(t);

    for(int i=0;i<N;i++)  
    {
      cin>>arr[i];
      process(arr[i]);
    }

    int K; 
    cin>>K;

    int m = t.length();
    int ans = 0;

    for(int k=0;k<N;k++) 
    {
        string s = arr[k];
        int n = s.length();
            //base case
        for(int j=0;j<=m;j++)
         dp[0][j][0] = dp[0][j][1] = j;

        for(int i=0;i<=n;i++)
         dp[i][0][0] = dp[i][0][1] = MOD;

         dp[1][0][1] = 0;
        //bottom up
        for(int i=1;i<=n;i++)
        { 
           for(int j=1;j<=m;j++) 
           {
            if(s[i-1]==t[j-1])
            {
                dp[i][j][0] =  dp[i-1][j-1][0];
                dp[i][j][1] =  dp[i-1][j-1][1];
            } 
            else
            {
                dp[i][j][0] =  dp[i][j-1][0] + 1;
                dp[i][j][1] =  min(dp[i-1][j][0],dp[i][j-1][1] + 1);
            }
          }
        }

      

        bool poss = 0;
        for(int k=1;k<=m;k++)
        {
             if(dp[n][k][1]<MOD) 
             {
                int i = n, j = k;
                while(i!=0)
                 {
                    if(s[i-1]==t[j-1]) 
                        i = i-1, j = j-1;
                    else 
                    {
                        if(dp[i-1][j][0]<=dp[i][j-1][1] + 1)
                            i = i-1;
                          else 
                            j = j-1;
                        
                    }
                }
                if(dp[n][k][1]-j<=K)
                {
                    
                    poss = 1; 
                    break;
                }
            }
        }

        ans+=poss;
    }

    cout<<ans<<endl;
 
    return 0;
}
