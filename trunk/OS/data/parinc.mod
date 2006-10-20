set PROD;   # products
set DEP;   # resources
 
param hours {DEP} >= 0;   # hours available in each department
param a {DEP,PROD} >= 0;   # hours consumed by product type j  in department i
param c {PROD} >= 0;   # marginal production cost
var x {PROD} >= 0;    # units of each product produced

maximize profit:
   sum {j in PROD} c[j]*x[j];

subject to hours_available {i in DEP}:
   sum {j in PROD}  a[i,j]*x[j] <= hours[i];

