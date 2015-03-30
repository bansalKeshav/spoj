#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;

#define Point pair<pair<int, int>, pair<char, pair<int, int> > >
#define X first.first
#define Y first.second
#define val second.first
#define time second.second.first
#define prev second.second.second
#define mp(a,b,c,d,e) make_pair(make_pair(a,b), make_pair(c,make_pair(d,e)))

int r,c,i,j,temp;
char grid[502][502],final_grid[502][502];
int vis[502][502];
queue< Point >qq;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void bfs()
{
    while(!qq.empty())
    {
        Point q=qq.front();
        qq.pop();
//        printf(" now a point %d %d %c %d %d\n",q.X,q.Y,q.val,q.time ,q.prev);

        if (grid[q.X][q.Y]=='#'||final_grid[q.X][q.Y]=='*')
            continue;

        if(q.prev!=-1)
        {
          int nx=q.X-dx[q.prev] ,ny=q.Y-dy[q.prev];
           if(final_grid[nx][ny]=='*')
            continue;
        }
        if(vis[q.X][q.Y]!=-1)
        {
            if (vis[q.X][q.Y]<q.time)
                continue;
            else if (vis[q.X][q.Y]==q.time)
            {
                if (final_grid[q.X][q.Y]!=q.val)
                    final_grid[q.X][q.Y] = '*';
                continue;
            }
        }

        vis[q.X][q.Y]=q.time;
        final_grid[q.X][q.Y]=q.val;
  //       printf("final_grid[%d][%d]=%c\n",q.X,q.Y,q.val);
        for(int i=0;i<4;i++)
        {
            int nx=q.X+dx[i] ,ny=q.Y+dy[i];
            if(nx>=0&&nx<r&&ny>=0&&ny<c&&vis[nx][ny]&&grid[nx][ny]!='#')
            {
                qq.push(mp(nx,ny,q.val,q.time+1,i));
    //            printf("push in queue %d %d %c %d \n",nx,ny,q.val,q.time+1);
            }
        }
      //  printf("\n\n");


    }
}
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  scanf("%d %d",&r,&c);
  memset(vis,-1,sizeof(vis));
   for(i=0;i<r;i++)
    {
    for(j=0;j<c;j++)
    {
        temp=getchar();
        if (temp =='#'||temp =='.'||(temp >='a'&&temp<='z'))
        {
            grid[i][j] = temp ;

            if (grid[i][j]=='.')
            final_grid[i][j] = '.';

            else if (grid[i][j]=='#')
            final_grid[i][j] = '#';

            else
            {
                final_grid[i][j] = '.';
                qq.push(mp(i,j,grid[i][j],0,-1));
            }
        }
        else j--;
    }
    }
  bfs();

  for (int i=0;i<r;i++)
    {
        final_grid[i][c] = '\0';
        printf("%s\n", final_grid[i]);
    }
    printf("\n");
 }
 return 0;
}
