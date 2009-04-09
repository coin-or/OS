$Title Rosenbrock Test Function (RBROCK,SEQ=83)

$Ontext

   A Classical Unconstrained Test Problem


Rosenbrock, H H, An Automatic Method for finding the Greatest or least value of a function. Computer Journal 3 (1960), 175-184. Modified to be consistent with OSiL paper.

$Offtext


Variables f

Integer Variables x1, x2;


Equations

   func;

func.. f =e= 100*sqr(x2 - sqr(x1)) + sqr(1 - x1) +9*x2;



x1.lo = 0;
x2.lo = 0; 

OPTION  MINLP = OS;

Model rosenbr / all /;
Solve rosenbr minimizing f using minlp;

