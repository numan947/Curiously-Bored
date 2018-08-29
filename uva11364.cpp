#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{

    int n,m;
    int ara[30];
    scanf("%d",&n);
    for(int ij=0;ij<n;ij++){
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d",&ara[i]);
        }

        int mn=10000,mx=-100000;

        for(int i=0;i<m;i++){
            mn = min(ara[i],mn);
            mx = max(ara[i],mx);
        }

        printf("%d\n",2*(mx-mn));
    }

}
