#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node * next;
};

/*
node.next adalah pointer
* node.next adalah objek yg tersimpan di alamat yg ditunjuk oleh pointer
&node adalah pointer
*/

int main(){
	struct node * headAddress = NULL; // langkah 3
	struct node * tmpAddress;
	struct node * iteratorPtr;
	struct node * prevPtr;
	
	//creating our first node by asking the memory allocation first.
	tmpAddress = malloc(sizeof(struct node)); //langkah 4
	(*tmpAddress).data = 39;
	(*tmpAddress).next = NULL; // langkah 5
	
	headAddress = tmpAddress;
	
	//tambahkan 1 node di depan
	tmpAddress = malloc(sizeof(struct node)); //minta alamat kapling baru
	(*tmpAddress).data = 38;
	(*tmpAddress).next = headAddress;
	
	headAddress = tmpAddress;
	
	//tambahkan 1 node di belakang
	tmpAddress = malloc(sizeof(struct node)); //kapling baru lagi
	(*tmpAddress).data = 40;
	(*tmpAddress).next = NULL;
	
	iteratorPtr = headAddress; //iteratorPtr adalah alamat yg akan dicek
	while(1){
		if((*iteratorPtr).next == NULL){ //iteratorPtr merujuk ke node paling akhir
			(*iteratorPtr).next = tmpAddress;
			break;
		}else{
			//alamat utk dicek berikutnya adalah alamat yg tersimpan di kolom next di rumah di alamat sekarang
			iteratorPtr = (*iteratorPtr).next;
		}
	}
	
	//tambahkan beberapa node di tengah ?
	tmpAddress = malloc(sizeof(struct node));
	iteratorPtr = headAddress;
	(*tmpAddress).next = NULL;
    (*tmpAddress).data = 39;
	while(iteratorPtr != NULL){
        if((*(*iteratorPtr).next).next == NULL) {
            (*tmpAddress).next = (*iteratorPtr).next;
            (*iteratorPtr).next = tmpAddress;
            break;
        }
        else{
            iteratorPtr = (*iteratorPtr).next;
        }
	}
	
	//hapus node awal
	tmpAddress = headAddress;
	headAddress = (*tmpAddress).next;
	free(tmpAddress);	

	//hapus node akhir
	iteratorPtr = headAddress;  // what we are checking now
	while(1){
		if((*iteratorPtr).next == NULL){ //iteratorPtr merujuk ke node paling akhir
			free(iteratorPtr);
			(*prevPtr).next = NULL;
			break;
		}else{
			prevPtr = iteratorPtr; // prev address
			iteratorPtr = (*iteratorPtr).next; //alamat yg dicek berikutnya
		}
	}
	
	//hapus node di tengah ?
	iteratorPtr = headAddress;
    while(iteratorPtr != NULL) {
		if((*iteratorPtr).next == NULL) { // node tengah yang sudah ditambahkan (39) menjadi node terakhir karena node 40 sudah dihapus dan awal juga dihapus
			free(iteratorPtr);
			(*prevPtr).next = NULL;
			break;
		}
		else {
			prevPtr = iteratorPtr;
			iteratorPtr = (*iteratorPtr).next;
		}
    }

	//bukti print setelah menambah node tengah dan hapus node tengah
	if(headAddress != NULL){
		printf("List berisi:\n");
		iteratorPtr = headAddress;
		while(iteratorPtr != NULL){
			printf(" [%d] : %d\n",iteratorPtr, (*iteratorPtr).data);
			iteratorPtr = (*iteratorPtr).next;
		}
	}else{
		printf("List kosong\n");
	}
	
	return 0;
}
