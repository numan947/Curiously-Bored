#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define pconent(t, x) (t.find(x) != t.end())


#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second


#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int FFTMOD = 1007681537;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-6;


inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;} //gcd
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;} //lcm
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;} //nth power
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}  //add mod
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}  //sub mod

inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}  //check sqrt
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}  //check cbrt
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";



int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;

    while(scanf("%d", &n)){
        if(n==0)break;

        printf("Printing order for %d pages:\n",n);

        int pages = n%4==0?n/4:n/4+1;

        int fp = 1;
        int bp = 4*pages;



        for(int i=1;i<=pages;i++)
        {
            printf("Sheet %d, front: ",i);
            if(bp>0&&bp<=n)printf("%d, ",bp);
            else printf("Blank, ");
            bp--;
            printf("%d\n",fp);
            fp++;

            if(fp<=n){
                printf("Sheet %d, back : ",i);

                printf("%d, ",fp);
                fp++;

                if(bp>0&&bp<=n)printf("%d\n",bp);
                else printf("Blank\n");
                bp--;

            }





        }






    }


}




