#include <stdio.h>

int main(void){
	int x, y, hasil;
	
	printf("Masukkan angka kesatu: ");
	scanf("%d", &x);
	printf("Masukkan angka kedua: ");
	scanf("%d", &y);
	
	multiply(&x, &y, &hasil);
	
	printf("%d", hasil);

	return 0;
}

void multiply(int *ptrx, int *ptry, int *hasil) {
	*hasil = *ptrx * *ptry;
}

