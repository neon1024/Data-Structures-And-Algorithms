#pragma once
//DO NOT INCLUDE BAGITERATOR

//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111;
#define DEFAULT_CAPACITY_UNIQUE_ELEMENTS 1  // must not be zero
#define DEFAULT_CAPACITY_POSITIONS 1  // must not be zero

typedef int TElem;

class BagIterator;

class Bag {

    private:
        /*
            6.ADT Bag – represented as a dynamic array of unique elements (U) and
            a dynamic array of positions (P) in U of the elements from the Bag.
            For example, the bag [5, 10, -1, 2, 3, 10, 5, 5, -5] will be represented
            as: U = [5, 10, -1, 2, 3, -5] and P = [0, 1, 2, 3,4, 1, 0, 0, 5]
        */

        // dynamic array of unique elements (U)
        TElem* unique_elements;
        int capacity_unique_elements;  // maximum number of unique elements that can be stored
        int size_unique_elements;  // the current number of unique elements

        // dynamic array of positions (P) in U
        TElem* positions;
        int capacity_positions;  // the maximum number of positions that can be stored
        int size_positions;  // the current number of positions

        //DO NOT CHANGE THIS PART
        friend class BagIterator;

        void resize_unique_elements();

        void resize_positions();

        void add_to_positions(int index);

        void add_to_unique_elements(TElem elem);

        void remove_first_occurrence_from_positions(int position);

        void remove_from_unique_elements(TElem elem);

    public:

	//constructor
	Bag();

	//adds an element to the bag
	void add(TElem e);

	//removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;

	//destructor
	~Bag();
};
