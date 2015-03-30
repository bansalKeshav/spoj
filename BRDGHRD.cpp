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

struct dna
{
    int a,b;
};
bool arrange(struct dna p1,struct dna p2)
{
    if(p1.a==p2.a)
     return p1.b<p2.b;

    return p1.a<p2.a;
}


int index(int A[], int l, int h, int key)
{
    int mid;

    while( h - l > 1 )
    {
        mid = l + (h - l)/2;
        (A[mid] > key ? h : l) = mid;
    }

    return h;
}

int LIS(int A[], int size)
{
    int *tailTable   = new int[size];
    int len; // always points empty slot
    memset(tailTable, 0, sizeof(tailTable[0])*size);
    tailTable[0] = A[0];
    len = 1;
    for( int i = 1; i < size; i++ )
    {
        if( A[i] < tailTable[0] )
            tailTable[0] = A[i];
        else if( A[i] >= tailTable[len-1] )
            tailTable[len++] = A[i];
        else
            tailTable[index(tailTable, -1, len-1, A[i])] = A[i];
    }

    delete[] tailTable;
    return len;
}
int fun(dna arr[],int n)
{
    int i,j;
    sort(arr,arr+n,arrange);
    int A[n+2],index[n+2];
    /*for(i=0;i<n;i++)
    {
        index[arr[i].a]=i;
    }*/
    for(i=0;i<n;i++)
    {
        A[i]=arr[i].b;
    }

 /*for(i=0;i<n;i++)
    {
      printf("%d ",arr[i].a);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
      printf("%d ",arr[i].b);
    }
    printf("\n");
*/
    /*for(i=1;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(arr[i].b>arr[j].b&&lis[i]<lis[j]+1)
             lis[i]=lis[j]+1;
        }
    }*/
    if(n==1)
    {
        return 1;
    }
    return LIS(A, n);
}
int main()
{
CASE
{
int n,i;
scanf("%d",&n);
dna arr[n+2];
 for(i=0;i<n;i++)
    {
      scanf("%d",&arr[i].a);
    }
    for(i=0;i<n;i++)
    {
      scanf("%d",&arr[i].b);
    }
  cout<<fun(arr,n)<<endl;
}


return 0;
}

