#include<algorithm>
#include<cstdio>
 
using namespace std;
 
// distance, gallon capacity, mpg, cost of first filling
double d, g, mpg, c;
// station distance, station cost
double sd[100], sc[100];
int n; // number of gas stations
 
double simul(double distance, int station) {
    if(distance + g * mpg >= d || station == n)
        return 0;
    
    printf("%lf\n",g);
    double best = 1000000;
    for(int i = station; i < n; i++) {
        double fuel_used = (sd[i] - distance) / mpg;
        if(g - fuel_used < 0) break;
        if(g - fuel_used <= g / 2.0) {
            best = min(best, 200 + fuel_used * sc[i] + simul(sd[i], i + 1));
        } else if(g - fuel_used > g / 2.0 && i + 1 < n && sd[i + 1] > distance + g * mpg) {
            return 200 + fuel_used * sc[i] + simul(sd[i], i + 1);
        }
    }
 
    return best;
}
 
int main() {
    freopen("input.txt", "r", stdin);
    for(int T = 1;; T++) {
        scanf("%lf", &d);
        if(d == -1) break;
        scanf("%lf %lf %lf %d", &g, &mpg, &c, &n);
        for(int i = 0; i < n; i++)
            scanf("%lf %lf", &sd[i], &sc[i]);
        printf("Data Set #%d\n", T);
        printf("minimum cost = $%.2f\n", c + simul(0, 0)/100);
    }
}