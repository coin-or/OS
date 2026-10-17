* Eastborne Realty from Anderson, Sweeney, Williams, Camm and Martin MS 13e
* optimal solution is x0 = 4, x1 = 2


Variable z;
Integer Variables x0, x1;

Equations
   obj
   con1
   con2
   con3;

obj.. z =e= 10*x0 + 15*x1;

con1..  282*x0 + 400*x1 =l=   2000;
con2..  4*x0 + 40*x1 =l=   140;
con3..  x0  =l=   5;


Option MIP = CoinOS ;

Model eastborne_ip / all /;
Solve  eastborne_ip  maximizing z using mip;

Display z.l;
Display x0.l;
Display x1.l;