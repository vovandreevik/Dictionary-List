#include <iostream>
#include "DictionaryList.h"


DictionaryList::DictionaryList() {
	head_ = nullptr;
}

bool DictionaryList::isEmpty() {
	return head_ == nullptr;
}

DictionaryList::DictionaryList(const DictionaryList& other) {
	head_ = other.head_;
}

DictionaryList::~DictionaryList() {
	if (head_ != nullptr) {
		Node* next = head_;
		while (next) {
			next = next->next_;
			delete head_;
			head_ = next;
		}
	}
}


DictionaryList::Node* DictionaryList::head() const
{
	return head_;
}

void DictionaryList::out()
{
	Node* out = this->head();
	while (out != nullptr) {
		std::cout << out->key_ << '\n';
		out = out->next_;
	}
}

void DictionaryList::insert(Node* x)
{
	if (this->search(x->key_)) {
		return;
	}

	if (isEmpty()) {
		head_ = x;
		return;
	}

	if (x->key_ < head_->key_) {
		x->next_ = head_;
		head_ = x;
	}

	else {
		Node* temp = head_;
		while (temp != nullptr) {
			if (temp->next_->key_ > x->key_) {
				break;
			}
			temp = temp->next_;
		}

		if (temp == nullptr) {
			x->next_ = nullptr;
			temp->next_ = x;
		}

		else {
			x->next_ = temp->next_;
			temp->next_ = x;
		}
	}
}



void DictionaryList::insert(int key) {
	Node* node = new Node(key);
	this->insert(node);
}

void DictionaryList::remove(Node* x)
{
	if (this->head() != nullptr) {
		Node* temp = head_;
		if (temp == x) {
			head_ = temp->next_;
			temp = temp->next_;
		}
		while (temp->next_) {
			if (temp->next_ == x) {
				if (temp->next_->next_) {
					temp->next_ = temp->next_->next_;
				}
				else {
					temp->next_ = nullptr;
				}
			}
			if (temp->next_) {
				temp = temp->next_;
			}
		}
	}
}


void DictionaryList::remove(int key)
{
	Node* current = head_;
	while (current->next_) {
		if (current->next_->key_ == key) {
			if (current->next_->next_) {
				current->next_ = current->next_->next_;
			}
			else {
				current->next_ = nullptr;
			}
		}
		if (current->next_) {
			current = current->next_;
		}
	}
}

DictionaryList::Node* DictionaryList::searchLink(int key)
{
	Node* x = this->head();
	while (x != nullptr and x->key_ != key)
	{
		x = x->next_;
	}
	return x;
}

bool DictionaryList::search(int key)
{
	return (searchLink(key) != nullptr);
}

void DictionaryList::merge(DictionaryList* sub) {
	Node* node = sub->head();

	if (isEmpty()) {
		head_ = node;
	}

	while (node) {
		Node* next = node->next_;
		
		if (node == sub->head_) {
			if (sub->head_->next_) { 
				sub->head_ = sub->head_->next_; 
			}
			else { 
				sub->head_ = nullptr; 
			}
		}
		this->insert(node);
		if (sub->head() == nullptr) {
			sub->remove(node);
		}
		if (next != nullptr) {
			node = next;
		}
		else { 
			node = nullptr; 
		}
	}
}

void DictionaryList::remove(DictionaryList* sub) {
	if (isEmpty()) return;
	
	Node* subHead = sub->head();

	while (subHead) {
		this->remove(subHead->key_);
		subHead = subHead->next_;
	}
}

DictionaryList* getIntersection(DictionaryList* first, DictionaryList* second) {
	DictionaryList* resList = new DictionaryList;
	
	DictionaryList::Node* subHead = first->head();

	while (subHead != nullptr) {
		if (second->search(subHead->key_)) {
			resList->insert(subHead->key_);
		}
		subHead = subHead->next_;
	}
	return resList;
}


DictionaryList& DictionaryList::operator= (const DictionaryList* other) {

	this->head_ = other->head_;
	return *this;
}


DictionaryList* DictionaryList::operator= (const DictionaryList& other) {
	Node* node = other.head_;

	while (node) {
		this->insert(node->key_);
		node = node->next_;
	}
	return this;
}