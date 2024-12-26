#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 0;
int Heap[105];

int parent(int i){
    return i / 2;
}

int leftChild(int i){
    return 2 * i;
}

int rightChild(int i){
    return 2 * i + 1;
}

int isEmpty(){
    return size == 0;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Top(){
    if (size == 0){
        return -1;
    }
    else {
        return Heap[1];
    }
}

void insert(int newElement){
    size++;
    Heap[size] = newElement;

    int i = size;
    while(Heap[i] < Heap[parent(i)]){
        swap(&Heap[i], &Heap[parent(i)]);
        i = parent(i);
    }
}

void delete(int element){
    int idx = 1;
    for (int i = 1; i <= size; i++) {
        if (Heap[i] == element) {
            idx = i;
            break;
        }
    }

    Heap[idx] = Heap[size];
    //Heap[size] = NULL;
    size--;

    int left = leftChild(idx), right = rightChild(idx);

    while((left <= size && right <= size) && (Heap[idx] > Heap[left] || Heap[idx] > Heap[right])){
        if (Heap[right] > Heap[left]){
            swap(&Heap[left], &Heap[idx]);
            idx = left;
        }
        else{
            swap(&Heap[right], &Heap[idx]);
            idx = right;
        }
        left = leftChild(idx);
        right = rightChild(idx);
    }
}

void printHeap() {
    for (int i = 1; i <= size; i++) {
        printf("%d ", Heap[i]);
    }
    printf("\n");
}

int main() {
    char commands[1500];
    int number; 

    while (1) {
        if (fgets(commands, sizeof(commands), stdin) == NULL) break;

        if (strcmp(commands, "\n") == 0) {
            break;
        }
        if (sscanf(commands, "insert %d", &number) == 1) {
            insert(number);  
        } else if (sscanf(commands, "delete %d", &number) == 1) {
            delete(number);  
        }
    }

    printHeap();
    return 0;
}
