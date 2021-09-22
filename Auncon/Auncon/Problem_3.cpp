#include <stdio.h>
#define SIZE  100
//#define _CRT_SECURE_NO_WARNINGS

int index = 0;

int *intersection(int arr1[], int arr2[], int x, int y) {
	int inter[SIZE];
	

	for (int i = 0; i < x; i++)
		scanf("%d", &arr1[i]);

	for (int i = 0; i < y; i++)
		scanf("%d", &arr2[i]);

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (arr1[i] == arr2[j]) {
				inter[index] = arr1[i];
				index++;
			}
		}
	}

	return inter;
}


int main1() {
	int arr1[SIZE];
	int arr2[SIZE];
	int x = 0, y = 0;


	printf ("Enter number of content of 1st array and 2nd array: ");
	scanf("%d %d", &x, &y);



	int* intersect;
	intersect = intersection(arr1, arr2, x, y);

	for (int i = 0; i < index; i++)
		printf("%d\t", intersect[i]);

	//printf("%d %d", x, y);

	

	return 0;
}