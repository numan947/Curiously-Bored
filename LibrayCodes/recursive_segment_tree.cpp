#include <bits/stdc++.h>
using namespace std;

#define MAX 12



typedef struct STN{
	//elems
}SegmentTreeNode;



int arr[MAX];
int tree[4*MAX];
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


/************************************WITHOUT_LAZY*****************************/

void updateParent(int nd, int l, int r)
{
	//IMPLEMENT PARENT UPDATES HERE.........
	//INITIALIZE NODE MERGING RULES HERE........
}

void build_tree(int nd, int l, int r)
{
	if(l>r)return; //out of bound
	if(l==r){ //reached leaves

		//INITIALIZE LEAVES LOGIC HERE..eg:
		//tree[nd]=arr[l];

		/*********WRITE NOTHING BELOW THIS*************/
		return;
	}

	build_tree(left(nd),l,mid(l,r));
	build_tree(right(nd),1+mid(l,r),r);

	updateParent(nd,left(nd),right(nd));
}


void update_tree(int nd, int l, int r, int i, int j, int val)
{
	if(l>r||l>j||r<i) //out of bound
		return;

	if(l==r){ //reached node
		//UPDATE THE LEAF NODE HERE..e.g:
		//tree[nd] += val


		/*********WRITE NOTHING BELOW THIS*************/
		return;
	}

	update_tree(left(nd),l,mid(l,r),i,j,val);
	update_tree(right(nd),1+mid(l,r),r,i,j,val);


	updateParent(nd,left(nd),right(nd));
}

int query_tree(int nd, int l, int r, int i, int j)
{
	if(l>r||l>j||r<i){//out of bound

		//INSERT PROGRAM SPECIFIC RETURN LOGIC HERE..eg: MUST RETURN INVALID
		//return 0/INF/-INF; 
	}

	if(l>=i&&r<=j) //current [l,r] segment is totaly within [i,j]
		return tree[nd];

	int q1 = query_tree(left(nd),l,mid(l,r),i,j);
	int q2 = query_tree(right(nd),1+mid(l,r),r,i,j);

	//INSERT PROGRAM SPECIFIC NODE MERGING RULES HERE..e.g:
	return q1+q2;
}

/*****************WITHOUT_LAZY_END************************************************/


typedef struct STN{
	//elems
}STNode;



int arr[MAX];
/*************************WITH_LAZY************************************************/
ll tree[4*MAX];
ll lazy[4*MAX];




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

void update_lazy(int nd, int l, int r,ll checker, ll val)
{
	if(checker){ //check if lazy update is needed for this node, pass 1 when lazy update is getting set
		tree[nd]+=(r-l+1)*val; //update current node
		if(r!=l){ //mark current node's children for lazy update
			lazy[left(nd)]+=val;
			lazy[right(nd)]+=val;
		}
	}
}


void updateParent(int nd, int l, int r)
{
	//IMPLEMENT PARENT UPDATES HERE.........
	//INITIALIZE NODE MERGING RULES HERE........

	tree[nd] = tree[l] + tree[r];
}

void build_tree(int nd, int l, int r)
{
	if(l>r)return; //out of bound

	//INITIALIZE LAZY HERE
	//lazy[nd] = 0;

	if(l==r){ //reached leaves

		//INITIALIZE LEAVES LOGIC HERE..eg:
		//tree[nd]=arr[l];

		/*********WRITE NOTHING BELOW THIS*************/
		return;
	}

	build_tree(left(nd),l,mid(l,r));
	build_tree(right(nd),1+mid(l,r),r);

	updateParent(nd,left(nd),right(nd));
}


void update_tree(int nd, int l, int r, int i, int j, ll val)
{

	//clear this node's lazy updates
	update_lazy(nd,l,r,lazy[nd],lazy[nd]);
	lazy[nd]=0;

	if(l>r||l>j||r<i) //out of bound
		return;

	if(l>=i&&r<=j){ //reached node
		//UPDATE LAZILY...........
		update_lazy(nd,l,r,1,val);
		/*********WRITE NOTHING BELOW THIS*************/
		return;
	}

	update_tree(left(nd),l,mid(l,r),i,j,val);
	update_tree(right(nd),1+mid(l,r),r,i,j,val);


	updateParent(nd,left(nd),right(nd));
}

ll query_tree(int nd, int l, int r, int i, int j)
{
	//clear this node's lazy updates
	update_lazy(nd,l,r,lazy[nd],lazy[nd]);
	lazy[nd]=0;


	if(l>r||l>j||r<i){//out of bound

		//INSERT PROGRAM SPECIFIC RETURN LOGIC HERE..eg: MUST RETURN INVALID
		//return 0/INF/-INF;
		return 0; 
	}

	if(l>=i&&r<=j) //current [l,r] segment is totaly within [i,j]
		return tree[nd];

	ll q1 = query_tree(left(nd),l,mid(l,r),i,j);
	ll q2 = query_tree(right(nd),1+mid(l,r),r,i,j);

	//INSERT PROGRAM SPECIFIC NODE MERGING RULES HERE..e.g:
	return q1+q2;
}

/*****************WITH_LAZY_END************************************************/
