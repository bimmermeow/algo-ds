#include <iostream>

template <class item_type>
class Stack
{
	struct node
		{
			item_type item;
			node *next;
		};
	private:
		node *tail;
		int anz_items;
	public:
		Stack() {
			tail = 0;
			anz_items =0;
		}
		//virtual ~Stack();
		void push(item_type &r) {
			node newitm = {*r, tail};
			tail = &newitm;
		}
		item_type pop() {
			if (tail==0) return false;
			item_type retitm = *tail.item;
			node *old = tail;
			tail = *tail.next;
			delete *old;
			return retitm;
		}
		item_type top() {
			if (tail==0) return false;
			return *tail.item;
		}
		int length() {
			return anz_items;
		}
		bool empty() {
			if (tail==0) return true;
			else return false;
		}
};

int main() {
	// Stack stack();
	return 0;
}
