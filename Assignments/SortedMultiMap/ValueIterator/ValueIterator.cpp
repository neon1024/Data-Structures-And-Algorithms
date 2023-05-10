#include "ValueIterator.h"

ValueIterator::ValueIterator(const SortedMultiMap &smm, TKey key): smm{smm}, key{key} {
    this->first_position = this->smm.search_key(this->key);
    this->current_position = this->first_position;
}

void ValueIterator::first() {
    this->current_position = this->first_position;
}

void ValueIterator::next() {
    if(!this->valid())
        throw exception();

    int CurrentElement = this->smm.DLLANodes[this->current_position].next;

    while(CurrentElement != -1) {
        if(this->smm.DLLANodes[CurrentElement].info.first == this->key) {
            this->current_position = CurrentElement;
            return;
        } else {
            CurrentElement = this->smm.DLLANodes[CurrentElement].next;
        }
    }

    this->current_position = -1;
}
///Theta(1)

bool ValueIterator::valid() const{
    if(this->current_position == -1)
        return false;
    return true;
}
///Theta(1)

TValue ValueIterator::getCurrent() const{
    if(!this->valid())
        throw exception();
    return this->smm.DLLANodes[this->current_position].info.second;
}
///Theta(1)
