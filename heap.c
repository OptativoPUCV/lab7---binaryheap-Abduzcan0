#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
    return NULL;
}



void heap_push(Heap* pq, void* data, int priority){
    pq->heapArray->priority[pq->size]=data;
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){

    Heap* heap = (Heap*)malloc(sizeof(Heap));
    if(heap == NULL)return NULL;
    
    heap->heapArray = (heapElem*)malloc(sizeof(heapElem)*3);
    if(heap->heapArray == NULL)return NULL;
    
    heap->size = 0;
    heap->capac = 3;

   return heap;
}
