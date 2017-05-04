template <class item_type>
class Tabelle {
public:
	struct node {
		node* prev;
		node* next;
		item_type item;
	};
	node* iterator;
	node* tail;
	node* head;
	unsigned int anz_items;
	Tabelle() {
		iterator=0;
		tail =0;
		head=0;
	}
	bool insert(item_type r) {
		node knoten;
		knoten.item = r;
		if(iterator == 0) {
			knoten.next = 0;
			knoten.prev = 0;
			head = &knoten;
			tail = &knoten;
			iterator = &knoten;
			return true;
		}
		if(iterator==tail) {
			knoten.prev = 0;
			knoten.next = iterator;
			iterator->prev = &knoten;
			tail = &knoten;
			return true;
		}
		iterator->prev.next = &knoten;
		knoten.next = iterator;
		knoten.prev = iterator->prev;
		iterator->prev = &knoten;
		return true;
	}
	bool append(item_type r) {
		node knoten;
		knoten.item = r;
		if(iterator == 0) {
			knoten.prev = 0;
			head = &knoten;
			iterator = &knoten;
		} else {
			knoten.prev = tail;
		}
		knoten.next = 0;
		tail->next = &knoten;
		tail = &knoten;
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
	item_type getNode() {
		return iterator->item;
	}
	bool setNode(item_type r) {
		if(iterator==0) return false;
		iterator->item = r;
		return true;
	}
};
