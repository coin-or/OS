set prcn := 1..10;

param TMachine integer >=0;
param lambda {prcn} >=0;
param mu >=0;

var x {prcn} integer >=0;
var u >= 0;

minimize objective:
	u;

subject to total_machine:
	sum {i in prcn}x[i] = TMachine;

subject to waiting_difference {i in prcn, j in prcn: i<>j}:
	(lambda[i]/(mu*x[i]))^((2*x[i]+2)^0.5-1)/(mu*x[i]-lambda[i])-(lambda[j]/(mu*x[j]))^((2*x[j]+2)^0.5-1)/(mu*x[j]-lambda[j]) <= u;

