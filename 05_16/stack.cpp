#include "stack.h"

Stack::Stack() {
	tail = 0;
	anz_items =0;
}

item_type Stack::top() {
	if (tail==0) return false;
	return *tail.item;
}
item_type Stack::pop() {
	if (tail==0) return false;
	item_type retitm = *tail.item;
	old = tail;
	tail = *tail.next;
	delete *old;
	return retitm;
}
void Stack::push(item_type &r) {
	node newitm = {*r, tail};
	tail = &newitm;
}
int Stack::length() {
	return anz_items;
}
bool Stack::empty() {
	if (tail==0) return true;
	else return false;
}
