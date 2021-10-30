#include<stdio.h>
#include<stdlib.h>
int minn(int a,int b)
{
    return(a<b?a:b);
}
struct node
{
 int val;
 struct node* next;
};
struct graph
{   
 int v;
 struct node** arr;
};
struct graph* createGraph(int v)
{
    int i;
    struct graph* temp =(struct graph*)malloc(sizeof(struct graph));
    temp->v=v;
    for(i=0;i<v;i++)
     temp->arr=malloc(sizeof(int*)*v);
    for(i=0;i<v;i++)
     temp->arr[i]=NULL;
    return temp;
}
void addEdge(struct graph* g,int u,int v)
{
    struct node* temp =(struct node*)malloc(sizeof(struct node));
    temp->val = v;
    temp->next = g->arr[u];
    g->arr[u] = temp;     
}
void apUtil(struct graph * g,int node,int* isVisited,int* des,int* parent,int* low,int* ap)
{
    struct node* temp=NULL;
    static int time=0;
    int children=0;
    temp = g->arr[node];
    isVisited[node]=1;
    time++;
    des[node]=low[node]=time;

    while(temp!=NULL)
    {       
       if(!isVisited[temp->val])
        {
          children++;
          parent[temp->val]=node;
          apUtil(g,temp->val,isVisited,des,parent,low,ap);

      low[node]= minn(low[node],low[temp->val]);

          if(parent[node]==-1 && children>1)
             ap[node]=1;

      if(parent[node]!=-1 && des[node]<=low[temp->val])
            ap[node]=1;           
        }    
        else if(temp->val!=parent[node])
        {
            low[node]=minn(low[node],des[temp->val]);
        }
       temp= temp->next;
      }
     //printf("%d",node);
}
void AP(struct graph* g)
{
    int i;
    int* des = (int*)malloc(sizeof(int)*g->v);
    int* isVisited = (int*)malloc(sizeof(int)*g->v);
    int* parent = (int*)malloc(sizeof(int)*g->v);
    int* low = (int*)malloc(sizeof(int)*g->v);
    int* ap = (int*)malloc(sizeof(int)*g->v);
    for(i=0;i<g->v;i++)
    {
        isVisited[i]=0;
        parent[i]=-1;
        ap[i]=0;
    }
    int start=0;
    for(i=0;i<g->v;i++)
    {
        if(isVisited[i]==0)
        {
            apUtil(g,i,isVisited,des,parent,low,ap);
        }
    }
    
    ap[start]=0;
    printf("\n");
    printf("Articulation points are :\n");
    for(i=0;i<g->v;i++)
    {
        if(ap[i]==1)
            printf("\nVertex %d ",i);
    }
}
void main()
{
    int v,e,i;
    printf("No. of vertices :");
    scanf("%d",&v);
    struct graph* g = createGraph(v);
    printf("No. of edges :");
    scanf("%d",&e);
    int v1,v2;
    for(i=0;i<e;i++)
    {
        printf("Edge %d :",i+1);
        scanf("%d %d",&v1,&v2);
        addEdge(g,v1,v2);
        addEdge(g,v2,v1);
    }
    AP(g);
}   