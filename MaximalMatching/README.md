A matching in a Bipartite Graph is a set of the edges chosen in such a way that no two edges share an endpoint. A maximum matching is a matching of maximum size (maximum number of edges). In a maximum matching, if any edge is added to it, it is no longer a matching. There can be more than one maximum matchings for a given Bipartite Graph. 

There are many real world problems that can be formed as Bipartite Matching. For example, consider the following problem:
There are M job applicants and N jobs. Each applicant has a subset of jobs that he/she is interested in. Each job opening can only accept one applicant and a job applicant can be appointed for only one job. Find an assignment of jobs to applicants in such that as many applicants as possible get jobs.

Steps to get Maximal Matching :

1) Build a Flow Network
There must be a source and sink in a flow network. So we add a source and add edges from source to all vertices on Vm. Similarly, add edges from all vertices of Vn to sink. The capacity of every edge is marked as 1 unit.

2) Find the maximum flow.
We use Ford-Fulkerson algorithm to find the maximum flow in the flow network built in step 1. The maximum flow is actually the Maximal Bipartite Matching we are looking for.

‘graph(mxn)’ with M rows (for M job applicants) and N columns (for N jobs). The value graph[i][j] is 1 if i’th applicant is interested in j’th job, otherwise 0 i.e edge exists between vertex i of Vm to vertex j of Vn.

The idea is to use DFS traversal to find a matching (similar to augmenting path in Ford-Fulkerson). We call bpm() for every vertex in Vn, bpm() is the DFS based function that tries all possibilities to assign a matching from Vm to the vertex in Vn.

In bpm(), we one by one try all vertices that an vertex ‘u’ from Vn is joined to in until we find a unmatched vertex/no more matches exist. For every vertex v in Vm , we do following.
If v is not assigned/matched to any u, we simply assign it to vertex u and return true. If v is assigned to some vertex say x, then we recursively check whether x can be assigned some another vertex from Vn. To make sure that x doesn’t get the same match again, we mark the ‘v’ as seen before we make recursive call for x. If x can get other matching, we change the matching for v and return true. We use an array match[0..N-1] that stores the vertices of Vm assigned to different vertices of Vn.

How to run?
```
gcc MaximalMatching.c
./a.exe
```

Sample Input:
```
Considering Bipartite Graph K(m,n) enter the values of (M N): 4 3
Number of edges :5
Enter Edge(V1 V2) with V1 belonging to Vm and V2 belonging to Vn
Edge 1 :0 1
Edge 2 :1 1
Edge 3 :2 0
Edge 4 :2 2
Edge 5 :3 2
```
Sample Output:
```
Matrix representing graph edges :
0 1 0 
0 1 0 
1 0 1 
0 0 1 
Matching from Vm to Vn are :
2 -> 0
0 -> 1
3 -> 2
Maximum Matchings from Vm to Vn are : 3
```