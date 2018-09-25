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
#define numLeadZero(s) __builtin_clz(s)
#define numTrailZero(s) __builtin_ctz(s)
#define numOnes(s) __builtin_popcount(s)
#define parity(s) __builtin_parity(s)







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

/*
//double comparisons
bool EQ(double d1,double d2) //d1==d2
{
	return fabs(d1-d2)<EPS;
}
bool GT(double d1,double d2) //d1>d2
{
	return (d1-d2)>EPS;
}
bool LT(double d1,double d2) //d1<d2
{
	return GT(d2,d1);
}
bool GTE(double d1, double d2) //d1>=d2
{
	return GT(d1,d2)||EQ(d1,d2);
}
bool LTE(double d1,double d2)//d1<=d2
{
	return LT(d1,d2)||EQ(d1,d2);
}

*/

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1};


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


int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	queue<int>q;
	priority_queue<int>pq;
	stack<int>stk;
	int n,c1,c2;

	while(cin>>n){

		while(!q.empty())
			q.pop();
		while(!pq.empty())
			pq.pop();
		while(!stk.empty())
			stk.pop();

		int qq = 0,pqq = 0, stkq = 0,cmdc=0;

		while(n--){
			cin>>c1>>c2;
			if(c1==1){
				q.push(c2);
				pq.push(c2);
				stk.push(c2);
			}
			else{
				cmdc++;
				if(!stk.empty() && stk.top()==c2){
					stkq++;
					stk.pop();
				}
				if(!q.empty() && q.front()==c2){
					qq++;
					q.pop();
				}
				if(!pq.empty() && pq.top()==c2){
					pqq++;
					pq.pop();
				}
			}
		}

		//cout<<qq<<" "<<pqq<<" "<<stkq<<endl;

		if(((cmdc!=stkq)&&(cmdc!=qq)&&(cmdc!=pqq)))
			cout<<"impossible"<<endl;
		else if(pqq>qq&&pqq>stkq && cmdc==pqq)
			cout<<"priority queue"<<endl;
		else if(qq>pqq&&qq>stkq && cmdc==qq)
			cout<<"queue"<<endl;
		else if(stkq>qq&&stkq>pqq && cmdc==stkq)
			cout<<"stack"<<endl;
		else/* if((pqq==qq && qq)||(stkq==qq && qq)||((pqq==stkq && pqq)))*/
			cout<<"not sure"<<endl;


	}


	

    return 0;
}