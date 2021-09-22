#include<iostream>
using namespace std;
const int SIZE = 100;

int process_id[SIZE];
char process_name[SIZE];
int duration[SIZE];
int arrival_time[SIZE];
int rem_time[SIZE];
char scheduled_process[SIZE] = {0};
int total_time;

void time_counter(int n) {
	total_time = 0;
	for (int i = 0; i < n; i++) {
		total_time += duration[i];
	}
}

void copy_cat(int n) {
	for (int i = 0; i < n; i++) {
		rem_time[i] = duration[i];
	}
}

void show_schedule(int n) {
	cout << "Process ID" << "Process Name" << "Duration" << "Arrival Time" << endl;
	for (int i = 0; i < n; i++) {
		cout << process_id[i] << "\t" << process_name[i] << "\t" << duration[i] << "\t" << arrival_time[i] << endl;
	}
}

void sorting_process(int n, int tq) {
	int pivot;
	int min = arrival_time[0];
	int index;

	for (int i = 0; i < n; i++) {
		//pivot = arrival_time[i];
		min = arrival_time[i];
		index = i;

		for (int j = i; j < n; j++) {
			if (min > arrival_time[j]) {
				min = arrival_time[j];
				index = j;
				//cout << "Hi";
			}
		}
		//cout << index << i;
		if (index != i) {
			swap(arrival_time[i], arrival_time[index]);
			swap(duration[i], duration[index]);
			swap(process_id[i], process_id[index]);
			swap(process_name[i], process_name[index]);
		}

	}
	//show_schedule(n);
}

void print_schedule() {
	//cout << "asjdhahashd" << "\t" << scheduled_process[1] ;
	for (int i = 0; scheduled_process[i] != NULL; i++) {
		cout << scheduled_process[i] << "=>";
	}
}

void round_robin(int n, int tq) {
	int i = 0;
	int key = 0;
	int count_timer = 0;
	int schedule_pointer = 0;
	while (count_timer < total_time) {
		count_timer += tq;
		for (i = 0; i < n; i++) {
			if (count_timer > arrival_time[i]) {
				cout << scheduled_process[schedule_pointer];
				scheduled_process[schedule_pointer] = process_id[i];
				duration[i] -= tq;
				schedule_pointer++;
			}
		}
		if (duration[key] > 0) {
			cout << "Mate IF" << endl;
			scheduled_process[schedule_pointer] = process_id[key];
			schedule_pointer++;
		}
		else {
			cout << "Mate Else" << endl;
			key++;
			scheduled_process[schedule_pointer] = process_id[key];
			schedule_pointer++;
		}

	}
	print_schedule();
}

void scheduling_time(int n, int tq) {
	sorting_process(n, tq);

	round_robin(n, tq);
}

int main() {
	int tq = 0;
	int n = 0;
	cout << "Processes Number: ";
	cin >> n;
	cout << "Time Quantum: ";
	cin >> tq;
	int i = 0;
	
	while (i < n){
		cin >> process_id[i];
		cin >> process_name[i];
		cin >> duration[i];
		cin >> arrival_time[i];
		i++;
	}
	copy_cat(n);
	scheduling_time(n, tq);
	return 0;
}