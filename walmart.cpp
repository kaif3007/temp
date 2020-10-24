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
