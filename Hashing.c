#include <stdio.h>
#define TRUE 1
#define FALSE 0
const int b = 26;

typedef struct table{
    char* key;
}table;
table HashTable[b];

unsigned int stringToint(char* key){
    int number = 0;
    while(*key)
        number += *key++;
    return number;
}
int hashFunc(int x){
    return x % b;
}
void Insert(char* key){
    int hashKey = stringToint(key);
    int hashIndex = hashFunc(hashKey);
    int found = FALSE;
    while(HashTable[hashIndex].key != NULL && !found){
        if(HashTable[hashIndex].key == key)
            found = TRUE;
        else
            hashIndex = (hashIndex + 1) % b;
    }
    if(found)
        printf("Duplicate items are not allowed\n");
    else
        HashTable[hashIndex].key = key;
}
void Search(char* key){
    int hashKey = stringToint(key);
    int hashIndex = hashFunc(hashKey);
    int found = FALSE;
    while(HashTable[hashIndex].key != NULL && !found){
        if(HashTable[hashIndex].key == key){
            found = TRUE;
            printf("탐색 %s: 위치 = %d\n", HashTable[hashIndex].key, hashIndex);
            return;
        }
        else
            hashIndex = (hashIndex + 1) % b;
    }
    if(!found) {
        printf("This key \"%s\" is not found in table\n",key);
    }

}
int main() {
    int i;
    for(i=0; i<b; i++){
        HashTable[i].key = NULL;
    }
    Insert("apple"); Insert("berry"); Insert("grape"); Insert("raisn");
    Insert("banana"); Insert("watermelon"); Insert("grapefruit"); Insert("orange");
    Insert("kiwi"); Insert("pear"); Insert("peach");
    for(i=0; i<b; i++){
        printf("[%d]    ", i);
        if(HashTable[i].key != NULL)
            printf("%s\n", HashTable[i].key);
        else
            printf("\n");
    }
    printf("==================================================\n");
    Search("apple"); Search("berry"); Search("grape"); Search("raisn");
    Search("banana"); Search("watermelon"); Search("grapefruit"); Search("orange");
    Search("kiwi"); Search("pear"); Search("peach");
    return 0;
}
