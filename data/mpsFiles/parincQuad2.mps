NAME  ParIncQuad 
*****************************************************
* Source:  Anderson, Sweeney, Williams, Camm, and Martin 13e
* Author:  Horand Gassmann, Jun Ma and Kipp Martin
* Remarks: This problem contains a quadratic objective in order
*          to test the extended MPS format supported by CoinUtils
*          This is a maximization problem, so all the objective
*          coefficients (including quadratics) have their signs flipped
* optimal solution: x0 = 459.72 and x1 = 308.20
* optimal objective function value 49920.55
*****************************************************
ROWS
 N  OBJ
 L  R0000000
 L  R0000001
 L  R0000002
 L  R0000003
COLUMNS
    x0        OBJ                -80
    x0        R0000000           0.7   R0000001           0.5
    x0        R0000002             1   R0000003           0.1
    x1        OBJ               -150
    x1        R0000000             1   R0000001        0.8333
    x1        R0000002        0.6667   R0000003          0.25
RHS
    RHS1      R0000000           630
    RHS1      R0000001           600
    RHS1      R0000002           708
    RHS1      R0000003           135
BOUNDS
 UP BND1      x0                1000      
 UP BND1      x1                1000      
QUADOBJ
    x0        x0          0.06666666
    x0        x1                0.08
    x1        x1                 0.2
ENDATA
