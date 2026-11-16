#include <stdio.h>

int main(void){
    char objects[5] = {'A', 'B', 'C', 'D', 'E'};
    int marked[5] = {0,0,0,0,0};

    printf("---BEFORE M&S GARBAGE COLLECTION---\n");

    for(int i = 0; i < 5; i++){
        printf("Object %c exists\n", objects[i]);
    }
    printf("\n---MARK PHASE---\n");

    for (int i = 0; i < 3; i++){
        marked[i] = 1;
        printf("Marking object %c\n", objects[i]);
    }
    printf("\n---SWEEP PHASE---\n");

    for (int i = 0; i < 5; i++){
        if (marked[i] == 0){
            printf("Collecting object %c\n", objects[i]);
        } 
        else{
            printf("Keeping object %c\n", objects[i]);
        }
    }
    return 0;
}