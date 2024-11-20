//Pakkawat Kaolim 66070503446
//Lab 10.2 : Kruskal's

#include <stdio.h>

typedef struct ConnectedEdge {
    int start;
    int stop;
    int weight;
} Edge;

void Sort(Edge *ConnectedEdge, int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (ConnectedEdge[j].weight > ConnectedEdge[j + 1].weight) {
                Edge temp = ConnectedEdge[j];
                ConnectedEdge[j] = ConnectedEdge[j + 1];
                ConnectedEdge[j + 1] = temp;
            }
        }
    }
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

int Kruskal(int V, int E, Edge *ConnectedEdge) {
    int total = 0;
    int parent[V+1];

    for (int i = 0; i <= V; i++)
        parent[i] = i;

    Sort(ConnectedEdge, E);

    for (int i = 0; i < E; i++) {
        //check cycle
        int x = find(parent, ConnectedEdge[i].start);
        int y = find(parent, ConnectedEdge[i].stop);
        if (x != y) {
            total += ConnectedEdge[i].weight;
            Union(parent, x, y);
        }
    }

    return total;
}

int main(void) {
    int V, E, start, end, weight;
    scanf("%d %d", &V, &E);

    Edge ConnectedEdge[E];

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &start, &end, &weight);
        ConnectedEdge[i].start = start;
        ConnectedEdge[i].stop = end;
        ConnectedEdge[i].weight = weight;
    }

    int total = Kruskal(V, E, ConnectedEdge);
    printf("%d\n", total);
    return 0;
}
