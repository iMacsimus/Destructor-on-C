#include "list.h"
#include <stdlib.h>

struct __DM_List __DM_List_make(void) {
    struct __DM_List res = {.destruct = __DM_List_destruct, .push_back = __DM_List_push_back, .erase = __DM_List_erase, 
                                .end = calloc(1, sizeof(struct __DM_ListNode))};
    res.end->next = res.end;
    res.end->prev = res.end;
    res.begin = res.end;
    return res;
}

void __DM_List_destruct(void *ths) {
    struct __DM_List *cur = (struct __DM_List *)ths;
    for (struct __DM_ListNode *it = cur->begin; it != cur->end;) {
        struct __DM_ListNode *next = it->next;
        free(it);
        it = next;
    }
    free(cur->end);
}

void __DM_List_push_back(struct __DM_List *ths, void *ptr) {
    struct __DM_ListNode *new_elem = calloc(1, sizeof(*new_elem));
    new_elem->pointer = (struct __DM_BaseStruct *)ptr;
    
    new_elem->next = ths->end;
    new_elem->prev = ths->end->prev;

    new_elem->prev->next = new_elem;
    new_elem->next->prev = new_elem;

    ths->begin = ths->end->next;
}

void __DM_List_erase(struct __DM_List *ths, void *ptr) {
    for (struct __DM_ListNode *it = ths->begin; it != ths->end; it = it->next) {
        if ((void *)it->pointer == ptr) {
            it->pointer->destruct((void *)(it->pointer));
            it->prev->next = it->next;
            it->next->prev = it->prev;
            free(it);
        }
    }
}