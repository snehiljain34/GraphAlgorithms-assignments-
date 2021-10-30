#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
typedef struct 
{
    int src,dest,weight;
}Edge;
struct Graph
{
    int V,E;
    int ** graph;
    Edge* edge;
};
//Function to input the graph edge-wise and make a structure for the edges.
void read_graph(struct Graph * G)
{
    int i,j;
    G->graph=malloc(G->V*sizeof(int*));
    for(i=0;i<G->V;i++)
    {
        G->graph[i]=calloc(G->V,sizeof(int));
    }
    G->edge=malloc(sizeof(Edge)*G->E);
    printf("\nEnter vertex pairs with edge in between : Eg. (0 1 w) -> Edge between V0 and V1 with weight w\n");
    for(i=0;i<G->E;i++)
    {
        int v1,v2,w;
        printf("Edge %d  :",i+1);
        scanf("%d %d %d",&v1,&v2,&w);
        G->edge[i].src=v1;
        G->edge[i].dest=v2;
        G->edge[i].weight=w;
        G->graph[v1][v2]=1;
        G->graph[v2][v1]=1;
    }
}

void sort_edges(struct Graph * G)
{
     int i,j,swap;
    for(i=0;i<(G->E)-1;i++)
    {
        swap=0;
        for(j=0;j<(G->E)-i-1;j++)
        {
            if(G->edge[j].weight<G->edge[j+1].weight)
            {
                swap=1;            
               Edge temp=G->edge[j];
               G->edge[j]=G->edge[j+1];
               G->edge[j+1]=temp;
            }
        }
        if(swap==0)
            break;
    }
}


void dfs(int ** graph,int v,int * visited,int start)
{
    int i;
    visited[start]=1;
    for(i=0;i<v;i++)
    {
        if(graph[start][i]==1 && (!visited[i]))
        {
            dfs(graph,v,visited,i);
        }
    }
}
int isConnected(struct Graph * G)
{
    int * visited=calloc(G->V,sizeof(int));
    dfs(G->graph,G->V,visited,0);
    int i,f=1;
    for(i=0;i<G->V;i++)
    {
        if(visited[i]==0)
            {
                f=0;
                break;
            }
    }
    if(f==1)
        return 1;
    else
    {
        return 0;
    }
    
}

int main()
{   
    struct Graph *G;
    struct Graph g;
    G=&g;
    printf("Number of vertices: ");
    scanf("%d",&G->V);
    printf("Number of edges: ");
    scanf("%d",&G->E);
    printf("Graph with %d Edges %d Vertices",G->E,G->V);
    read_graph(G);
    sort_edges(G);
    int i;
    int f,src,dest,weight=0;
    for(i=0;i<G->E;i++)
    {
        src=G->edge[i].src;
        dest=G->edge[i].dest;
        G->graph[src][dest]=0;
        G->graph[dest][src]=0;
        f=isConnected(G);
        if(f==1)
            continue;
        else
        {
        printf("Edge (%d , %d) included in MST\n",src,dest);
        weight=weight+G->edge[i].weight;
        G->graph[src][dest]=1;
        G->graph[dest][src]=1;
        }
    }
    printf("Weight of MST is %d",weight);
    return 0;
}