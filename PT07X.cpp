//bansal0301
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include <string.h>
#include <vector>
using namespace std;
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define MAXN 100000

vector<int> adj[MAXN+2];
int n;
int dp[MAXN+2][2];

int func(int cur, int parent, bool isParentCovered)
{
 if(dp[cur][isParentCovered] != -1)
   return dp[cur][isParentCovered];

 int &ret = dp[cur][isParentCovered];
 ret = 0;
 int i, r;
 if(isParentCovered)
 {
    for(i=0;i<adj[cur].size();i++)
    {
    if(adj[cur][i] != parent)
        {
        ret += func(adj[cur][i], cur, false);
        }
    }
    r = 1;
    for(i=0;i<adj[cur].size();i++)
    {
        if(adj[cur][i] != parent)
        {
            r += func(adj[cur][i], cur, true) ;
        }
    }
    ret = min(ret, r);
}
 else
 {
  ret = 1;
  for(i=0;i<adj[cur].size();i++)
  {
  if(adj[cur][i] != parent)
   {
   ret += func(adj[cur][i], cur, true) ;
   }
  }
 }
 return ret;
}

int main()
 {
 int i,u,v;
 int r1,r2;
 scanf(" %d",&n);
  for(i=1;i<=n;i++)
  adj[i].clear();

  for(i=1;i<n;i++)
  {
   scanf(" %d %d",&u,&v);
   adj[u].push_back(v);
   adj[v].push_back(u);
   }
  memset(dp,-1,sizeof(dp));
  r1 = 1;
  for(i=0;i<adj[1].size();i++)
   r1 += func(adj[1][i], 1, true);

  r2 = 0;
  for(i=0;i<adj[1].size();i++)
   r2 += func(adj[1][i], 1, false);

  printf("%d\n",min(r1,r2));
 return 0;
}
