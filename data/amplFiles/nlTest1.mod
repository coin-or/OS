#########################################################################################
# this model tests several aspects of the translation from nl format to OSiL/OSoL:
# 1. multiple objectives
# 2. recognition of QPs, including modifications of the A-matrix
# 3. primal and dual initial values, with some numbers missing, others equal to zero
# 4. user-defined suffixes with various characteristics:
#    a. integer, binary, string and real
#    b. IN, OUT, INOUT, LOCAL and default
#
#
#  Copyright (C) 2012, Horand Gassmann, Jun Ma, Kipp Martin,
#  Northwestern University, and the University of Chicago.
#  All Rights Reserved.
#  This software is licensed under the Eclipse Public License.
#  Please see the accompanying LICENSE file in root directory for terms.
#########################################################################################

param scale = 100.0;
param lbl = 0.0;
param ubl = 10.0;

var x{0..3}; let x[0] := 1.73; let x[1] := 1.73; let x[3] := 0.0;

minimize obj1:     (1-x[0]**2)**2 
     + scale*   (x[0]-x[1]**2)**2 
     + scale**2*(x[1]-x[2]**2)**2 
     + scale**3*(x[2]-x[3]**2)**2; 

minimize obj2:     (2-x[0]**2)**2 
     + scale*   (x[0]-x[1]**2)**2 
     + scale**2*(x[1]-x[2]**2)**2 
     + scale**3*(x[2]-x[3]**2)**2; 
 
subject to boxL{i in 0..3}: lbl <= x[i] ;
subject to boxU{i in 0..3}: ubl >= x[i] ;
subject to con {i in 0..1} := 125 : x[i] + 3*x[i+2] = 5; 
subject to qpTest {i in 0..3} : (i - x[i])**2 + 4*(i-1)*x[i] <= 100;

problem Rosenbrock: x, obj1, boxL, boxU;
problem rbrock2:    x, obj1, obj2, con, qpTest;

suffix allvarnumeric;           let {i in 0..3} x[i].allvarnumeric := 3.14;

suffix allvarinteger, integer;  let {i in 0..3} x[i].allvarinteger := 7;
suffix allvarbinary,  binary;   let {i in 0..3} x[i].allvarbinary  := i mod 2;
suffix allvarstring,  symbolic; 
option allvarstring_table '\
   0    real \
   1    test ';                 let {i in 0..3} x[i].allvarstring  := "test";

suffix somevarnumeric;          let {i in 0..1} x[i].somevarnumeric := 2.71;
suffix somevarinteger, integer; let {i in 0..1} x[i].somevarinteger := 17;
suffix somevarbinary,  binary;  let {i in 0..1} x[i].somevarbinary  := (i+1) mod 2;
suffix somevarstring,  symbolic;
option somevarstring_table '\
   0    real \
   1    test \
   2     ?   ';                 let {i in 0..1} x[i].somevarstring_num  := 2;

suffix someconnumeric;          let {i in 0..3} boxL[i].someconnumeric := 1.4142;
suffix someconinteger, integer; let {i in 0..3} boxL[i].someconinteger := 13;
suffix someconbinary,  binary;  let {i in 0..3} boxL[i].someconbinary  := i mod 2;
suffix someconstring,  symbolic;
option someconstring_table '\
   0    real \
   1    test ';                 let {i in 0..3} boxL[i].someconstring  := "test";

suffix someobjnumeric;          let obj1.someobjnumeric := 2.306;
suffix someobjinteger, integer; let obj1.someobjinteger := 11;
suffix someobjbinary,  binary;  let obj1.someobjbinary  := 1;
suffix someobjstring,  symbolic;
option someobjstring_table '\
   0    real \
   1    test ';                 let obj1.someobjstring  := "test";

suffix someprobnumeric;         let rbrock2.someprobnumeric := -1.5;
suffix someprobinteger, integer;let rbrock2.someprobinteger := 19;
suffix someprobbinary,  binary; let rbrock2.someprobbinary  := 1;
suffix someprobstring,  symbolic;
option someprobstring_table '\
   0    real \
   1    test ';                       let rbrock2.someprobstring  := "test";

suffix morevarnumeric, IN;            let {i in 0..3} x[i].morevarnumeric := 2.718**i;
suffix morevarinteger, integer, OUT;  let {i in 0..3} x[i].morevarinteger := 3*i;
suffix morevarbinary,  binary, LOCAL; let {i in 0..3} x[i].morevarbinary  := 1;
suffix morevarstring,  symbolic;
option morevarstring_table '\
   0    real \
   1    test ';                       let {i in 0..3} x[i].morevarstring_num  := 1;

suffix moreconnumeric, LOCAL;         let {i in 0..3} boxU[i].moreconnumeric  := .301;
suffix moreconinteger, integer, OUT;  let {i in 0..3} boxU[i].moreconinteger  := 23;
suffix moreconbinary,  binary, INOUT; let {i in 0..3} boxU[i].moreconbinary   := 1;
suffix moreconstring,  symbolic;      
option moreconstring_table '\
   0    real \
   1    test ';                       let {i in 0..3} boxU[i].moreconstring_num := 1;

suffix moreobjnumeric, INOUT;         let obj1.moreobjnumeric := 0.001;
suffix moreobjinteger, integer, OUT;  let obj2.moreobjnumeric := 8;
suffix moreobjbinary,  binary, IN;    let obj1.moreobjnumeric := 1;
suffix moreobjstring,  symbolic, LOCAL;
option moreobjstring_table '\
   0    real \
   1    test ';                          let obj2.moreobjstring_num := 1;

suffix moreprobnumeric, OUT;             let rbrock2.moreprobnumeric := 0.12345;
suffix moreprobinteger, integer, LOCAL;  let rbrock2.moreprobinteger := 14;
suffix moreprobbinary,  binary, IN;      let rbrock2.moreprobbinary  := 1;
suffix moreprobstring,  symbolic;
option moreprobstring_table '\
   0    real \
   1    test ';                          let rbrock2.moreprobstring  := "test";


