#ifndef DLIST_HXX
#define DLIST_HXX
#include <sstream>
#include <string>
#include <cstddef> // For NULL
#include "dnode.h"
using std::stringstream;
using std::string;

template<typename T>
class DList {
  public:
	DList();

	bool insert(const T& object);
	void pushFront(const T& newContents);
	void pushBack(const T& newContents);

	const T& getFront() const;
	const T& getBack() const;
	bool get(const T& target) const;

	bool removeFirst(const T& object);
	bool removeAll(const T& object);
	void popFront();
	void popBack();

	void clear();

	unsigned long length() const;
	string to_string(bool show_index = false) const;

	const T& operator[](unsigned long index) const;

	~DList();
  private:
	DNode<T>* head;
	DNode<T>* tail;
	unsigned long size;

	DNode<T>* FindNode(DNode<T>* node, const T& object) const;
	DNode<T>* FindLowest(DNode<T>* node) const;
	DNode<T>* FindHighest(DNode<T>* node) const;
	bool Remove(DNode<T>* node, const T& object);
};

#include "dlist.cpp"
#endif // DLIST_HXX
