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

    if(pq->size==0)return NULL;
    
    return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
    if (pq->size == pq->capac) {
        pq->capac *= 2; 
        pq->heapArray = realloc(pq->heapArray, pq->capac * sizeof(heapElem));
    }

    int indice=pq->size;

    while(indice<0 && pq->heapArray[(indice-1)/2].priority<priority){

        pq->heapArray[indice]=pq->heapArray[(indice-1)/2];
        indice=(indice-1)/2;
    }
   
        
        
    

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
