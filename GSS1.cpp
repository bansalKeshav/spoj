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
int main()
{
int n;
scanf("%d",&n);
int a[n+2];
a[0]=0;
for(int i=1;i<=n;i++)
{
    if(a[i]>0)
    {
        a[i]=a[i-1]+a[i];
    }
    else
     a[i]=a[i-1];
}
int m,x,y;
scanf("%d",&m);
for(int i=0;i<m;i++)
{

}
return 0;
}
