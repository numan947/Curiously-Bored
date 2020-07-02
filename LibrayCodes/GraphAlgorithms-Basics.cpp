#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define INF 100000

/**
 * Basic Traversal Related Algorithms:
 * 1. DFS
 * 2. BFS
 * 3. Finding SCC in Undirected Graph
 * 4. Flood Fill
 * 5. Topological Sort
 * 6. Bipartite Graph Checking
 * 7. Graph Property Checking Using DFS
 * 8. Finding Articulation Points and Bridges in a Graph
 * 9. Finding SCC in Directed Graph
*/



/**
 * Depth First Search: Searches the deepest nodes first
*/

//AdjList[u][v].fi = neighbour of the u
//AdjList[u][v].se = weight of the edge that connects u to the neighbour
vector<pair<int,int> >AdjList[MAX];

//possible states of a vertex
#define UNVISITED 0 //we didn't encounter this vertex yet
#define EXPLORED 1 //we encountered the vertex, but didn't completed exploring all the outgoing edges
#define VISITED 2 //we explored all the outgoing edges of a vertex


//essentially stores the state of a vertex in dfs
vector<int>dfs_num; 

void dfs(int u)
{
    dfs_num[u] = VISITED;

    for(int j=0;j<AdjList[u].size();j++){
        pair<int,int> v = AdjList[u][j];

        if(dfs_num[v.first]==UNVISITED)
            dfs(v.first);
    }
}
/**
 * int main()
 * {
 *  dfs_num.assign(N,0);
 *  for(int i=0;i<N;i++)
 *     if(dfs_num[i]==UNVISITED)
 *          dfs(i);
 * }
*/


/**
 * Breadth First Search: Searches the nodes layer by layer, can find SSSP in unweighted path
*/

//d[v] = contains distance from a source node u
vector<int>dst;
vector<int>bfs_parent;
//number of nodes in the graph
int N;

//s is the source vertex
void bfs(int s)
{
    bfs_parent.assign(N,-1);
    dst.assign(N,INF);
    queue<int>q;

    dst[s] = 0;
    bfs_parent[s] = s;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        

        for(int j=0;j<AdjList[u].size();j++)
        {
            pair<int,int> v = AdjList[u][j];
            
            if(dst[v.first]==INF){
                bfs_parent[v.first] = u;
                dst[v.first] = 1+ dst[u];
                q.push(v.first);
            }
        }
    }
}


/**
 * 
 * Finding SCC + Number of SCC
 * Can be solved using: DFS, BFS, UFDS
 * 
*/

int FindNumberOfScc()
{
    dfs_num.assign(N,0);
    int numScc = 0;
    for(int i=0;i<N;i++)
        if(!dfs_num[i]){
            numScc++;
            dfs(i);
        }

    return numScc;
}


/**
 * Flood Fill: Finding Number of Vertices in a 
 * Connected Component in an Implicit Graph
*/

int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};
char grid[MAX][MAX];
int R,C;//boundary of the implicit graph grid

int FloodFill(int r, int c, char newColor, char colorToMatch)
{
    if(r<0||r>=R||c<0||c>=C)
        return 0;
    if(grid[r][c]!=colorToMatch)
        return 0;
    
    //current vertex
    int ans = 1;
    //so that we don't get stuck in an infinite loop
    grid[r][c] = newColor;

    for(int i=0;i<8;i++)
    {
        //check if more vertex are reachable usgin 8-directional movement
        ans+= FloodFill(r+dr[i],c+dc[i],newColor,colorToMatch);
    }
    return ans;
}


/**
 * Topological Sort: A Linear Ordering of the Vertices in a Graph G,
 * where Node u comes before Node v, if there is an edge from u to v (u->v)
 * Every DAG has at least 1 and possibly more Topological Ordering
 * 
 * We can slightly modify dfs(u) to find out the topological order of a a Graph
*/

vector<int>TopologicalOrder;

void dfs_top_ord(int u)
{
    //Tarjan's Simplified TopSort Algorithm

    dfs_num[u]= VISITED;

    for(int i=0;i<AdjList[u].size();i++)
    {
        pair<int,int> v = AdjList[u][i];

        if(dfs_num[v.first]==UNVISITED)
            dfs(i);
    }
    //all  u->v edges are explored, so add u to the list;
    //reversing the list, we can get the Topological Order
    TopologicalOrder.push_back(u);
}

