#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define INF 1000003


//AdjList[u][v].fi = neighbour of the u
//AdjList[u][v].se = weight of the edge that connects u to the neighbour
vector<pair<int,int> >AdjList[MAX];

//possible states of a vertex
#define UNVISITED 0 //we didn't encounter this vertex yet
#define EXPLORED 1 //we encountered the vertex, but didn't completed exploring all the outgoing edges
#define VISITED 2 //we explored all the outgoing edges of a vertex


//essentially stores the state of a vertex in dfs
vector<int>dfs_num; 


/**
 * SSSP: Single Source Shortest Path
 * These are the class of algorithms that, given a graph and a single starting node, can find
 * one of the shortest paths, from that node to all other nodes.
 * */

/**
 * 1. SSSP on UnWeighted/Constantly Weighted Graph (BFS)
 * 2. SSSP on Weighted Graph without Negative Cycle (Dijkstra)
 * 3. SSSP on Weighted Graph with Negative Cycle (Bellman-Ford)
*/




/**
 * 1. SSSP on UnWeighted Graph
 * 
 * BFS visits every vertices in a graph from a starting vertice
 * in a layer-by-layer manner. 
 * 
 * In unweighted graph, the distance between two neighbouring verices is simply 1 unit.
 * So, just running bfs and updating distance of a vertice using its parent's distance is enough.
 * if(vis[v]==UNVISITED)
 *      dist[v] = 1+dist[u]
 * If we need reconstruct the shortes path from a node to another: we can just store the BFS spanning tree
 * using vector<int>bfs_par.
*/

// CODE FOR BFS IS GIVEN IN GraphAlgorithms-Basics.cpp

int s; //this is usually the starting vertex
int V; //this is usually the numebr of vertices in the graph
vector<int>bfs_parent; //stores the parent of different nodes
/**
 * Print shortest path from vertex s-->u
*/
void printPath(int u)
{
    if(u==s){
        cout<<s;
        return;
    }
    printPath(bfs_parent[u]);
    cout<<" "<<u;
}


/**
 * 2. SSSP on Weighted Graph
 * 
 * For weighted graph there can be longer path, that has shorter total weights than the simple
 * path found by BFS. So, BFS doesn't work in this type of graph.
 * 
 * To solve SSSP on weighted graph, we use greedy Dijkstra algorithm.
 * The implementation below is a variant of Dijkstra's algorithm.
 * 
 * We maintain a priority_queue --> pq, it stores pairs of vertex information.
 * 
 * First item, d --> distance of the vertex from the source
 * Second item, u --> vertex number
 * 
 * pq --> sorted based on the increasing distance from the source, tie resolution ==> vertex number
 * Initially, pq: (0,s) ==> s--> source vertex
 * 1. Greedily takes out the first vertex from the priority queue, until pq is empty
 * 2. if distance d is greater than dist[u], then continue ((d,u) is the pair that we removed from priority_queue), otherwise process the node as follows : LAZY DELETION
 * 3. Try to relax all neighbours v, of vertex u. And every time we relax an edge u->v, we enqueue a pair (dist,v) in pq.
 * 
 * The algorithm uses LAZY DELETION technique, and as a result, causes more than one copy of a vertex inside the priority_queue
 * with different distances from source. This is why we have to check: whether the distance, dist[u]<d, before relaxing edges of u.
*/

vector<int>dist;

void DijkstraLazyDeletion(int src)
{
    dist.assign(V,INF);

    priority_queue<
    pair<int,int>, //what this priority queue will store 
    vector<pair<int,int> >, //what will be the internal data structure
    greater<pair<int,int> >  //how will the pq compare the elements
    >pq;

    dist[src] = 0;

    pq.push(make_pair(0,src));

    while(!pq.empty()){
        pair<int,int>temp = pq.top();
        pq.pop();

        int d = temp.first;
        int u = temp.second;

        if(d>dist[u]) //this is not the best, so ignore
            continue;
        
        for(int j=0;j<AdjList[u].size();j++){
            pair<int,int>v = AdjList[u][j];
            if(dist[u]+v.second<dist[v.first]){
                dist[v.first] = dist[u]+v.second;
                pq.push(make_pair(dist[v.first],v.first));
            }
        }
    }
}

/**
 * The modified Dijkstra’s implementation variant above may be different
 * from what you learn from other books. Analyze if this variant still runs in
 * O((V +E) log V ) on various types of weighted graphs?
 * 
 * Answer:
 * On positive weighted graph, yes. Each vertex will only be processed
 * once. Each time a vertex is processed, we try to relax its neighbors. Because of lazy
 * deletion, we may have at most O(E) items in the priority queue at a certain time, but
 * this is still O(log E) = O(log V 2 ) = O(2 × log V ) = O(log V ) per each dequeue or enqueue
 * operations. Thus, the time complexity remains at O((V + E) log V ). On graph with 
 * (a few) negative weight edges but no negative cycle, it runs slower due to the need of re-
 * processing processed vertices but the shortest paths values are correct. 
 * This is shown in an example in Section 4.4.4. On rare cases,
 * this Dijkstra’s implementation can run very slow on certain graph with some negative weight
 * edges although the graph has no negative cycle. If the graph has
 * negative cycle, this Dijkstra’s implementation variant will be trapped in an infinite loop.
*/