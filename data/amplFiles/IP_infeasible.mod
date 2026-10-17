# declare the variables and their bounds, 
# set notation could be used, but this is straightforward
var x0 integer  >= 0; 
var x1 integer >= 0; 


# specify the objective function
maximize profit:
                x0 + x1;
        
# specify the constraints

 subject to inequality1:
          -2.5*x0 + 1*x1 <= -.25;

 subject to inequality2:
	   2.5*x0 + 1*x1 <= 2.25;
                

                

                

                
  

 