Welsh Powell is used to implement graph labeling/coloring; it is an assignment of labels traditionally called "colors" to elements of a graph subject to certain constraints.

Chromatic number : A graph G that requires K distinct colors for it’s proper coloring, and no less, is called a K-chromatic graph, and the number K is called the chromatic number of graph G.
Welsh Powell helps estimate upper cap of the chromatic number.

Welsh Powell Algorithm consists of following Steps :

-Find the degree of each vertex
-List the vertices in order of descending degrees.
-Colour the first vertex with color 1.
-Move down the list and color all the vertices not connected to the coloured vertex, with the same color.
-Repeat step 4 on all uncolored vertices with a new color, in descending order of degrees until all the vertices are coloured.

How to run?
```
gcc BoruvkasAlgo.c
./a.exe
```

Sample Input :
```
Number of vertices: 5
Number of edges: 6

Enter vertex pairs with edge in between : Eg. (0 1) -> Edge between V0 and V1
Edge1 :0 1
Edge2 :0 2
Edge3 :2 3
Edge4 :3 1
Edge5 :3 4
```
Sample Output:
```
The vertices are colored in the following pattern:
Vertex 0 Color 3
Vertex 1 Color 1
Vertex 2 Color 1
Vertex 3 Color 2
Vertex 4 Color 3
Chormatic number is : 3
```