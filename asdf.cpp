#include <iostream>
#include <fstream>
using namespace std;

int ord[21], arr[21], lis[21], n;

int main() {
  freopen("input.txt", "r", stdin);
  int in;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> in;
    ord[i+1] = in;
  }
  for(int i=1;i<=n;i++)
    cout<<ord[i]<<" ";
  cout<<endl;
  while (cin >> in) { 
    arr[in] = 1;
    lis[1] = 1;
    for (int i = 2; i <= n; i++) {
      cin >> in;
      arr[in] = i, lis[i] = 1;
    }
  for(int i=1;i<=n;i++)
    cout<<arr[i]<<" ";
  cout<<endl;

    int m = 1;
    for (int i = 2; i <= n; i++)
      for (int j = 1; j < i; j++)
        if (ord[arr[i]] > ord[arr[j]] and lis[i] < lis[j] + 1) {
          lis[i] = lis[j] + 1;
          m = max(m, lis[i]);
        }
    cout << m << endl;
  }
  return 0;
}