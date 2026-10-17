# declare the variables and their bounds, 
# set notation could be used, but this is straightforward
var x0 >= -1000, <= 1000; 
var x1 >= -1000, <= 1000; 


# specify the objective function
minimize cost:
                4*x0 + 3*x1;
        
# specify the constraints

 subject to inequality1:
           1 <= x0 <= 1;
                
 subject to ineqequality2:
           1 <= x1 <=  1;
                

                

                
  

 