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
	while(scanf("%i", &n)!=EOF)
	{
		LL arr[n+2], a[n+2][n+2], s[n+2][n+2];
		LL l,i,j,k;
		for(int i=1; i<=n; i++)
			scanf("%lld", &arr[i]);
		for(i=1;i<=n+1;i++)
		{
		    for(j=1;j<=n+1;j++)
		    {
		        if(i==j)
		        {
		        a[i][j]=0;
		        s[i][j]=arr[i];
		        }
		        else
		        a[i][j]=INT_MAX;
		    }
		}
		for(l=2;l<=n;l++)
		{
		    for(i=1;i<=n-l+1;i++)
		    {
		        j=i+l-1;
		        int flag=0;
		        for(k=i;k<j;k++)
		        {
		            a[i][j]=MIN((s[i][k]*s[k+1][j])+(a[i][k]+a[k+1][j]),a[i][j]);
		            if(flag==0)
		            {
		                s[i][j]=(s[i][k]+s[k+1][j])%100;
		                flag=1;
		            }

		        }
		    }
		}
		printf("%lld\n",a[1][n]);
	}

return 0;
}
