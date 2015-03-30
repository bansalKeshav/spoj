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
char adj[110][110];
char pre[]={"ALLIZZWELL"};
int r,c;
int visited[110][110];

int dfs(int x,int y,int itr)
{
   //printf("%d %d",r,c);
   //printf("%d %d %d\n",x,y,itr);
    int i,j;
    if(itr==10)
    {
        return 1;
    }
    int ans=0;
    //printf("%d %d\n",r,c);
    for(i=x-1;i<=x+1;i++)
            {
               for(j=y-1;j<=y+1;j++)
               {
                   if(!(i==x&&j==y))
                   {
                     if(i>=0&&i<r&&j>=0&&j<c)
                     {
                       // printf("%d %d\n",i,j);
                       if(pre[itr]==adj[i][j]&&visited[i][j]==0)
                        {
                            visited[i][j]=1;
                           if( dfs(i,j,itr+1))
                           {
                               return 1;
                           }
                           visited[i][j]=0;
                        }
                     }
                    }
               }
      //         if(flag==1)    break;
            }
    //return flag;
    return 0;
}



int main()
{
int t;
scanf(" %d",&t);
//printf("%s",pre);
while(t--)
{
 int i,j;
 scanf("%d %d",&r,&c);
 memset(adj,1,sizeof(adj));
for(i=0;i<r;i++)
 {
     scanf("%s",&adj[i]);
 }
 int flag=0;
 for(i=0;i<r;i++)
 {
     for(j=0;j<c;j++)
     {
         if(adj[i][j]==pre[0])
         {
            memset(visited,0,sizeof(visited));
            visited[i][j]=1;
           if( dfs(i,j,1))
            {
                flag=1;
                break;
            }

         }
     }
     if(flag==1)
     break;
 }

if(flag==1)
{
    printf("YES\n");
}
else
{
    printf("NO\n");
}


}
 return 0;
}
