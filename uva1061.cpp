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

typedef struct Blood{
	string abo;
	string rh;
	bool tba=false;
}BloodType;



bool trueChar(string s,char ch)
{
	FOR(i,0,s.size())
		if(ch==s[i])return true;
	return false;
}


string reduce(string abo)
{
	//cout<<abo<<"  aaaaa"<<endl;
	string s="";
	if(abo[0]==abo[1])return s+abo[0];
	else if(abo[0]=='O') return s+abo[1];
	else if(abo[1]=='O')return s+abo[0];
	return "AB";
}



int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	string input;
	vector<string> tmp;
	map<string,vector<string> >aboMap;

	aboMap["A"] = vs {"AA","AO"};
	aboMap["B"] = vs {"BB","BO"};
	aboMap["AB"] = vs {"AB"};
	aboMap["O"] = vs {"OO"};

	vs all {"AA","AB","BB","AO","BO","OO"};

	vs tmpans;
	vs ans;

	int kase=0;

	while(true){
		getline(cin,input);
		tmp.clear();
		tokenize(input,tmp," ");
		if(tmp.size()<3)continue;
		if(tmp[0]=="E"&&tmp[1]=="N"&&tmp[2]=="D")
			break;

		BloodType parent1;
		BloodType parent2;
		BloodType child;

		if(tmp[0]=="?")
			parent1.tba=true;
		else{
			parent1.abo = tmp[0].substr(0,tmp[0].size()-1);
			parent1.rh = tmp[0].substr(tmp[0].size()-1,1);
		}

		if(tmp[1]=="?")
			parent2.tba=true;
		else{
			parent2.abo = tmp[1].substr(0,tmp[1].size()-1);
			parent2.rh = tmp[1].substr(tmp[1].size()-1,1);
		}

		if(tmp[2]=="?")
			child.tba=true;
		else{
			child.abo = tmp[2].substr(0,tmp[2].size()-1);
			child.rh = tmp[2].substr(tmp[2].size()-1,1);
		}


		ans.clear();
		tmpans.clear();

		if(child.tba){

			vs x1 = aboMap[parent1.abo];
			vs x2 = aboMap[parent2.abo];


			for(int i=0;i<x1.size();i++){
				string p = x1[i];
				for(int j=0;j<x2.size();j++){
					string q = x2[j];
					for(int ii=0;ii<p.size();ii++)
						for(int jj=0;jj<q.size();jj++){
							string ss = "";
							ss+=p[ii];
							ss+=q[jj];
							ss = reduce(ss);
							if(find(tmpans.begin(),tmpans.end(),ss)==tmpans.end())
							tmpans.pb(ss);
						}
				}
			}

			for(int i=0;i<tmpans.size();i++)
				ans.pb(tmpans[i]+"-");


			if(parent1.rh=="+"||parent2.rh=="+"){
				for(int i=0;i<tmpans.size();i++)
					ans.pb(tmpans[i]+"+");
			}

		}

		else{



			if(parent1.tba){
				//check compatible with parent2
				vs x1 = aboMap[parent2.abo];
				vs x2 = aboMap[child.abo];

				bool compatible=false;

				for(int i=0;i<x1.size();i++){
					string p = x1[i];
					for(int j=0;j<x2.size();j++){
						string q = x2[j];
						for(int ii=0;ii<p.size();ii++){
							for(int jj=0;jj<q.size();jj++){
								if(p[ii]==q[jj]){
									compatible = true;
									break;
								}
							}
							if(compatible)break;
						}
						if(compatible)break;
					}
					if(compatible)break;
				}

				//find parent2
			
				if(compatible){
					

					for(int i=0;i<x1.size();i++){
						string par = x1[i];
						
						for(int j=0;j<x2.size();j++){
							
							string ch = x2[j];
							
							for(int k=0;k<all.size();k++){
								

								// cout<<par<<" "<<ch<<" "<<all[k]<<endl;
								// cout<<ch[0]<<" "<<ch[1]<<endl;
								// cout<<par.find(ch[0])<<endl;
								// cout<<all[k].find(ch[1])<<endl;
								// cout<<std::string::npos<<endl;
								if((trueChar(par,ch[0]) && trueChar(all[k],ch[1]))||(trueChar(par,ch[1]) && trueChar(all[k],ch[0]))){
									if(find(tmpans.begin(),tmpans.end(),reduce(all[k]))==tmpans.end()){
										tmpans.pb(reduce(all[k]));
									}
								}			
							}
						}
					}


					if(parent2.rh=="-"&& child.rh=="+")
						for(int i=0;i<tmpans.size();i++)
							ans.pb(tmpans[i]+"+");
					else
						for(int i=0;i<tmpans.size();i++){
							ans.pb(tmpans[i]+"-");
							ans.pb(tmpans[i]+"+");
						}
					
				}

			}

			else{
				//check compatible with parent1
				vs x1 = aboMap[parent1.abo];
				vs x2 = aboMap[child.abo];

				bool compatible=false;

				for(int i=0;i<x1.size();i++){
					string p = x1[i];
					for(int j=0;j<x2.size();j++){
						string q = x2[j];
						for(int ii=0;ii<p.size();ii++){
							for(int jj=0;jj<q.size();jj++){
								if(p[ii]==q[jj]){
									compatible = true;
									break;
								}
							}
							if(compatible)break;
						}
						if(compatible)break;
					}
					if(compatible)break;
				}

				//find parent2
			
				if(compatible){
					

					for(int i=0;i<x1.size();i++){
						string par = x1[i];
						
						for(int j=0;j<x2.size();j++){
							
							string ch = x2[j];
							
							for(int k=0;k<all.size();k++){
								

								//  cout<<par<<" "<<ch<<" "<<all[k]<<endl;
								//  cout<<ch[0]<<" "<<ch[1]<<endl;
								// // cout<<par.find(ch[0])<<endl;
								// // cout<<all[k].find(ch[1])<<endl;
								// // cout<<std::string::npos<<endl;
								if((trueChar(par,ch[0]) && trueChar(all[k],ch[1]))||(trueChar(par,ch[1]) && trueChar(all[k],ch[0]))){
									if(find(tmpans.begin(),tmpans.end(),reduce(all[k]))==tmpans.end()){
										tmpans.pb(reduce(all[k]));
									}
								}			
							}
						}
					}

					if(parent1.rh=="-"&& child.rh=="+")
						for(int i=0;i<tmpans.size();i++)
							ans.pb(tmpans[i]+"+");
					else
						for(int i=0;i<tmpans.size();i++){
							ans.pb(tmpans[i]+"-");
							ans.pb(tmpans[i]+"+");
						}
					
				}
			}
		}



		cout<<"Case "<<++kase<<":";
		if(!parent1.tba)cout<<" "<<parent1.abo<<parent1.rh;
		else{
			if(ans.size()>1){
				cout<<" {"<<ans[0];
				for(int i=1;i<ans.size();i++)
					cout<<", "<<ans[i];
				cout<<"}";
			}
			else if(ans.size()>0)
				cout<<" "<<ans[0];
			else
				cout<<" "<<"IMPOSSIBLE";
		}
		if(!parent2.tba)cout<<" "<<parent2.abo<<parent2.rh;
		else{
			if(ans.size()>1){
				cout<<" {"<<ans[0];
				for(int i=1;i<ans.size();i++)
					cout<<", "<<ans[i];
				cout<<"}";
			}

			else if(ans.size()>0)
				cout<<" "<<ans[0];
			else
				cout<<" "<<"IMPOSSIBLE";
		}
		if(!child.tba)cout<<" "<<child.abo<<child.rh;
		else{
			if(ans.size()>1){
				cout<<" {"<<ans[0];
				for(int i=1;i<ans.size();i++)
					cout<<", "<<ans[i];
				cout<<"}";
			}
			else if(ans.size()>0)
				cout<<" "<<ans[0];
			else
				cout<<" "<<"IMPOSSIBLE";
		}
		cout<<endl;



	}

	

    return 0;
}
