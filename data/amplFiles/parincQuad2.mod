set PROD := 0..1;  # products
set DEP;   # resources
 
param hours {DEP} >= 0;   # hours available in each department
param a {DEP,PROD} >= 0;   # hours consumed by product type j  in department i
param c {PROD} >= 0;   # marginal production cost
var x {PROD} >= 0, <= 1000;    # units of each product produced

maximize profit:
   sum {j in PROD} c[j] * x[j] - 0.06666666*x[0]*x[0] - 0.08*x[0]*x[1] - 0.2*x[1]*x[1];

subject to hours_available {i in DEP}:
   sum {j in PROD} a[i,j]*x[j] <= hours[i];

data;

set DEP := cutanddye sewing finishing inspectandpack;

param:  c :=
0 80
1 150;

param: hours :=
cutanddye 630
sewing 600
finishing 708
inspectandpack 135;

param a:
                  0    1 :=
cutanddye         .7    1.0
sewing            .5    .8333
finishing         1.0   .6667
inspectandpack    0.1   .25  ;
