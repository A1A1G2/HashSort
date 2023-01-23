#include <stdio.h>
#include <stdlib.h>
#include <Math.h>
#define SIZE 10

int *createRandomArray(int size);
int hashCode(int factor ,int num);
int main(){
	int *hashTable,*arr;
	int i,tmp,index;
	arr = createRandomArray(SIZE);
	
	for(i = 0;i<10;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	hashTable = (int*) malloc(sizeof(int)*SIZE*2);
	for(i = 0;i<SIZE*2;i++){
		hashTable[i] = -1;
	}
	for(i = 0;i<SIZE;i++){
		tmp = arr[i];
		index = hashCode(SIZE*2,tmp);
		while(hashTable[index]!=-1){
			index = (index+1)%(SIZE*2);
		}
		hashTable[index] = tmp;
		printf("\n%d, %d",index,tmp);
	}
	
}
int *createRandomArray(int size){
	int *tmp =(int*) malloc(sizeof(int)*size);
	int i;
	for(i = 0;i<size;i++){
		tmp[i] = (i*7)%10;
	}
	return tmp;
}
int hashCode(int factor ,int num){
	double prNum = 0.6816;
	return factor*fmod(num*prNum,1);
}
