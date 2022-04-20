#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

struct Node
{
    int value;
    Node * next;
};

void print_list(Node * head)
{
    Node * current = head;
    while (current != NULL)
    {
        // process the current node, e.g., print the content
        cout << current->value << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

void print_num(Node * head)
{
    Node * current = head;
    while (current != NULL)
    {
        if (current == head)
            cout << current->value;
        else
            cout << setw(3) << setfill('0') << current->value;
        current = current->next;
    }
}

//reused and modified from print_list_reverse.cpp
void print_list_reverse(Node * head)
{
    if (head == NULL) return;
    else {
        bool flag = false;
        if (head->next == NULL) flag = true;
        print_list_reverse( head->next );
        if(flag) cout << head->value;
        else cout << setw(3) << setfill('0') << head->value;
        flag = false;
    }
}

//reused from print_list_reverse.cpp
void tail_insert(Node * & head,	Node * & tail, int num)
{
	Node * p = new Node;
	p->value = num;
	p->next = NULL;
	if (head == NULL) {
		head = p;
		tail = p;
	}
	else {
		tail->next = p;
		tail = p;
	}
}

void head_insert(Node * & head, int v)
{
    Node * p = new Node;
    p->value = v;
    p->next = head;
    head = p;
}

void delete_head( Node * & head)
{
    if (head != NULL) {
        Node * p = head;
        head = head->next;
        delete p;
    }
}

void delete_list(Node * & head)
{
    while ( head != NULL )
    {
        delete_head(head);
    }
}

void grow_array( char * & array, int & size )
{
    if (array == NULL)
        return;

    int newSize = size * 2;

    // doubled the size of the array;
    char * tmp = new char [ newSize ];
    // copy original contents
    for (int i = 0; i < size; ++i)
        tmp[i] = array[i];

    delete [] array;

    array = tmp;
    size = newSize;
}

void input_num(char * & digits, int & numDigits)
{
    int arraysize = 32;
    digits = new char [arraysize];
    char c;
    int numRead = 0;
    c = cin.get();
    while (!isspace(c))
    {
        if (numRead >= arraysize)
            grow_array( digits, arraysize );

        digits[numRead] = c;
        numRead++;
        c = cin.get();
    }
    numDigits = numRead;
}

Node * create_num_list()
{
    Node * head = NULL, * tail = NULL;

    string str;
    char * digits = NULL;  // a dynamic array for storing an input number
    int numDigits;
    int val;

    input_num(digits, numDigits);

    str.clear();
    for (int i = numDigits-1; i >= 0; --i) {
        str = digits[i] + str;
        if (str.length()==3) {
            val = atoi(str.c_str());

            tail_insert(head, tail, val);

            str.clear();
        }
    }
    if (!str.empty()) {
        val = atoi(str.c_str());
        tail_insert(head, tail, val);
    }

    if (digits != NULL) {
        delete [] digits;

    }

    return head;
}

// return the length of a linked list
int list_length(Node * head)
{

    int num = 0;

    Node * current = head;
    while (current != NULL)
    {
        ++num;
        current = current->next;
    }

    return num;
}


Node * create_last_list(Node * n1, Node * n2)
{
    Node * curr1 = n1, * curr2 = n2;
    Node * head = NULL, * tail = NULL;

    string str;
    int numDigits;
    int val;

    int length, extra = 0;
    if(list_length(n1) > list_length(n2))
        length = list_length(n1);
    else length = list_length(n2);
    str.clear();
    for (int i = 0; i < length; i++){
        if(curr1 != NULL && curr2 != NULL){
            int newVal = (curr1->value + curr2->value + extra)%1000;
            extra = (curr1->value + curr2->value + extra) / 1000;
            tail_insert(head, tail, newVal);

            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        else if (curr1 != NULL){ 
            tail_insert(head, tail, (curr1->value + extra)%1000);
            extra = (curr1->value + extra) / 1000;
            curr1 = curr1->next;
        }
        else if (curr2 != NULL){
            tail_insert(head, tail, (curr2->value + extra)%1000);
            extra = (curr2->value + extra) / 1000;
            curr2 = curr2->next;
        }
    }
    if (extra != 0) tail_insert(head, tail, extra);
    return head;
}

int main()
{
    Node * n1, * n2, * n3;

    n1 = create_num_list();
    cin.get();       // skip the '+' sign
    cin.get();       // the space after the '+' sign
    n2 = create_num_list();
    print_list(n1);
    print_list(n2);
    n3 = create_last_list(n1, n2);
    print_list(n3);
    print_list_reverse(n3); 
    cout << "\n";
    delete_list(n1);
    delete_list(n2);
    delete_list(n3); 
    return 0;
}

