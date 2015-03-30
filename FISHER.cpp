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
# define INF 10000000

using namespace std;

int adj[52][52];
int toll[52][52];
int dp[52][1002];

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
   int n,T,i,j,t;
    while(1)
    {
        scanf("%d %d",&n,&T);
        if(n==0&&T==0)
         break;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            scanf("%d",&adj[i][j]);
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            scanf("%d",&toll[i][j]);
        }

        for(t=0;t<=T;t++)
         dp[1][t]=0;

         for(i=2;i<=n;i++)
         {
             for(t=0;t<=T;t++)
             dp[i][t]=INF;
         }


         for(t=0;t<=T;t++)
          {
              for(i=1;i<=n;i++)
              {
                  for(j=1;j<=n;j++)
                  {
                      if(t>0)
                       {
                           dp[i][t]=MIN(dp[i][t],dp[i][t-1]);
                       }
                       if(t-adj[j][i]>=0)
                       {
                           dp[i][t]=MIN(dp[i][t],dp[j][t-adj[j][i]]+toll[j][i]);
                       }
                  }
              }
          }

        int ans = INF;
        int min_time = INF ;
        for (int i=0; i<=T; i++)
        {
            if(dp[n][i] < ans)
            {
                ans = dp[n][i];
                min_time = i;
            }
        }
        if (min_time != INF){
            printf("%d %d\n", ans, min_time);
        }
        else {
            printf("-1\n");
        }
    }

return 0;
}

