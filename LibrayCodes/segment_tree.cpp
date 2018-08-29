#include <bits/stdc++.h>
using namespace std;


const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

//type--1
void point_modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}
int range_query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

//type--2
void range_modify(int l, int r, int value) { //no lazy
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] += value;
    if (r&1) t[--r] += value;
  }
}

int point_query(int p) {
  int res = 0;
  for (p += n; p > 0; p >>= 1) res += t[p];
  return res;
}

void push() {
  for (int i = 1; i < n; ++i) {
    t[i<<1] += t[i];
    t[i<<1|1] += t[i];
    t[i] = 0;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build();
  modify(0, 1);
  printf("%d\n", query(3, 11));
  return 0
}



//Non-commutative combiner functions

void modify(int p, const S& value) {
  for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}

S query(int l, int r) {
  S resl, resr;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]);
    if (r&1) resr = combine(t[--r], resr);
  }
  return combine(resl, resr);
}











//Increment modifications, queries for maximum

int h = sizeof(int) * 8 - __builtin_clz(n);
int d[N];


void apply(int p, int value) {
    t[p] += value;
    if (p < n) d[p] += value; //if p is not a leaf, save lazy
}
void build(int p) { //updates all the parents of a given node
    while (p > 1) 
    {
        p >>= 1;
        t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
    }
}


void push(int p) { //propagates changes from all the parents of a given node down the tree starting from the root
    for (int s = h; s > 0; --s){
        int i = p >> s;
        if (d[i] != 0){
            apply(i<<1, d[i]);
            apply(i<<1|1, d[i]);
            d[i] = 0;
        }
    }
}

void update_inc(int l, int r, int value) { //process increment using the loop and update the tree by calling build
    l += n, r += n;
    int l0 = l, r0 = r;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) apply(l++, value);
        if (r&1) apply(--r, value);
    }
    build(l0);
    build(r0 - 1);
}


int query(int l, int r) { //answer query using loops, but before that, need to push the changes down the nodes we'll be using,
                          //usually pushing changes from the parents of the border leaves are enough
    l += n, r += n;
    push(l);
    push(r - 1);
    int res = -2e9;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, t[l++]);
        if (r&1) res = max(t[--r], res);
    }
    return res;
}




//Assignment modifications, sum queries

//calculate value at node p

//We suppose there's a value we never use for modification, in our case it's 0. 
//In case there's no such value — we would create additional boolean array and 
//refer to it instead of checking d[p] == 0


//k = length of the interval corresponding to node p;
//We can avoid passing this parameter if we precalculate this value for every node in a separate array
//or calculate it from the node index on the fly
void calc(int p, int k) {
  if (d[p] == 0) t[p] = t[p<<1] + t[p<<1|1];
  else t[p] = d[p] * k;
}

//apply change to a node
void apply(int p, int value, int k) {
  t[p] = value * k;
  if (p < n) d[p] = value;
}

void build(int l, int r) {
  int k = 2;
  for (l += n, r += n-1; l > 1; k <<= 1) {
    l >>= 1, r >>= 1;
    for (int i = r; i >= l; --i) calc(i, k);
  }
}

void push(int l, int r) {
  int s = h, k = 1 << (h-1);
  for (l += n, r += n-1; s > 0; --s, k >>= 1)
    for (int i = l >> s; i <= r >> s; ++i) if (d[i] != 0) {
      apply(i<<1, d[i], k);
      apply(i<<1|1, d[i], k);
      d[i] = 0;
    }
}

void modify(int l, int r, int value) {
  if (value == 0) return;
  push(l, l + 1);
  push(r - 1, r);
  int l0 = l, r0 = r, k = 1;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
    if (l&1) apply(l++, value, k);
    if (r&1) apply(--r, value, k);
  }
  build(l0, l0 + 1);
  build(r0 - 1, r0);
}

int query(int l, int r) {
  push(l, l + 1);
  push(r - 1, r);
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}








struct SegmentTreeNode {
  void assignLeaf(T value) {

  }
  
  void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
  }
  
  V getValue() {
  }
};





//*****************************RECURSIVE********************************




//range-->[a,b]
void build_tree(int cur_node,int l, int r)
{
    if(l>r)return; //out
    if(l==r){
        tree[cur_node] = arr[l];
        return;
    }

    build_tree(cur_node*2,l,(l+r)/2);
    build_tree(cur_node*2+1,1+(l+r)/2,r);

    tree[cur_node] = max(tree[cur_node*2],tree[cur_node*2+1]);
}


void update_tree(int cur_node,int l, int r,int i,int j,int val)
{
    if(l>r||l>j||r<i)
        return;
    if(l==r){
        tree[cur_node]+=val;
        return;
    }

    update_tree(2*cur_node,l,(l+r)/2,i,j,val);
    update_tree(2*cur_node+1,1+(l+r)/2,i,j,val);

    tree[cur_node] = max(tree[cur_node*2],tree[1+2*cur_node]);
}

int query_tree(int cur_node,int l, int r,int i,int j)
{
    if(l>r||l>j||r<i)
        return -INF;
    if(l>=i&&r<=j)
        return tree[cur_node];

    int q1 = query_tree(node*2,l,(l+r)/2,i,j);
    int q2 = query_tree(node*2+1,1+(l+r)/2,r,i,j);

    return max(q1,q2);
}




int lazy[MAX];

void update_tree(int cur_node,int l, int r, int i, int j,int val)
{
    if(lazy[node]!=0){ //pending update on the node
        tree[node]+=lazy[node];

        if(l!=r){ //this is not a leaf, so mark children for update
            lazy[2*cur_node]+=lazy[node];
            lazy[1+2*cur_node]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(l>r||l>j||i<r) //out of bound
        return;

    if(l>=i&&j<=r){ //fully inside the segment
        tree[node]+=val;
        if(l!=r){
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return;
    }

    update_tree(2*cur_node,l,(l+r)/2,i,j,val);
    update_tree(2*cur_node+1,1+(l+r)/2,r,i,j,val);

    tree[cur_node] = max(tree[2*cur_node],tree[1+2*cur_node]);
}


int query_tree(int cur_node,int l, int r,int i, int j)
{
    if(l>r||l>j||r<i)
        return -INF;

    if(lazy[node]!=0){ //pending update
        tree[node]+=lazy[node];
        if(l!=r){
            tree[2*node]+=lazy[node];
            tree[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(i>=l&&j<=r)
        return tree[node];

    int q1 = query_tree(2*cur_node,l,(r+l)/2,i,j);
    int q2 = query_tree(1+2*cur_node,1+(r+l)/2,i,j);

    return max(q1,q2);
}