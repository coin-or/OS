NAME    IP_unbounded
*
*  This is an unbounded IP
*
ROWS
 N  OBJ
 L  CON
COLUMNS
    INT       'MARKER'                 'INTORG'
    X0        OBJ         -1.
    X0        CON         -1.
    X1        OBJ         -1.
    X1        CON          1.
    INT       'MARKER'                 'INTEND'
RHS
    RHS       CON          5.
BOUNDS
 LO B1        X0           0.
 LO B1        X1           0.
ENDATA
