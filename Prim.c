#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTEX 7
#define INDIRECT 1000

int weight[MAX_VERTEX][MAX_VERTEX] = {
    //  0     1    2     3    4   5   6
        {0,3,17,6,INDIRECT,INDIRECT,INDIRECT}, //0
        {3,0,INDIRECT,5,INDIRECT,INDIRECT,12}, //1
        {17,INDIRECT,0,INDIRECT,10,8,INDIRECT}, //2
        {6,5,INDIRECT,0,9,INDIRECT,INDIRECT},  //3
        {INDIRECT,INDIRECT,10,9,0,4,2},  //4
        {INDIRECT,INDIRECT,8,INDIRECT,4,0,14},  //5
        {INDIRECT,12,INDIRECT,INDIRECT,2,14,0}  //6
};

int T[7];
int TV[7][7] = {0};
int count = 0;
int getMinVertex(int n){
    int i,j,k;
    int v;
    int row, col;
    int min = 1000;
    int isTrue = 0;
    for(i=0; i<count; i++){
        v = T[i];
        for(j=0; j<n;j++){
            for(k=0; k<count;k++) {
                if (j == T[k]) {
                    isTrue = TRUE;
                    break;
                }
            }
            if(isTrue == TRUE) {
                isTrue = FALSE;
                continue;
            }
            if(weight[v][j] < min) {
                min = weight[v][j];
                row = v;
                col = j;
            }
        }//jfor
    }//ifor
    TV[row][col] = TRUE;
    return col;
}

void Prim(int n){
    int i,j;
    int u, v;
    T[0] = 0;
    count++;

    for(i=0; i<n;i++){
        u = getMinVertex(n);
        T[count++] = u;
    }
    count--;
    for(i=0; i<count;i++)
        printf("%d  ", T[i]);
    printf("\n");
    for(i=0;i<count;i++){
        for(j=0;j<count;j++){
            if(TV[i][j] == TRUE)
                printf("(%d,%d)  ", i,j);
        }
    }
}

int main() {
    Prim(7);
    return 0;
}
