#pragma once
#include "Generic_DS/Node.h"

using namespace std;

template <typename T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	int size;

public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	~LinkedList() {
		Node<T>* current = head;
		while (current != nullptr) {
			Node<T>* next = current->getNext();
			delete current;
			current = next;
		}
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	void InsertEnd(T& value) {
		Node<T>* newNode = new Node<T>(value);
		if (isEmpty()) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->setNext(head);
			head->setPrev(newNode);
			head = newNode;
		}
		size++;
	}

	void Print() {
		Node<T>* current = head;
		while (current != nullptr) {
			cout << current->getValue() << endl;
			current = current->getNext();
		}
	}

	Node<T>* search(T& value) {
		Node<T>* current = head;
		while (current != nullptr) {
			if (current->getValue() == value) {
				return current;
			}
			current = current->getNext();
		}
		return nullptr;
	}

	void DeleteFirst() {
		if (isEmpty()) {
			return;
		}
		Node<T>* temp = head;
		head = head->getNext();
		if (head != nullptr) {
			head->setPrev(nullptr);
		}
		else {
			tail = nullptr;
		}
		delete temp;
		size--;
	}

	void DeleteNode(T& value) {
		if (isEmpty()) {
			return;
		}
		Node<T>* current = head;
		while (current != nullptr) {
			if (current->getValue() == value) {
				if (current->getPrev() != nullptr) {
					current->getPrev()->setNext(current->getNext());
				}
				else {
					head = current->getNext();
				}
				if (current->getNext() != nullptr) {
					current->getNext()->setPrev(current->getPrev());
				}
				else {
					tail = current->getPrev();
				}
				delete current;
				size--;
				return;
			}
			current = current->getNext();
		}
	}

	int countNodes() {
		int count = 0;
		Node<T>* current = head;
		while (current != nullptr) {
			count++;
			current = current->getNext();
		}
		return count;
	}

	T GetHead() {
		if (isEmpty()) {
			return;
		}
		return head->getValue();
	}
};




