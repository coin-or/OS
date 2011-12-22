# ---------------------------------------------
#
# Name: IP_noconstraint
#
# Description: A two-variable toy problem with simple box constraints 
#
# Author: Horand Gassmann, Jun Ma and Kipp Martin
#
# Copyright 2011 Horand Gassmann, Jun Ma, Kipp Martin,
#    Dalhousie University, and the University of Chicago
# 
# ---------------------------------------------

var x >= 2.5, <= 8.5, integer;
var y >= 3.5, <= 9.5, integer;

minimize obj: 10*x + 9*y;

