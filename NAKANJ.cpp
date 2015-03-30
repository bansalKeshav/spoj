#include<stdio.h>
#include<memory.h>
#include<queue>
using namespace std;
int visited[12][12],dist[12][12];
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  char t1[3],t2[3];
  int sx,sy,dx,dy,i,j;

  memset(visited,1,sizeof(visited));
  memset(dist,10000,sizeof(dist));
  for(i=1;i<=8;i++)
  {
      for(j=1;j<=8;j++)
      {
          visited[i][j]=0;
      }
  }
  scanf("%s %s",&t1,&t2);
  sx=t1[0]-96;
  dx=t2[0]-96;
  sy=t1[1]-48;
  dy=t2[1]-48;
  if(sx==dx&&sy==dy)
   {
    printf("0\n");
   }
   else
   {
    queue<int >qx;
    queue<int >qy;
    qx.push(sx);
    qy.push(sy);
    visited[sx][sy]=1;
    dist[sx][sy]=0;
    while(!qx.empty())
    {
        sx=qx.front();
        sy=qy.front();
        qx.pop();
        qy.pop();
        // printf(" ab bta %d%d %d%d\n",sx,sy,dx,dy);
        if(sx==dx&&sy==dy)
        {
            printf("%d\n",dist[sx][sy]);
            break;
        }

       if(visited[sx+2][sy-1]==0&&(sy-1)>0)
       {
           qx.push(sx+2);
           qy.push(sy-1);
           visited[sx+2][sy-1]=1;
           dist[sx+2][sy-1]=dist[sx][sy]+1;
       }
       if(visited[sx+2][sy+1]==0)
       {
           qx.push(sx+2);
           qy.push(sy+1);
           visited[sx+2][sy+1]=1;
           dist[sx+2][sy+1]=dist[sx][sy]+1;
       }

       if(visited[sx-2][sy-1]==0&&(sx-2)>0&&(sy-1)>0)
       {
           qx.push(sx-2);
           qy.push(sy-1);
           visited[sx-2][sy-1]=1;
           dist[sx-2][sy-1]=dist[sx][sy]+1;
       }
       if(visited[sx-2][sy+1]==0&&(sx-2)>0)
       {
           qx.push(sx-2);
           qy.push(sy+1);
           visited[sx-2][sy+1]=1;
           dist[sx-2][sy+1]=dist[sx][sy]+1;
       }

       if(visited[sx+1][sy+2]==0)
       {
           qx.push(sx+1);
           qy.push(sy+2);
           visited[sx+1][sy+2]=1;
           dist[sx+1][sy+2]=dist[sx][sy]+1;
       }
       if(visited[sx-1][sy+2]==0&&(sx-1)>0)
       {
           qx.push(sx-1);
           qy.push(sy+2);
           visited[sx-1][sy+2]=1;
           dist[sx-1][sy+2]=dist[sx][sy]+1;
       }
       if(visited[sx+1][sy-2]==0&&(sy-2)>0)
       {
           qx.push(sx+1);
           qy.push(sy-2);
           visited[sx+1][sy-2]=1;
           dist[sx+1][sy-2]=dist[sx][sy]+1;
       }
       if(visited[sx-1][sy-2]==0&&(sx-1)>0&&(sy-2)>0)
       {
           qx.push(sx-1);
           qy.push(sy-2);
           visited[sx-1][sy-2]=1;
           dist[sx-1][sy-2]=dist[sx][sy]+1;
       }

    }
    if(sx!=dx&&sy!=dy)
    {
        printf("this will not display\n");
    }
  }
    /* while(!qx.empty())
	   qx.pop();
     while(!qy.empty())
	   qy.pop();
     */

 }
 return 0;
}
