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
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        char adj[n+2][m+2];
        int dist[n+2][m+2];
        int i,j;
        // queue<pair<int ,int> >q;
        queue<int >qx;
        queue<int >qy;
       // printf("%d %d",n,m);
        for(i=0;i<n;i++)
        {
            scanf("%s",&adj[i]);
            //printf("%s",adj[i]);
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                adj[i][j]-=48;
            }
        }


        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                //scanf("%d",&adj[i][j]);
                dist[i][j]=99999;
                if(adj[i][j]==1)
                {
                     //q.push(make_pair(i, j));
                     qx.push(i);
                     qy.push(j);
                     dist[i][j]=0;
                }

            }
        }
        //printf("sad");
        int x,y;
        while(!qx.empty())
        {
            x= qx.front();
            y= qy.front();
            qx.pop();
            qy.pop();
            //printf("andhar");
            for(i=x-1;i<=x+1;i++)
            {
               for(j=y-1;j<=y+1;j++)
               {
                   if(!(i==x&&j==y))
                   {
                     if(i>=0&&i<n&&j>=0&&j<m)
                     {
                        if(dist[i][j]>dist[x][y]+abs(i-x)+abs(j-y))
                         {
                            dist[i][j]=dist[x][y]+abs(i-x)+abs(j-y);
                            //q.push(make_pair(i,j));
                            qx.push(i);
                            qy.push(j);
                        }
                      }
                    }
               }
            }
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("%d ",dist[i][j]);
            }
            printf("\n");
        }

    }
return 0;
}
