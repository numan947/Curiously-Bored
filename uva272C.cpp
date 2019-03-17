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

const int MOD = (int) 1e9 + 7;
const int FFTMOD = 1007681537;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-6;

//some common functions

// inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;} //gcd
// inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;} //lcm
// inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;} //nth power
// inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}  //add mod
// inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}  //sub mod
// inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}  //check sqrt
// inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}  //check cbrt

//some helper functions for input processing

// inline void tokenize(string str,vector<string> &tokens, string delim){ tokens.clear();size_t s = str.find_first_not_of(delim), e=s; while(s!=std::string::npos){e=str.find(delim,s);tokens.push_back(str.substr(s,e-s));s=str.find_first_not_of(delim,e);}}
// inline bool isPalindrome(string str){for(int i=0;i<(str.size())/2;i++)if(str[i]!=str[str.size()-1-i])return false;return true;}
// inline string customStrip(string in,string delim){string ret = "";for(int i=0;i<in.size();i++){if(delim.find(in[i],0)==std::string::npos)ret+=in[i];}return ret;}
// inline string commaSeparate(long long value){string numWithCommas = to_string(value);int insertPosition = numWithCommas.length() - 3;while (insertPosition > 0) {numWithCommas.insert(insertPosition, ",");insertPosition-=3;}return numWithCommas;}
// inline string strip(string s){int i=0;while(i<s.size()){if(isspace(s[i]))i++;else break;}s.erase(0,i);i = s.size()-1;while(i>=0){if(isspace(s[i]))i--;else break;}s.erase(i+1,s.size()-i-1);return s;}
// template <typename T> int sgn(T val) {return (T(0) < val) - (val < T(0));}

//errors
#define db(x) cerr << #x << " = " << (x) << "\n";
#define endl '\n'

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

/*//4 directional movement: N->E->S->W
int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};
*/


/*//8 directional movement
int dr[] = {1,1,1,0,0,-1,-1,-1};
int dc[] = {1,0,-1,1,-1,1,0,-1};*/


#define MAX 100002

ll arr[MAX];
ll tree[4*MAX+10];
//true if a node need to be updated
bool lazyUpdate[4*MAX+10];

//contains the actual update
ll lazyUpdateValue[4*MAX+10];



//build complexity O(N)....start from node 1
void build(int node, int st, int ed)
{

    if(st==ed){
        //leaf addition rules here
        tree[node] = arr[st];

    }else{
        int mid = (st+ed)>>1;

        build(2*node, st, mid);
        build(2*node+1,mid+1,ed);

        //merging rules here
        tree[node] = max(tree[2*node] , tree[2*node + 1]);
    }
}


void rangeUpdate(int node, int st, int ed, int l, int r, ll val)
{

    //if there is pending update, clear it first
    if(lazyUpdate[node]){
        //this node needs to be updated

        //update this node using the updateValue
        tree[node]=lazyUpdateValue[node];

        if(st!=ed){
            //mark child as lazy, and propagate the update
            lazyUpdate[node*2] = 1;

            //***may need to accumulate update***
            lazyUpdateValue[node*2] = lazyUpdateValue[node];

            lazyUpdate[node*2+1] = 1;
            lazyUpdateValue[node*2+1] = lazyUpdateValue[node];
        }
        //clear update for current node
        lazyUpdate[node] = 0;
        lazyUpdateValue[node] = 0;
    }

    if(r<st||ed<l){
        // Current segment is not within range [l, r]
        return;
    }

    if(st>=l && ed<=r){
        //current segment is fully within the range

        //update current node
        tree[node] = val;

        if(st!=ed){
            //this is not a leaf node so,
            //mark children for lazy update
            lazyUpdate[2*node] = 1;
            //***may need to accumulate update***
            lazyUpdateValue[2*node] = val;

            lazyUpdate[2*node+1] = 1;
            lazyUpdateValue[2*node+1] = val;
        }
        return;
    }

    int mid = (st+ed)>>1;

    rangeUpdate(node*2, st, mid, l,r,val);
    rangeUpdate(node*2+1,mid+1,ed,l,r,val);

    //merge updates
    tree[node] = max(tree[node*2] , tree[node*2+1]);
}

//range query:  #O(logN)
ll rangeQuery(int node, int st, int ed, int l, int r)
{
    if(r<st||ed<l){
        // range represented by this node is completely outside the given range
        return 0;
    }

    //if used with lazy propagation
    if(lazyUpdate[node]){

        //update this node
        tree[node] = lazyUpdateValue[node];

        if(st!=ed){
            lazyUpdate[2*node] = 1;
            lazyUpdateValue[2*node] = lazyUpdateValue[node];

            lazyUpdate[2*node+1] = 1;
            lazyUpdateValue[2*node+1] = lazyUpdateValue[node];
        }

        lazyUpdate[node] = 0;
        lazyUpdateValue[node] = 0;
    }


    if(l<=st && ed<=r){
        // range represented by this node is completely inside the given range
        return tree[node];
    }

    // range represented by this node is partially inside and partially outside the given range

    int mid = (st+ed)>>1;
    ll p1 = rangeQuery(2*node,st,mid,l,r);
    ll p2 = rangeQuery(2*node+1,mid+1,ed,l,r);

    //merge result here
    return max(p1,p2);
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
	
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);


	// ms(lazyUpdate,0);
	// ms(lazyUpdateValue,0);
	// ms(tree,0);
	// ms(arr,0);


	int N;
	cin>>N;
	FOR(i,0,N)
		cin>>arr[i];
	
	build(1,0,N-1);

	int M;cin>>M;

	ll w,h;
	while(M--){
		cin>>w>>h;
		ll getMx = rangeQuery(1,0,N-1,0,w-1);
		cout<<getMx<<endl;
		rangeUpdate(1,0,N-1,0,w-1,getMx+h);
	}

	return 0;
}
