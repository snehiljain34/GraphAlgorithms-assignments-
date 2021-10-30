#include<stdio.h>
#include<stdlib.h>
int ** read_graph(int m,int n,int e)
{
    int **graph=malloc(m*sizeof(int*));
    int i,j;
    for(i=0;i<m;i++)
        graph[i]=calloc(n,sizeof(int));
    printf("Enter Edge(V1 V2) with V1 belonging to Vm and V2 belonging to Vn\n");
    for(i=0;i<e;i++)
    {
        int v1,v2;
        printf("Edge %d :",i+1);
        scanf("%d %d",&v1,&v2);
        graph[v1][v2]=1;
    }
    printf("Matrix representing graph edges :\n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                printf("%d ",graph[i][j]);
            printf("\n");
        }
    return graph;
}
//dfs based recursive function that returns 1 if matching for vertex v is possible
int bpm(int ** graph,int m,int n,int u,int * seen,int * match)
{
    int v;
    for(v=0;v<n;v++)
    {
        //if there exists a edge between u(from Vm) and v(from Vn) and v is not visited yet
        if(graph[u][v] && !seen[v])
        {
            //Mark v as visited
            seen[v]=1;
            //if v is not matched with yet or previous match has alternate matches
            if(match[v]<0 || bpm(graph,m,n,match[v],seen,match))
            {
                match[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
//To get Matching from Vm to Vn
int maxMatch(int ** graph,int m,int n)
{
    //Array to keep track of matching , match[V2]=V1 indicates matching between V1 and V2 belonging to Vm and Vn respectively .
    int * match=malloc(sizeof(int)*n);
    int i;
    //All vertices of Vn are initially unassigned.
    for(i=0;i<n;i++)
        match[i]=-1;
    //Count of total matchings
    int result=0;
    for(i=0;i<m;i++)
    {
        int * seen=calloc(n,sizeof(int));
        bpm(graph,m,n,i,seen,match);
    }
    printf("Matching from Vm to Vn are :\n");
    for(i=0;i<n;i++)
    {
        if(match[i]!=-1)
        {
            result++;
            printf("%d -> %d\n",match[i],i);
        }
    }
    return result;   
}
void main()
{
    int m,n;
    printf("Considering Bipartite Graph K(m,n) enter the values of (M N): ");
    scanf("%d %d",&m,&n);
    int e;
    printf("Number of edges :");
    scanf("%d",&e);
    int ** graph=read_graph(m,n,e);
    printf("Maximum Matchings from Vm to Vn are : %d",maxMatch(graph,m,n));
}