#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
const int INF = 15009;
#define MAX 50000+5


typedef struct STN{
	int pMax,sMax,s,Max;
}SegmentTreeNode;

SegmentTreeNode merge(SegmentTreeNode a, SegmentTreeNode b)
{
	SegmentTreeNode tmp;
	tmp.s = a.s+b.s;
	tmp.pMax = max(a.pMax,a.s+b.pMax);
	tmp.sMax = max(b.sMax,a.sMax+b.s);
	tmp.Max = max(tmp.pMax,max(tmp.sMax,max(a.Max,max(b.Max,a.sMax+b.pMax))));

	return tmp;
}

int arr[MAX];
SegmentTreeNode tree[4*MAX];


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
void build_tree(int nd, int l, int r)
{
	if(l>r)return; //out of bound
	if(l==r){ //reached leaves

		//INITIALIZE LEAVES LOGIC HERE..eg:
		tree[nd].pMax=tree[nd].sMax=tree[nd].Max=tree[nd].s=arr[l];

		/*********WRITE NOTHING BELOW THIS*************/
		return;
	}

	build_tree(left(nd),l,mid(l,r));
	build_tree(right(nd),1+mid(l,r),r);

	//INITIALIZE NODE MERGING RULES HERE..eg:

	tree[nd] = merge(tree[left(nd)],tree[right(nd)]);
}

void update_tree(int nd,int l, int r, int i,int j, int val){
	if(l>r||l>j||r<i)
		return;
	if(l==r){
		tree[nd].pMax=tree[nd].sMax=tree[nd].Max=tree[nd].s=val;
		return;
	}
	update_tree(left(nd),l,mid(l,r),i,j,val);
	update_tree(right(nd),1+mid(l,r),r,i,j,val);

	tree[nd]=merge(tree[left(nd)],tree[right(nd)]);
}

SegmentTreeNode query_tree(int nd, int l, int r, int i, int j)
{
	if(l>r||l>j||r<i){//out of bound

		//INSERT PROGRAM SPECIFIC RETURN LOGIC HERE..eg: MUST RETURN INVALID
		//return 0/INF/-INF;
		return {-INF,-INF,-INF,-INF};
	}

	if(l>=i&&r<=j) //current [l,r] segment is totaly within [i,j]
		return tree[nd];

	SegmentTreeNode q1 = query_tree(left(nd),l,mid(l,r),i,j);
	SegmentTreeNode q2 = query_tree(right(nd),1+mid(l,r),r,i,j);

	//INSERT PROGRAM SPECIFIC NODE MERGING RULES HERE..e.g:
	return merge(q1,q2);
}

/*****************WITHOUT_LAZY_END************************************************/

int main()
{
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int N,M,a,b,t;
	scanf("%d",&N);
	FOR(i,0,N)
		scanf("%d",arr+i);
	build_tree(1,0,N-1);
	scanf("%d",&M);
	FOR(i,0,M){
		scanf("%d %d %d",&t,&a,&b);
		if(!t){
			update_tree(1,0,N-1,a-1,a-1,b);
		}
		else
			cout<<query_tree(1,0,N-1,--a,--b).Max<<endl;
	}
	

    return 0;
}
