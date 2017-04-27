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
		Stack();
		//virtual ~Stack();
		void push(item_type &r);
		item_type pop();
		item_type top();
		int length();
		bool empty();
};
