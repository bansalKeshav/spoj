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
    int n,m,t1,t2,flag=0,pre=0;
    scanf("%d",&n);
    int array[n],pos[n],dp[n];

    for (int i=0; i<n; i++)
        pos[i]=0,dp[i]=0;

    for (int i=0; i<n; i++)
        scanf("%d",&array[i]);

    scanf("%d",&m);
    for (int i=0; i<m; i++)
    {
        scanf("%d %d",&t1,&t2);
        pos[t1-1]=t2;
    }
    for (int i=0; i<n; i++)
    {
        if (pos[i]!=0)
        {
            int sum=0,j,l=MAX(pre,i-pos[i]+1);
            for (j=l; j<MIN(l+pos[i],n); j++)
                sum+=array[j];
            int k=j;
            if (!flag)
            {
                dp[MIN(l+pos[i]-1,n-1)]=sum;
                flag=1;
            }
            else
                dp[MIN(l+pos[i]-1,n-1)]=sum+dp[l-1];
            for (j=MIN(l+pos[i],n); j<MIN(n,i+pos[i]); j++)
            {
                sum=(sum+array[j]-array[j-pos[i]]);
                dp[j]=MAX(dp[j-1],dp[j-pos[i]]+sum);
            }
            pre=k;
        }
        else if (i>0)
            dp[i]=MAX(dp[i],dp[i-1]);
    }

    printf("%d\n",dp[n-1]);
    return 0;
}
