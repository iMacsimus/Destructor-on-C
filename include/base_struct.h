#ifndef __destruct_manager_base_struct_H
#define __destruct_manager_base_struct_H

struct __DM_BaseStruct {
    void (*destruct)(void *ths);
};

#endif