CC = cl
KNITROINCLUDE = ./include



KnitroSolver.dll: KnitroSolver.obj
    link   -NODEFAULTLIB:LIBC.lib KnitroSolver.obj ./lib/knitro.lib -DLL -out:KnitroSolver.dll
    del KnitroSolver.obj

KnitroSolver.obj: KnitroSolver.c
    $(CC) -c  -I$(KNITROINCLUDE) KnitroSolver.c



ALL: KnitroSolver.obj KnitroSolver.dll
