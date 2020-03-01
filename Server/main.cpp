// C / C++ program for Dijkstra's shortest path algorithm for adjacency
// list representation of graph
// And server socket

#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;


//Puntero no inicializado (PNI)

// A structure to represent a node in adjacency list
struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode* next; //Puntero (NI) a otro dato de la estructura nodo llamado next
};

// A structure to represent an adjacency list
struct AdjList
{
    struct AdjListNode* head;  // pointer to head node of list
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;
    struct AdjList* array; //PNI a la list. adj.
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest, int weight)
{
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode)); // Aloja el espacio en memoria para el nodo, newNode es un puntero
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList)); // Al array se le asigna un espacio en memoria de tipo AdjList x 9

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest, int weight)
{

    //AGREGA LA RELACION EN LA LISTA DEL SRC CON EL DEST

    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the beginning
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    //AGREGA LA RELACION EN LA LISTA DEL DEST CON EL SRC

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

//                       _________________________________
//______________________/ Estructuras para el Heap

// Structure to represent a min heap node
struct MinHeapNode
{
    int  v;
    int dist;
};

// Structure to represent a min heap
struct MinHeap
{
    int size;      // Number of heap nodes present currently
    int capacity;  // Capacity of min heap
    int *pos;     // This is needed for decreaseKey()
    struct MinHeapNode **array; // aqui se crea un puntero a un puntero q apunta a un MinHeapNode
};

// A utility function to create a new Min Heap Node
struct MinHeapNode* newMinHeapNode(int v, int dist)
{
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}

// A utility function to create a Min Heap
struct MinHeap* createMinHeap(int capacity)
{
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->pos = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array =(struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// A utility function to swap two nodes of min heap. Needed for min heapify
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// A standard function to heapify at given idx
// This function also updates position of nodes when they are swapped.
// Position is needed for decreaseKey()
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size &&
        minHeap->array[left]->dist < minHeap->array[smallest]->dist )
        smallest = left;

    if (right < minHeap->size &&
        minHeap->array[right]->dist < minHeap->array[smallest]->dist )
        smallest = right;

    if (smallest != idx)
    {
        // The nodes to be swapped in min heap
        MinHeapNode *smallestNode = minHeap->array[smallest];
        MinHeapNode *idxNode = minHeap->array[idx];

        // Swap positions
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        // Swap nodes
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

// A utility function to check if the given minHeap is empty or not
int isEmpty(struct MinHeap* minHeap)
{
    return minHeap->size == 0;
}

// Standard function to extract minimum node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    if (isEmpty(minHeap))
        return NULL;

    // Store the root node
    struct MinHeapNode* root = minHeap->array[0];

    // Replace root node with last node
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    // Update position of last node
    minHeap->pos[root->v] = minHeap->size-1;
    minHeap->pos[lastNode->v] = 0;

    // Reduce heap size and heapify root
    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

// Function to decrease dist value of a given vertex v. This function
// uses pos[] of min heap to get the current index of node in min heap
void decreaseKey(struct MinHeap* minHeap, int v, int dist)
{
    // Get the index of v in  heap array
    int i = minHeap->pos[v];

    // Get the node and update its dist value
    minHeap->array[i]->dist = dist;

    // Travel up while the complete tree is not hepified.
    // This is a O(Logn) loop
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
    {
        // Swap this node with its parent
        minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
        swapMinHeapNode(&minHeap->array[i],  &minHeap->array[(i - 1) / 2]);

        // move to parent index
        i = (i - 1) / 2;
    }
}

// A utility function to check if a given vertex
// 'v' is in min heap or not
bool isInMinHeap(struct MinHeap *minHeap, int v)
{
    if (minHeap->pos[v] < minHeap->size)
        return true;
    return false;
}


//             _________________
//____________/Dijkstra y otros


// Function to print shortest
// path from source to j
// using parent array
string path;

void printPath(int parent[], int j)
{
    //string path;
        // Base Case : If j is source
        if (parent[j] == -1)
            return;

        printPath(parent, parent[j]);

        path += to_string(j);
}

// A utility function used to print the solution
string giveRoute(int dist[], int n, int parent[], int src, int V)
{
    path = "";
    string arw = "-->";
    string spc = "  ";
    string spc2 = "  ";
    printPath(parent, n);
    string Route = (to_string(src) += arw += to_string(n) += spc2 += to_string(dist[n]) += spc  += to_string(src) += path);
    return Route;

}



// The main function that calulates distances of shortest paths from src to all
// vertices. It is a O(ELogV) function
string dijkstra(Graph *graph, int src, int stp)
{
    int V = graph->V;// Get the number of vertices in graph
    int dist[V];      // dist values used to pick minimum weight edge in cut
    int parent[V];

    // minHeap represents set E
    struct MinHeap* minHeap = createMinHeap(V);

    // Initialize min heap with all vertices. dist value of all vertices
    for (int i = 0; i < V; ++i)
    {
        dist[i] = INT_MAX;
        minHeap->array[i] = newMinHeapNode(i, dist[i]);
        minHeap->pos[i] = i;
        parent[i] = -1;
    }

    // Make dist value of src vertex as 0 so that it is extracted first
    minHeap->array[src] = newMinHeapNode(src, dist[src]);
    minHeap->pos[src]   = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);

    // Initially size of min heap is equal to V
    minHeap->size = V;

    // In the following loop, min heap contains all nodes
    // whose shortest distance is not yet finalized.
    while (!isEmpty(minHeap))
    {
        // Extract the vertex with minimum distance value
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v; // Store the extracted vertex number

        // Traverse through all adjacent vertices of u (the extracted
        // vertex) and update their distance values
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL)
        {
            int v = pCrawl->dest;

            // If shortest distance to v is not finalized yet, and distance to v
            // through u is less than its previously calculated distance
            if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX &&
                pCrawl->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + pCrawl->weight;
                parent[v] = u;

                // update distance value in min heap also
                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    // print the calculated shortest distances
    return giveRoute(dist, stp, parent,src,V);
}


//              ____________________________________
//_____________/ Creacion del socket y funcion main

int main() {

    // create the graph
    int V = 9;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    //______________________________________________________________
    //Crear el socket
    int srv_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (srv_socket == -1){
        cerr << "No se pudo crear el socket";
        return -1;
    }

    // Ligar (bind) a un puerto o IP
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000); //host to network short
    inet_pton(AF_INET,"0.0.0.0",&hint.sin_addr);

    if (bind(srv_socket,(sockaddr*) &hint, sizeof(hint)) == -1){
         cerr << "No se pudo enlazar al IP/puerto";
         return -2;
    }


    // Poner el socket a escuchar
    if(listen(srv_socket, SOMAXCONN) == -1){
        cerr << "Not srv_socket" ;
    }

    // Aceptar llamadas
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
    char host [NI_MAXHOST];
    char svc[NI_MAXSERV];

    int clt_socket = accept(srv_socket,(sockaddr*)&client,&clientSize);

    if (clt_socket == -1) {
        cerr << "Promeblemas con el cliente";
    } else{
        cout << "Conexion con cliente establecida exitosamente!\n";
    }


    int nodes[2];

    char buffer [4096] = {0};

    while (true){
        memset(buffer,0,4096);
        int bytesRecv = read(clt_socket,buffer,4096);
        if (bytesRecv == -1){
            cerr << "Hubo un error de conexion" << endl;
            break;
        }

        if (bytesRecv == 0){
            cout << "El cliente se ha desconectado" << endl;
            break;
        }
        cout << buffer << endl;

        nodes[0] = (int) buffer[0] - 48;
        nodes[1] = (int) buffer[1] - 48;

        if (0 <= nodes[0] && 0 <= nodes[1] && nodes[0] <= 8 && nodes[1] <= 8){

            cout << nodes[0] << endl;
            cout << nodes[1] << endl;

            string res = dijkstra(graph, nodes[0], nodes[1]);
            cout << res << endl;

            send(clt_socket,res.c_str(),res.size(), 0 );

        }else{
            send(clt_socket,"ERROR",5, 0 );
        }

    }

    close(clt_socket);



    return 0;
}
