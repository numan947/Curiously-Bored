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


inline void tokenize(string str,vector<string> &tokens, string delim){ tokens.clear();size_t s = str.find_first_not_of(delim), e=s; while(s!=std::string::npos){e=str.find(delim,s);tokens.push_back(str.substr(s,e-s));s=str.find_first_not_of(delim,e);}}


#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";


//getline(cin,input_string)
//gets(input_string)




int main()
{
    //freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    long long file_size;
    vector<long long> tx;
    long long s=0;

    while(true){
        tx.clear();
        cin>>file_size;
        if(file_size==0)break;
        long long cnt = 0;
        while(cnt<file_size){
            long long tmp;
            cin>>tmp;
            cnt+=tmp;
            tx.pb(tmp);
        }


        printf("Output for data set %lld, %lld bytes:\n",++s,file_size);

        long long tt=5;

        long long fs = file_size;

        while(tt<=tx.size()){
            int tr = 0;
            for(long long i=tt-1;i>=tt-5;i--)
                tr+=tx[i];

            fs-=tr;

            double bps = 1.0*tr/5.00;

            double trr = ceil(5.0*fs/tr);
            if(tr)
                printf("   Time remaining: %lld seconds\n",(long long)trr);
            else
                printf("   Time remaining: stalled\n");

            tt+=5;

        }



        printf("Total time: %lu seconds\n\n",tx.size());



    }


    return 0;
}
