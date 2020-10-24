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
