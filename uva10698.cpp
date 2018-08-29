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

int win = 3, draw = 1, loss = 0;

typedef struct tt{
	int pts;
	int gs;
	int ga;
	int totalPlayed;
	string name;

	string percentage;


}Team;


bool samePos(Team a, Team b){
	return a.pts==b.pts && (a.gs-a.ga)==(b.gs-b.ga) && a.gs == b.gs;
}

bool WHAT(Team a, Team b)
{
	if(a.pts==b.pts){
		if((a.gs-a.ga)==(b.gs-b.ga)){
			if(a.gs==b.gs){
				string s1 = a.name;
				transform(s1.begin(),s1.end(),s1.begin(),::tolower);
				string s2 = b.name;
				transform(s2.begin(),s2.end(),s2.begin(),::tolower);
				return s1<s2;
			}

			return a.gs > b.gs;
		}		

		return (a.gs-a.ga)>(b.gs-b.ga);
	}
	return a.pts>b.pts;
}


int main()
{

    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

	int T,G;
	cout.precision(2);
	cout << fixed;
	map<string,Team>mp;
	vector<Team>vv;
	vector<string>tmp;
	int kase=0;

	while(scanf("%d %d",&T,&G)){
		if(!T && !G)break;
		mp.clear();
		vv.clear();

		if(kase)printf("\n");
		kase++;
		string input;
		while(T--){
			cin>>input;
			Team pp;
			pp.name=input;
			pp.pts=0;
			pp.gs=0;
			pp.ga=0;
			pp.totalPlayed=0;
			mp[input]=pp;
		}
		getchar();

		while(G--){
			getline(cin,input);
			tmp.clear();
			tokenize(input,tmp," ");
			
			string team1 = tmp[0];
			int g1 = stoi(tmp[1]);

			string team2 = tmp[4];
			int g2 = stoi(tmp[3]);

			mp[team1].gs+=g1;
			mp[team1].ga+=g2;
			mp[team1].totalPlayed++;

			mp[team2].gs+=g2;
			mp[team2].ga+=g1;
			mp[team2].totalPlayed++;


			if(g1>g2){
				mp[team1].pts+=win;
				mp[team2].pts+=loss;
			}
			else if(g1<g2){

				mp[team2].pts+=win;
				mp[team1].pts+=loss;
			}
			else{
				mp[team1].pts+=draw;
				mp[team2].pts+=draw;
			}

		}

		for(map<string,Team>::iterator it=mp.begin();it!=mp.end();it++){
			vv.pb(it->se);
		}

		sort(vv.begin(),vv.end(),WHAT);

		printf("%2d.",1);
		cout.width(16);
		cout.fill(' ');
		cout<<vv[0].name;
		printf("%4d%4d%4d%4d%4d",vv[0].pts,vv[0].totalPlayed,vv[0].gs,vv[0].ga,vv[0].gs-vv[0].ga);


		if(vv[0].totalPlayed>0){
			cout.width(7);
			cout.fill(' ');
			cout<<100.0*vv[0].pts/(vv[0].totalPlayed*win)<<endl;

		}
		else printf("    N/A\n");

		for(int i=1;i<vv.size();i++){
			
			if(!samePos(vv[i-1],vv[i]))printf("%2d.",i+1);
			else printf("   ");

			cout.width(16);
			cout.fill(' ');
			cout<<vv[i].name;
			printf("%4d%4d%4d%4d%4d",vv[i].pts,vv[i].totalPlayed,vv[i].gs,vv[i].ga,vv[i].gs-vv[i].ga);

			if(vv[i].totalPlayed>0){
				cout.width(7);
				cout.fill(' ');
				cout<<100.0*vv[i].pts/(vv[i].totalPlayed*win)<<endl;

			}
			else printf("    N/A\n");
		}


	}



	

    return 0;
}
