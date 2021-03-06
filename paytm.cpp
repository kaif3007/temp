##########################################################################
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++)
         cin>>arr[i];

     unordered_set<int> ss;

     int j=0,ans=0;

     int sum=0;

     for(int i=0;i<n;i++)
     {
        while(ss.find(arr[i])!=ss.end())
        {
            sum-=arr[j];
            ss.erase(arr[j]);
            j++;
        }

    
        ss.insert(arr[i]);
        sum+=arr[i];
        ans=max(ans,sum);
     }

     cout<<ans<<endl;

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
print all nodes at a distance k from leaf node

int cnt;
int arr[100005];

void func(Node* root,int k,int l)
{
    if(!root)
     return;
     
     if(root->left==NULL and root->right==NULL and l-k>=0 and arr[l-k]==false )
     {
             arr[l-k]=true;
             cnt++;
             return;
     }
     
     arr[l]=0;
     func(root->left,k,l+1);
     func(root->right,k,l+1);
}

int printKDistantfromLeaf(Node* root, int k)
{
    cnt=0;
    memset(arr,0,sizeof(arr));
    
    func(root,k,0);
   
	return cnt;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
closest leaf to a given node

struct node 
{ 
    int data; 
    node *left,*right; 
}; 
  

node* create(int key) 
{ 
    node* temp = new node; 
    temp->data = key; 
    temp->left =NULL;
    temp->right = NULL; 
    return temp; 
} 
 


void down(node *root, int l, int &minn) 
{ 

    if (!root) 
        return ; 
  
    if (!root->left and !root->right) 
    { 
        if (minn>l) 
            minn = l; 
        return; 
    } 
  
    down(root->left,l+1,minn); 
    down(root->right,l+1,minn); 
} 
  

int recurse(node *root, node *x, int &minn) 
{ 

    if (!root) 
        return -2; 

    if (root == x) 
        return 0; 
  
    int l = recurse(root->left, x, minn); 
  
    if (l != -2) 
    { 
        down(root->right, l+2, minn); 
        return l+1; 
    } 
  
    int r = recurse(root->right, x, minn); 
  
    if (r != -2) 
    { 
 
        down(root->left, r+2, minn); 
        return r+1; 
    } 
  
    return -2; 
} 
#############################################################################################
arrange odd even o(1) space
#############################################################################################
min cut to make palindrome

int minPalPartion(char* str) 
{ 
    // Get the length of the string 
    int n = strlen(str); 
  
    /* Create two arrays to build the solution in bottom-up manner 
       C[i] = Minimum number of cuts needed for a palindrome partitioning 
                 of substring str[0..i] 
       P[i][j] = true if substring str[i..j] is palindrome, else false 
       Note that C[i] is 0 if P[0][i] is true */
    int C[n]; 
    bool P[n][n]; 
  
    int i, j, k, L; // different looping variables 
  
    // Every substring of length 1 is a palindrome 
    for (i = 0; i < n; i++) { 
        P[i][i] = true; 
    } 
  
    /* L is substring length. Build the solution in bottom up manner by 
       considering all substrings of length starting from 2 to n. */
    for (L = 2; L <= n; L++) { 
        // For substring of length L, set different possible starting indexes 
        for (i = 0; i < n - L + 1; i++) { 
            j = i + L - 1; // Set ending index 
  
            // If L is 2, then we just need to compare two characters. Else 
            // need to check two corner characters and value of P[i+1][j-1] 
            if (L == 2) 
                P[i][j] = (str[i] == str[j]); 
            else
                P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1]; 
        } 
    } 
  
    for (i = 0; i < n; i++) 
    { 
        if (P[0][i] == true) 
            C[i] = 0; 
        else 
        { 
            C[i] = INT_MAX; 
            for (j = 0; j < i; j++)
            { 
                if (P[j + 1][i] == true && 1 + C[j] < C[i]) 
                    C[i] = 1 + C[j]; 
            } 
        } 
    } 
  
    // Return the min cut value for complete string. i.e., str[0..n-1] 
    return C[n - 1]; 
} 
#########################################################################################
max sum path between 2 leaves of a binary tree

int ans;
int recurse(Node* root)
{
    if(!root)
     return 0;
     
    int p1=recurse(root->left);
    int p2=recurse(root->right);
    
    if(root->left and root->right)
        { 
            ans=max({ans,p1+p2+root->data});
            return max(p1,p2)+root->data;
        }
        
    return root->left?p1+root->data:p2+root->data;
}

int maxPathSum(Node* root)
{ 
    ans=INT_MIN;
    recurse(root);
    
    return ans;
}

#########################################################################################
transform a to b if we can move only 1 character from a to its front

int transform (string a, string b)
    {
	    vector<int> v(300,0);
	    if(a.size()!= b.size())
	     return -1;
	    
	    for(int i=0;i<a.size();i++)
	    {
	        v[a[i]]++;
	        v[b[i]]--;
	    }
	    
	    int flag = 0;
	    for(int i=0;i<300;i++)
	    {
	        if(v[i]!=0){
	            flag = 1;
	            break;
	        }
	    }
	    
	    if(flag)
	    {
	       return -1;
	    }
	    
	    int x = a.size()-1;
	    int y = b.size()-1;
	    int ans = 0;
	    while(x>=0)
	    {
	        if(x>=0 && a[x]== b[y])
	            y--;
	        else if(x>=0 && a[x] != b[y])
	            ans++;
	        x--;
	    }
	  
	  return ans;
    }
};
