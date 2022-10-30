#include "include/destruct_manager.h"
#include <stdlib.h>

struct DestructManager __DestractManager_make(void) {
    struct DestructManager res = {.add = __DestructManager_add, .destruct_current = __DestructManager_destruct_current,
                                    .destruct_all = __DestructManager_destruct_all, .resources = __dm_list.make()};
    return res;
}

void* __DestructManager_add(struct DestructManager *ths, void *rsc) {
    ths->resources.push_back(&ths->resources, rsc);
    return rsc;
}

void __DestructManager_destruct_current(struct DestructManager *ths, void *rsc) {
    ths->resources.erase(&ths->resources, rsc);
}

void __DestructManager_destruct_all(struct DestructManager *ths) {
    for (struct __DM_ListNode *it = ths->resources.begin; it != ths->resources.end; it = it->next) {
        it->pointer->destruct((void *)(it->pointer));
    }
    ths->resources.destruct(&ths->resources);
}

struct Wrapper *__Wrapper_make_p(void *data, void (*destruct)(void *ths)) {
    struct Wrapper *res = calloc(1, sizeof(*res));
    res->destruct_data = destruct;
    res->destruct = __Wrapper_destruct;
    res->data = data;
    return res;
}

void __Wrapper_destruct(void *ths) {
    struct Wrapper *cur = (struct Wrapper *)ths;
    cur->destruct_data(cur->data);
    free(ths);
}