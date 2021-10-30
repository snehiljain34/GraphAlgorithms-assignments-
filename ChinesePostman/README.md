Chinese Postman Problem is a variation of Eulerian circuit problem for undirected graphs. An Euler Circuit is a closed walk that covers every edge once starting and ending position is same. Chiniese Postman problem is defined for connected and undirected graph. The problem is to find shortest path or circuity that visits every edge of the graph at least once.

 In weighted graph the minimum possible weight of Postman tour is sum of all edge weights which we get through Eulerian Circuit. We can’t get a shorter route as we must visit all edges at-least once.

Algorithm to find shortest closed path or optimal Chinese postman route in a weighted graph that may
not be Eulerian.
1) If graph is Eulerian, return sum of all edge weights.Else do following steps.
2) We find all the vertices with odd degree 
3) List all possible pairings of odd vertices .For n odd vertices total number of pairings possible are, (n-1) * (n-3) * (n -5)... * 1
4) For each set of pairings, find the shortest path connecting them.
5) Find the pairing with minimum shortest path connecting pairs.
6) Modify the graph by adding all the edges that have been found in step 5.
7) Weight of Chinese Postman Tour is sum of all edges in the modified graph.
8) Print Euler Circuit of the modified graph. This Euler Circuit is Chinese Postman Tour. 

Sample input:
```
Number of vertices: 4
Number of edges: 4

Enter vertex pairs with edge in between : Eg. (0 1 w) -> Edge between V0 and V1 with weight w
Edge1 :0 1 2
Edge2 :1 2 4
Edge3 :2 3 5
Edge4 :3 0 6
```
Sample output:
```
Number of odd degree vertices : 0
Graph contains Eulerian circuit and hence miniumun cost path is given by sum of all edge weights.
Minimun weight path for the Chinese postman problem has cost :17
```