#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
};

class Deque {
private:
	int queueSize;
	Node* head;
	Node* tail;
public:
	Deque() {
		head = new Node();
		tail = new Node();

		head->prev = NULL;
		head->next = tail;
		tail->prev = head;
		tail->next = NULL;
		queueSize = 0;
	}

	void push_front(int x) {
		Node* new_node = new Node();
		new_node->data = x;

		new_node->prev = head;
		new_node->next = head->next;
		head->next->prev = new_node;
		head->next = new_node;
		queueSize++;
	}

	void push_back(int x) {
		Node* new_node = new Node();
		new_node->data = x;

		new_node->prev = tail->prev;
		new_node->next = tail;
		tail->prev->next = new_node;
		tail->prev = new_node;
		queueSize++;
	}

	void pop_front() {
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

	void pop_back() {
		if (queueSize == 0) {
			cout << -1 << endl;
		}
		else {
			Node* del = tail->prev;
			int data = del->data;

			del->prev->next = tail;
			tail->prev = del->prev;
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
	Deque deq;

	cin >> N;
	while (N--) {
		cin >> command;
		if (command == "push_back") {
			cin >> input;
			deq.push_back(input);
		}
		else if (command == "push_front") {
			cin >> input;
			deq.push_front(input);
		}
		else if (command == "pop_front") {
			deq.pop_front();
		}
		else if (command == "pop_back") {
			deq.pop_back();
		}
		else if (command == "size") {
			cout << deq.size() << endl;
		}
		else if (command == "empty") {
			cout << deq.empty() << endl;
		}
		else if (command == "front") {
			deq.front();
		}
		else if (command == "back") {
			deq.back();
		}
	}

	return 0;
}