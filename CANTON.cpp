#include<stdio.h>
#include<iostream>
using namespace std;
long long int a[1000][1000];
void precompute()
{
    long long int i,j;
    a[1][1]=1;
    for(j=2;j<1000;j++)
    {
        if(j%2==0)
          a[1][j]=a[1][j-1]+1;
        else
         a[1][j]=a[1][j-1]+2*(j-1);
         //cout<<a[1][j]<<" ";
    }
    cout<<a[1][999]<<endl;
    for(i=2;i<1000;i++)
    {
        if(i%2!=0)
          a[i][1]=a[i-1][1]+1;
        else
         a[i][1]=a[i-1][1]+2*(i-1);
        // cout<<a[i][1]<<endl;
    }
    cout<<a[999][1]<<endl;
    for(i=2;i<15;i++)
    {
        for(j=2;j<15;j++)
        {
            if(i%2==0)
            {
                if(j%2==0)
                {
                    a[i][j]=a[i-1][j+1]-1;
                    cout<<a[i][j]<<" ";
                }
                else
                {
                    a[i][j]=a[i-1][j+1]+1;
                    cout<<a[i][j]<<" ";
                }
            }
            else
            {
                if(j%2!=0)
                {
                    a[i][j]=a[i-1][j+1]-1;
                    cout<<a[i][j]<<" ";
                }
                else
                {
                    a[i][j]=a[i-1][j+1]+1;
                    cout<<a[i][j]<<" ";
                }
            }
        }
        cout<<endl;
    }
}
void find(long long int n)
{
    long long int i=1,j=999;
     //printf("hghg %d",n);
    while(a[i][j]!=n)
    {
        if(a[i][j]==n)
        {
            printf("%d/%d",i,j);
            break;
        }
        if(a[i+1][j]>n)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
 precompute();
 int t;
 long long int n;
 scanf("%d",&t);
 while(t--)
 {
  //scanf("%lld",&n);
  //find(n);
 }
 return 0;
}
