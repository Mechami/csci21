#ifndef DNODE_HXX
#define DNODE_HXX
#include <cstddef> // For NULL
#include "dlist.h"
template<typename T>
class DList;

template<typename T>
class DNode {
  friend class DList<T>;

  public:
	DNode(const T& object);
	DNode(DNode<T>* left, DNode<T>* right, const T& object);

	const T& Contents() const;
	T& Contents();

	virtual ~DNode();
  private:
	DNode<T>* left;
	DNode<T>* right;
	T contents;

	bool Insert(const T& object);
	DNode<T>* FindNode(const T& object);
};

#include "dnode.cpp"
#endif // DNODE_HXX
