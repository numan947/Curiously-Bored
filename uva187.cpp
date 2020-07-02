#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <iostream>
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



// stoi(string)
// atoi(char*)
// atof(char*)
// stof(string)

typedef struct transaction
{
    int t_n;
    int a_n;
    ll money;
}tn;



string find_name(vector<pair<int,string> >vis,int acc)
{
    string toret = "";
    for(int i=0;i<vis.size();i++)
        if(vis[i].fi==acc){
            toret += vis[i].se;
            break;
        }
//
//    db(toret.size());endln;
//    db(30-toret.size());endln;

    int tg = 30-toret.size();

    for(int i=0;i<tg;i++)
        toret+=" ";
//    db(toret.size());endln;


    return toret;
}


int main()
{

    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string input_buff;

    vector<pair<int,string> >vis;

    vector<tn>vtn;;

    //part1 input
    while(true)
    {
        getline(cin,input_buff);

        string acc_no = input_buff.substr(0,3);
        string acc_name = input_buff.substr(3);

        if(acc_no=="000")break;


        vis.pb(mp(stoi(acc_no),acc_name));

    }

    //part2 input
    while(true)
    {
        getline(cin,input_buff);
        if(input_buff.substr(0,3)=="000")break;

        tn t;
        t.t_n=stoi(input_buff.substr(0,3));
        t.a_n=stoi(input_buff.substr(3,3));
        t.money = stol(input_buff.substr(6));

        vtn.pb(t);

    }

    //processing

    char buff[200];

    int p = 0;

    int ctn = vtn[0].t_n;

    long long imbalance = 0;

    vector<tn>ctnv;


    while(p<vtn.size())
    {
        if(ctn==vtn[p].t_n){
            imbalance+=vtn[p].money;
            ctnv.pb(vtn[p]);
            p++;
        }
        else{
            if(imbalance){
                printf("*** Transaction %3d is out of balance ***\n",ctn);
                for(int i=0;i<ctnv.size();i++)
                {
                    printf("%3d %s %10.2lf\n",ctnv[i].a_n,find_name(vis,ctnv[i].a_n).c_str(),ctnv[i].money*1.00/100.0f);
                }

                printf("999 Out of Balance                 %10.2lf\n\n",-imbalance*1.00/100.0);

//                printf("%d\n",strlen("Out of Balance                "));
            }

            ctn = vtn[p].t_n;
            ctnv.clear();
            imbalance=0;


        }





    }








    return 0;
}
