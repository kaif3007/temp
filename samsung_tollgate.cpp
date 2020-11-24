		                               //shubham arya
		                               //NIT Patna
                                       //samsung ....tollgate
#include <bits/stdc++.h>
#include<time.h>
#define ll long long int
#define mp make_pair
#define pi pair<ll,ll>
using namespace std;
const ll MAX=1e13;
const ll MOD=1e9+7;
int n,cost[25],men[25];
int fans=INT_MAX;


void dfs(int i,int b3,int b2,int b1,int cc)
{
	int tm=b3+b2+b1;
	if(cc>fans) return; //Avoid extra calling of dfs
	if(i==n-1)
	{
      if(tm<men[i]) cc+=cost[i];
      fans=min(fans,cc);
      return;
	}
	dfs(i+1,b3,b2,b1,cc+cost[i]); //pay the toll
	dfs(i+1,b3+men[i],b2,b1,cc+2*cost[i]); //hire and double pay
    if(tm>=men[i])   //battle condition
    {
    	if(b1+b2<men[i]) //No need to write it because we don't need b3 more.(ie, it was the last chance of hired men of a particular gate as b3)
    	{
    		b3=tm-men[i];
    		b2=0;b1=0;
    	}
    	else if(b1<men[i])
    	{
    		b2=b2+b1-men[i];
    		b1=0;
    	}
    	dfs(i+1,0,b3,b2,cc);
    }
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	/*clock_t start, end;
 double cpu_time_used;
 start = clock();*/
	while(t--)
	{
        cin>>n;
        for (int i = 0; i < n; ++i)
        {
        	cin>>men[i]>>cost[i];
        }
        dfs(0,0,0,0,0);
        cout<<fans<<endl;
        fans=INT_MAX;
	}
	/*end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<"time used:"<<cpu_time_used<<endl;*/
	return 0;
}
/*
5
7
10 100 
70 5
80 15
20 60
50 90
30 80
10 10       
9
600 800 
300 400
300 400
1000 400
300 600
100 300
600 300
600 500
1000 300
11
1000 10
700 900
400 500
300 10
900 900
300 10 
50 900
50 900 
700 900
500 900
50 10
20
896 546
543 216
454 310
408 367
40 602
252 582
954 627
850 234
763 479
232 278
301 538
528 508
936 154
629 443
758 336
432 700
882 256
278 738
517 882
317 136
20 
410 610
831 909
675 629
421 774
386 869
544 219
492 414
996 557
499 482
231 285
804 978
304 881
489 911
75 315
927 648
252 914
330 396
937 133
495 882
813 717

// output1=150
// output2=3000
// output3=2370
// output4=4721
// output5=8231
*/