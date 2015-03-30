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

struct city
{
    int x;
    int y;
};


bool arrange(struct city p1,struct city p2)
{
    if(p1.x==p2.x)
    {
        return p1.y<p2.y;
    }
    else
     return p1.x<p2.x;
}


int dp(struct city pair[],int n)
{
    int i,j,max=0;
    int lis[n+2];
    sort(pair,pair+n,arrange);
/*
    for(int i=0;i<n;i++)
     {
          cout<<pair[i].x;
     }
     cout<<endl;
     for(int i=0;i<n;i++)
     {
          cout<<pair[i].y;
     }
*/


     for(i=0;i<n;i++)
     lis[i]=1;

     for(i=0;i<n;i++)
     {
         for(j=0;j<i;j++)
         {
             if((pair[j].y<=pair[i].y)&&(lis[i]<lis[j]+1))
             {
                 lis[i]=lis[j]+1;
             }
         }

     }

     for(i=0;i<n;i++)
      max=MAX(max,lis[i]);

return max;

}


int main()
{
CASE
{
 int n;
 cin>>n;
 struct city pair[n+2];

 for(int i=0;i<n;i++)
  cin>>pair[i].x;
 for(int i=0;i<n;i++)
  cin>>pair[i].y;


cout<<dp(pair,n)<<endl;

}


return 0;
}
