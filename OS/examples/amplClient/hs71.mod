# declare the variables and their bounds, 
# set notation could be used, but this is straightforward
var x1 >= 1, <= 5; 
var x2 >= 1, <= 5; 
var x3 >= 1, <= 5; 
var x4 >= 1, <= 5;

# specify the objective function
minimize cost:
                x1 * x4 * (x1 + x2 + x3) + x3;
        
# specify the constraints

 subject to inequality1:
                x1 * x2 * x3 * x4 >= 25;
                
 subject to inequality2:
               40 <= x1^2 + x2^2 + x3^2 +x4^2 <= 40;
                

                

                
  

 