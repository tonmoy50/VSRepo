#include<iostream>
using namespace std;

void show_schedule(int n);

int TAT = 0;
struct fcfs {
	char process_id[10];
	char process_name[10];
	int arrival_time;
	int duration;
	struct fcfs *next;
	struct fcfs *prev;

}*Processes;

void init() {
	Processes = new fcfs;
	Processes->next = NULL;
	Processes->prev = NULL;
}

void linker(struct fcfs *new_node) {
	struct fcfs *temp;
	temp = Processes;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->prev = temp;
	new_node->next = NULL;
}

void swap(struct fcfs *node1, struct fcfs *node2) {
	struct fcfs *temp;
	temp = node1;
	if (node2->next == NULL) {
		node1->next = node2->next;
		node2->next->prev = node2->prev;

		node2->next = temp->prev->next;
		node2->prev = temp->prev;

		//node2->prev = temp->prev;
		temp->prev->next = node2;
		node1->prev = node2;
	}

	else {
		node1->next = node2->next;
		node2->next->prev = node2->prev;

		node2->next = temp->prev->next;
		node2->prev = temp->prev;

		node2->prev = temp->prev;
		temp->prev->next = node2;
		node1->prev = node2;
	}
}



void fcfs_sort(int n) {
	struct fcfs *temp, *temp2;
	while (n != 0) {
		temp = Processes;
		while (temp->next != NULL) {
			if (temp->arrival_time > temp->next->arrival_time) {
				swap(temp, temp->next);
			}
			//show_schedule(n);
			temp = temp->next;
		}
		n--;
	}
}

int timeline_counter(int i) {
	int total = 0;
	struct fcfs *temp;
	temp = Processes->next;
	while (i != 0) {
		total += temp->duration;
		temp = temp->next;
		i--;
	}
	return total;
}

void show_schedule(int n) {
	cout << "Sequence No.\t" << "Process Name\t" << "   Timeline\t" << "Turnaround Time\t" << endl;
	struct fcfs *temp;
	int i = 1;
	temp = Processes->next;
	while (temp != NULL) {
		TAT += timeline_counter(i) - temp->arrival_time;
		cout << i << "\t\t\t" << temp->process_name << "\t\t" << (timeline_counter(i) - temp->duration) << " - " << timeline_counter(i) << "\t\t" << (timeline_counter(i) - temp->arrival_time) << endl;
		temp = temp->next;
		i++;
	}

}


int main() {
	init();
	int i = 0;
	while (true) {
		int n = 0;
		cout << "Input n = ";
		cin >> n;
		n += i;
		
		
		for (; i < n; i++) {
			struct fcfs *new_node;
			new_node = new fcfs;
			linker(new_node);
			cin >> new_node->process_id >> new_node->process_name >> new_node->duration >> new_node->arrival_time;
		}

		//fcfs_sort(n);

		show_schedule(n);
		double avg_tat = (double)TAT / n;
		cout << "Average TAT - " << avg_tat << endl;

	}

	return 0;
}