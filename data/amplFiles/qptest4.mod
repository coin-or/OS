# not a QP, but fill-in in the A-matrix
var x {0..1};


minimize qp: (1-x[0])^2 + 100*(x[1]-x[0]^2) + 9*x[1];

subj to con4: (1-x[0])^2 + (2-x[1])^2 <= 100; 
subj to con1: x[0] + 10.5*x[0]^2 + 11.7*x[1]^2 + 3*x[0]*x[1] <= 25;
subj to con2: log(x[0]*x[1]) + 7.5*x[0] + 5.25*x[1] >= 10;
subj to con3: 1.3*x[0] + 2.6*x[1] <= 8;   # purely linear 

