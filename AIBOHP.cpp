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
int n,i,j,k;
char str[5005],rev_str[5005];
int dp[5001][2];
CASE
{
scanf("%s",str);
n=strlen(str);

for(i=0;i<n;i++)
	rev_str[i]=str[n-i-1];

for(i=0;i<=n;i++)
	{
	for(j=0;j<=n;j++)
		{
		if(i==0 || j==0)
			dp[j][1]=0;

		else if(str[i-1]==rev_str[j-1])
			dp[j][1] = dp[j-1][0]+1;

		else
			dp[j][1] = max(dp[j][0],dp[j-1][1]);
		}

	for(j=0;j<=n;j++)
		dp[j][0]=dp[j][1];
	}

printf("%d\n",n-dp[n][0]);
}
return 0;
}
