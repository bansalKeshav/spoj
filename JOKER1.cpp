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

#define MAX 67
#define ll long long
#define MOD 1000000007
using namespace std;

int arr[MAX];

int main(){
    int t;
    int N;
    ll ans ;
    cin >> t;
    while (t--)
    {
        ans = 1;
        scanf("%d",&N);
        for (int i=0; i<N; i++)
        {
            scanf("%d",&arr[i]);
        }
        sort(arr, arr + N);
        for (int i=0; i<N; i++)
        {
            ans = (ans * (arr[i]-i))%MOD;
        }
        cout << ans << endl;
    }
    cout << "KILL BATMAN\n";
    return 0;
}
