Variable z;
Nonnegative Variables x0, x1;

Equations
   con1
   func;

func.. z =e= x0 + x1;

con1..  -x0 + x1 =l=   5;


OPTION  MIP = CoinCbc;
OPTION  RMIP = CoinCbc;
OPTION  LP = CoinIpopt;

Model unbounded_lp / all /;
Solve unbounded_lp  maximizing z using lp;

Display z.l;
Display x0.l;
Display x1.l;

