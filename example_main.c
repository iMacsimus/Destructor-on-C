#define DESTRUCT_MANAGER_ACTIVATE_DEFINES
#include "include/destruct_manager.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    //prologue
    struct DestructManager dm = DestructManager.make();
    // function body
    char *s1 = calloc(1, 1);
    dm.add(&dm, Wrapper.make_pointer(s1, free));

    if (1) SC_IDM
        char *s2 =  DM_ADD(calloc(10000, 1));
        SC_IDM
            char *s3 = DM_ADD(calloc(100000, 1));
        CDM_SC
    CDM_SC
    

    //epilogue
    dm.destruct_all(&dm);
    return 0;
}