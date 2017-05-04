template <class item_type>
class Stack
{
	struct node
	{
		item_type item;
		node* next;
	};
private:
	node* tail;
	int anz_items;

public:
	Stack(){
		tail = 0;
		anz_items = 0;
	};
	virtual ~Stack(){};
	void push(item_type &r) {
		node* p;
		p = new node;
		p->item = r;
		p->next = tail;
		tail = p;
		anz_items++;
	};
	item_type pop() {
		if (!empty()){
			node* reta = tail;
			item_type ret = reta->item;
			tail = tail->next;
			anz_items--;
			delete(reta);
			return ret;
		}
		return NULL;
	};
	item_type top() {
		if (!empty())
			return tail->item;
		return NULL;
	};
	int length() {
		return anz_items
	};
	bool empty() {
		if (anz_items == 0)
			return true;
		else
			return false;
	};
};

void main() {}