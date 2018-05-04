#include <iostream>
#include <string>
using namespace std;

int key=-1;

struct Data{
	int id;
	string name;
};

struct Node{
	Data element;
	Node *next;
};

struct Queue{
	Node *front;
	Node *rear;
};


void newNode(Node* &head) {
	head = new Node;
	head->next = NULL;
}

void MAKENULL(Queue &q) {
	newNode(q.front);
	q.rear = q.front;
}

void Enqueue(Queue &q, Data value) {
	newNode(q.rear->next);
	q.rear = q.rear->next;
	q.rear->element = value;
}

bool isEmpty(Queue q) {
	return (q.front == q.rear);
}

void Dequeue(Queue &q) {
	if (isEmpty(q)) {
		return;
	}
	else if (q.front->next == q.rear) {
		q.rear = q.front;
		q.front->next = NULL;
		return;
	}
	q.front->next = q.front->next->next;
}

Data getFirst(Queue q) {
	return q.front->next->element;
}

int size(Queue q) {
	int count = 0;
	Node* temp = q.front->next;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}

void printQ(Queue q) {
	Node* temp = q.front->next;
	cout << "\nNo.:\t------\tName:\n";
	while (temp != NULL) {
		cout << temp->element.id << "\t------\t" << temp->element.name;
		cout << endl;
		temp = temp->next;
	}
	cout << endl;
}

Data setData(){
	key++;
	Data d;
	cout<<"Enter Name: ";
	cin>> d.name;
	d.id = key;
	return d;
}

void main(){
	Queue Q;
	MAKENULL(Q);
	char CMD;
	cout<<"-------------\nJUST A QUEUE\n";
	do{
		cout<<"\n1-Enqueue\n2-Dequeue\n3-Print\n4-ANY OTHER INPUT TO EXIT\n";
		cout<<"Command:"; cin>>CMD;
		switch(CMD){
		case '1':
			Enqueue(Q,setData());
			break;
		case '2':
			if(isEmpty(Q)){
				cout<<"\nQueue is Empty!\n";
				break;
			}
			Dequeue(Q);
			break;
		case '3':
			if(isEmpty(Q)){
				cout<<"\nQueue is Empty!\n";
				break;
			}
			printQ(Q);
			break;
		}
	}while(CMD=='1'||CMD=='2'||CMD=='3');
}
