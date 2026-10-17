set ORIG;   # origins
set DEST;   # destinations

param supply {ORIG} >= 0;   # amounts available at origins
param demand {DEST} >= 0;   # amounts required at destinations

   check: sum {i in ORIG} supply[i] >= sum {j in DEST} demand[j];

param vcost {ORIG,DEST} >= 0;  # variable shipment costs per unit
param limit {ORIG,DEST} > 0;   # limit on units shipped
var Trans {ORIG,DEST} >= 0;    # units to ship

param fcost {ORIG} >= 0;       # fixed costs for use of origins
var Use {ORIG} binary;         # = 1 iff origin is used

minimize Total_Cost:
   sum {i in ORIG, j in DEST} 
      vcost[i,j] * Trans[i,j] / (1 - Trans[i,j]/limit[i,j]) +
   sum {i in ORIG} fcost[i] * Use[i];

subject to Supply {i in ORIG}:  
   sum {j in DEST} Trans[i,j] <= supply[i] * Use[i];

subject to Demand {j in DEST}:  
   sum {i in ORIG} Trans[i,j] = demand[j];
