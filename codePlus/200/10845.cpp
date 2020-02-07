#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
};

class Queue {
private:
	int queueSize;
	Node* head;
	Node* tail;
public:
	Queue() {
		head = new Node();
		tail = new Node();

		head->prev = NULL;
		head->next = tail;
		tail->prev = head;
		tail->next = NULL;
		queueSize = 0;
	}

	void push(int x) {
		Node* new_node = new Node();
		new_node->data = x;
		
		new_node->prev = tail->prev;
		new_node->next = tail;
		tail->prev->next = new_node;
		tail->prev = new_node;
		queueSize++;
	}

	void pop() {
		if (queueSize == 0) {
			cout << -1 << endl;
		}
		else {
			Node* del = head->next;
			int data = del->data;

			del->next->prev = head;
			head->next = del->next;
			free(del);
			queueSize--;
			cout << data << endl;
		}
	}

	int size() {
		return queueSize;
	}

	int empty() {
		if (queueSize == 0)
			return 1;
		else
			return 0;
	}

	void front() {
		if (queueSize == 0) {
			cout << -1 << endl;
		}
		else {
			cout << head->next->data << endl;
		}
	}

	void back() {
		if (queueSize == 0) {
			cout << -1 << endl;
		}
		else {
			cout << tail->prev->data << endl;
		}
	}
};

int main() {
	int N, input;
	string command;
	Queue q;

	cin >> N;
	while (N--) {
		cin >> command;
		if (command == "push") {
			cin >> input;
			q.push(input);
		}
		else if (command == "pop") {
			q.pop();
		}
		else if (command == "size") {
			cout << q.size() << endl;
		}
		else if (command == "empty") {
			cout << q.empty() << endl;
		}
		else if (command == "front") {
			q.front();
		}
		else if (command == "back") {
			q.back();
		}
	}

	return 0;
}