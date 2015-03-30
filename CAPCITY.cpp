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
LL n,m,i,u,v;
int flag=0;
scanf("%lld %lld",&n,&m);
vector<LL>from[n+2],to[n+2];
LL src,cc,temp;
bool visited[n+2];
for(i=0;i<m;i++)
{
 scanf("%lld %lld",&u,&v);
 from[u].push_back(v);
 to[v].push_back(u);
}
for(i=1;i<=n;i++)
{
    queue<LL >Q;
    src=i;
    LL k=0;
    memset(visited,0,sizeof(visited));
    Q.push(src);
    visited[src]=1;
    while(!Q.empty())
    {
        temp=Q.front();
        Q.pop();
        for(LL itr=0;itr<to[temp].size();itr++)
        {
            if(visited[to[temp][itr]]==0)
            {
                Q.push(to[temp][itr]);
                k++;
                visited[to[temp][itr]]=1;
            }
        }
    }
//    cout<<i<<" "<<k<<endl;

    if(k>=n-1)
    {
//        cout<<k<<endl;
        src=i;
        flag=1;
        break;
    }
}
//cout<<"src="<<src<<endl;
if(flag!=1)
{
    printf("0\n");
}
else
{
    vector<LL>ans;
    queue<LL >Q;
    memset(visited,0,sizeof(visited));
    Q.push(src);
    ans.push_back(src);
    visited[src]=1;
    while(!Q.empty())
    {
        temp=Q.front();
        Q.pop();
        for(LL itr=0;itr<from[temp].size();itr++)
        {
            if(visited[from[temp][itr]]==0)
            {
                Q.push(from[temp][itr]);
                ans.push_back(from[temp][itr]);
                visited[from[temp][itr]]=1;
            }
        }
    }
    sort (ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
return 0;
}
