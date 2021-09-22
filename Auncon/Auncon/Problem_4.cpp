#include <stdio.h>
#include<iostream> 
#define SIZE  100

using namespace std;

void sort_array(int arr[], int n, int k) {
	
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int index = 0;
	int min;

	for (int i = 0; i < n; i++) {
		min = arr[i];
		int min_ind = i;
		for (int j = i; j < n; j++) {
			if (arr[j] < min)
				min_ind = j;
		}

		swap(arr[i], arr[min_ind]);

	}



}


int main() {
	int arr[SIZE];
	int k = 0, n = 0;

	scanf("%d", &n);
	scanf("%d", &k);

	sort_array(arr, n, k);

	printf("%d", arr[k - 1]);


	return 0;
}