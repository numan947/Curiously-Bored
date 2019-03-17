#include <bits/stdc++.h>
using namespace std;

/**
 * Segment tree or segtree is a basically a binary tree used for storing the intervals or segments. Each
 * node in the segment tree represents an interval.
 * Consider an array A of size N and a corresponding segtree T:
 * 
 * 1. The root of T will represent the whole array A[0:N-1].
 * 2. Each leaf in the segtree T will represent a single element A[i] such that 0 <= i < N.
 * 3. The internal nodes in the segtree tree T represent union of elementary intervals A[i:j] where 
 * 0 <= i < j < N.
 * 
 * 
 * 
 * 
 * The root of the segtree will represent the whole array A[0:N-1]. Then we will break the interval or
 * segment into half and the two children of the root will represent the A[0:(N-1) / 2] and A[(N-1) / 2 + 1
 * (N-1)]. So in each step we will divide the interval into half and the two children will represent the
 * two halves. So the height of the segment tree will be log2N. There are N leaves representing the N
 * elements of the array. The number of internal nodes is N-1. So total number of nodes are 2*N - 1.
 * 
 * 
 * 
 * Once we have built a segtree we cannot change its structure i.e., its structure is static. We can update
 * the values of nodes but we cannot change its structure. Segment tree is recursive in nature. Because of
 * its recursive nature, Segment tree is very easy to implement. Segment tree provides two operations:
 * 
 * 1. Update: In this operation we can update an element in the Array and reflect the corresponding change
 *    in the Segment tree.
 * 2. Query: In this operation we can query on an interval or segment and return the answer to the problem 
 *    on that particular interval.
*/


/**
 * Since a segtree is a binary tree, we can use a simple linear array to represent the segment tree. In
 * almost any segtree problem we need think about --> 
 * 
 * what we need to store in the segment tree?. 
 * 
 * For example, if we want to find the sum of all the elements in an array from index left to right, then
 * at each node (except leaf nodes) we will store the sum of its children nodes. If we want to find the
 * minimum of all the elements in an array from index left to right, then at each node (except leaf nodes)
 * we will store the minimum of its children nodes.
 * 
 * BUILD:
 * Once we know what we need to store in the segment tree we can build the tree using -->
 * recursion ( bottom-up approach ). We will start with the leaves and go up to the root and update the
 * corresponding changes in the nodes that are in the path from leaves to root. Leaves represent a single
 * element. In each step we will merge two children to form an internal node. Each internal node will 
 * represent a union of its children’s intervals. Merging may be different for different problems. So, 
 * recursion will end up at root which will represent the whole array.
 * 
 * UPDATE:
 * For update, we simply have to search the leaf that contains the element to update. This can be done by
 * going to either on the left child or the right child depending on the interval which contains the
 * element. Once we found the leaf, we will update it and again use the bottom-up approach to update the
 * corresponding change in the path from leaf to root.
 * 
 * QUERY:
 * To make a query on the segment tree we will be given a range from l to r. We will recurse on the tree
 * starting from the root and check if the interval represented by the node is completely in the range from
 * l to r. If the interval represented by a node is completely in the range from l to r, we will return
 * that node’s value.
*/

#define MAX 100


//index of tree node will be in order of O(4*n), as we are using 2*node, 2*node+1
int tree[4*MAX+10];
int arr[MAX+10];

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
        tree[node] = tree[2*node] + tree[2*node + 1];
    }
}

//point update: no lazy #O(logN)
void pointUpdate(int node, int st, int ed, int idx, int val)
{
    if(st==ed){
        //we are at the leaf, update it
        arr[idx]+=val;
        tree[node] = arr[idx];
    }
    else{
        int mid = (st+ed)>>1;

        if(st<=idx && idx<=mid){
            pointUpdate(2*node,st,mid,idx,val);
        }
        else{
            pointUpdate(2*node+1,mid+1,ed,idx,val);
        }

        //merge using the new update
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}


//range query:  #O(logN)
int rangeQuery(int node, int st, int ed, int l, int r)
{
    if(r<st||ed<l){
        // range represented by this node is completely outside the given range
        return 0;
    }

    //if used with lazy propagation
/*     if(lazyUpdate[node]){

        //update this node
        tree[node] += (ed-st+1)*lazyUpdateValue[node];

        if(st!=ed){
            lazyUpdate[2*node] = 1;
            lazyUpdateValue[2*node]+=lazyUpdateValue[node];

            lazyUpdate[2*node+1] = 1;
            lazyUpdateValue[2*node+1]+=lazyUpdateValue[node];
        }

        lazyUpdate[node] = 0;
        lazyUpdateValue[node] = 0;
    }
 */

    if(l<=st && ed<=r){
        // range represented by this node is completely inside the given range
        return tree[node];
    }

    // range represented by this node is partially inside and partially outside the given range

    int mid = (st+ed)>>1;
    int p1 = rangeQuery(2*node,st,mid,l,r);
    int p2 = rangeQuery(2*node+1,mid+1,ed,l,r);

    //merge result here
    return p1+p2;
}


/**
 * LAZY UPDATE:
 * update an interval from l to r, instead of a single element. One solution is to update all the elements
 * one by one. Complexity of this approach will be O(N) per operation since where are N elements in the 
 * array and updating a single element will take O(logN) time.
 * To avoid multiple call to update function, we can modify the update function to work on an interval.
*/

/**
 * Let's be Lazy i.e., do work only when needed. How ? When we need to update an interval, we will update a 
 * node and mark its child that it needs to be updated and update it when needed. For this we need an array 
 * lazy[] of the same size as that of segment tree. Initially all the elements of the lazy[] array will be 
 * 0 representing that there is no pending update. If there is non-zero element lazy[k] then this element 
 * needs to update node k in the segment tree before making any query operation.
*/

/**
 * To update an interval we will keep 3 things in mind:
 * 
 * 1. If current segment tree node has any pending update, then first add that pending update to current
 * node.
 * 
 * 2. If the interval represented by current node lies completely in the interval to update, then update
 * the current node and update the lazy[] array for children nodes.
 * 
 * 3. If the interval represented by current node overlaps with the interval to update, then update the
 * nodes as the earlier update function.
*/


// ----l------------r----
//----------st----------------ed---------

//true if a node need to be updated
bool lazyUpdate[4*MAX+10];

//contains the actual update
int lazyUpdateValue[4*MAX+10];


void rangeUpdate(int node, int st, int ed, int l, int r, int val)
{

    //if there is pending update, clear it first
    if(lazyUpdate[node]){
        //this node needs to be updated

        //update this node using the updateValue
        tree[node]+=(ed-st+1)*lazyUpdateValue[node];

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
        tree[node]+=(ed-st+1)*val;

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
    tree[node] = tree[node*2] + tree[node*2+1];
}

