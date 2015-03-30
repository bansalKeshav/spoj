//bansal0301
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<vector>
#include<queue>
#include<ctype.h>
#include<map>
# define CASE int t;scanf("%d",&t);while(t--)
# define LL long long int
using namespace std;
int MIN(int a ,int b)
{
if(a>b)
return b;
return a;
}
int MAX(int a,int b)
{
if(a>b)
return a;
return b;
}

class _x{
 public: int s, e, p,m;
	}VAL[10005];
int N;

int comp(class _x a, class _x b ){
	return b.e>a.e;
}

int lesserlater(int s, int e, int x)
{
//	cout << s << ' ' << e << ' ' << x << endl;
 	if(s==e)
		return s;
	if(e>N)
		return -1;
	int m=(s+e)/2;
	//cout << m << '*' << VAL[m].e << ' ' << VAL[m+1].e << endl;
	if(VAL[m].e < x)
	{
		if( VAL[m+1].e >= x )
			return m;
		else
			return lesserlater(m+1, e,x);
	}
	else if( VAL[m].e >= x )
			return lesserlater(s, m, x);
}

int main ()
{

CASE
{
	cin >> N;
	for(int i=1;i<=N;i++)
	{
		cin >> VAL[i].s >> VAL[i].e >> VAL[i].p;
		VAL[i].e+=VAL[i].s;
    }
		sort(VAL,VAL+N+1, comp);
	for(int j=1;j<=N;j++)
	{
        int k=lesserlater(0,j,VAL[j].s);
		VAL[j].p+=VAL[k].p;
		if(VAL[j].p<VAL[j-1].p)
			VAL[j].p=VAL[j-1].p;
    }
	cout << VAL[N].p << endl;
}
return 0;
}
