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

/*************************WITH_LAZY************************************************/

/*
applies lazy updates to the tree 
and marks the children for update
*/

int arr[MAX];
int tree[4*MAX];
int lazy[4*MAX];




inline int left(int node)
{
	return node<<1;
}
inline int right(int node)
{
	return (node<<1)|1;
}
inline int mid(int l, int r)
{
	return (l+r)>>1;
}
/*************************WITH_LAZY************************************************/

void updateParent(int nd, int l, int r)
{
	//IMPLEMENT PARENT UPDATES HERE.........
	//INITIALIZE NODE MERGING RULES HERE........
}

/*
applies lazy updates to the tree 
and marks the children for update
*/
void apply_lazy(int nd, int l, int r) 
{
	//check if lazy update needed
	if(lazy_update_needed){
		if(l==r){ //this is leaf 
			
			//update current node using the lazy update..e.g:
			//tree[nd]+=lazy[nd];

		}
		else{
			//update current node using lazy update and propagate the update suitably....e.g:
			//tree[nd] +=lazy[nd];
			//lazy[left(nd)] +=lazy[nd];
			//lazy[right[nd]] +=lazy[nd];
		}

		//clear this node's update..e.g:
		//lazy[nd] = FALSE;
	}
}


void build_tee(int nd, int l, int r)
{
	if(l>r)
		return;
	if(l==r){
		//initialize the leaves...e.g:
		
		//tree[nd] = arr[l];

		//initialize lazy...e.g:
		//lazy[l] = NONE;

		/************WRITE_NOTHING_BELOW_THIS****************/
		return;
	}

	build_tree(left(nd),l,mid(l,r));
	build_tree(right(nd),1+mid(l,r),r);

	updateParent(nd,left(nd),right(nd));
	//initialize lazy for this node..e.g:
	//lazy[nd] = NONE
}


void update_tree(int nd, int l, int r, int i, int j, int val)
{
	//clear pending lazy update on this node
	apply_lazy(nd,l,r);

	if(l>r||l>j||r<i) //out of bound
		return;
	if(l>=i&&r<=j){ //segment [l,r] is fully within [i,j], 
					//so update current node, 
					//and mark it's children for lazy update

		if(l==r){
			//current node is leaf, so no lazy marking needed here,just update the node
			//LOGIC FOR UPDATE HERE
			//tree[nd] = val;
		}
		else{
			//current node is internal,
			//LOGIC FOR UPDATING CURRENT NODE and MARKING CHILDREN FOR UPDATE
			//tree[nd] = val;
			//lazy[left(nd)] += val;
			//lazy[right(nd)] +=val;
		}


		/*********DONT WRITE BELOW THIS**************/
		return;
	}

	//UPDATE THESE SUITABLY..........may need to change just val and merging rules
	update_tree(left(nd),l, mid(l,r),i,j,val);
	update_tree(left(nd),1+mid(l,r),r,i,j,val);

	updateParent(nd,left(nd),right(nd));

}


int query_tree(int nd, int l, int r, int i, int j)
{
	//clear pending update on the node
	apply_lazy(nd,l,r);
	if(l>r||l>j||r<i){
		//RETURN SUITABLY FOR NOT FOUND VALUE
		return -1/INF/-INF/0;
	}

	if(l>=i&&r<=j){ //fully within range--> [l,r] is within [i,j]
		return tree[nd];
	}

	int res1 = query_tree(left(nd),l,mid(l,r),i,j);
	int res2 = query_tree(right(nd),1+mid(l,r),r,i,j);

	//MERGING RULES HERE

	return res1+res2;
}




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
	// freopen("output.txt", "w", stdout);
	

    return 0;
}
