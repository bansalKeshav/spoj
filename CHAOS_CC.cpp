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
int a[5000];
a[3]=1;
a[4]=1;
a[5]=1;
a[6]=2;
a[7]=2;
a[8]=2;
for(int i=9;i<5000;i++)
{
    if(a[i-3]==2||a[i-4]==2||a[i-5]==2)
    {
        a[i]=1;
    }
    else
    {
        a[i]=2;
    }
}
CASE
{
int n;
scanf("%d",&n);
if(a[n]==1)
{
    printf("Joker\n");
}
else
{
    printf("Bane\n");
}
}


return 0;
}
