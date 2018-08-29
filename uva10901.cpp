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

#define RR 1
#define LL 0



typedef struct tt{
	int tt;
	int id;
}Car;


vector<Car>ans;


int n,t,m;

void loadFerry(int ft, queue<Car>&bankQ,queue<Car>&ferryQ)
{
	Car x;
	while(!bankQ.empty()){
		
		x = bankQ.front();
		
		if(ferryQ.size()<n && x.tt<=ft){
			ferryQ.push(x);
			bankQ.pop();
		}
		else 
			break;
	}
}

void unloadFerry(int ft,queue<Car>&ferryQ)
{
	while(!ferryQ.empty()){
		Car x = ferryQ.front();
		x.tt = ft;
		ans.pb(x);
		ferryQ.pop();
	}
}



void updateFerryTimeAndPlace(int &ferryAt,int &ft,queue<Car>leftQ,queue<Car>rightQ)
{
	
	//case0: one or both Q is empty
	if(leftQ.empty() && rightQ.empty())
		return;

	if(leftQ.empty()){
		ft = max(ft,rightQ.front().tt);
		if(ferryAt==LL){
			ft+=t;
		}
		ferryAt=RR;
		return;
	}
	if(rightQ.empty()){
		ft = max(ft,leftQ.front().tt);
		if(ferryAt==RR){
			ft+=t;
		}
		ferryAt=LL;
		return;
	}


	if(ferryAt==LL){

		if(leftQ.front().tt<=ft)
			return;
		if(leftQ.front().tt<=rightQ.front().tt){
			ft = max(ft,leftQ.front().tt);
			return;
		}
		else{
			ft = max(ft,rightQ.front().tt) + t;
			ferryAt=RR;
			return;
		}
	}

	if(ferryAt==RR){
		//printf("%d %d %d\n",ft,leftQ.front().tt,rightQ.front().tt );
		if(rightQ.front().tt<=ft)
			return;
		if(rightQ.front().tt<=leftQ.front().tt){
			ft = max(ft,rightQ.front().tt);
			return;
		}
		else{
			ft = max(leftQ.front().tt,ft) + t;
			ferryAt=LL;
			return;
		}
	}

}


bool ccc(Car a, Car b){
	return a.id<b.id;
}

int main()
{

   freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

   int c;
   cin>>c;



   int tt;string ss;

   queue<Car>leftQ;
   queue<Car>rightQ;
   queue<Car>ferryQ;


   while(c--){

   	cin>>n>>t>>m;
   	ans.clear();
   



   	FOR(iii,0,m){
   		cin>>tt>>ss;
   		Car cc;
   		cc.tt=tt;
   		cc.id=iii;
   		
   		if(ss=="left")
   			leftQ.push(cc);
   		if(ss=="right")
   			rightQ.push(cc);
   	}

   	int ferryAt=LL;
   	int ft=0;
	
	//updateFerryTimeAndPlace(ferryAt,ft,leftQ,rightQ);

   /*	if((!leftQ.empty() && !rightQ.empty())&&(leftQ.front().tt>rightQ.front().tt)){
   		ft = rightQ.front().tt+t;
   		ferryAt=RR;
   		//printf("ASDFG--R\n");
   	}

   	else if(!leftQ.empty()){
   		ft=leftQ.front().tt;
   		ferryAt=LL;
   		//printf("ASDFG--L\n");
   	}
   	else if(!rightQ.empty()){
   		ft = rightQ.front().tt+t;
   		ferryAt=RR;
   	}*/

   	//printf("%d\n", ft);


   	int tmp;

   	while(ft<=1000000&&(leftQ.size()||rightQ.size())){
   		updateFerryTimeAndPlace(ferryAt,ft,leftQ,rightQ);
   		if(ferryAt==LL){
   			loadFerry(ft,leftQ,ferryQ);
   			//printf("Loading %d cars from left at %d\n",ferryQ.size(),ft);
   			ft+=t;
   			//printf("Unloading to right at %d\n",ft);
   			unloadFerry(ft,ferryQ);
   			ferryAt=RR;
   		}

   		else if(ferryAt==RR){
   			loadFerry(ft,rightQ,ferryQ);
   			//printf("Loading %d cars from right at %d\n",ferryQ.size(),ft);
   			ft+=t;
   			unloadFerry(ft,ferryQ);
   			//printf("Unloading to left at %d\n",ft);
   			ferryAt=LL;
   		}
   		//ft++;
   	}

   	sort(ans.begin(), ans.end(), ccc);
   	for(int i=0;i<ans.size();i++)
   		cout<<ans[i].tt<<endl;
   	if(c)printf("\n");



   }


	

    return 0;
}

/*

   		if(ferryAt==RR){

   			printf("Time---%d, FerryAt---%d\n",ft,ferryAt);


   			while(!rightQ.empty()){
   				if(rightQ.front()<=ft && ferryQ.size()<n){
   					tmp = rightQ.front();
   					rightQ.pop();
   					ferryQ.push(tmp);
   				}
   				else
   					break;
   			}

   			//if ferry not empty, cross river and unload
   			if(!ferryQ.empty()){
   				ft+=t;
   				ferryAt=LL;
   				while(!ferryQ.empty()){
   					ferryQ.pop();
   					printf("%d\n",ft);
   				}

   				//currently at Left bank, check if we need to go to the right instead

   				if(leftQ.empty() && !rightQ.empty()){
   					ft = max(rightQ.front(),ft)+t;
   					ferryAt = RR;
   				}
   				else if(!leftQ.empty() && !rightQ.empty()){
   					if(leftQ.front()>rightQ.front()){
   						ft = max(rightQ.front(),ft)+t;
   						ferryAt=RR;
   					}
   				}
   				else if(!leftQ.empty())
   					ft = max(leftQ.front(),ft);
   			}
   		}


   		

   		if(ferryAt==LL){
   			printf("Time---%d, FerryAt---%d\n",ft,ferryAt);
   			while(!leftQ.empty()){
   				if(leftQ.front()<=ft && ferryQ.size()<n){
   					tmp = leftQ.front();
   					leftQ.pop();
   					ferryQ.push(tmp);
   				}
   				else
   					break;
   			}

   			//if ferry not empty, cross river and unload
   			if(!ferryQ.empty()){
   				ft+=t;
   				ferryAt=RR;
   				while(!ferryQ.empty()){
   					ferryQ.pop();
   					printf("%d\n",ft);
   				}

   				//currently at Right bank, check if we need to go to the right instead

   				if(!leftQ.empty() && rightQ.empty()){
   					ft = max(ft,leftQ.front())+t;
   					ferryAt = LL;
   				}
   				else if(!leftQ.empty() && !rightQ.empty()){
   					if(leftQ.front()<rightQ.front()){
   						ft = max(ft,leftQ.front())+t;
   						ferryAt=LL;
   					}
   				}
   				else if(!rightQ.empty())
   					ft = max(ft,rightQ.front());
   			}

   		}

















*/