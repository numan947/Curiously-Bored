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
inline bool isPalindrome(string str){for(int i=0;i<(str.size())/2;i++)if(str[i]!=str[str.size()-1-i])return false;return true;}
inline string customStrip(string in,string delim){string ret = "";for(int i=0;i<in.size();i++){if(delim.find(in[i],0)==std::string::npos)ret+=in[i];}return ret;}
inline string commaSeparate(long long value){string numWithCommas = to_string(value);int insertPosition = numWithCommas.length() - 3;while (insertPosition > 0) {numWithCommas.insert(insertPosition, ",");insertPosition-=3;}return numWithCommas;}



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


typedef struct dataMIDI{
	bool noteStat;
	int noteNum;
	int measure;
	int beat;
	int tick;
}myData;



int main()
{

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

	int values[]={0,60,120,180,240,300,360,420,480};
	int n;
	vector<myData>all;
	map<int,vector<int> >myMap;
	vector<int>toErase;
	while(true){
		cin>>n;
		if(n==-1){
			printf("%d\n",n );
			break;
		}

		all.clear();
		myMap.clear();
		toErase.clear();
		myData input;
		while(n--){
			cin>>input.noteStat>>input.noteNum>>input.measure>>input.beat>>input.tick;

			int maxSofar = INF;
			int update;
			for(int i=0;i<9;i++){
				if(abs(input.tick-values[i])<=maxSofar){
					maxSofar = input.tick-values[i];
					update = values[i];
				}
				else
					break;
			}
			input.tick = update;

			if(update==480){
				if(input.beat<4){
					input.beat++;
					input.tick=0;
				}
				else{
					input.measure++;
					input.beat=1;
					input.tick=0;
				}
			}

			myMap[input.noteNum].pb(all.size());
			all.pb(input);
		}


		for(map<int,vector<int> >::iterator it=myMap.begin();it!=myMap.end();it++){
			for(int i=0;i<(it->second).size();i+=2){
				int x = (it->second)[i];
				int y = (it->second)[i+1];

				if(all[x].measure==all[y].measure&&
					all[x].beat==all[y].beat&&
					all[x].tick==all[y].tick){
						toErase.pb(x);
						toErase.pb(y);
				}

			}
		}

		int dd = all.size()-toErase.size();
		printf("%d\n",dd);
		for(int i=0;i<all.size();i++){
			if(find(toErase.begin(),toErase.end(),i)==toErase.end())
			cout<<all[i].noteStat<<" "<<all[i].noteNum<<" "<<all[i].measure<<" "<<all[i].beat<<" "<<all[i].tick<<endl;
		}

	}

	

    return 0;
}
