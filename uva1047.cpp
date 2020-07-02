#include <bits/stdc++.h>
using namespace std;
/*Like set but has some more functionality:
 1. Find kth smallest minimum
 2. Find the index of an element
 Does these in O(log n) time
 
 How to use:
 ordered_set<type> ss;
 ss.insert(val);
 ss.insert(val);
 ss.insert(val);

 cout<<ss.ordere_of_key(val)<<endl; // number of elements in ss less than val
 cout<<*ss.find_by_order(k)<<endl; // prints the kth smallest number in s (0-based)
*/
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
*/


#define ms(s, n) memset(s, n, sizeof(s))

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

#define mapHas(t, x) (t.find(x) != t.end()) //for map
#define vectHas(v,x) (find(v.begin(),v.end(),x)!=v.end()) //for vector
#define setHas(t,x) (t.count(x)!=0)


#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)



//bit manipulation
#define bit(n, i) (((n) >> (i)) & 1) //check bit
#define setBit(n,i) (n|=(1<<i)) //set i'th bit of n
#define checkBit(n,i) (n &(1<<i)) //check i'th bit of n
#define resetBit(n,i) (n&=~(1<<i)) //reset i'th bit of n
#define toggleBit(n,i) (n^=(1<<i)) //toggle i'th bit of n
#define lsOnBit(n) (n&(-n)) //get lsb of n that is on
#define turnOnAll(n) ((1<<n) - 1) //turn on size of n bits from right (kind of opposite of clear)
#define remainder(s,n) (s & (n-1)) //remainder of s when divided by n, where n is power of 2
#define powerOfTwo(s) ((s & (s-1)) == 0) //determine if s is a power of 2
#define turnOffLastSetBit(s) (s=(s&(s-1)))
#define turnOnLastZero(s) (s=(s|(s+1))) 
#define numLeadZero(s) __builtin_clz(s)
#define numTrailZero(s) __builtin_ctz(s)
#define numOnes(s) __builtin_popcount(s)
#define parity(s) __builtin_parity(s)


//shorthands
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vs;
const int MOD = (int) 1e9 + 7;
const int FFTMOD = 1007681537;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-6;


/*
//double comparisons and ops
//d1==d2
inline bool EQ(double d1,double d2){return fabs(d1-d2)<EPS;}
//d1>d2
inline bool GT(double d1,double d2){return (d1-d2)>EPS;}
//d1<d2
inline bool LT(double d1,double d2){return GT(d2,d1);}
//d1>=d2
inline bool GTE(double d1, double d2){return GT(d1,d2)||EQ(d1,d2);}
//d1<=d2
inline bool LTE(double d1,double d2){return LT(d1,d2)||EQ(d1,d2);}
//numPosAfterDecimal={10,100,1000,10000,....}
//Roundoff(3.56985,10000) = 3.5699
inline double Roundoff(double val,int numPosAfterDecimal){return round(val*numPosAfterDecimal)/numPosAfterDecimal;}
*/


/*//4 directional movement
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};*/

#define MAX 22

int towerCustomer[MAX];
bool permuter[MAX];



vii cMap;

int main()
{
/*The standard C++ I/O functions (cin/cout) flush the buffer 
on every next I/O call which unncecessarily increase I/O time.
For enhancing C++ I/O speed,you can either use C’s standard I/O
function (scanf/printf) instead of (cin/cout) or you can write
the following lines in main function.*/
	
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	// cout.tie(0);
	
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n,p,m,KS=0;
	vector<int>taken;
	//getNcR();

	while(cin>>n>>p){
		if(!n&&!p)break;
		//vc.clear();
		ms(permuter,0);
		cMap.clear();
		FOR(i,0,n)
			cin>>towerCustomer[i];
		cin>>m;
		FOR(i,0,m){
			int t,tt;
			cin>>t;

			int msk=0;

			while(t--){
				cin>>tt;
				setBit(msk, --tt);
			}
			cin>>tt;
			cMap.pb(mp(msk,tt));
		}

		for(int i=n-p;i<n;i++)
			permuter[i]=1;


		vector<int>ans;
		int mx=-INF;

		do{

			taken.clear();
			int total = 0;
			int curMsk = 0;
			for(int i=0;i<n;i++){
				if(permuter[i]){
					setBit(curMsk, i);
					total += towerCustomer[i];
					taken.pb(i+1);
				}
			}

			for(int i=0;i<m;i++){
				int tmp = numOnes((curMsk&cMap[i].fi));
				if(tmp>1){
					total -= (tmp-1)*cMap[i].se; 
				}
			}

			if(total>mx){
				mx = total;
				ans.clear();
				for(int i=0;i<taken.size();i++)
					ans.pb(taken[i]);
			}
			else if(total==mx){
				sort(taken.begin(), taken.end());
				sort(ans.begin(), ans.end());
				bool nr = true;
				for(int i=0;nr&&i<p;i++)
					if(taken[i]<ans[i])nr=false;
				if(!nr){
					ans.clear();
					for(int i=0;i<taken.size();i++)
						ans.pb(taken[i]);
				}
			}
		}while(next_permutation(permuter,permuter+n));

		cout<<"Case Number  "<<++KS<<endl;
		cout<<"Number of Customers: "<<mx<<endl;
		cout<<"Locations recommended:";
		for(int i=0;i<ans.size();i++)
			cout<<" "<<ans[i];
		cout<<endl<<endl;
	}
	

    return 0;
}
