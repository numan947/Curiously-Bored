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
//number of nodes in the graph
int N;

//s is the source vertex
void bfs(int s)
{
    dst.assign(N,INF);
    queue<int>q;

    dst[s] = 0;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        

        for(int j=0;j<AdjList[u].size();j++)
        {
            pair<int,int> v = AdjList[u][j];
            
            if(dst[v.first]==INF){
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
    dfs_num[u]= VISITED;

    for(int i=0;i<AdjList[u].size();i++)
    {
        pair<int,int> v = AdjList[u][i];

        if(dfs_num[v.first]==UNVISITED)
            dfs(i);
    }
    //all  u->v edges are explored, so add u to the list;
    //reversing the list, we can get the Topological Order
    TopologicalOrder.push_back(i);
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
 * Finding Articulation Points and Bridges:
 * 
 * Articulation Points: 
 * These are the vertices in a graph, which, if deleted,
 * makes the rest of the graph disconnected
 * 
 * 
*/