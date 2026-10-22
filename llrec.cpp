#include "llrec.h"

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot) {
    if (head != nullptr) {
        llpivot(head->next, smaller, larger, pivot);
        if (head->val <= pivot) {
            head->next = smaller;
            smaller = head;

        } else {
            head->next = larger;
            larger=head;
        }
    } else {
        smaller = nullptr; larger = nullptr;
    }
    head = nullptr;
    return;
}