//kahn's algorithm can also detect cycle in graph
map<int,int>InDegree; //keeps track of the InDegrees

void topsort_kahn()
{
    // may need priority Q, if condition like this is given:
    // In the case there is no relation between two beverages Dilbert should start drinking the one that 
    // appears first in the input
    queue<int>q;
    for(int i=0;i<N;i++){
        if(!InDegree[i]){
            q.push(i);
            
        }
    }

    int cnt = 0;//keeps track of number of visited vertices

    while(!q.empty()){
        int u = q.front();
        q.pop();

        TopologicalOrder.push_back(u);
        cnt++;
        for(int i=0;i<AdjList[u].size();i++){
            int v = AdjList[u][i].first;
            if(--InDegree[v]==0){
                q.push(v);
            }
        }
    }

    if(cnt!=N){
        //There is a cycle in the graph
    }

}



/**
 * Bipartite Graph Checking: This is basically to find out if, the Graph
 * can be Bi-Colored.
 * 
 * Can be solved using both DFS and BFS
 * 
 * There are atmost (N*N)/4 edges in a Graph, if it is bicolorable
 * This can be used for trivial reject
*/

vector<int>color;
bool is_bicolorable_bfs(int s)
{
    color.assign(N,INF);
    queue<int>q;

    color[s] = 0;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int j=0;j<AdjList[u].size();j++){
            pair<int,int>v = AdjList[u][j];
            
            if(color[v.first]==INF){
                color[v.first] = 1-color[u];
                q.push(v.first);
            }
            else if(color[v.first] == color[u])
                return false;
        }
    }
    return true;
}



/**
 * Graph Property Checking:
 * 
 * Tree Edge: An edge from EXPLORED -> UNVISITED
 * 
 * Back Edge: An edge from EXPLORED1 -> EXPLORED2, where EXPLORED2 is not parent of EXPLORED1
 * (for undirected graph)
 * 
 * Cross Edge: An edge from EXPLORED -> VISITED
 * 
*/

//stores the immediate parent of a vertex
vector<int>dfs_parent;

void dfs_prop_check(int u)
{
    //just got to this vertex, mark it as EXPLORED
    dfs_num[u] = EXPLORED;

    for(int j=0;j<AdjList[u].size();j++){
        pair<int,int> v = AdjList[u][j];

        //Tree Edge : EXPLORED -> UNVISITED
        if(dfs_num[v.first]==UNVISITED){ 
            dfs_parent[v.first] = u;
            dfs_prop_check(v.first);
        }
        //REVERSE EDGE: Can be a Back Edge
        else if(dfs_num[v.first]==EXPLORED)
        {
            //Back Edge: EXPLORED -> EXPLORED
            if(dfs_parent[u]!=v.first){
                //THIS IS BACK EDGE
            }
            else{
                //THIS IS JUST A REVERSE EDGE TO PARENT OF u, i.e v is parent of u
            }
        }
        else if(dfs_num[v.first]==VISITED){
            //Cross Edge: EXPLORED -> VISITED
        }
    }
    //all edges of u is explore now, so, mark u as VISITED

    dfs_num[u] = VISITED;
}



/**
 * Finding Articulation Points and Bridges: Undirected Graph
 * 
 * Articulation Points: 
 * These are the vertices in a graph, which, if deleted,
 * makes the rest of the graph disconnected
 * 
 * Bridges:
 * These are the edges in a graph, which, if deleted,
 * makes the rest of the graph disconnected
 * 
 * 
 * Naive Algorithm:
 * Run O(V+E) DFS --> count number of connected components in a the Graph, it's usually just 1
 * 
 * For each vertex v in V:
 *  remove vertex v and incident edges
 *  Run O(V+E) DFS and check if connected components increases
 *  if yes --> vertex v is a Articulation Point, same logic can be applied to Bridges
 * 
 * Efficient Algorithm:
 * 
 * Aside from dfs_num, maintain dfs_low.
 * 
 * dfs_num[u] = time of first visit of u vertex, an iteration
 * counter is enough to act as time.
 * 
 * dfs_low[u] = the lowest dfs_num rechable from current DFS spanning subtree of u.
 * 
 * Initially, dfs_num[u] = dfs_low[u] = time_of_visiting_u_for_the_first_time
 * 
 * So, dfs_low[u] can only be smaller if there is a back edge in the graph.
 * 
 * When we are in a node u, with v as its neighbour,
 * if dfs_low[v] >= dfs_num[u] ==> u vertex is an Articualtion Point
 * 
 * if dfs_low[v]>dfs_num[u] ==> u-v edge is a Bridge
 * 
 * SPECIAL CASE: ==> Not detected by the algorithm
 * The root of the dfs spanning tree is an Articualtion Point,
 * only if it has more than one children in the dfs spanning tree.
 * 
*/

