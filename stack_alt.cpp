template <class item_type>
class Stack
{
public:
	struct node {
		item_type item;
		node* next;
	};
	int anz_items;
	node* tail;
	Stack() {
		tail = 0;
		anz_items =0;
	}
	//virtual ~Stack();
	void push(item_type r) {
		node newitm;
		newitm.item = r;
		newitm.next = tail;
		tail = &newitm;
		anz_items++;
	}
	item_type pop() {
		if (tail==0) return false;
		node n = *tail;
		item_type retitm = n.item;
		tail = n.next;
		anz_items--;
		// delete old;
		return retitm;
	}
	item_type top() {
		if (tail==0) return false;
		return tail->item;
	}
	int length() {
		return anz_items;
	}
	bool empty() {
		if (tail==0) return true;
		else return false;
	}
};
