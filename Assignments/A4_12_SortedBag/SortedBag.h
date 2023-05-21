/*
 * 12. ADT SortedBag using a hashtable with open addressing (double  hashing) in which the elements are stored.
 * If an element appears multiple times, it will be stored multiple times in the  hashtable.
 * In the constructor of the iterator create a sorted array of the elements and use that array for iterating.
 */

/*
 * TODO don't create other classes
 */

#pragma once
//DO NOT INCLUDE SORTEDBAGITERATOR

//DO NOT CHANGE THIS PART
typedef int TComp;
typedef TComp TElem;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TCOMP (-11111)
#define DELETED (-1111111111)

class SortedBagIterator;

class SortedBag {
	friend class SortedBagIterator;

private:
    TComp* elements;
    int capacity;
    int number_of_elements;

    Relation relation;

    int hash(TComp element, int i) const;
    int hash1(TComp element) const;
    int hash2(TComp element) const;

    void resize();
    void rehash();

public:
	// constructor
	explicit SortedBag(Relation r, int capacity=2);

    // TODO copy constructor

	// adds an element to the sorted bag
	void add(TComp e);

	// removes one occurrence of an element from a sorted bag
	// returns true if an element was removed, false otherwise
	bool remove(TComp e);

	// checks if an element appears in the sorted bag
	bool search(TComp e) const;

	// returns the number of occurrences for an element in the sorted bag
	int nrOccurrences(TComp e) const;

	// returns the number of elements from the sorted bag
	int size() const;

	// returns an iterator for this sorted bag
	SortedBagIterator iterator() const;

	// checks if the sorted bag is empty
	bool isEmpty() const;

	//destructor
	~SortedBag();
};
