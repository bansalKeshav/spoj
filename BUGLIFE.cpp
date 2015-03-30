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
    int t;
    scanf("%d",&t);
for(int j=1;j<=t;j++)
{
int n,m,i,t1,t2;
scanf("%d %d",&n,&m);
int a[m+2];
memset(a,-1,sizeof(a));
pair<int ,int >p[m+2];
    for(i=0;i<m;i++)
    {
      scanf("%d %d",&t1,&t2);
      p[i].first=MIN(t1,t2);
      p[i].second=MAX(t1,t2);
    }
    sort(p,p+m);
    int flag=0;
    for(i=0;i<m;i++)
    {
      //printf("%d %d\n",p[i].first,p[i].second);
      t1=p[i].first;
      t2=p[i].second;
      if(a[t1]==-1&&a[t2]==-1)
      {
          a[t1]=0;
          a[t2]=1;
      }
      else if(a[t1]==-1&&a[t2]!=-1)
      {
          a[t1]=!a[t2];
      }
      else if(a[t1]!=-1&&a[t2]==-1)
      {
          a[t2]=!a[t1];
      }
      else if(a[t1]==a[t2])
      {
          flag=1;
          break;
      }

    }
 if(flag==1)
 {
     printf("Scenario #%d:\nSuspicious bugs found!\n",j);
 }
 else
 {
     printf("Scenario #%d:\nNo suspicious bugs found!\n",j);
 }

}


return 0;
}
