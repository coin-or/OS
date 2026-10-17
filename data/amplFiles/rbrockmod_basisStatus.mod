
var x {0..1} := 1.73205;
let x[0].sstatus := "bas";
let x[1].sstatus := "low";

minimize Rosenbrock: (1-x[0])^2 + 100*(x[1]-x[0]^2)^2 + 9*x[1];

subj to con1 := 3.1415 : x[0] + 10.5*x[0]^2 + 11.7*x[1]^2 + 3*x[0]*x[1] <= 25;
subj to con2 := 2.7183 : log(x[0]*x[1]) + 7.5*x[0] + 5.25*x[1] >= 10;

let con1.sstatus := "sup";
let con2.sstatus := "low";

