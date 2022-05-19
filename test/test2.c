#include "../fflags.h"
#include <stdio.h>

ff_defArg(main, true)
                ff_argRule('c', c, must, 1)
ff_endArg(main, true);
ff_childList(sys, ff_child(main));

int main(int argc, char **argv) {
    ff_FFlags *ff = ff_initFFlags(argc, argv, true, true, stderr, sys);
    if (ff == NULL)
        return 1;

    char *text = NULL;
    int mark = 0;

    while (1) {
        mark = ff_getopt(&text, ff);
        switch (mark) {
            case 1:
                printf("mark = 1, %s\n", text);
                break;
            case 0:
                printf("error\n");
                goto out;
            default:
                goto out;
        }
    }

    out:
    ff_freeFFlags(ff);
    return 0;
}