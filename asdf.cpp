#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int cnt = 0, dv[10005], dt = 0;
vector<int> ans[10000];
int buf[10000];
void dfs(int n, int idx, int i) {
    if(n == 1) {
        for(i = 0; i < idx; i++)
            ans[cnt].push_back(buf[i]);
        cnt++;
        return ;
    }
    for(; i < dt; i++) {
        if((n/dv[i] >= dv[i] || n == dv[i])&& n%dv[i] == 0) {
            buf[idx] = dv[i];
            dfs(n/dv[i], idx+1, i);
        }
    }
}
int main() {
    int n;
    while(scanf("%d", &n) == 1 && n) {
        int i, sq = (int)sqrt(n);
        printf("%d\n",sq );
        dt = 0;
        for(i = 2; i <= sq; i++) {
            if(n%i == 0) {
                dv[dt++] = i;
                if(i*i != n)
                    dv[dt++] = n/i;
            }
        }
        sort(dv, dv+dt);
        for(int i=0;i<dt;i++)
            printf("%d\n",dv[i] );
    }
    return 0;
}