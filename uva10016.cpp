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
#define MAX 105

int grid[MAX][MAX];

void printMatrix(int N)
{
		FOR(i,0,N){
			cout<<grid[i][0];
			FOR(j,1,N)cout<<" "<<grid[i][j];
			cout<<endl;
		}
}


void upSideDownFlip2(int ring, int n)
{

	int ii=ring,jj=n-ring-1;
	while(ii<jj){
		swap(grid[ii][ring],grid[jj][ring]);
		swap(grid[ii][n-1-ring],grid[jj][n-1-ring]);
		ii++;jj--;
	}

	for(int col=ring+1;col<n-1-ring;col++){
		swap(grid[ring][col],grid[n-1-ring][col]);
	}
}





/*void upSideDownFlip(int ring,int n)
{
	printMatrix(n);
	cout<<ring<<" "<<"UPSIDE_DOWN "<<(n-ring-1)/2<<endl<<endl;
	for(int j=ring;j<=(n-ring-1)/2;j++){
		cout<<"ASD"<<endl;
		swap(grid[j][ring],grid[n-1-j][ring]);
		swap(grid[j][n-1-ring],grid[n-1-j][n-1-ring]);

	}

	for(int col=ring+1;col<n-1-ring;col++){
		swap(grid[ring][col],grid[n-1-ring][col]);
	}
	
	 printMatrix(n);cout<<endl;
	// for(int j=0;j<n/2;j++)

}
*/
void leftRightFlip2(int ring,int n)
{
	int ii=ring,jj=n-ring-1;
	
	while(ii<jj){
		swap(grid[ring][ii],grid[ring][jj]);
		swap(grid[n-1-ring][ii],grid[n-1-ring][jj]);
		ii++;jj--;
	}


	for(int row=ring+1;row<n-1-ring;row++)
		swap(grid[row][ring],grid[row][n-1-ring]);
}

/*void leftRightFlip(int ring,int n)
{
	printMatrix(n);
	cout<<ring<<" "<<"LEFT_RIGHT"<<endl<<endl;
	for(int j=ring;j<=(n-1-ring)/2;j++){
		swap(grid[ring][j],grid[ring][n-1-j]);
		swap(grid[n-1-ring][j],grid[n-1-ring][n-1-j]);
	}
	for(int row=ring+1;row<n-1-ring;row++)
		swap(grid[row][ring],grid[row][n-1-ring]);
	 
	 printMatrix(n);cout<<endl;
}*/
void mainDiagonalFlip(int ring,int n){
	// printMatrix(n);cout<<endl;
	// cout<<ring<<" "<<"MAIN_DIAGONAL"<<endl<<endl;
	for(int i=ring;i<n-ring;i++)
		swap(grid[ring][i],grid[i][ring]);
	for(int i=n-1-ring;i>ring;i--)
		swap(grid[n-1-ring][i],grid[i][n-1-ring]);

	// printMatrix(n);cout<<endl;

}
void inverseDiagonalFlip(int ring,int n){
	// printMatrix(n);cout<<endl;
	// cout<<ring<<" "<<"INVERSE_DIAGONAL"<<endl<<endl;
	
	for(int i=ring;i<n-ring;i++)
		swap(grid[i][ring],grid[n-1-ring][n-1-i]);
	

	for(int i=n-1-ring;i>ring;i--)
		swap(grid[ring][i],grid[n-1-i][n-1-ring]);
	//printMatrix(n);cout<<endl;
}



int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int M;
	cin>>M;
	while(M--){
		int N;cin>>N;
		FOR(i,0,N)FOR(j,0,N)cin>>grid[i][j];

		int totalRings = ceil(1.0*N/2.0);
		
		//cout<<totalRings<<endl;
		//printMatrix(N);

		FOR(II,0,totalRings){
			int T;cin>>T;
			FOR(III,0,T){
				int mv;cin>>mv;
				switch(mv){
					case 1:
						upSideDownFlip2(II,N);
						break;
					case 2:
						leftRightFlip2(II,N);
						break;
					case 3:
						mainDiagonalFlip(II,N);
						break;
					case 4:
						inverseDiagonalFlip(II,N);
						break;
				}
			}
		}
		printMatrix(N);



	}

	

    return 0;
}
