```bash
$ make btest
gcc -O -Wall -m32 -lm -o btest bits.c btest.c decl.c tests.c
In file included from btest.c:16:0:
/usr/include/stdio.h:27:10: fatal error: bits/libc-header-start.h: No such file or directory
 #include <bits/libc-header-start.h>
          ^~~~~~~~~~~~~~~~~~~~~~~~~~
compilation terminated.
In file included from decl.c:1:0:
/usr/include/stdio.h:27:10: fatal error: bits/libc-header-start.h: No such file or directory
 #include <bits/libc-header-start.h>
          ^~~~~~~~~~~~~~~~~~~~~~~~~~
compilation terminated.
In file included from /usr/lib/gcc/x86_64-linux-gnu/7/include-fixed/limits.h:194:0,
                 from /usr/lib/gcc/x86_64-linux-gnu/7/include-fixed/syslimits.h:7,
                 from /usr/lib/gcc/x86_64-linux-gnu/7/include-fixed/limits.h:34,
                 from tests.c:3:
/usr/include/limits.h:26:10: fatal error: bits/libc-header-start.h: No such file or directory
 #include <bits/libc-header-start.h>
          ^~~~~~~~~~~~~~~~~~~~~~~~~~
compilation terminated.
Makefile:11: recipe for target 'btest' failed
make: *** [btest] Error 1
$ sudo apt-get update
$ sudo apt-get install gcc-multilib
```
```bash
sudo service binfmt-support start
```