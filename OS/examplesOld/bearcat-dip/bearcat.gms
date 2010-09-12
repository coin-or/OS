* turn off listing of symbols
$OFFSYMXREF
$OFFSYMLIST
* set some print-related options
* turn off row and column listing
OPTION LIMROW  = 20 ;
OPTION LIMCOL = 0 ;
* list all solver available
*OPTION SUBSYSTEMS;
* control output
OPTION SYSOUT = off;
OPTION SOLPRINT = off ;

$eolcom //



SETS
	nodes,      
	routes(nodes),
	hubs(nodes),
	NO_hubs(nodes),
	paths / 1*10000/,
	rdemandIndex "index set of route demands -- min of total demand and capacity" ,
	tdemandIndex "index set of total demands" ;
	
ALIAS(nodes, i);
ALIAS(nodes, j);
ALIAS(nodes, h);
ALIAS(nodes, s);
ALIAS(routes, k);
ALIAS(rdemandIndex, l);
ALIAS(rdemandIndex, l1);
ALIAS(rdemandIndex, l2);
ALIAS(rdemandIndex, lprime);
ALIAS(paths, p);
ALIAS(tdemandIndex, d1);
ALIAS(tdemandIndex, d2);
ALIAS(tdemandIndex, d);
   
SETS TRANSITIONS(k, i, j, l1, l2);

PARAMETERS cost(i, j), demand(s), rdemand( l), tdemand( d);




PARAMETERS cost(i, j), demand(s), rdemand( l),
	pathCoeff(p, i, j, k),  pathCost( p, k), 
	pathConvexityCoef(p,k), n(p, k, i), f(p,k,l);


$include  percentile6-30.dat

NO_hubs( nodes) =  NOT hubs( nodes);





******************* END GENERATE THE OPTIONS FILE ******************************************

VARIABLES
 	zDistanceDemand  "the distance traveled weighted by demand" ;

NONNEGATIVE VARIABLES  
	 	y(s, i, j,  k),  w(i,j,l,k), beta(k, d1, l2);
		

BINARY VARIABLES  x(i, j, k),   z(s,k);


EQUATIONS

	distanceDemandWeighted,
	
	nodeAssign(s),
	nodeAssignRoute(k),
	assignOUT(i, k),
	assignIN(i, k),

	linking(s, i, j, k),   //link multicommodity variables with xijk
	commodityDemand(s, k), // 
	conservation(s, i, k), //multicommodity conservation of flow	

	fixedCharge(k, i, j, l),

	
	betaConservation(k, d1),
	betaInit(k, d1),
	betaFinal(k, d1),

	routeDemand( k),
	xsum(i, j, k);
	


distanceDemandWeighted .. zDistanceDemand  =e=  
	sum( (i, j, l, k)$( ord(l) > 1 AND ord(i) <> ord(j) ), cost(i, j)*rdemand( l)*w(i, j, l, k) )  ;
	

	

******* Start Assignmnet Constraints *********
   

nodeAssign(s)  ..  sum(k ,  z(s, k)  ) =e= 1; 

nodeAssignRoute(k) ..  z(k,k) =e= 1;

assignOUT(i, k) ..  sum( ( j)$(ord(i) <> ord(j) ), x(i, j, k) ) =e= z(i, k);  

assignIN(i, k) .. sum( ( j)$(ord(i) <> ord(j) ), x(j, i, k) ) =e= z(i, k); 

******* End Assignmnet Constraints *********


******* Start Multi-commodity Constraints *********

linking(s, i, j, k)$( NO_hubs(s) AND ord(i) <> ord(j) AND NO_hubs(j)  ) .. y(s, i, j, k) =l= x(i, j, k);

commodityDemand(s, k)$(NO_hubs( s) ) ..  sum( i$(ord(i) <> ord(s) ),  y(s, i, s, k) ) =e=  z(s, k) ;

conservation(s, i, k)$(NO_hubs(s) AND NO_hubs(i) AND ord(s) <> ord(i) ) ..   
	sum( j$(ord(j) <> ord(i) AND ord(j) <> ord(s) ),  y(s, j, i, k) )  =e=   
	sum( j$(ord(j) <> ord(i) AND NO_hubs( j)),  y(s, i, j, k) )  ;
	
******* End Multi-Commodity Constraints *********



******* Dynamic Programming Constraints For Beta *********

betaInit(k, d1)$(ord(k) = 1 AND ord(d1) = 1) .. sum( l , beta(k, d1, l) ) =e= 1;


betaConservation(k, d1)$(ord(k) > 1 and ord(k) < card(routes) ) ..  
	sum( (d2,  l2)$( tdemand(d2)  +  rdemand(l2)  = tdemand(d1) ), beta(k - 1, d2, l2)  )  =e= 
	sum(l2$( tdemand(d1) + rdemand(l2) <= sum(s, demand(s) ) ), beta(k, d1, l2) );
	
	
	
betaFinal(k, d1)$(ord(k) = card(routes) AND card(routes) > 1) ..  
	sum((d2, l2)$(tdemand(d2)   +  rdemand(l2)  = tdemand(d1)   ), beta(k - 1, d2, l2)  )  =e= 
	sum(l2$(  tdemand(d1)  + rdemand(l2) = sum(s, demand(s) )  ), beta(k, d1, l2) );


******* End Dynamic Programming Constraints For Beta *********



******* Start Linking Constraints *********


routeDemand( k) .. sum( (d, l)$( tdemand(d) + rdemand(l) <= sum(s, demand(s) ) ), 
	rdemand(l)*beta(k, d, l)  )   =e= sum(s, demand(s)*z(s, k) );
	
	
xsum(i, j, k)$(ord(i) <> ord(j))  ..   sum(l$(ord(l) > 1), w(i,j,l,k) ) =e= x(i,j,k);


******* End Linking Constraints *********


MODEL bearcat /  distanceDemandWeighted, 
	nodeAssign, nodeAssignRoute, assignOUT, assignIN,
 	linking, commodityDemand, conservation, 
 	betaInit, betaConservation, betaFinal,
 	routeDemand, xsum  /;
 	
 	
 SOLVE bearcat USING RMIP MINIMIZING  zDistanceDemand ;	

