/*
 * List.cpp
 *
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - List is sorted by patient's care card number.
 *                   - List length will stay equal to or less than MAX_ELEMENTS
 *
 * Last modified on: May 2017
 * Author: Brendin Green
 */

#include <iostream>
#include "List.h"

using namespace std;

// Default constructor
List::List() : elementCount(0), capacity(List::MAX_ELEMENTS) {}

// Description: Returns the total element count currently stored in List.
int List::getElementCount() const {
    return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and elementCount has been incremented.
bool List::insert(const Patient& newElement){
    // Check if appendable
    if (elementCount < capacity) {

        for (int i = 0; i < getElementCount(); i++) {
            if (elements[i] > newElement){
                // Insert before ith element
                for (int j = getElementCount(); j > i; j--){
                    elements[j] = elements[j-1];
                }
                elements[i] = newElement;

                elementCount++;
                return true;
            }
            if (elements[i] == newElement) {
                return false;
            }
        }
        elements[elementCount] = newElement;
        elementCount++;
        return true;
    }
    return false;
}

// Description: Remove an element.
// Postcondition: toBeRemoved is removed and elementCount has been decremented.
bool List::remove(const Patient& toBeRemoved){
    // Search for the element we want to remove
    for (int i = 0; i < getElementCount(); i++){
        if (elements[i] == toBeRemoved){
            for (int j = i + 1; j < elementCount; j++ ) {
                elements[j-1] = elements[j];
            }
            elementCount--;
            return true;
        }
    }
    return false;
}

// Description: Remove all elements.
void List::removeAll(){
    elementCount = 0;
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target){
    for (int i = 0; i < getElementCount(); i++) {
        if (elements[i] == target){
            return &elements[i];
        }
    }
    return NULL;
}

// Description: Prints all elements stored in List.
void List::printList() {
    for (int i = 0; i < getElementCount(); i++){
        elements[i].printPatient();
    }
}