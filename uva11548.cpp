#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define pb push_back

//shorthands
typedef vector<string> vs;
int findMaxMatch(string s1, string s2)
{
	int mxCnt = 0;
	for(int i=0;i<s1.size();i++){
		int mtch=0;
		int k=0;
		while((k+i)<s1.size()&&k<s2.size()){
			if(s1[k+i]==s2[k])
				mtch++;
			k++;
		}
		mxCnt= max(mxCnt,mtch);
	}

	for(int i=0;i<s2.size();i++){
		int mtch=0;
		int k=0;
		while((k+i)<s2.size()&&k<s1.size()){
			if(s2[k+i]==s1[k])
				mtch++;
			k++;
		}
		mxCnt= max(mxCnt,mtch);
	}

	return mxCnt;

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
	
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	//auto start = std::chrono::system_clock::now();

	string inp;
	vs words;
	int n,t;
	cin>>t;

	while(t--){
		words.clear();
		cin>>n;
		FOR(i,0,n){
			cin>>inp;
			words.pb(inp);
			//cout<<words[i]<<endl;
		}
		int maxMatch = 0;
		for(int i=0;i<n-1;i++){
			if(words[i].size()<=maxMatch)
				continue;
			for(int j=i+1;j<n;j++){
				if(words[j].size()<=maxMatch)
					continue;
				maxMatch = max(maxMatch,max(findMaxMatch(words[i],words[j]),0));
			}
		}

		cout<<maxMatch<<endl;

	}

	//auto end = std::chrono::system_clock::now();
    //std::chrono::duration<double> diff = end-start;
    //std::cout <<  diff.count() << " s\n";

    return 0;
}
