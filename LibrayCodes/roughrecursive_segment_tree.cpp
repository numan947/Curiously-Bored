#include <bits/stdc++.h>
using namespace std;
#define N 20
#define MAX 80 // Why? :D
#define inf 0x7fffffff

int arr[N];
int tree[4*N];
int left(int node)
{
	return node<<1;
}
int right(int node)
{
	return (node<<1)|1;
}
int mid(int l, int r)
{
	return (l+r)>>1;
}

string s;
void build_tree(int node, int l, int r)
{
	if(l>r)return; //out of range
	if(l==r){
		//ASSIGN NODE HERE
		//tree[node] = ....
		if(s[l]=='0')
			tree[node]=0;
		else 
			tree[node]=1;
		
		return;
	}

	build_tree(left(node),l,mid(l,r));
	build_tree(right(node),1+mid(l,r),r);

	//MERGING RULES
	tree[node] = tree[left(node)] + tree[right(node)];
}

void update_tree(int node, int l, int r, int i, int j, int val) //update using val
{
	if(l>r||l>j||r<i) //out of bound
		return;

	if(l==r){ //leaf node
		//UPDATE RULES
		//update tree node
		//tree[node]=.......update logic using val
    		if(val == 'S')
    			tree[node] = 1;
    		else if(val == 'R')
    			tree[node] = 0;
    		else if(val == 'F')
    			tree[node] = !(tree[node]);
		return;
	}
	update_tree(left(node),l,mid(l,r),i,j,val);
	update_tree(right(node),1+mid(l,r),r,i,j,val);

	//MERGING RULES
	tree[node] = tree[left(node)]+tree[right(node)];
}

int query_tree(int node, int l, int r, int i, int j)
{
	if(l>r||l>j||r<i) //out of range
		return 0;

	if(l>=i&&r<=j) //current segment is totally in [i,j]
		return tree[node];

	int q1 = query_tree(left(node),l,mid(l,r),i,j);
	int q2 = query_tree(right(node),1+mid(l,r),r,i,j);
	//MERGING RUELS
	return q1+q2;

}




int main() {
	for(int i = 0; i < N; i++) arr[i] = 1;

	s= "101010101010001000";

	build_tree(1, 0,s.size()-1);
	int NN = s.size();
	update_tree(1, 0, NN-1, 0, 17, 'S'); // Increment range [0, 6] by 5
	update_tree(1, 0, NN-1, 0, 5, 'F'); // Incremenet range [7, 10] by 12
	//update_tree(1, 0, N-1, 10, N-1, 100); // Increment range [10, N-1] by 100
	//update_tree(1, 0, NN-1, 4, 9, 'R');
	cout << query_tree(1, 0, NN-1, 2, 10) << endl; // Get max element in range [0, N-1]
}