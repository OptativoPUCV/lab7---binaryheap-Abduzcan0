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
        pq->capac = pq->capac * 2+1; 
        pq->heapArray = realloc(pq->heapArray, pq->capac * sizeof(heapElem));
    }

    int indice=pq->size;

    while(indice>0 && pq->heapArray[(indice-1)/2].priority<priority){

        pq->heapArray[indice]=pq->heapArray[(indice-1)/2];
        indice=(indice-1)/2;
    }
    
    pq->heapArray[indice].priority=priority;
    pq->heapArray[indice].data=data;    
        
    pq->size++;

}


void heap_pop(Heap* pq){

    pq->size--;
    pq->heapArray[0] = pq->heapArray[pq->size];

    int posicion=0;
    int hijoIzquierdo=1;
    int hijoDerecho=2;

    while(hijoIzquierdo<pq->size){

        int hijo = hijoIzquierdo;

        if(hijoDerecho<pq->size && pq->heapArray[hijoDerecho].priority>pq->heapArray[hijoIzquierdo].priority){

            hijo=hijoDerecho;
            
        }else{
            if (pq->heapArray[posicion].priority >= pq->heapArray[hijo].priority)break;
        }
         heapElem aux = pq->heapArray[posicion];
        pq->heapArray[posicion] = pq->heapArray[hijo];
        pq->heapArray[hijo] = aux;

        posicion = hijo;
        hijoIzquierdo = (hijoIzquierdo * 2) + 1;
        hijoDerecho = (hijoDerecho * 2) + 1;
    }
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
