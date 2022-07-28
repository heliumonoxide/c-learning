#include <stdio.h>

struct angka {
	int x;
	int y;
};

int dibagi(struct angka awal){
	struct angka baru = awal;
	int z = baru.x / baru.y;
	return z;
}


int main(){
	struct angka awal = {4, 2};
	int baru = dibagi(awal);
	
	printf("nilai dari %d : %d adalah %d", awal.x, awal.y, baru);	
	
	return 0;
	
}
