$Title Rosenbrock Test Function (RBROCK,SEQ=83)

$Ontext

   A Classical Unconstrained Test Problem


Rosenbrock, H H, An Automatic Method for finding the Greatest or least value of a function. Computer Journal 3 (1960), 175-184. Modified to be consistent with OSiL paper.

$Offtext


Variables f, x1, x2;
Equations
   con1
   con2
   func;

func.. f =e= 100*sqr(x2 - sqr(x1)) + sqr(1 - x1) +9*x2;

con1.. x1 + 10.5*sqr(x1) + 11.7*sqr(x2) + 3*x1*x2 =l= 25;
con2..  log(x1*x2) + 7.5*x1 + 5.25*x2 =g= 10;

x1.lo = .01;
x2.lo = .01; 

Model rosenbr / all /;
Solve rosenbr minimizing f using nlp;

