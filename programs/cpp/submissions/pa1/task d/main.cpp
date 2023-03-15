#include<cstdio>
#include<cstring>
#include "function.h"
using namespace std;

void ReadInt(int &data) {	// this function is to read integers faster since the input is large
	data=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	do {
		data=(data<<3)+(data<<1)+ch-'0';
		ch=getchar();
	} while (ch>='0' && ch<='9');
}

void WriteInt(int &data) {	// this function is to write integers faster since the output is large
	char buff[20];
	int t=0;
	for(; data; data/=10) buff[t++]='0'+data%10;
	if (!t) buff[t++]='0';
	while (t) putchar(buff[--t]);
}

int main() {
	int n,k;
	ReadInt(n), ReadInt(k);
	Node *head=nullptr, *tail=nullptr;
	for(int i=1; i<=n; i++) {
		int x;
		ReadInt(x);
		if (tail==nullptr) {
			head=tail=new Node(x,nullptr);
		} else {
			tail=tail->next=new Node(x,nullptr);
		}
	}
	
	OperateList(head,k);
	for(Node *cur=head; cur!=nullptr; ) {
		WriteInt(cur->value);
		putchar(' ');
		Node *tmp=cur->next;
		delete cur;
		cur=tmp;
	}
	putchar('\n');
}
