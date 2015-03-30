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
int n,m,i,j,x,y;
scanf("%d %d",&n,&m);
int a[n+2][m+2];
scanf("%d %d",&x,&y);

for(i=1;i<=n;i++)
{
  for(j=1;j<=m;j++)
  {
    scanf("%d",&a[i][j]);
  }
}
for(i=x+1;i<=n;i++)
{
    a[i][y]=a[i-1][y]-a[i][y];
}
for(j=y+1;j<=m;j++)
{
    a[x][j]=a[x][j-1]-a[x][j];
}

for(i=x+1;i<=n;i++)
{
    for(j=y+1;j<=m;j++)
    {
        a[i][j]=MAX(a[i-1][j],a[i][j-1])-a[i][j];
    }
}
/*
for(i=1;i<=n;i++)
{
  for(j=1;j<=m;j++)
  {
    printf("%d ",a[i][j]);
  }
  printf("\n");
}
*/
if(a[n][m]>=0)
{
    printf("Y %d\n",a[n][m]);
}
else
{
    printf("N \n");
}

return 0;
}
