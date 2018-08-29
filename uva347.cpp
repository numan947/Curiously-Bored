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
#define sz(a) int((a).size())
#define contains(t, x) (t.find(x) != t.end()) //for map
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

//some common functions
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;} //gcd
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;} //lcm
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;} //nth power
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}  //add mod
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}  //sub mod
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}  //check sqrt
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}  //check cbrt

//some helper functions for input processing
inline void tokenize(string str,vector<string> &tokens, string delim){ tokens.clear();size_t s = str.find_first_not_of(delim), e=s; while(s!=std::string::npos){e=str.find(delim,s);tokens.push_back(str.substr(s,e-s));s=str.find_first_not_of(delim,e);}}
inline bool isPalindrome(string str){for(int i=0;i<(str.size())/2;i++)if(str[i]!=str[str.size()-1-i])return false;return true;}
inline string customStrip(string in,string delim){string ret = "";for(int i=0;i<in.size();i++){if(delim.find(in[i],0)==std::string::npos)ret+=in[i];}return ret;}
inline string commaSeparate(long long value){string numWithCommas = to_string(value);int insertPosition = numWithCommas.length() - 3;while (insertPosition > 0) {numWithCommas.insert(insertPosition, ",");insertPosition-=3;}return numWithCommas;}
inline string strip(string s){int i=0;while(i<s.size()){if(isspace(s[i]))i++;else break;}s.erase(0,i);i = s.size()-1;while(i>=0){if(isspace(s[i]))i--;else break;}s.erase(i+1,s.size()-i-1);return s;}

//errors
#define db(x) cerr << #x << " = " << (x) << "\n";
#define endl '\n'

/*
//double comparisons
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
*/

/*//4 directional movement
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};*/

#define MAX 12

int d[]={1000000,100000,10000,1000,100,10,1};


bool isRunAround(ll num,int sz)
{
	int digitMask = 0;
	int unqdgtMask = 0;
	int cur = 0;

	while(true){
		if(bit(digitMask,cur))
			break;
		else
			setBit(digitMask, cur);
		ll tmp = num/d[7+cur-sz];
		int dig = tmp%10;
		if(bit(unqdgtMask,dig))
			return false;
		setBit(unqdgtMask, dig);
		cur+=dig;
		cur%=sz;
	}
	if(digitMask==((1<<(sz))-1) && cur==0)
		return true;
	return false;
}

int getLen(ll num)
{
	int c = 0;
	while(num>0){
		num/=10;
		c++;
	}
	return c;
}

int allSol[] = {9682415,9625814,9625184,9612485,9582461,9581426,9568124,9561824,9518426,9512468,9485261,9468251,9461258,9425681,9425618,9415268,8951246,8946125,8942561,8941526,8596124,8526194,8496251,8426951,8251946,8249561,8246195,8241596,8194256,8149625,8142695,8124956,6958142,6951842,6895124,6894152,6825194,6824159,6819425,6812495,6258149,6251849,6195824,6194852,6189425,6182495,6125894,6124859,5968241,5961248,5894612,5824619,5814962,5814269,5681942,5681249,5618942,5618249,5268941,5261948,5194682,5184962,5184269,5124689,4962581,4962518,4956812,4956182,4859612,4852619,4689512,4682519,4619582,4612589,4269581,4269518,4256819,4256189,4159682,4152689,2695814,2695184,2689415,2619485,2589461,2581496,2568194,2561894,2519468,2518496,2495681,2495618,2485961,2468951,2461958,2415968,1958246,1948526,1946825,1942568,1894256,1849625,1842695,1824956,1596824,1526894,1496258,1426958,1258946,1249568,1248596,1246895,974835,974235,973485,973425,953748,953742,953148,953142,948537,948531,942537,942531,914835,914235,913485,913425,895374,895314,859734,859134,853794,853194,835974,835914,794853,794253,748953,748359,742953,742359,734859,734259,597483,597423,597348,597342,591483,591423,591348,591342,537948,537942,537489,537429,531948,531942,531489,531429,489537,489531,485973,485913,485379,485319,483597,483591,429537,429531,425973,425913,425379,425319,423597,423591,379485,379425,374895,374295,359748,359742,359148,359142,348597,348591,342597,342591,319485,319425,314895,314295,295374,295314,259734,259134,253794,253194,235974,235914,194853,194253,148953,148359,142953,142359,134859,134259,97842,97428,97423,97342,96834,96384,96172,96127,94683,94638,94183,94138,92847,92478,92473,92347,91834,91672,91627,91384,89742,89463,89413,89247,86731,86317,86312,86231,84963,84913,84792,84297,83946,83941,83496,83491,81736,81367,81362,81236,79612,79284,79234,79162,78924,78631,78429,78136,74612,74289,74239,74162,73924,73681,73429,73186,72961,72916,72461,72416,68394,68349,68173,68123,67813,67318,67291,67241,63894,63849,63178,63128,62813,62791,62741,62318,61729,61724,61279,61274,49683,49638,49183,49138,47928,47923,47892,47392,46839,46389,46172,46127,42978,42973,42897,42397,41839,41672,41627,41389,39742,39468,39418,39247,38946,38941,38496,38491,36817,36812,36781,36281,34968,34918,34792,34297,31867,31862,31786,31286,29784,29734,29617,29167,28974,28631,28479,28136,27961,27916,27461,27416,24789,24739,24617,24167,23974,23681,23479,23186,18673,18623,18394,18349,17863,17368,17296,17246,16729,16724,16279,16274,13894,13849,13678,13628,12863,12796,12746,12368,9627,9623,9267,9263,7962,7926,7562,7526,7162,7126,6792,6752,6712,6392,6352,6312,6279,6275,6271,6239,6235,6231,5627,5623,5267,5263,3962,3926,3562,3526,3162,3126,2796,2756,2716,2679,2675,2671,2639,2635,2631,2396,2356,2316,1627,1623,1267,1263,852,825,741,714,582,528,471,417,285,258,174,147,97,95,93,91,79,75,73,71,59,57,53,51,39,37,35,31,19,17,15,13};

int main()
{
/*The standard C++ I/O functions (cin/cout) flush the buffer 
on every next I/O call which unncecessarily increase I/O time.
For enhancing C++ I/O speed,you can either use C’s standard I/O
function (scanf/printf) instead of (cin/cout) or you can write
the following lines in main function.*/
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);


	//cout<<d[0]<<endl;


	// cout<<getLen(12)<<endl;
	// cout<<isRunAround(12,2)<<endl;

/*	for(ll i = 9682415;i>9;i--)
	{
		if(isRunAround(i, getLen(i))){
			allSol[i] = i;
			cout<<i<<",";
		}
		else
			allSol[i] = allSol[i+1];
	}*/
	
//	cout<<endl;
	ll inp,KASE = 0;



	while(cin>>inp){
		if(!inp)break;
		if(inp>9682415)
			cout<<"Case "<<++KASE<<": "<<0<<endl;
		else{
			int t = upper_bound(allSol,allSol+448,inp,greater<int>())-allSol-1;
			cout<<"Case "<<++KASE<<": "<<allSol[t]<<endl;
		}
	}
	

    return 0;
}
