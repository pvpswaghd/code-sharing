#ifndef FUNCTION_H
#define FUNCTION_H

struct Node {
	int value;
	Node *next;
	
	Node(int v,Node *nxt) {
		value=v;
		next=nxt;
	}
};

void OperateList(Node* &head, int k) ;

#endif