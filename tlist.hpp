
/* Name: Andrew Stade
Date: 9/14/2020
Section: COP 4530 */

template <class T>
TList<T>::TList()		// default constructor (creates an empty linked list)
{
	setVoid();		// creates an empty list
}

template <class T>
TList<T>::TList(T val, int num)	// creates a list containing "num" copies of the data element "val"
{
	setVoid();		// creates an empty list w/ setVoid
	
	for(int i = 0; i < num; i++)
	{
		InsertFront(val);
	}
}

template <class T>
TList<T>::~TList()		// destructor
{
	auto iter = GetIterator();
	
	for(int i = 1; i < size; i++) // runs through the list and deletes backwards 
	{
		iter.Next();
		delete iter.ptr->prev;
		
		if(i == size)	 // deletes last node
		{
			delete iter.ptr;
		}
	}
}

template <class T>
TList<T>::TList(const TList& L)		// copy constructor
{
	auto iter = L.GetIterator();
	
	setVoid();						// clear the list 
	
	for(int i = 0; i < L.GetSize(); i++) // runs through list iterating member then adding at the back
	{
		InsertBack(iter.GetData());
		iter.Next();
	}
}

template <class T>
TList<T> TList<T>::operator=(const TList& L)		// copy assignment operator
{
	Clear();		// clear list
	
	auto iter = L.GetIterator();
	
	for(int i = 0; i < L.GetSize(); i++)
	{
		InsertBack(iter.GetData());
		iter.Next();
	}
	
	return *this;
}

template <class T>
TList<T>::TList(TList && L)			// move constructor
{
	size = L.size;		// copy private data to L data
	first = L.first;
	last = L.last;
}

template <class T>
TList<T> TList<T>::operator=(TList && L)		// move assignment operator
{
	int tempo = 0;
	
	Node<T> *tPtr = first;
	first = L.first;		// move first to L.first
	L.first = tPtr;			// ptr swap for first
	
	tPtr = last;			
	last = L.last;			// move last to L.last
	L.last = tPtr;			// ptr swap for last
	
	tempo = size;
	size = L.size;			// move size to L.size
	L.size = tempo;
	
	return *this;
}

template <class T>
void TList<T>::setVoid()		// sets list to empty
{
	size = 0;
	first = nullptr;
	last = nullptr;
}

template <class T>
bool TList<T>::IsEmpty() const		// checks to see whether list is empty
{
	if(size == 0)
	{
		return true;
	}
	return false;
}

template <class T>
void TList<T>::Clear()			// clear out list, reset to empty
{
	for(int i = 0; i < size; i++)
	{
		RemoveFront();
	}
	setVoid(); 		// running setVoid just to double check the list is empty
}

template <class T>
int TList<T>::GetSize() const			// return the size of the list
{
	return size;
}

template <class T>
void TList<T>::InsertFront(const T& d)	// insert data d as first element
{
	Node<T> *n = new Node<T>(d);
	
	if(size == 0)
	{
		first = n;
		last = n;
		size++;
	}
	else
	{
		n->next = first;
		first->prev = n;
		first = n;
		size++;
	}
}

template <class T>
void TList<T>::InsertBack(const T& d)		// insert data d as last element
{
	Node<T> *n = new Node<T>(d);
	
	if(size == 0)
	{
		first = n;
		last = n;
		size++;
	}
	else
	{
		n->prev = last;
		last->next = n;
		last = n;
		size++;
	}
	
}

template <class T>
void TList<T>::RemoveFront()			// remove first element of list
{
	if(size == 1)			// if size is 1 -> delete value then reset to empty
	{
		delete first;
		setVoid();
	}
	if(size > 1)
	{
		Node<T> *tPtr = first->next;
		tPtr->prev = 0;
		delete first;
		first = tPtr;
		size--;
	}
}

template <class T>
void TList<T>::RemoveBack()			// remove last element of list
{
	if(size == 1)			// if size is 1 -> delete value then reset to empty
	{
		delete last;
		setVoid();
	}
	if(size > 1)
	{
		Node<T> *tPtr = last->prev;
		tPtr->next = 0;
		delete last;
		last = tPtr;
		size--;
	}
}

template <class T>
T& TList<T>::GetFirst() const			// return first element of list
{
	return first->data;
}

template <class T>
T& TList<T>::GetLast() const			// return last element of list
{
	return last->data;
}

template <class T>
TListIterator<T> TList<T>::GetIterator() const  // return iterator to first item
{
	TListIterator<T> iter;
	iter.ptr = first;
	return iter;
}

template <class T>
TListIterator<T> TList<T>::GetIteratorEnd() const // return iterator to last item
{
	TListIterator<T> iter;
	iter.ptr = last;
	return iter;
}

// insert data element d just before item at pos position
template <class T>
void TList<T>::Insert(TListIterator<T> pos, const T& d)
{
	Node<T> *prevNode = nullptr;
	Node<T> *tempNode = new Node<T>(d);
	if(pos.HasPrevious() == true)
	{
		prevNode = pos.ptr->prev;
	}
	else
	{
		prevNode = nullptr;
	}
	
	tempNode->next = pos.ptr;
	pos.ptr->prev = tempNode;
	
	if(prevNode == nullptr)
	{
		first = tempNode;
	}
	else
	{
		prevNode->next = tempNode;
		tempNode->prev = prevNode;
	}
	size++;
}

// remove data item at position pos. Return iterator to the item 
//  that comes after the one being deleted
template <class T>
TListIterator<T> TList<T>::Remove(TListIterator<T> pos)
{
	Node<T> *currentP = pos.ptr;
	Node<T> *prevP = currentP->prev;
	Node<T> *nextP = currentP->next;
	
	pos.Next();	
	prevP->next = nextP;
	nextP->prev = prevP;
	
	delete currentP;
	size--;
	
	return pos;
}

// print list contents in order, separated by given delimiter
template <class T>
void TList<T>::Print(std::ostream& os, char delim) const
{
	auto iter = this->GetIterator();
	
	for(int i = 0; i < size; i++)
	{
		os << iter.GetData() << delim;
		iter.Next();
	}
}

// Iterator Functions 

template <class T>
TListIterator<T>::TListIterator()			// default constructor
{
	ptr = nullptr;
}

template <class T>
bool TListIterator<T>::HasNext() const		// next item available?
{
	if(ptr->next == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template <class T>
bool TListIterator<T>::HasPrevious() const		// previous item available?
{
	if(ptr->prev == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template <class T>
TListIterator<T> TListIterator<T>::Next()		// advance to next item
{
	if(HasNext() == true)
	{
		ptr = ptr->next;
	}
	return *this;
}

template <class T>
TListIterator<T> TListIterator<T>::Previous()		// move to previous item
{
	if(HasPrevious() == true)
	{
		ptr = ptr->prev;
	}
	return *this;
}

template <class T>
T& TListIterator<T>::GetData() const			// return data element of current node
{
	return ptr->data;
}
   