#include <cs50.h>
#include <stdio.h>

int getHeight(){
    int height;
    do{

        height = get_int("What will be the height of your pyramid? ");

        if (height < 1 || height > 8) {
            continue;
        }

    } while(height < 1 || height > 8);
    return height;
}

void printSpace(int n){
    for(int j = 0; j < n; j++){
        printf(" ");
    }
}

void printHashes(int n) {
    for (int k = 0; k < n; k++) {
        printf("#");
    }
}

void printPyramid(int i, int height){
    printSpace(height - i - 1);
    printHashes(i + 1);
    printf("  ");
    printHashes(i + 1);
    printf("\n");
}

int main()
{

    int height = getHeight();

    for (int i = 0; i < height; i++) {
        printPyramid(i, height);
    }
}
