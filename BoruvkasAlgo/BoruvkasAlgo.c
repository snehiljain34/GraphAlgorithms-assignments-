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
    Edge* edge;
};
struct Subset
{
    int parent;
    int rank;
};
//Function to input the graph edge-wise and make a structure for the edges.
void read_graph(struct Graph * G)
{
    int i,j;
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
        
    }
}
//Finding set of an element i(path compression)
int find(struct Subset subsets[],int i)
{
    if(subsets[i].parent!=i)
        subsets[i].parent=find(subsets,subsets[i].parent);
    return subsets[i].parent;
}
//does union of two sets of x and y
void Union(struct Subset subsets[],int x,int y)
{
    int xroot = find(subsets,x);
    int yroot = find(subsets,y);
    //attach smaller rank tree under root of higher rank tree
    if(subsets[xroot].rank<subsets[yroot].rank)
        subsets[xroot].parent=yroot;
    else if(subsets[xroot].rank>subsets[yroot].rank)
        subsets[yroot].parent=xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
    
}
void boruvka(struct Graph * G)
{
    int i,v;
    struct Subset *subsets = malloc(G->V*sizeof(struct Subset));
    int *cheapest = malloc(G->V*sizeof(int));
    for(v=0;v<G->V;v++)
    {
        subsets[v].parent =v;
        subsets[v].rank=0;
        cheapest[v]=-1;
    }
    int numTrees = G->V;
    int MSTWeight = 0;
    printf("\nMST construction\n");
    //Keep combining components/trees of forest to get 1 single connected component
    while(numTrees>1)
    {
    //Traverse through each edge and update the cheapest cost of every component
        for(i=0;i<G->E;i++)
        {   //Find components(or sets) of two corners of current edge
            int set1=find(subsets,G->edge[i].src);
            int set2=find(subsets,G->edge[i].dest);
            //If two corners of current edge belong to same set ignore.
            if(set1==set2)
                continue;
            //If not part of same set check if current edge is closer to previos cheapest edges of set1 and set2
            else
            {
                {
                    if(cheapest[set1]==-1||G->edge[cheapest[set1]].weight>G->edge[i].weight)
                        cheapest[set1]=i;
                    if(cheapest[set2]==-1||G->edge[cheapest[set2]].weight>G->edge[i].weight)
                        cheapest[set2]=i;
                    
                }
            }
        }
        //consider the above picked cheapest edges and add them
        for(i=0;i<G->V;i++)
        {       //check if cheapest for current set exists
                if(cheapest[i]!=-1)
                {
                        int set1 = find(subsets, G->edge[cheapest[i]].src);
                        int set2 = find(subsets, G->edge[cheapest[i]].dest);

                        if (set1 == set2)
                            continue;
                        MSTWeight += G->edge[cheapest[i]].weight;
                        printf("Edge %d-%d included in MST\n",
                        G->edge[cheapest[i]].src, G->edge[cheapest[i]].dest,
                        G->edge[cheapest[i]].weight);
                        // Do a union of set1 and set2 and decrease number of components
                        Union(subsets, set1, set2);
                        numTrees--;
                        
                }
        }
        printf("Number of components after iteration: %d\n",numTrees);
        //reset array of cheapest edges
        for(i=0;i<G->V;i++)
        {
            cheapest[i]=-1;
        }
            
    }
        printf("Weight of MST is %d\n",MSTWeight);
        return;
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
    boruvka(G);
    return 0;

}