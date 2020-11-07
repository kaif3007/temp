##############################################################################################
  PALINDROMIC ARRAY:-
#############################################################################################

  int n;
  cin>>n;

  int arr[n];
  for(int i=0;i<n;i++)
     cin>>arr[i];

  vector<int> sol;

  int i=0,j=n-1;
  while(i<j)
  {
      if(arr[i]==arr[j])
      {
         sol.push_back(arr[i]);
         i++;
         j--;
      }
      else if(arr[i]<arr[j])
      {
         i++;
         arr[i]+=arr[i-1];
      }
      else
      {
         j--;
         arr[j]+=arr[j+1];
      }
  }

  if(i==j)
    sol.push_back(arr[i]);

  for(int i=0;i<sol.size();i++)
    cout<<sol[i]<<" ";

  int cnt=sol.size()-1;
  if(cnt%2)
     cnt--;

   while(cnt>=0)
   {
      cout<<sol[cnt]<<" ";
      cnt--;
   }
##################################################################################################

