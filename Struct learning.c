#include <stdio.h>

struct anjing {
	int kaki;
	int kepala;
	int telinga;
	int hidung;
};

struct anjing berubah(struct anjing ayam){
	struct anjing karakteristik = ayam;
	karakteristik.kaki /= 2;
	karakteristik.hidung = 1;
	karakteristik.telinga = 2;
	karakteristik.kepala = 1;
	
	return karakteristik;
}

struct Point {
	int x, y;
};

int main(){
	struct anjing yaAnjing = {4, 1, 2, 1};
	struct anjing ayam = berubah(yaAnjing);
	
	printf("Kaki: %d\nKepala: %d\nTelinga: %d\nHidung: %d\n", yaAnjing.kaki, yaAnjing.kepala, yaAnjing.telinga, yaAnjing.hidung);
	printf("\nKaki: %d\nKepala: %d\nTelinga: %d\nHidung: %d\n", ayam.kaki, ayam.kepala, ayam.telinga, ayam.hidung);
	
	return 0;
	
}
