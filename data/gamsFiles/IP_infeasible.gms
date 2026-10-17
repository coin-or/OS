Variable z;
Integer Variables x0, x1;

Equations
   con1
   con2
   func;

func.. z =e= x0 + x1;

con1..  -2.5*x0 + x1 =l=   -.25;
con2..  2.5*x0 + x1 =l=  2.25;

OPTION  MIP = CoinCbc;
OPTION  RMIP = CoinCbc;

Model infeasible_ip / all /;
Solve  infeasible_ip  maximizing z using mip;

Display z.l;
Display x0.l;
Display x1.l;

