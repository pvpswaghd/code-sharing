#include "function.h"
#include <iostream>

using namespace std;

void OperateList(Node* &head, int k) {
		Node* headA = head;  
		for(int i = 1; i < k; i++){
			headA = headA->next;	
		}
		Node* current = headA->next, *prev = headA, *next = nullptr;
		while(current!=nullptr){
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}	
		current = head, headA->next = head;
		while(current->next != headA)
			current = current->next;
		current->next = nullptr;	
		head = prev;
}
