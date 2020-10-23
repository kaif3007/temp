###########################################################
// input  -> a string
//output  -> all words having length closest to avg. length of input string

vector<string> closest_words(string s)
{
    vector<int> v;
    vector<string> words;

    int n=s.size();

    int i=0;
    int tot=0;

    //separate all words and store their length in v along with words in words vector
    while(i<n)
    {
        int j=i;

        while(j<n and s[j]!=' ')
            j++;

        if(j>i)
        {
            tot+=j-i;
            v.push_back(j-i);
            words.push_back(s.substr(i,j-i));
        }

        i=j+1;
    }

    
    //find minimum difference
    int mindiff=1e9;
    for(int i=0;i<v.size();i++)
    {
        if(abs(((int)v.size())*v[i]-tot)<mindiff)
             mindiff=abs(((int)v.size())*v[i]-tot);
    }


    //put all words that satisfy mindiff

    vector<string> sol;
    for(int i=0;i<v.size();i++)
    {
        if(abs(((int)v.size())*v[i]-tot)==mindiff)
             sol.push_back(words[i]);
    }

    return sol;
}


##############################################################

void cousin_parents(Node* root)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int u=q.size();
        // map will store equal sum pairs at this level
        map<int,vector<int> > mm;

        for(int i=0;i<u;i++)
        {
            Node* p=q.front();
            q.pop();

            int sum=0;
            if(p->left)
            {
                sum+=p->left->val;
                q.push(p->left);
            }
            if(p->right)
            {
                sum+=p->right->val;
                q.push(p->right);
            }
 
            mm[sum].push_back(p->val);
        }

        cout<<"At this level, pairs are:"<<endl;

        for(auto it=mm.begin();it!=mm.end();it++)
        {
            vector<int> v=it->second;
            if(v.size()==1)
                continue;

            //all pairs having sum equal to it->first;

            cout<<"Having sum "<<it->first<<endl;
            for(int i=0;i<v.size();i++)
                for(int j=i+1;j<v.size();j++)
                    cout<<v[i]<<" "<<v[j];

                cout<<endl<<endl;
            
        }
    }
}
############################################################################
//Node is a node of doubly linked list having fields next, prev,and val;
void reversell(Node* &n)
{
    //null or only 1 node
    if(n==NULL or n->next==NULL)
        return;

    Node* tmp=n,*pre=NULL;

    while(tmp!=NULL)
    {
        Node* nxt=tmp->next;

        tmp->prev=nxt;
        tmp->next=pre;

        pre=tmp;
        tmp=nxt;
    }

    //adjust head
     n=pre;

    return;
}

######################################################
//find if A and B are identical
bool isidentical(Node* A,Node* B)
{
     if(A==NULL and B==NULL)
        return 1;
     if(A==NULL or B==NULL)
        return 0;

    return (A->val==B->val) and isidentical(A->left,B->left) and isidentical(A->right,B->right);
     
}



bool issubtree(Node* A,Node* B)
{
    if(B==NULL)
        return true;

    if(A==NULL)
         return false;

    if(isidentical(A,B))
        return true;

    return issubtree(A->left,B) or issubtree(A->right,B);
}
#####################################################

//find if A and B are child of same parent
bool issibling(Node* T,Node* A,Node* B)
{
     if(T==NULL)
        return 0;

     return (T->left==A and T->right==B) or (T->left==B and T->right==A) or issibling(T->left,A,B)
     or issibling(T->right,A,B);
}

//find level of a node
void level(Node* T,Node* A,int l,int &ans)
{
    if(T==NULL)
        return;

    if(T==A)
         ans=l;

    level(T->left,A,l+1);
    level(T->right,A,l+1);
}


bool iscousin(Node* T,Node* A,Node* B)
{
    int la,lb;
    level(N,A,0,la);
    level(N,B,0,lb);

//must be at same level and must not be siblings
    return la==lb and !issibling(T,A,B);
}


#####################################################

int maxdiff(vector<vector<int> >&arr)
{ 
     int n,m;
     n=arr.size();
     m=arr[0].size();
    
    int max_horiz=-1e9,max_vert=-1e9,max_diag=-1e9;
    int min_horiz=1e9,min_vert=1e9,min_diag=1e9;

 //horizontal lines
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<m;j++)
            sum+=arr[i][j];

        max_horiz=max(max_horiz,sum);
        min_horiz=min(min_horiz,sum);
    }

//vertical lines
    for(int i=0;i<m;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
            sum+=arr[j][i];

        max_vert=max(max_vert,sum);
        min_vert=min(min_vert,sum);
    }

//diagonal lines
    for(int i=0;i<n;i++)
    {
        int r=0,c=i;
        int sum=0;
        while(r<n and c<m)
        {
            sum+=arr[r][c];
            r++;
            c++;
        }
        max_diag=max(max_diag,sum);
        min_diag=min(min_diag,sum);
    }

    for(int i=0;i<n;i++)
    {
        int r=i,c=0;
        int sum=0;
        while(r<n and c<m)
        {
            sum+=arr[r][c];
            r++;
            c++;
        }
        max_diag=max(max_diag,sum);
        min_diag=min(min_diag,sum);
    }

    return max({max_horiz,max_diag,max_vert})-min({min_horiz,min_diag,min_vert});

}
    
##############################################
