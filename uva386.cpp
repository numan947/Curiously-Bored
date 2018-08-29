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
	// freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	set<set<int> >st;

	st.clear();

	for(int i=2;i<=200;i++){
		st.clear();
		ll ti = i*i*i;
		for(int j=2;j<=130;j++){
			ll tj = j*j*j;
			if(tj>=ti)
				break;
			for(int k=2;k<=150;k++){
				ll tk=k*k*k;
				if(tk+tj>=ti)
					break;
				for(int l=2;l<=200;l++){
					ll tl=l*l*l;
					if(ti==tj+tk+tl){
						set<int>tmp;
						tmp.insert(j);
						tmp.insert(k);
						tmp.insert(l);

						if(st.insert(tmp).se)
							// printf("\"Cube = %d, Triple = (%d,%d,%d)\\n\"\n",i,j,k,l);
							printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
					}
					else if(tj+tk+tl>ti)
						break;
				}
			}
		}
	}
	

// 	printf("Cube = 6, Triple = (3,4,5)\n"
// "Cube = 12, Triple = (6,8,10)\n"
// "Cube = 18, Triple = (2,12,16)\n"
// "Cube = 18, Triple = (9,12,15)\n"
// "Cube = 19, Triple = (3,10,18)\n"
// "Cube = 20, Triple = (7,14,17)\n"
// "Cube = 24, Triple = (12,16,20)\n"
// "Cube = 25, Triple = (4,17,22)\n"
// "Cube = 27, Triple = (3,18,24)\n"
// "Cube = 28, Triple = (18,19,21)\n"
// "Cube = 29, Triple = (11,15,27)\n"
// "Cube = 30, Triple = (15,20,25)\n"
// "Cube = 36, Triple = (4,24,32)\n"
// "Cube = 36, Triple = (18,24,30)\n"
// "Cube = 38, Triple = (6,20,36)\n"
// "Cube = 40, Triple = (14,28,34)\n"
// "Cube = 41, Triple = (2,17,40)\n"
// "Cube = 41, Triple = (6,32,33)\n"
// "Cube = 42, Triple = (21,28,35)\n"
// "Cube = 44, Triple = (16,23,41)\n"
// "Cube = 45, Triple = (5,30,40)\n"
// "Cube = 46, Triple = (3,36,37)\n"
// "Cube = 46, Triple = (27,30,37)\n"
// "Cube = 48, Triple = (24,32,40)\n"
// "Cube = 50, Triple = (8,34,44)\n"
// "Cube = 53, Triple = (29,34,44)\n"
// "Cube = 54, Triple = (6,36,48)\n"
// "Cube = 54, Triple = (12,19,53)\n"
// "Cube = 54, Triple = (27,36,45)\n"
// "Cube = 56, Triple = (36,38,42)\n"
// "Cube = 57, Triple = (9,30,54)\n"
// "Cube = 58, Triple = (15,42,49)\n"
// "Cube = 58, Triple = (22,30,54)\n"
// "Cube = 60, Triple = (21,42,51)\n"
// "Cube = 60, Triple = (30,40,50)\n"
// "Cube = 63, Triple = (7,42,56)\n"
// "Cube = 66, Triple = (33,44,55)\n"
// "Cube = 67, Triple = (22,51,54)\n"
// "Cube = 69, Triple = (36,38,61)\n"
// "Cube = 70, Triple = (7,54,57)\n"
// "Cube = 71, Triple = (14,23,70)\n"
// "Cube = 72, Triple = (8,48,64)\n"
// "Cube = 72, Triple = (34,39,65)\n"
// "Cube = 72, Triple = (36,48,60)\n"
// "Cube = 75, Triple = (12,51,66)\n"
// "Cube = 75, Triple = (38,43,66)\n"
// "Cube = 76, Triple = (12,40,72)\n"
// "Cube = 76, Triple = (31,33,72)\n"
// "Cube = 78, Triple = (39,52,65)\n"
// "Cube = 80, Triple = (28,56,68)\n"
// "Cube = 81, Triple = (9,54,72)\n"
// "Cube = 81, Triple = (25,48,74)\n"
// "Cube = 82, Triple = (4,34,80)\n"
// "Cube = 82, Triple = (12,64,66)\n"
// "Cube = 82, Triple = (19,60,69)\n"
// "Cube = 84, Triple = (28,53,75)\n"
// "Cube = 84, Triple = (42,56,70)\n"
// "Cube = 84, Triple = (54,57,63)\n"
// "Cube = 85, Triple = (50,61,64)\n"
// "Cube = 87, Triple = (20,54,79)\n"
// "Cube = 87, Triple = (26,55,78)\n"
// "Cube = 87, Triple = (33,45,81)\n"
// "Cube = 87, Triple = (38,48,79)\n"
// "Cube = 88, Triple = (21,43,84)\n"
// "Cube = 88, Triple = (25,31,86)\n"
// "Cube = 88, Triple = (32,46,82)\n"
// "Cube = 89, Triple = (17,40,86)\n"
// "Cube = 90, Triple = (10,60,80)\n"
// "Cube = 90, Triple = (25,38,87)\n"
// "Cube = 90, Triple = (45,60,75)\n"
// "Cube = 90, Triple = (58,59,69)\n"
// "Cube = 92, Triple = (6,72,74)\n"
// "Cube = 92, Triple = (54,60,74)\n"
// "Cube = 93, Triple = (32,54,85)\n"
// "Cube = 95, Triple = (15,50,90)\n"
// "Cube = 96, Triple = (19,53,90)\n"
// "Cube = 96, Triple = (48,64,80)\n"
// "Cube = 97, Triple = (45,69,79)\n"
// "Cube = 99, Triple = (11,66,88)\n"
// "Cube = 100, Triple = (16,68,88)\n"
// "Cube = 100, Triple = (35,70,85)\n"
// "Cube = 102, Triple = (51,68,85)\n"
// "Cube = 103, Triple = (12,31,102)\n"
// "Cube = 105, Triple = (33,70,92)\n"
// "Cube = 106, Triple = (58,68,88)\n"
// "Cube = 108, Triple = (12,72,96)\n"
// "Cube = 108, Triple = (13,51,104)\n"
// "Cube = 108, Triple = (15,82,89)\n"
// "Cube = 108, Triple = (24,38,106)\n"
// "Cube = 108, Triple = (54,72,90)\n"
// "Cube = 110, Triple = (29,75,96)\n"
// "Cube = 111, Triple = (16,47,108)\n"
// "Cube = 112, Triple = (72,76,84)\n"
// "Cube = 113, Triple = (50,74,97)\n"
// "Cube = 114, Triple = (18,60,108)\n"
// "Cube = 114, Triple = (57,76,95)\n"
// "Cube = 115, Triple = (3,34,114)\n"
// "Cube = 116, Triple = (23,86,97)\n"
// "Cube = 116, Triple = (30,84,98)\n"
// "Cube = 116, Triple = (44,60,108)\n"
// "Cube = 117, Triple = (13,78,104)\n"
// "Cube = 120, Triple = (9,55,116)\n"
// "Cube = 120, Triple = (42,84,102)\n"
// "Cube = 120, Triple = (60,80,100)\n"
// "Cube = 121, Triple = (49,84,102)\n"
// "Cube = 122, Triple = (19,92,101)\n"
// "Cube = 123, Triple = (6,51,120)\n"
// "Cube = 123, Triple = (18,96,99)\n"
// "Cube = 123, Triple = (44,51,118)\n"
// "Cube = 125, Triple = (20,85,110)\n"
// "Cube = 126, Triple = (14,84,112)\n"
// "Cube = 126, Triple = (23,94,105)\n"
// "Cube = 126, Triple = (63,84,105)\n"
// "Cube = 127, Triple = (13,65,121)\n"
// "Cube = 129, Triple = (38,57,124)\n"
// "Cube = 132, Triple = (5,76,123)\n"
// "Cube = 132, Triple = (48,69,123)\n"
// "Cube = 132, Triple = (66,88,110)\n"
// "Cube = 133, Triple = (21,70,126)\n"
// "Cube = 134, Triple = (44,102,108)\n"
// "Cube = 134, Triple = (86,95,97)\n"
// "Cube = 135, Triple = (15,90,120)\n"
// "Cube = 137, Triple = (44,73,128)\n"
// "Cube = 138, Triple = (9,108,111)\n"
// "Cube = 138, Triple = (69,92,115)\n"
// "Cube = 138, Triple = (72,76,122)\n"
// "Cube = 138, Triple = (81,90,111)\n"
// "Cube = 139, Triple = (94,96,99)\n"
// "Cube = 140, Triple = (14,108,114)\n"
// "Cube = 140, Triple = (49,98,119)\n"
// "Cube = 140, Triple = (90,95,105)\n"
// "Cube = 141, Triple = (72,85,122)\n"
// "Cube = 142, Triple = (28,46,140)\n"
// "Cube = 142, Triple = (31,64,137)\n"
// "Cube = 144, Triple = (16,96,128)\n"
// "Cube = 144, Triple = (68,78,130)\n"
// "Cube = 144, Triple = (72,96,120)\n"
// "Cube = 145, Triple = (12,81,136)\n"
// "Cube = 145, Triple = (55,75,135)\n"
// "Cube = 147, Triple = (22,75,140)\n"
// "Cube = 150, Triple = (24,102,132)\n"
// "Cube = 150, Triple = (71,73,138)\n"
// "Cube = 150, Triple = (75,100,125)\n"
// "Cube = 150, Triple = (76,86,132)\n"
// "Cube = 151, Triple = (46,47,148)\n"
// "Cube = 152, Triple = (24,80,144)\n"
// "Cube = 152, Triple = (62,66,144)\n"
// "Cube = 153, Triple = (17,102,136)\n"
// "Cube = 156, Triple = (65,87,142)\n"
// "Cube = 156, Triple = (78,104,130)\n"
// "Cube = 159, Triple = (3,121,131)\n"
// "Cube = 159, Triple = (87,102,132)\n"
// "Cube = 160, Triple = (56,112,136)\n"
// "Cube = 160, Triple = (69,123,124)\n"
// "Cube = 162, Triple = (18,108,144)\n"
// "Cube = 162, Triple = (36,57,159)\n"
// "Cube = 162, Triple = (50,96,148)\n"
// "Cube = 162, Triple = (59,93,148)\n"
// "Cube = 162, Triple = (81,108,135)\n"
// "Cube = 164, Triple = (8,68,160)\n"
// "Cube = 164, Triple = (24,128,132)\n"
// "Cube = 164, Triple = (38,120,138)\n"
// "Cube = 164, Triple = (69,99,146)\n"
// "Cube = 167, Triple = (12,86,159)\n"
// "Cube = 168, Triple = (56,106,150)\n"
// "Cube = 168, Triple = (84,112,140)\n"
// "Cube = 168, Triple = (108,114,126)\n"
// "Cube = 170, Triple = (96,107,141)\n"
// "Cube = 170, Triple = (100,122,128)\n"
// "Cube = 171, Triple = (19,114,152)\n"
// "Cube = 171, Triple = (27,90,162)\n"
// "Cube = 171, Triple = (54,80,163)\n"
// "Cube = 171, Triple = (107,108,136)\n"
// "Cube = 174, Triple = (40,108,158)\n"
// "Cube = 174, Triple = (45,126,147)\n"
// "Cube = 174, Triple = (47,97,162)\n"
// "Cube = 174, Triple = (52,110,156)\n"
// "Cube = 174, Triple = (66,90,162)\n"
// "Cube = 174, Triple = (76,96,158)\n"
// "Cube = 174, Triple = (87,116,145)\n"
// "Cube = 175, Triple = (28,119,154)\n"
// "Cube = 176, Triple = (25,92,167)\n"
// "Cube = 176, Triple = (42,86,168)\n"
// "Cube = 176, Triple = (50,62,172)\n"
// "Cube = 176, Triple = (64,92,164)\n"
// "Cube = 177, Triple = (48,137,142)\n"
// "Cube = 178, Triple = (34,80,172)\n"
// "Cube = 178, Triple = (48,133,147)\n"
// "Cube = 179, Triple = (17,57,177)\n"
// "Cube = 180, Triple = (20,120,160)\n"
// "Cube = 180, Triple = (50,76,174)\n"
// "Cube = 180, Triple = (63,126,153)\n"
// "Cube = 180, Triple = (90,120,150)\n"
// "Cube = 180, Triple = (116,118,138)\n"
// "Cube = 181, Triple = (108,109,150)\n"
// "Cube = 184, Triple = (12,144,148)\n"
// "Cube = 184, Triple = (108,120,148)\n"
// "Cube = 185, Triple = (57,68,180)\n"
// "Cube = 185, Triple = (68,113,166)\n"
// "Cube = 186, Triple = (18,121,167)\n"
// "Cube = 186, Triple = (64,108,170)\n"
// "Cube = 186, Triple = (93,124,155)\n"
// "Cube = 187, Triple = (58,131,160)\n"
// "Cube = 188, Triple = (115,122,149)\n"
// "Cube = 189, Triple = (21,46,188)\n"
// "Cube = 189, Triple = (21,126,168)\n"
// "Cube = 190, Triple = (30,100,180)\n"
// "Cube = 190, Triple = (56,133,163)\n"
// "Cube = 191, Triple = (39,146,156)\n"
// "Cube = 192, Triple = (34,123,173)\n"
// "Cube = 192, Triple = (38,106,180)\n"
// "Cube = 192, Triple = (96,128,160)\n"
// "Cube = 193, Triple = (25,68,190)\n"
// "Cube = 194, Triple = (90,138,158)\n"
// "Cube = 196, Triple = (126,133,147)\n"
// "Cube = 197, Triple = (53,58,194)\n"
// "Cube = 198, Triple = (22,132,176)\n"
// "Cube = 198, Triple = (27,46,197)\n"
// "Cube = 198, Triple = (73,135,170)\n"
// "Cube = 198, Triple = (99,132,165)\n"
// "Cube = 199, Triple = (6,127,180)\n"
// "Cube = 200, Triple = (32,136,176)\n"
// "Cube = 200, Triple = (70,140,170)\n");

    return 0;
}
