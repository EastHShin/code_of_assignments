#define _CRT_SECURE_NO_WARNINGS

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

int TV[MAX_VERTEX];
int T[MAX_VERTEX][MAX_VERTEX] = { 0 };
int edgeCount = 0;

int parent[MAX_VERTEX];

void initSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }
}

void SimpleUnion(int i, int j) {
    int tmp1 = SimpleFind(i);
    int tmp2 = SimpleFind(j);
    parent[i] = tmp2;
    parent[tmp1] = tmp2;

    for (int k = 1; k <= MAX_VERTEX; k++) {
        if (parent[k] == tmp1 && i != k) {
            parent[k] = tmp2;
        }
    }
}


int SimpleFind(int i) {
    for (; parent[i] >= 0; i = parent[i]);
    return i;
}
void Sollin_First_Step(int n) {
    int i, j, k;
    int v;
    int row = 0, col = 0;
    initSet(n);
    int isTrue = 0;
    int min;
    for (i = 0; i < n; i++) {
        min = 100;
        for (j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (weight[i][j] < min) {
                min = weight[i][j];
                row = i;
                col = j;
            }
        }//jfor
        T[row][col] = TRUE;
    }//ifor

    for (i = 0; i < n; i++) {           //중복 제거
        for (j = 0; j < n; j++) {
            if (T[i][j] == TRUE) {
                T[j][i] = FALSE;
                SimpleUnion(i, j);
                edgeCount++;
            }
        }
    }
}
void Sollin_Second_Step(n) {
    int i, j, k;
    int u, v;
    int row = 0, col = 0;
    int isTrue = 0;
    int min = 100;
    for (i = 0; i < n; i++) {
        
        u = SimpleFind(i);
        for (j = 0; j < n; j++) {
            v = SimpleFind(j);
            if (i == j || u == v)
                continue;
            if (weight[i][j] < min) {
                min = weight[i][j];
                row = i;
                col = j;
            }
        }//jfor
    }//ifor
    T[row][col] = TRUE;
    SimpleUnion(row, col);
}

void Sollin(int n) {
    int i, j;
    int u, v;
    
    Sollin_First_Step(n);
    while (edgeCount < (n - 1)) {
        Sollin_Second_Step(n);
        edgeCount++;
    }
    printf("T={ ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (T[i][j] == TRUE)
                printf("(%d,%d) ", i, j);
        }
    }    
    printf("}\n");
}

int main() {
    printf("Sollin's algorithm을 이용한 minimum cost spanning tree 생성:\n");
    Sollin(7);
    return 0;
}