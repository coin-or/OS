set sites;
param long{sites} ;
param lat{sites} ;
param demand{sites} ;

var CG_long ;
var CG_lat  ;

minimize demand_weighted_distance :
	sum{i in sites} demand[i]*sqrt( (CG_long-long[i])^2  + (CG_lat - lat[i])^2  ) ;
