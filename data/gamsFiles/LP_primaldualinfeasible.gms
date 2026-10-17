Variable z;
Variables x0, x1;

Equations
   con1
   con2
   con3
   con4
   func;

func.. z =e= - x0 - x1;

con1..  x0 - x1 =g=   -5;
con2..  x0  =g=  0;
con3..  x1  =g=  0;
con4..  x1  =l=  -1;


OPTION  MIP = CoinCbc;
OPTION  RMIP = CoinCbc;
OPTION  LP = CoinCbc;

Model unbounded_lp / all /;
Solve unbounded_lp  minimizing z using lp;

Display z.l;
Display x0.l;
Display x1.l;

