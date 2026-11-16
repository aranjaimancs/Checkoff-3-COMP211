#include <stdio.h>

int main(void){
    char objects[5] = {'A', 'B', 'C', 'D', 'E', 'F'};

    int next [5] = {1, 2, -1, 4, 3};

    int marked[5] = {0,0,0,0,0};
    int root = 0;

    printf("---BEFORE GARBAGE COLLECTION---\n");

    for (int i = 0; i < 5; i++){
        printf("Object %c exists\n", objects[i]);
    }
    printf("\n---MARK PHASE---\n");
    int curr = root;

    while (curr != -1 && marked[curr] == 0){
        marked[curr] = 1;
    printf("Marking object %c\n", objects[curr]);    
    
    curr = next[curr];
    }
    printf("\n---SWWEP PHASE---\n");
    for (int i = 0; i < 5; i++){
        if (marked[i] == 0){
            printf("Colecting object %c memory\n", objects[i]);
        }
        else{
            printf("Keeping object %c\n", objects[i]);
        }
    }
    return 0;
}