#include <stdio.h>

void printTab(int* tab, int length){
    int i = 0;
    for(; i < length-1;i++){
        printf("%d,", tab[i]);
    }
    printf("%d\n",tab[i]);
}

void swap(int* tab, int a, int b){
    int c = tab[a];
    tab[a] = tab[b];
    tab[b] = c;
}

//O(n^2)
void bubbleSort(int* tab, int length){
    int i;
    int hasChanged = 0;
    do {
        hasChanged = 0;
        i = 1;
        for(;i < length; i++){
            if(tab[i-1] > tab[i]){
                swap(tab, i-1, i);
                hasChanged = 1;
            }
        }
    } while (hasChanged);
}

//O(n^2)
void insertionSort(int* tab, int length){
    int valueToInsert;
    int holePosition;
    int i = 1;
    for(;i < length; i++){
        valueToInsert = tab[i];

        holePosition = i;
        while (holePosition > 0 && tab[holePosition-1] > valueToInsert){
            tab[holePosition] =  tab[holePosition - 1];
            holePosition--;
        }
        if(holePosition !=i){
            tab[holePosition] = valueToInsert;
        }
    }
}

//O(n^2)
void selectionSort(int* tab, int length){
    //chercher la valeur la plus basse
    int lowest = 0;
    int i = 0;
    int j = 0;
    int change = 0;
    for(;i < length; i++){
        lowest = i;
        for(j = i+1;j < length; j++){
            if(tab[j] < tab[lowest]){
                lowest = j;
            }
        }
        if(lowest != i){
            swap(tab, lowest, i);
        }
    }
}

//O(n log n)
//(divide and conquer)

int main(){
    int i;
    int a[8] = {14,33,27,10,35,19,42,44};
    selectionSort(a, 8);
    for(i = 0;i < 8; i++){
        printf("%d\n", a[i]);
    }
    return 0;
}
