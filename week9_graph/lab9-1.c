//Pakkawat Kaolim 66070503446
#include <stdio.h>

#define MAX_VERTICES 1000

typedef struct node *node_pointer;

typedef struct node{
    int vertex;
    struct node *link;
};

int main(void){
    node_pointer graph[MAX_VERTICES];
    int n_edge, node, connected_node;
    scanf("%d ", &n_edge);
    for(int i = 0; i < n_edge; i++){
        scanf("%d %d ", &node, &connected_node);
    }
}
