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

class UnionFind{
private:
	vector<int>parents;
	vector<int>ranks;
	vector<int>sizes;
	int totalDisjointSets;
public:
	UnionFind(int N) //N elements Union Find
	{
		ranks.assign(N,0);
		parents.assign(N,0);
		sizes.assign(N,1);
		totalDisjointSets = N;

		for(int i=0;i<N;i++){
			parents[i]=i;
		}
	}

	int findSet(int j)
	{
		if(parents[j]==j)return j;
		//path compression heuristic
		parents[j] = findSet(parents[j]);
		return parents[j];
	}

	bool isSameSet(int i, int j)
	{
		return findSet(i)==findSet(j);
	}

	void unionSet(int i, int j)
	{
		if(!isSameSet(i,j)){
			int ip = findSet(i);
			int jp = findSet(j);

			//rank heuristic
			if(ranks[ip]>ranks[jp]){
				parents[jp]=ip;
				sizes[jp]+=sizes[ip];
			}
			else{
				if(ip>jp){
					parents[ip]=jp;
					sizes[ip]+=sizes[jp];
					if(ranks[ip]==ranks[jp])
						ranks[jp]++;
				}
				else{
					parents[jp]=ip;
					sizes[jp]+=sizes[ip];
					if(ranks[jp]==ranks[ip])
						ranks[ip]++;	
				}
			}
			totalDisjointSets--;
		}
	}

	int numDisjointSets()
	{
		return totalDisjointSets;
	}

	int sizeOfSet(int i)
	{
		return sizes[findSet(i)];
	}


};


/*int main()
{

    freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);

	int n,c,p1,p2;
	while(cin>>n){

		UnionFind friends(2*n+1);


		while(cin>>c>>p1>>p2){
			if(!c&&!p1&&!p2)break;

			int twinP1 = 2*n-p1;
			int twinP2 = 2*n-p2;
			//cout<<p1<<" "<<p2<<" "<<twinP1<<" "<<twinP2<<endl;

			if(c==1){
				if(friends.isSameSet(twinP1,p2)||friends.isSameSet(twinP2,p1))
					cout<<-1<<endl;
				else if(!friends.isSameSet(p1,p2)&&!friends.isSameSet(twinP1,twinP2)){
					friends.unionSet(p1,p2);
					friends.unionSet(twinP1,twinP2);
				}
			}
			else if(c==2){
				if(friends.isSameSet(p1,p2)||friends.isSameSet(twinP1,twinP2)){
					cout<<-1<<endl;
				}
				else if(!friends.isSameSet(twinP1,p2)&&!friends.isSameSet(twinP2,p1)){
					friends.unionSet(twinP1,p2);
					friends.unionSet(twinP2,p1);
				}
			}

			else if(c==3){
				cout<<(friends.isSameSet(twinP1,twinP2)||friends.isSameSet(p1,p2))<<endl;
			}
			else if(c==4){
				cout<<(friends.isSameSet(p1,twinP2)||friends.isSameSet(twinP1,p2))<<endl;
			}


		}
	}
    return 0;
}
*/
vector<int>enemyList[10005];

void setFriends(UnionFind &u, int p1,int p2)
{
	int pr1 = u.findSet(p1);
	int pr2 = u.findSet(p2);
	if(u.isSameSet(p1,p2))
		return;

	for(int i=0;i<enemyList[pr1].size();i++)
		if(enemyList[pr1][i]==pr2){
			cout<<-1<<endl;
			return;
		}

	u.unionSet(pr1,pr2);

	int tmp = u.findSet(pr1);

	if(tmp==pr1){ //pr1 is root, transfer pr2's enemies to pr1

		for(int i=0;i<enemyList[pr2].size();i++)
		{	
			int enemy = enemyList[pr2][i];
			enemyList[pr1].pb(enemy);
			for(int j=0;j<enemyList[enemy].size();j++)
				if(enemyList[enemy][j]==pr2)
					enemyList[enemy][j]=pr1;
		}
		enemyList[pr2].clear();

	}
	else{
		for(int i=0;i<enemyList[pr1].size();i++)
		{	
			int enemy = enemyList[pr1][i];
			enemyList[pr2].pb(enemy);
			for(int j=0;j<enemyList[enemy].size();j++)
				if(enemyList[enemy][j]==pr1)
					enemyList[enemy][j]=pr2;
		}
		enemyList[pr1].clear();
	}

}


void setEnemies(UnionFind &u, int p1,int p2){
	
	int pr1 = u.findSet(p1);
	int pr2 = u.findSet(p2);
	
	if(pr1==pr2){
		cout<<-1<<endl;
		return;
	}


	for(int i=0;i<enemyList[pr1].size();i++)
		if(enemyList[pr1][i]==pr2)
			return;

	for(int i=0;i<enemyList[pr1].size();i++)
		for(int j=0;j<enemyList[pr2].size();j++)
			if(enemyList[pr1][i]==enemyList[pr2][j]){
				cout<<-1<<endl;
				return;
			}

	for(int i=0;i<enemyList[pr1].size();i++)
		setFriends(u,enemyList[pr1][i],pr2);
	for(int i=0;i<enemyList[pr2].size();i++)
		setFriends(u,enemyList[pr2][i],pr1);

	pr1 = u.findSet(pr1);
	pr2 = u.findSet(pr2);

	enemyList[pr1].pb(pr2);
	enemyList[pr2].pb(pr1);

}
int main()
{

 //   freopen("input.txt", "r", stdin);
   //	freopen("output.txt", "w", stdout);

   	

	int n,c,p1,p2;
	while(cin>>n){
		FOR(i,0,n)
			enemyList[i].clear();
		UnionFind s(n);


		while(cin>>c>>p1>>p2){
			if(!c&&!p1&&!p2)break;
			//cout<<p1<<" "<<p2<<" "<<twinP1<<" "<<twinP2<<endl;

			if(c==1){//set friends

				setFriends(s,p1,p2);

			}
			else if(c==2){//set enemies

				setEnemies(s,p1,p2);
			}

			else if(c==3){//check friends
				cout<<s.isSameSet(p1,p2)<<endl;
			}
			else if(c==4){//check enemies 
				int pr1 = s.findSet(p1);
				int pr2 = s.findSet(p2);
				for(int i=0;i<enemyList[pr1].size();i++)
					if(enemyList[pr1][i]==pr2){
						cout<<1<<endl;
						pr2=-100;
						break;
					}

				if(pr2!=-100)
					cout<<0<<endl;
			}


		}
	}
    return 0;
}
