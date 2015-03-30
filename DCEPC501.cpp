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
LL MIN(LL a ,LL b)
{
if(a>b)
return b;
return a;
}
LL MAX(LL a,LL b)
{
if(a>b)
return a;
return b;
}
 LL dp[100009];
int main()
{
    int t;
    scanf("%d",&t);
while(t--)
{
LL i,n;
scanf("%lld",&n);
LL a[n+6];
memset(a,0,sizeof(a));
memset(dp,0,sizeof(dp));

for(i=0;i<n;i++)
    {
     scanf("%lld",&a[i]);
    }

for(i=n-1;i>=0;i--)
{
    dp[i]=MAX(a[i]+dp[i+2],MAX(a[i]+a[i+1]+dp[i+4],a[i]+a[i+1]+a[i+2]+dp[i+6]));
}
printf("%lld\n",dp[0]);
}


return 0;
}
