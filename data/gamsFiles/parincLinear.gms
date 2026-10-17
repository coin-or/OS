* turn off listing of symbols
$OFFSYMXREF
$OFFSYMLIST
* turn off listing of input files
VARIABLES
        z "maximize the profit" ;

POSITIVE VARIABLES
        x1,  x2;

EQUATIONS
        profit, con1, con2, con3, con4;

profit ..  z  =e=  -10*x1 - 9*x2 ;
con1 ..   .7*x1 + x2  =l=  630 ;
con2 ..   .5*x1 + (5/6)*x2  =l=  600 ;
con3 ..   1.*x1 + (2/3)*x2  =l=  708 ;
con4 ..   .1*x1 + .25*x2  =l=  135 ;

MODEL parinc /all/;

* specify the obj and constraints explicitly
* model parinc /profit, con1
* con2, con3, con4/


* set some options
* turn off row and column listing
OPTION LIMROW = 0 ;
OPTION LIMCOL = 0 ;
* list all solver available
*OPTION SUBSYSTEMS;
* control output
OPTION SYSOUT = off;
OPTION SOLPRINT = off

OPTION LP = OS;

SOLVE parinc USING LP MINIMIZING  z ;

* display the primal values
DISPLAY x1.l, x2.l;

* display the dual values
DISPLAY con1.m, con2.m, con3.m, con4.m ;



