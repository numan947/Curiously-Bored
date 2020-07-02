#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define contains(t, x) (t.find(x) != t.end())


#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second


#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)

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


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
typedef pair<string, string> ps;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<string> vs;
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
inline bool isPalindrome(string str){for(int i=0;i<(str.size())/2;i++)if(str[i]!=str[str.size()-1-i])return false;return true;}
inline string customStrip(string in,string delim){string ret = "";for(int i=0;i<in.size();i++){if(delim.find(in[i],0)==std::string::npos)ret+=in[i];}return ret;}
inline string commaSeparate(long long value){string numWithCommas = to_string(value);int insertPosition = numWithCommas.length() - 3;while (insertPosition > 0) {numWithCommas.insert(insertPosition, ",");insertPosition-=3;}return numWithCommas;}
inline string strip(string s){int i=0;while(i<s.size()){if(isspace(s[i]))i++;else break;}s.erase(0,i);i = s.size()-1;while(i>=0){if(isspace(s[i]))i--;else break;}s.erase(i+1,s.size()-i-1);return s;}



#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";
#define endl '\n'

/*The standard C++ I/O functions (cin/cout) flush the buffer 
on every next I/O call which unncecessarily increase I/O time.
For enhancing C++ I/O speed,you can either use C’s standard I/O
function (scanf/printf) instead of (cin/cout) or you can write
the following lines in main function.*/
// ios_base::sync_with_stdio(0);
// cin.tie(0);
// cout.tie(0);

//getline(cin,input_string)
//gets(input_string)

#define MX 105


int position[MX][MX];

int scores[MX];

int W[MX];
int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int g,p;
	int s,k,x;
	
	while(true){
		cin>>g>>p;
		if(!g&&!p)break;

		FOR(i,0,g){
			FOR(j,1,p+1){
				cin>>x;
				position[i][x]=j;
			}
		}

		cin>>s;

		FOR(i,0,s){
			cin>>k;
			FOR(ii,0,p+1)scores[ii]=0;
			FOR(j,1,k+1){
				cin>>x;
				FOR(k,0,g){
					int cur = position[k][j];
					scores[cur]+=x;
				}
			}
			int sz=0;
			W[sz++]=1;

			FOR(j,2,p+1){
				if(scores[j]>scores[W[0]]){
					sz=0;
					W[sz++]=j;
				}
				else if(scores[j]==scores[W[0]])
					W[sz++]=j;
			}

			FOR(j,0,sz){
				if(j)cout<<' ';
				cout<<W[j];
			}
			cout<<endl;
		}



	}
	

    return 0;
}


/*int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int g,p;
	int s,k;
	
	while(true){
		cin>>g>>p;
		if(!g&&!p)break;
		
		
		FOR(i,0,g)
			FOR(j,0,p)cin>>position[i][j];

		cin>>s;
		FOR(i,0,s){
			cin>>k;
			FOR(j,0,k){
				cin>>stm[i][j];
			
			}
		}
		vi winners;
		

		FOR(kk,0,s){
			FOR(i,0,p)scores[i]=0;
			winners.clear();
			int maxPoint=-50000;
			FOR(i,0,g){
				FOR(j,0,p){

					if((position[i][j]-1)<k){
						scores[j]+=stm[kk][position[i][j]-1];
						maxPoint=max(maxPoint,scores[j]);
					}
				}
			}

			FOR(i,0,p)
				if(maxPoint==scores[i])winners.pb(i+1);
			sort(winners.begin(),winners.end());
			cout<<winners[0];
			FOR(i,1,winners.size())cout<<" "<<winners[i];
			cout<<endl;
		}



	}

	

    return 0;
}
*/


/*
		cout<<g<<" "<<p<<endl;
		FOR(i,0,g){
			FOR(j,0,p)cout<<position[i][j]<<" ";
			cout<<endl;
		}
		cout<<s<<endl;
		FOR(i,0,s){
			cout<<k;
			FOR(j,0,k)cout<<" "<<stm[i][j];
			cout<<endl;
		}

*/