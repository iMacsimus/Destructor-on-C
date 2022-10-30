#ifndef __destruct_manager_H
#define __destruct_manager_H

#include "list.h"
#include <stdlib.h>

//declare functions
struct DestructManager;
struct DestructManager __DestractManager_make(void);
void* __DestructManager_add(struct DestructManager *ths, void *rsc);
void __DestructManager_destruct_current(struct DestructManager *ths, void *rsc);
void __DestructManager_destruct_all(struct DestructManager *ths);
//declare struct
struct DestructManager {
    void* (*add)(struct DestructManager *ths, void *rsc);
    void (*destruct_current)(struct DestructManager *ths, void *rsc);
    void (*destruct_all)(struct DestructManager *ths);
    struct __DM_List resources;
};
//an empty object, which is used as namespace contained functions (exmpl: DestructManager.make())
static struct {struct DestructManager (*make)(void);} DestructManager = {.make = __DestractManager_make};

#ifdef DESTRUCT_MANAGER_ACTIVATE_DEFINES

#define DM_GET_CUR() (__DM_CUR)
#define SC_IDM { struct DestructManager __DM_CUR = DestructManager.make(); // Init DestructManager at the begin of current scope
#define CDM_SC __DM_CUR.destruct_all(&__DM_CUR); }// Call Destruct Manager at the end of current scope
#define CDM_RETURN(x) __DM_CUR.destruct_all(&__DM_CUR); return x; // Call Destruct Manager before return;
#define DM_ADD(x) (__DM_CUR.add(&__DM_CUR, Wrapper.make_pointer(x, free)))

#endif
// declare wrapper functions
struct Wrapper;
struct Wrapper *__Wrapper_make_p(void *data, void (*destruct)(void *ths));
void __Wrapper_destruct(void *ths);
//declare wrapper struct
struct Wrapper {
    void (*destruct)(void *ths); // free
    void (*destruct_data)(void *ths);
    void *data;
};
static struct {struct Wrapper *(*make_pointer)(void *data, void (*destruct)(void *ths));} Wrapper = {.make_pointer = __Wrapper_make_p};

#endif