#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Graph {
    int v,e;
    int ** graph;
    int tot_weight;
    int * deg;
    int * odd;
};
//Function to input the graph as adjacency matrix
void read_graph(struct Graph * G)
{
    G->graph=malloc(G->v*sizeof(int*));
    int i,j;
    //Adjacency matrix with edge weights
    for(i=0;i<G->v;i++)
    {
        G->graph[i]=calloc(G->v,sizeof(int));
    }
    //Array to store degree of all vertices
    G->deg=calloc(G->v,sizeof(int));
    G->tot_weight=0;
    printf("\nEnter vertex pairs with edge in between : Eg. (0 1 w) -> Edge between V0 and V1 with weight w\n");
    for(i=0;i<G->e;i++)
    {
        int v1,v2,weight;
        printf("Edge%d :",i+1);
        scanf("%d %d %d",&v1,&v2,&weight);
        G->graph[v1][v2]=weight;
        G->graph[v2][v1]=weight;
        //Adding to degrees of the vertices
        {G->deg[v1]++;G->deg[v2]++;}
        G->tot_weight+=weight;
    }
}

int isBridge(struct Graph * G,int u, int v){
   int deg = 0;
   int i;
   for(i = 0; i<G->v; i++)
      if(G->graph[v][i])
         deg++;
      if(deg>1){
         return 0; //the edge is not forming bridge
      }
   return 1; //edge forming a bridge
}

void fleuryAlgorithm(struct Graph * G,int start){
   int edge = G->e;
   int v;
   for(v = 0; v<G->v; v++){
      if(G->graph[start][v]){ //when (u,v) edge is presnt and not forming bridge
         if(edge <= 1 || !isBridge(G,start, v))
         {
            printf("%d -- %d ",start,v);
            G->graph[start][v] = G->graph[v][start] = 0; //remove edge from graph
            G->e--;
            fleuryAlgorithm(G,v);
         }
      }
   }
}


int dijkstra(int ** G,int n,int startnode,int endnode)
{
    int i,j;
	int ** cost=malloc(sizeof(int*)*n);
    int ** distance=malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
        {
            cost[i]=malloc(n*sizeof(int));
            distance[i]=malloc(n*sizeof(int));
        }
    int * pred=malloc(n*sizeof(int));
	int * visited=malloc(n*sizeof(int));
    int count,mindistance,nextnode;
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INT_MAX;
			else
				cost[i][j]=G[i][j];
	
	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count<n-1)
	{
		mindistance=INT_MAX;
		
		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
			
			//check if a better path exists through nextnode			
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}
    printf("\nMinimun cost between the two odd degree vertices: %d", distance[endnode]);
    printf("\nPath=%d",endnode);		
	j=i;
	do
	{
		j=pred[j];
		printf("<-%d",j);
	}while(j!=startnode);
    return distance[endnode];
}


void main()
{
    int i,j;
    struct Graph *G;
    struct Graph g;
    G=&g;
    printf("Number of vertices: ");
    scanf("%d",&G->v);
    printf("Number of edges: ");
    scanf("%d",&G->e);
    read_graph(G);
    //Array to store all odd degree vertices
    G->odd=malloc(sizeof(int)*G->v);
    int o=0;
    for(i=0;i<G->v;i++)
    {
        if(G->deg[i]%2!=0)
            G->odd[o++]=i;

    }

    printf("Number of odd degree vertices : %d\n",o);
    if(o==0)
        {
            printf("Graph contains Eulerian circuit and hence miniumun cost path is given by sum of all edge weights.\n");
            printf("Minimun weight path for the Chinese postman problem has cost :%d\n",G->tot_weight);
            fleuryAlgorithm(G,0);
        }
    if(o==2)
    {
        printf("Graph contains Eulerian path and hence miniumun cost path is given by sum of all edge weights + min cost between the two odd vertices.\n");
        int mincost=dijkstra(G->graph,G->v,G->odd[0],G->odd[1]);
        printf("\nMinimun weight path for the Chinese postman problem has cost :%d\n", G->tot_weight+mincost);        
        //Euler path 
        fleuryAlgorithm(G,G->odd[0]);
        //Reconnecting edge to complete circuit
        printf("%d -- %d",G->odd[1],G->odd[0]);
    }
    if(o!=0 && o!=2)
    {
         printf("Graph contains neither Eulerian path or circuit and hence miniumun cost path is given by sum of all edge weights + min cost between the edges added to make graph eulerian.\n");
         printf("Odd degree vertices are :\n");
         for(i=0;i<o;i++)
            printf("%d ",G->odd[i]);
        printf("\nOdd Vertex Possible Pairings with respective costs are :");
        for(i=0;i<o;i++)
            for(j=i+1;j<o;j++)
                printf("\n(%d , %d) with cost %d",G->odd[i],G->odd[j],dijkstra(G->graph,G->v,G->odd[i],G->odd[j]));
    }  
}