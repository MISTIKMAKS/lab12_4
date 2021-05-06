#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

struct Data {
	int a;
};

struct List {
	Data d;
	List* next;
};

void Print(List* u);
void Process(List* u);

int main() {
	List* u = NULL;

	u = new List;
	u->d.a = 1;

	u->next = NULL;

	List* x;
	x = u;

	x->next = new List;
	x = x->next;
	x->d.a = 2;
	x->next = NULL;

	x->next = new List;
	x = x->next;
	x->d.a = -3;
	x->next = NULL;

	x->next = new List;
	x = x->next;
	x->d.a = -4;
	x->next = NULL;

	x->next = new List;
	x = x->next;
	x->d.a = 5;
	x->next = NULL;

	x->next = u;

	Print(u);
	Process(u);
}

void Print(List* u) {
	if (u != NULL) {
		List* p = u;
		cout << "Ring List:" << endl;
		cout << p->d.a << endl;
		p = p->next;
		while (p != u) {
			cout << p->d.a << endl;
			p = p->next;
		}
	}
	else {
		cout << "List Empty" << endl;
	}
}

void Process(List* u) {
	int summ = 0;
	if (u != NULL) {
		List* p = u;
		cout << "Ring List Summ:" << endl;
		if (p->d.a > 0) {
			summ = summ + p->d.a;
		}
		p = p->next;
		while (p != u) {
			if (p->d.a > 0) {
				summ = summ + p->d.a;
			}
			p = p->next;
		}
	}
	else {
		cout << "List Empty" << endl;
	}
	cout << summ;
}