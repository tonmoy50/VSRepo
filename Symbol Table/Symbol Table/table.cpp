#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<string>
#define SIZE 100
#define MEGASIZE 200
using  namespace std;

int global_loc = 0;
char delete_key[SIZE];

struct Symbols {
	bool info = false;
	char sym_name[SIZE];
	char sym_type[SIZE];
	//struct chains *neighbour;
	Symbols *neighbour;
}hr[100], *Chains;

void init() {
	Chains = new Symbols;
	Chains->neighbour = NULL;
}

int hashfunc(char letter) {
	int x = (int)letter;
	x = x % 100;
	return x;
}

bool decider(char x) {
	if (x == ',') return true;
	else return false;
}

void insert_in_structure(char name[], char type[], int location) {
	if (hr[location].info == true) {
		Symbols *temp = new Symbols;
		temp = &hr[global_loc];
		while (temp->neighbour != NULL) {
			temp = temp->neighbour;
		}
		Symbols *new_place = new Symbols;
		temp->neighbour = new_place;
		new_place->info = true;
		strcpy(new_place->sym_name, name);
		strcpy(new_place->sym_type, type);
		new_place->neighbour = NULL;
	}
	else {
		hr[location].info = true;
		strcpy(hr[location].sym_name, name);
		strcpy(hr[location].sym_type, type);
	}

	//cout << hr[global_loc].neighbour->sym_name << endl;
}

void insert() {
	//gets_s(hr[0].sym_name);
	int locator;
	bool decision = false;
	char temp_name[SIZE];
	char temp_type[SIZE];
	char temp[MEGASIZE];
	int mega_iter = 0, iter1 = 0, iter2 = 0;
	cout << "Enter the tuples: " << endl;
	gets_s(temp);
	
	decision = decider(temp[0]);

	while (temp[mega_iter] != NULL) {
		if (decision == false) {
			temp_name[iter1] = temp[mega_iter];
			mega_iter++;
			iter1++;
			decision = decider(temp[mega_iter]);
			if (decision == true) mega_iter++;
		}
		else {
			temp_type[iter2] = temp[mega_iter];
			mega_iter++;
			iter2++;
		}
	}

	temp_name[iter1] = '\0';
	temp_type[iter2] = '\0';
	//cout << temp_name << endl;
	//cout << temp_type << endl;
	locator = hashfunc(temp_name[0]);
	global_loc = locator;
	insert_in_structure(temp_name, temp_type, locator);

}

int search() {
	char key[SIZE];
	cout << "Enter key: ";
	gets_s(key);
	global_loc = hashfunc(key[0]);
	int res;
	strcpy(delete_key, key);
	Symbols *temp = &hr[global_loc];
	while(temp != NULL){
		res = strcmp(temp->sym_name, key);

		if (res == 0) {
			if (temp->info == true) {
				cout << "FOUND" << endl;
				cout << "Symbol Name: " << temp->sym_name << endl << "Symbol Type: " << temp->sym_type << endl;
				return res;
			}

		}
		//else cout << "NOT FOUND";
		temp = temp->neighbour;
	}
	if (res != 0) {
		cout << "NOT FOUND";
		return res;
	}
}

void deletes() {
	if (search() == 0) {
		//hr[global_loc].info = false;
		/*for (int i = 0; hr[global_loc].sym_name[i] != NULL; i++)
			hr[global_loc].sym_name[i] = '\0';

		for (int i = 0; hr[global_loc].sym_type[i] != NULL; i++)
			hr[global_loc].sym_type[i] = '\0';*/

		Symbols *temp = &hr[global_loc];
		if (strcmp(delete_key, temp->sym_name) == 0) temp->info = false;
		else {
			while (strcmp(temp->sym_name, delete_key) != 0 || temp->neighbour != NULL) {
				temp = temp->neighbour;
			}
			if (strcmp(delete_key, temp->sym_name) == 0) {
				//temp->neighbour = temp->neighbour->neighbour;
				Symbols *kakkarot = &hr[global_loc];
				while (kakkarot->neighbour != temp){
					kakkarot = kakkarot->neighbour;
				}
				kakkarot->neighbour = temp->neighbour;
				delete temp;
			}
		}
		cout << "Successfully Deleted....Enjoy!!" << endl;

	}
	else
		cout << "Sorry Can't delete......Key not Found in the Table :(" << endl;

}

void Update() {
	if (search() == 0) {
		if (hr[global_loc].info == true) {
			insert();
		}
	}
	else
		cout << "Key Doesn't Match";

}

void show() {

	cout << "Symbol_Name" << "\t" << "Symbol_Type" <<endl;

	for (int i = 0; i < SIZE; i++) {
		Symbols *temp;
		temp = &hr[i];
			//cout << hr[i].sym_name << "\t\t" << hr[i].sym_type << endl;

			
		while (temp != NULL) {
			if (temp->info == true) {
				cout << temp->sym_name << "\t\t" << temp->sym_type << endl;
			}
			temp = temp->neighbour;
		}
		
			
	}
}

int main() {
	//cout << endl << hashfunc('a');
	/*char hey[SIZE];
	gets_s(hey);
	cout << hey;
	gets_s(hey);
	cout << hey;*/

	init();

	while (true) {
		cout << "1 --> Insert\t" << "2 --> Search\t" << "3 --> Update\t" << "4 --> Show table\t" << "5 --> Delete" <<endl;
		int wish;
		cin >> wish;
		getchar();
		switch (wish)
		{
		case 1:
			insert();
			break;
		case 2:
			search();
			break;
		case 3:
			Update();
			break;
		case 4:
			show();
			break;
		case 5:
			deletes();
			break;
		default:
			cout << "Wrong Command!!!";
			break;
		}
		cout << endl;
		cout << endl;
	}

	return 0;
}