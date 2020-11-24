		                               //shubham arya
		                               //NIT Patna
                                       //check if a graph is bipertite or not without using STL and print one of the colored nodes.

#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pi pair<ll,ll>
using namespace std;
const ll MAX=1e13;
const ll MOD=1e9+7;

struct Node
{
	int data;
	struct Node *next;
};
struct list_
{
	struct Node *head;
};

struct Node *create_node(int d)
{
	struct Node *tmp=(struct Node*)malloc(sizeof(struct Node));
    tmp->data=d;
    tmp->next=NULL;
    return tmp;
}
struct Node *add_edge(int src,int dest,struct list_ *root)
{
	struct Node *tmp=create_node(dest);
	tmp->next=root[src].head;
	root[src].head=tmp;

	struct Node *tmp2=create_node(src);
	tmp2->next=root[dest].head;
	root[dest].head=tmp2;
}

void pop_q(struct Node **rt,struct Node **last)
{
	struct Node *tmp=*rt;
	if(*last==*rt)
		*last=NULL;
	*rt=tmp->next;
	tmp->next=NULL;   //breaking the link
	free(tmp);
}

int front_q(struct Node *rt)
{
	return rt->data;
}

bool bfs(int *col,int src,struct list_ *root)
{
    col[src]=1;
    struct Node *rt=NULL,*last=NULL;                      //create a linked list which will work as a queue in STL and write two functions front() and pop().
    struct Node *tmp=create_node(src);                    //*last is used to insert at last in the queue
    rt=tmp;
    last=tmp;
    while(rt!=NULL)
    {
      int x=front_q(rt);
      pop_q(&rt,&last);

      tmp=root[x].head;
      while(tmp!=NULL)
      {
      	int v=tmp->data;
      	if(col[v]==-1)
      		{
      			col[v]=1-col[x];
      			struct Node *tmp2=create_node(v);
      			if(rt==NULL)
      			{
      				rt=tmp2;
      				last=tmp2;
      			}
      			else
      			 {
                last->next=tmp2;
                last=tmp2;
             }
      		}
      	else if(col[v]==col[x])
      		return false;
      	tmp=tmp->next;
      }
    }
    free(rt);
	return true;
}
void util_bfs(struct list_ *root,int n)
{
	int *col=new int[n];
	for (int i = 0; i < n; ++i)
	col[i]=-1;

    bool flag=false;
    for (int i = 0; i < n; ++i)
    {
    	if(col[i]==-1)
    		flag=bfs(col,i,root);
    	if(flag==false) break;
    }

    if(!flag) 
    	{
    		cout<<"Graph is not bipartite\n";
            for (int i = 0; i < n; ++i)
             cout<<col[i]<<" ";
            cout<<"\n";
    	}
    else
    	{
    		cout<<"1 colored nodes:\n";
    	   for (int i = 0; i < n; ++i)
             if(col[i]==1)
             cout<<i+1<<" ";
            cout<<"\n";
    	}
   delete []col;
}
int main()
{
    int n,m;
    	cin>>n>>m;
    	struct list_ *root=(struct list_*)malloc(n*sizeof(struct list_));
    	for (int i = 0; i < n; ++i)
    		root[i].head=NULL;

    	for (int i = 0; i < m; ++i)
    	{
    		int a,b;
    		cin>>a>>b;
    		add_edge(a-1,b-1,root);
    	}
        util_bfs(root,n);  //Also works for disconnected graph
        free(root);
	return 0;
}