vector<int>dfs_low;

int current_time; //initially 0
int dfsRoot; //initially the vertex that is passed as u in the function
int rootChildren; //initially 0 before passing root to the function


void ArticulationPointAndBridge(int u)
{
    dfs_low[u] = dfs_num[u] = current_time++;

    for(int i=0;i<AdjList[u].size();i++){
        pair<int,int>v = AdjList[u][i];

        if(dfs_num[v.first]==UNVISITED){
            dfs_parent[v.first] = u;
            
            if(dfsRoot==u)
                rootChildren++;
            
            ArticulationPointAndBridge(v.first);

            if(dfs_low[v.first]>=dfs_num[u]){
                //u is an articulation point
            }
            if(dfs_low[v.first]>dfs_num[u]){
                //u-v is a bridge
            }
            //update dfs_low[u], as the dfs_low[v.first] is the lowest we can reach from u
            dfs_low[u] = min(dfs_low[u],dfs_low[v.first]);

        }
        else if(dfs_parent[u]!=v.first){
            //this is the back edge, we can reach dfs_num[v.first] from u,
            //and v.first should have smaller time
            dfs_low[u] = min(dfs_low[u],dfs_num[v.first]);
        }
    }
}


/**
 * SCC in Directed Graph:
 * 
 * Two Known Algorithms for Finding SCCs in Directed Graphs:
 *  
 *  1. Kosaraju
 *  2. Tarjan
 * 
 * Tarjan is similar to ArticulationPoint/Bridge finding algorithm.
 * 
 * In addition to dfs_num and dfs_low, we keep a vector and use it as a stack.
 * We add u to the back of the vector ==> this vector keeps track of the explored vertices.
 * 
 * Updating dfs_low is different from that of ArticulationPoint and Bridges:
 * 
 * Here we only update dfs_low, if the vertex in consideration is visited: 
 * dfs_low[u] = min(dfs_low[u],dfs_low[v.first]) ==> only if v is already visited
 * 
 * Now, if we still have a vertex in the dfs spanning tre, with dfs_low[u] == dfs_num[u],
 * then, it must be the root of an SCC.
 * 
 * The memebers of that SCC are found by popping the vector from end until we reach u.
 * 
 * */

int numSCC; //initially zero
vector<int>S; //keeps track of currently explored vertices to find out the SCC members
vector<int>visited; //keeps track of visited, so that overlapping SCCs don't update
void tarjanSCC(int u)
{
    dfs_low[u] = dfs_num[u] = current_time++;
    S.push_back(u);
    visited[u] = VISITED;
    for(int i=0;i<AdjList[u].size();i++){
        pair<int,int>v = AdjList[u][i];

        //if v is not visited, visit it first
        if(dfs_num[v.first]==UNVISITED)
            tarjanSCC(v.first);
        
        //if v is visited, try to update the dfs_low[u]
        if(visited[v.first]==VISITED)
            dfs_low[u] = min(dfs_low[u],dfs_low[v.first]);
        

        //check if cycle is created yet, if current vertex is inside a cycle, and not the root of
        //that cycle, dfs_num[u] != dfs_low[u], otherwise, dfs_low[u] == dfs_num[u], as dfs explores
        //all outgoing edges of the node

        if(dfs_low[u]==dfs_num[u]){

            while(1){
                int v = S.back();
                visited[v] = UNVISITED;
                S.pop_back();
                if(u==v)
                    break;
            }
        }
    }
}