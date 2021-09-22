#include<iostream>
#include<math.h>

using namespace std;

struct Doublylist{
	int data;
	struct Doublylist *next;
	struct Doublylist *prev;
}*head, *tail;

void init() {
	head = new Doublylist;
	tail = new Doublylist;

	head->next = tail;
	head->prev = NULL;

	tail->next = NULL;
	tail->prev = head;
}

void linker(Doublylist *new_node) {
	Doublylist *temp;
	temp = head;

	while (temp->next != tail) {
		temp = temp->next;
	}
	
	new_node->next = temp->next;
	new_node->prev = temp;

	temp->next = new_node;
	new_node->next->prev = new_node;
}

void data_entry(int testcase) {
	int iter = 0;
	
	while (iter != testcase) {
		Doublylist *new_node = new Doublylist;
		cin >> new_node->data;
		linker(new_node);
		iter++;
	}
}

void sel_sort() {

	Doublylist *temp1, *temp2, *pivot;
	pivot = new Doublylist;
	temp1 = head->next;

	while (temp1 != tail){

		pivot = temp1;
		temp2 = temp1->next;
		while (temp2 != tail){
			if (pivot->data > temp2->data) pivot = temp2;
			temp2 = temp2->next;
		}
		swap(temp1->data, pivot->data);
		temp1 = temp1->next;
	}
}

void showdata() {
	Doublylist *temp;
	temp = head->next;

	while (temp != tail) {
		cout << temp->data << "\t";
		temp = temp->next;
	}
}

int main() {
	/*init();

	int testcase = 0;
	cin >> testcase;
	data_entry(testcase);
	sel_sort();
	showdata();*/

	printf("HIIIII!!!!!!!!!");

	return 0;
}