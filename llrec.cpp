#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot) {
    if (head != nullptr) { // if head isnt a null ptr
        llpivot(head->next, smaller, larger, pivot); // runs pivot on head->next.
        if (head->val <= pivot) { // if less than or equal to
            head->next = smaller; // first values next ptr points to smaller start
            smaller = head; // smaller now points to the new first value
            // sets 
        } else {
            head->next = larger; // first values next ptr points to larger start
            larger=head; // larger now points to new the new first value
        }
    } else { // if head is empty, initialised smaller and larger as null
        smaller = nullptr; larger = nullptr;
    }
    head = nullptr; // sets head as nullptr so no memory leak
    return;
}