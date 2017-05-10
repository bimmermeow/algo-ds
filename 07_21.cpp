#include <iostream>
using namespace std;

template <class item_type>
class Tabelle {
public:
	struct node {
		node* prev;
		node* next;
		item_type item;
	};
	node* iterator;
	//Der Iterator darf nur leer sein, wenn die Tabelle leer ist
	node* tail;
	node* head;
	unsigned int anz_items;
	Tabelle() {
		iterator=0;
		tail =0;
		head=0;
	}
	~Tabelle() {
		while(iterator!=0) {
			delete_node();
		}
	}
	//Fügt vor dem iterator an
	bool insert(item_type r) {
		node* knoten = new node();
		knoten->item = r;
		if(iterator == 0) {
			knoten->next = 0;
			knoten->prev = 0;
			head = knoten;
			tail = knoten;
			iterator = knoten;
			return true;
		}
		if(iterator==tail) {
			knoten->prev = 0;
			knoten->next = iterator;
			iterator->prev = knoten;
			tail = knoten;
			return true;
		}
		node* prevptr = iterator->prev;
		prevptr->next = knoten;
		knoten->next = iterator;
		knoten->prev = iterator->prev;
		iterator->prev = knoten;
		return true;
	}
	//Fügt am Head hinzu
	bool append(item_type r) {
		node* knoten = new node();
		knoten->item = r;
		if(iterator == 0) {
			knoten->prev = 0;
			head = knoten;
			tail = knoten;
			iterator = knoten;
		} else {
			knoten->prev = head;
			head->next = knoten;
			head = knoten;
		}
		knoten->next = 0;
		return true;
	}
	bool last() {
		if(head == 0) return false;
		iterator = head;
		return true;
	}
	bool first() {
		if(tail == 0) return false;
		iterator = tail;
		return true;
	}
	bool previous() {
		if(iterator->prev==0) return false;
		iterator = iterator->prev;
		return true;
	}
	bool next() {
		if(iterator->next==0) return false;
		iterator = iterator->next;
		return true;
	}
	//delete setzt iterator normalerweise auf den record davor
	bool delete_node() {
		if(iterator==0) return false;
		if(iterator==tail) {
			// cout << "iterator = tail" << endl;
			iterator = tail->next;
			iterator->prev = 0;
			delete tail;
			tail = iterator;
			return true;
		}
		if(iterator==head) {
			// cout << "iterator = tail" << endl;
			iterator = head->prev;
			iterator->next = 0;
			delete head;
			head = iterator;
			return true;
		}
		iterator->prev->next = iterator->next;
		iterator->next->prev = iterator->prev;
		node* i_prev = iterator->prev;
		delete iterator;
		iterator = i_prev;
		return true;
	}
	item_type getNode() {
		return iterator->item;
	}
	bool setNode(item_type r) {
		if(iterator==0) return false;
		iterator->item = r;
		return true;
	}
};


int main() {
	Tabelle<int> t;
	cout << "Insert 3: ";
	t.insert(3);
	cout << t.getNode() << endl;
	cout << "Insert 2: ";
	t.insert(2);
	cout << t.getNode() << endl;
	cout << "Insert 1: ";
	t.insert(1);
	cout << t.getNode() << endl;
	cout << "previous: " << t.previous() << endl;
	cout << t.getNode() << endl;
	cout << "previous: " << t.previous() << endl;
	cout << t.getNode() << endl;
	cout << "previous: " << t.previous() << endl;
	cout << t.getNode() << endl;
	cout << "next: " << t.next() << endl;
	cout << t.getNode() << endl;
	cout << "append 5 ";
	t.append(5);
	cout << t.getNode() << endl;
	cout << "last: " << t.last() << endl;
	cout << t.getNode() << endl;
	cout << "setze auf 10" << endl;
	t.setNode(10);
	cout << t.getNode() << endl;
	cout << "delete: " << endl;
	t.delete_node();
	cout << t.getNode() << endl;
	t.next();
	cout << t.getNode() << endl;
	cout << "delete: " << endl;
	t.delete_node();
	cout << t.getNode() << endl;
}
