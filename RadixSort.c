#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 20

int queue[MAX_QUEUE_SIZE];
int front =0, rear = 0;

void printArr(int a[], int size){
    for(int i =0; i<size; i++)
        printf("%d ",a[i]);
    printf("\n");
}

int addq(int item){
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    if(front == rear)
        return -1;
    queue[rear] = item;
    return 1;
}
int deleteq(){
    if(front == rear)
        return -1;
    front = (front + 1) % MAX_QUEUE_SIZE;
    return queue[front];
}

int radixSort(int a[], int size){
    int i,j,k,index;
    int max = a[0];
    int digit = 0;
    int factor = 1;
    for(i=1; i<size; i++)
        if(max<a[i])
            max = a[i];

    for(i=max; i>0; i/=10){
        digit++;
    }
    for(i=0; i<digit; i++){
        for(j=0; j<10; j++){
            for(k=0; k<size; k++){
                if((a[k] / factor) % 10 == j)
                    addq(a[k]);
            }
        }
        factor *= 10;
        for(index=front; index!=rear; index++)
            a[index] = deleteq();
        if(i == digit-1)
            printArr(a, size);
        front = 0;
        rear = 0;
    }
}


int main() {
    int list[] = { 1, 300, 200, 104, 101, 91, 88, 60, 15, 31, 12, 26, 82, 51,6 };
    int n = sizeof(list) / sizeof(int);
    printArr(list,n);
    printf("Radix Sort: ");
    radixSort(list, n);
    return 0;
}
