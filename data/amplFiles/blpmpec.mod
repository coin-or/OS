
param ns ; # := 20 ;   # number of simulated "individuals" per market
param nmkt ; # := 94 ; # number of markets
param nbrn ; # := 24 ; # number of brands per market 
param nbrnPLUS1 := nbrn+1; # number of products plus outside good 
param nk1 ; # := 25;   # of observable characteristics
param nk2 ; # := 4 ;   # of observable characteristics
param niv ; # := 21 ;  # of instrument variables
param nz := niv-1 + nk1 -1 ; # of instruments including iv and X1
param nd ; # := 4 ; # of demographic characteristics

set S := 1..ns ;    # index set of individuals 
set M := 1..nmkt ;  # index set of market
set J := 1..nbrn ;  # index set of brand (products), including outside good
set MJ := 1..nmkt*nbrn; # index of market and brand
set K1 := 1..nk1 ;    # index set of product observable characteristics
set K2 := 1..nk2 ;    # index set of product observable characteristics
set Demogr := 1..nd;
set DS := 1..nd*ns;
set K2S := 1..nk2*ns;

set H := 1..nz ;   # index set of instrument including iv and X1

## Define input data: 
param X1 {mj in MJ, k in K1} ;
param X2 {mj in MJ, k in K2} ;
param ActuShare {m in MJ} ;
param Z {mj in MJ, h in H} ;
param D {m in M, di in DS} ;
param v {m in M, k2i in K2S} ;
param invA {i in H, j in H} ;   # optimal weighting matrix = inv(Z'Z); 
param OutShare {m in M} := 1 - sum {mj in (nbrn*(m-1)+1)..(nbrn*m)} ActuShare[mj];

###  Define initial guesses:

param iniSIGMA {k in K2};
param solSIGMA {k in K2};
param sol2SIGMA {k in K2};

param iniPI {k in K2, d in Demogr};
param solPI {k in K2, d in Demogr};
param sol2PI {k in K2, d in Demogr};

param iniTheta1 {k in K1};
param solTheta1 {k in K1}; 
param sol2Theta1 {k in K1}; 

param iniDelta {mj in MJ};
param solDelta {mj in MJ};
param sol2Delta {mj in MJ};

#### Define variables

var theta1 {k in K1}; 
var SIGMA {k in K2};
var PI {k in K2, d in Demogr};
var delta {mj in MJ} ; ## <= 0, >= -10; 

var EstShareIndivTop {mj in MJ, i in S} = exp( delta[mj] + sum {k in K2} (X2[mj,k]*SIGMA[k]*v[ceil(mj/nbrn), i+(k-1)*ns]) + sum{k in K2, d in Demogr} (X2[mj,k]*PI[k,d]*D[ceil(mj/nbrn),i+(d-1)*ns]) );

var EstShareIndiv{mj in MJ, i in S} = EstShareIndivTop[mj,i]/ (1+ sum{l in ((ceil(mj/nbrn)-1)*nbrn+1)..(ceil(mj/nbrn)*nbrn)} EstShareIndivTop[l, i]);

var EstShare {mj in MJ} = 1/ns * (sum{i in S} EstShareIndiv[mj,i]) ;

var w {mj in MJ} = delta[mj] - sum {k in K1} (X1[mj,k]*theta1[k]) ;

var Zw {h in H} ; ### = sum {mj in MJ} Z[mj,h]*w[mj];

minimize GMM : sum{h1 in H, h2 in H} Zw[h1]*invA[h1, h2]*Zw[h2];

subject to
     
     conZw {h in H}: Zw[h] = sum {mj in MJ} Z[mj,h]*w[mj] ;

     Shares {mj in MJ}: log(EstShare[mj]) = log(ActuShare[mj]) ;
