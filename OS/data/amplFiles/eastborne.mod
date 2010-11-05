# Eastborne Realty from Anderson, Sweeney, Williams, Camm and Martin MS 13e
# optimal solution is x0 = 4, x1 = 2


var x0 integer >= 0;
var x1 integer >= 0;


maximize profit:
   10*x0 + 15*x1;

subject to con1:
   282*x0 + 400*x1 <=  2000;
subject to con2:
   4*x0 + 40*x1  <=    140;
subject to con3:
   x0 <= 5;


