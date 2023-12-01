#include <stdio.h>
#include <stdlib.h>

#define maxNode 4

typedef struct node {
    int vertexNum;
    struct node *next;
} node;

typedef struct List {
    node *head;
} List;

List *adjList[maxNode] = {0};

void addNode(int s, int d) {
    node *src, *dest, *temp;

    if (adjList[s]->head == NULL) {
        src = (node*)malloc(sizeof(node));
        src->vertexNum = s;
        src->next = NULL;
        adjList[s]->head = src;
    }

    dest = (node*)malloc(sizeof(node));
    dest->vertexNum = d;
    dest->next = NULL;

    if (adjList[s]->head == NULL) {
        adjList[s]->head = dest;
    } else {
        temp = adjList[s]->head;
            while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = dest;
    }
}

void printList() {
    int i;
    for (i = 0; i < maxNode; i++) {
        node *p = adjList[i]->head;
        printf("Adjacency List for vertex %d \n", i);
        while (p) {
            printf("%d->", p->vertexNum);
            p = p->next;
        }
        printf("\n");
    }
}

int main() {
    int i;

    // Initialize the adjacency list
    for (i = 0; i < maxNode; i++) {
        adjList[i] = (List*)malloc(sizeof(List));
        adjList[i]->head = NULL; // Initialize the head to NULL
    }

    addNode(0, 1);
    addNode(0, 3);
    addNode(1, 2);
    printList();

    return 0;
}
