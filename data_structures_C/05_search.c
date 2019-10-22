#include <stdio.h>

//recher un élément de façon linéaire,
//a une complexité O(n)
int linearSearch(int* tab, int valueToSearch, int length){
    int i = 0;
    for(i = 0; i < length; i++){
        if (tab[i] == valueToSearch)
            return i;
    }
    return -1;
}

//O(log n)
//Attention, ne fonctionne que si le tableau est trié!
int binarySearch(int* tab, int valueToSearch, int length){
    int low = 0;
    int high = length-1;
    int mid;
    for(;;){
        if (high < low){
            return -1;
        }
        mid = low + (high - low) / 2;
        if(tab[mid] < valueToSearch){
            low = mid + 1;
        }
        if(tab[mid] > valueToSearch){
            high = mid - 1;
        }
        if(tab[mid] == valueToSearch){
            return mid;
        }
    }
}

//interpolation Sort
//hashtable

int main(){
    int a[6] = {1,2,5,4,9,20};
    int index = binarySearch(a, 9, 6);
    printf("%d\n", index);
}
