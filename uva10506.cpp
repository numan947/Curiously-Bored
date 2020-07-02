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


//shorthands
typedef long long ll;

#define MAX 65536
int N,M;
ll targetSize;
map<string,bool>oroboroMap;

bool generateOroboro(string tmp, string cur)
{
	if(oroboroMap.size()==targetSize){
		if(!mapHas(oroboroMap,tmp+cur[0]) || !oroboroMap[tmp+cur[0]]){
			cout<<cur<<endl;
			return true;
		}
		return false;
	}
	string bmp = tmp.substr(1);
	// cout<<cur<<endl;
	for(int i=0;i<N;i++){
		if(!mapHas(oroboroMap,tmp+to_string(i)) || oroboroMap[tmp+to_string(i)]==0){
			oroboroMap[tmp+to_string(i)] = 1;
			if(generateOroboro(bmp+to_string(i),cur+to_string(i)))
				return true;
			oroboroMap[tmp+to_string(i)] = 0;
		}
	}

	return false;

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

	while(cin>>M>>N){
		oroboroMap.clear();

		if(M==1 || N==1){
			FOR(i,0,M)
				cout<<"0";
			cout<<endl;
		}
		else{
			string tmp = "";
			targetSize=N;

			FOR(i,0,M-1){
				tmp+="0";
				targetSize*=N;
			}
			generateOroboro(tmp,tmp);
		}
	}
	

	return 0;
}
