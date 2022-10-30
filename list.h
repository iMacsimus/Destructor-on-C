#ifndef __destruct_manager_list_H
#define __destruct_manager_list_H

#include "base_struct.h"

struct __DM_ListNode {
    struct __DM_BaseStruct *pointer;
    struct __DM_ListNode *prev;
    struct __DM_ListNode *next;
};

//declare functions
struct __DM_List;
struct __DM_List __DM_List_make(void);
void __DM_List_destruct(void *ths);
void __DM_List_push_back(struct __DM_List *ths, void *ptr);
void __DM_List_erase(struct __DM_List *ths, void *ptr);
//declare struct
struct __DM_List {
    void (*destruct)(void *ths);
    void (*push_back)(struct __DM_List *ths, void *ptr);
    void (*erase)(struct __DM_List *ths, void *ptr);

    struct __DM_ListNode *begin;
    struct __DM_ListNode *end;
};
//an empty object, which is used as namespace contained functions (exmpl: __dm_list.make())
static struct {struct __DM_List (*make)(void);} __dm_list = {.make = __DM_List_make};

#endif