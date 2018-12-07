#include <stdio.h>
#include <stdlib.h>


struct Node{
    int vertex;
    int cost;
    struct Node* next;  
};

struct Graph{
    int numVertices;
    struct Node** adjList;
};


struct Node* createNode(int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int numVertices)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->adjList = (struct Node**)malloc(numVertices*sizeof(struct Node*));

    int i;
    for (i=0;i<numVertices;i++){
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    //adding edge from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // adding edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void printGraph(struct Graph* graph){
    
    printf("Printing graph with Node: %d\n",graph->numVertices);
    int v;

    for(v = 0;v<graph->numVertices;v++){
        struct Node* tmp = graph->adjList[v];
        printf("%d|",v);
        while(tmp){
            printf(" %d ->",tmp->vertex);
            tmp=tmp->next;
        }
        printf("\n");
    }
}


void deleteGraph(struct Graph* graph){
    int i;
    for(i=0;i<graph->numVertices;i++){
        struct Node* tmp = graph->adjList[i];
        while(tmp){
            struct Node* ttmp = tmp->next;
            free(tmp);
            tmp=ttmp;
        }
    }
    free(graph);
}



int* visited;
int* inCurrentRun;


bool DirectedCycleCheck(struct Graph* graph,int vtx)
{
    if(!visited[vtx]){
        visited[vtx] = 1;
        inCurrentRun[vtx] = 1;

        struct Node* currentNode = graph->adjList[vtx];
        while(currentNode){
            if(inCurrentRun[currentNode->vertex])
                return true;
            else if(!visited[currentNode->vertex])
                if(DirectedCycleCheck(graph,currentNode->vertex))
                    return true;
            
            currentNode = currentNode->next;
        }

    }
    inCurrentRun[vtx] = 0;
    return false;
}

bool UndirectedCycleCheck(struct Graph* graph, int vtx,int parent)
{
    visited[vtx] = 1;

    struct Node* currentNode = graph->adjList[vtx];

    while(currentNode){
        if(!visited[currentNode->vertex]){
            if(UndirectedCycleCheck(graph,currentNode->vertex,vtx))
                return true;
        }
        else if(currentNode->vertex != parent)
            return true;
        
        currentNode = currentNode->next;
    }

    return false;

}

bool hasCycle(struct Graph* graph, bool directed = 1)
{
    visited = (int*)malloc(graph->numVertices*(sizeof(int)));
    inCurrentRun = (int*)malloc(graph->numVertices*(sizeof(int)));


    int i;
    for(i=0;i<graph->numVertices;i++)
        visited[i] = inCurrentRun[i] = 0;

    for(i=0;i<graph->numVertices;i++)
        if(!visited[i]){
            if(directed && DirectedCycleCheck(graph,i))
                return true;
            else if(UndirectedCycleCheck(graph,i,-1))
                return true;
        }
    
    return false;
}


int main()
{
    // struct Graph *g = createGraph(4); 
    // addEdge(g,0, 1); 
    // addEdge(g,0, 2); 
    // addEdge(g,1, 2); 
    // addEdge(g,2, 0); 
    // addEdge(g,2, 3); 
    // addEdge(g,3, 3); 

    // printGraph(g);

    // if(hasCycle(g,1))
    //     printf("LOOPY PIECE OF SHIT!\n");
    // else
    //     printf("OH YOU BEAUTIFUL DAG!!");

    
    struct Graph* g = createGraph(5);
    addEdge(g,1,0);
    addEdge(g,0,2);
    addEdge(g,1,2);
    // addEdge(g,2,0);
    addEdge(g,0,3);
    addEdge(g,3,4);

    printGraph(g);
    if(hasCycle(g,0))
        printf("LOOPY PIECE OF SHIT!\n");
    else
        printf("OH YOU BEAUTIFUL DAG!!");


}