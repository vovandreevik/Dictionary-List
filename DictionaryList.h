#pragma once
class DictionaryList
{
private:
	struct Node {
		int key_;
		Node* next_;

		Node(int key, Node* next = nullptr) {
			key_ = key;
			next_ = next;
		}
	};

	Node* head_;

	void insert(Node* x);
	void remove(Node* x);
	Node* head() const;
	Node* searchLink(int item);

public:
	DictionaryList();
	DictionaryList(const DictionaryList& other);
	~DictionaryList();
	DictionaryList& operator= (const DictionaryList* other);
	DictionaryList* operator= (const DictionaryList& other);
	void out();
	bool isEmpty();
	void insert(int item);
	void remove(int item);
	bool search(int item);
	void merge(DictionaryList* subList);
	void remove(DictionaryList* subList);
	friend DictionaryList* getIntersection(DictionaryList* leftList, DictionaryList* rightList);
};