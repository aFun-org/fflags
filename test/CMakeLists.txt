﻿FUNCTION(add_fflags_test name src)
    add_executable(_fflags_${name} ${src})
    target_link_libraries(_fflags_${name} FFlags)
    add_test(NAME fflags_${name} COMMAND $<TARGET_FILE:_fflags_${name}> ${ARGN})
ENDFUNCTION()

add_fflags_test(test1 test1.c -m 10 -w 20 -e 30 -r 40)
add_fflags_test(test2 test2.c -c \"/dev/ttyS1\")