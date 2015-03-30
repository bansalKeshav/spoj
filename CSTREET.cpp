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

 int adj[1002][1002];
typedef struct array
{
    int a;
    int b;
    int c;
}data;
int n;

bool arrange(data a ,data b)
{
    if(a.c==b.c)
    {
     return a.a<b.a;
    }
     return a.c<b.c;
}

int bfs(int a,int b,int adj[1002][1002])
{
    int flag=0;
  //  printf("in bfs %d %d \n",a,b);
    if(a==b)
    {
        return 1;
    }
    else
    {
        bool mark[n+2];
        memset(mark,0,sizeof(mark));
        queue<int >q;
        q.push(a);
        mark[a]=true;
        int temp;
        while(!q.empty())
        {
            temp=q.front();
            q.pop();
            if(temp==b)
            {
                flag=1;
                break;
            }
            else
            {
                for(int i=1;i<=n;i++)
                {
                    if(adj[temp][i]==1&&mark[i]!=true)
                    {
                 	q.push(i);
	   				mark[i]=true;
//	   				printf("%d %d\n",temp,i);
	   				}
                }
            }
        }
    }
    if(flag==1)
     return 1;

return 0;
}
int main()
{
CASE
{
 int p,m,ans=0;
 scanf("%d %d %d",&p,&n,&m);
 data pp[m+2];
 int visited[n+2];
 memset(visited,0,sizeof(visited));
 int u,v,w;
 for(int i=0;i<m;i++)
 {
     scanf("%d %d %d",&u,&v,&w);
     pp[i].a=MIN(u,v);
     pp[i].b=MAX(u,v);
     pp[i].c=w;
 }
 sort(pp,pp+m,arrange);
 for(int i=0;i<m;i++)
 {
     u=pp[i].a;
     v=pp[i].b;
     w=pp[i].c;
     if(visited[u]==1&&visited[v]==1)
     {
         if(bfs(u,v,adj)!=1)
         {
            adj[u][v]=1;
            adj[v][u]=1;
            ans=ans+w;
           // printf(" %d %d %d %d in bfs \n",u,v,w,ans);
         }
     }
     else
     {
         visited[u]=1;
         visited[v]=1;
         adj[u][v]=1;
         adj[v][u]=1;
         ans=ans+w;
         //printf(" %d %d %d %d \n",u,v,w,ans);
     }
 }
 printf("%d\n",ans*p);
}
return 0;
}
