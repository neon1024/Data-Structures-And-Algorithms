#include <exception>
#include "BagIterator.h"
#include "Bag.h"

BagIterator::BagIterator(const Bag& c): bag(c) {
    /* Constructs the object BagIterator
     * Time Complexity: Theta(1)
     */
    this->current_position = 0;
}

void BagIterator::first() {
    /* Make the iterator point to the first element
     * Time Complexity: Theta(1)
     */
    this->current_position = 0;
}

void BagIterator::next() {
    /* Make the iterator point to the next element
     * Time Complexity: Theta(1)
     */
    if(valid()) {
        this->current_position++;
    } else {
        throw std::exception();
    }
}

bool BagIterator::valid() const {
    /* Check if the current element is valid
     * Returns True if the current element is valid, False otherwise
     * Time Complexity: Theta(1)
     */
    return this->current_position < bag.size();
}

TElem BagIterator::getCurrent() const {
    /* Get the current element that the iterator points to
     * Time Complexity: Theta(1)
     */
    if(valid()) {
        return bag.unique_elements[bag.positions[this->current_position]];
    }
	throw std::exception();
}
