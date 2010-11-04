Variable z;
Integer Variables x0, x1;

Equations
   con1
   func;

func.. z =e= -x0 - x1;

con1..  -x0 + x1 =l=   5;


OPTION  MIP = CoinCbc;
OPTION  RMIP = CoinCbc;

Model infeasible_ip / all /;
Solve  infeasible_ip  minimizing z using mip;

Display z.l;
Display x0.l;
Display x1.l;
