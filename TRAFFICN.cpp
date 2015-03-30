//bansal0301
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<cstdio>
#include<limits.h>
#include<vector>
#include<queue>
#include<ctype.h>
#include<map>
# define CASE int t;scanf("%d",&t);while(t--)
# define LL long long int
#define INF 1061109567
using namespace std;
struct edge
{
    int v;
    int w;
};
int mini( int a, int b ) { return( a > b ? b : a ); }

bool operator <( edge a, edge b )
{
    return a.w > b.w;
}

void dijkstra( vector< edge > graph[], int* dist, int s )
{
    dist[ s ] =0;
    priority_queue< edge > q;
    q.push( ( edge ) { s, 0 } );
    while ( !q.empty() ) {
        edge p = q.top();
        q.pop();
        for ( int i = 0; i < graph[ p.v ].size(); ++i )
         {
            edge k = graph[ p.v ][ i ];
            if ( dist[ p.v ] + k.w < dist[ k.v ] )
            {
                dist[ k.v ] = dist[ p.v ] + k.w;
                q.push( k );
            }
        }
    }
}
int readint() {
    int n = 0;
    char c = getchar_unlocked();
    while ( !( '0' <= c && c <= '9' ) ) {
        c = getchar_unlocked();
    }
    while ( '0' <= c && c <= '9' ) {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    return n;
}

int main() {
    int t,s, T, k, n, m, i, u, v, w;
    int fodist[ 10001 ], badist[ 10001 ];
    vector< edge > fo[ 10001 ], ba[ 10001 ];
    t = readint();
   // scanf("%d",&t);
    while ( t-- )
    {
           n = readint();
           m = readint();
           k = readint();
           s = readint();
           T = readint();
        //scanf("%d %d %d %d %d",&n,&m,&k,&s,&T);
        for ( i = 0; i <= n; ++i )
        {
            fodist[ i ] = badist[ i ] = INF;
            fo[ i ].clear();
			ba[ i ].clear();
        }
        for ( i = 0; i < m; ++i )
        {
            u = readint();
            v = readint();
            w = readint();
            //scanf("%d %d %d",&u,&v,&w);
            fo[ u ].push_back( ( edge ) { v, w } );
            ba[ v ].push_back( ( edge ) { u, w } );
        }
        dijkstra( fo, fodist, s );
        dijkstra( ba, badist, T );
        int ans = mini( fodist[ T ], badist[ s ] );
        while ( k )
        {
            u = readint();
            v = readint();
            w = readint();
            //scanf("%d %d %d",&u,&v,&w);
            ans = mini( ans, mini( fodist[ v ] + w + badist[ u ], badist[ v ] + w + fodist[ u ] ) );
            --k;
        }
        if ( ans == INF )
        {
            printf( "-1\n" );
        }
        else
        {
            printf( "%d\n", ans );
        }
    }
    return 0;
}



