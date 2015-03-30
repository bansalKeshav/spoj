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
    LL ans;
CASE
{
 int i,j,n,k,T;
 scanf("%d %d %d",&T,&n,&k);
 int dp[n+2][k+2][2];
 memset(dp,0,sizeof(dp));
 dp[0][0][0]=1;
 dp[0][0][1]=1;
 for(i=1;i<n;i++)
        {
            for(j=0;j<=k;j++)
            {

                    dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
                    if(j>0)
                        dp[i][j][1]=dp[i-1][j-1][1];

                    dp[i][j][1]+=dp[i-1][j][0];

            }
        }
        ans=dp[n-1][k][0]+dp[n-1][k][1];
        cout<<T<<" "<<ans<<endl;

}


return 0;
}
