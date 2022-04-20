#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


struct Car {
	string id;
	Car *next;
};

void appendCar(Car *&head, Car*&tail, string id);
void printTrain(Car *&head);

int main() {
	Car *head = NULL;
  Car *tail = NULL;
	int n;
	cin >> n;
	string id;
	for (int i = 0; i < n; i++) {
		cin >> id;
		appendCar(head, tail, id);
	}
	printTrain(head);

	return 0;
}

// Please implement the function appendCar() here.
void appendCar(Car *&head, Car *&tail, string id) {
    Car *p = new Car;
    p->id = id;
    p->next = NULL;
    if(head == NULL){
        head = p;
        tail = p;
    }
    else{
        tail->next = p;
        tail = p;
    }
}

void printTrain(Car *&head) {
	Car *current = head;
	while (current != NULL) {
		if (current->next != NULL) {
			cout << current->id << ", ";
		}
		else {
			cout << current->id;
		}
		current = current->next;
	}
}
