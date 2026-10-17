#########################################################################################
# this model tests several aspects of the translation from nl format to OSiL/OSoL:
# 1. multiple objectives
# 2. recognition of QPs, including modifications of the A-matrix
# 3. primal and dual initial values, with some numbers missing, others equal to zero
# 4. built-in suffixes: .sstatus
# 5. user-defined suffixes with various characteristics:
#    a. integer, binary, string and real (i.e., numeric, which is the default)
#    b. IN, OUT, INOUT, LOCAL and default (which is INOUT)
#
#
#  Copyright (C) 2012, Horand Gassmann, Jun Ma, Kipp Martin,
#  Northwestern University, and the University of Chicago.
#  All Rights Reserved.
#  This software is licensed under the Eclipse Public License.
#  Please see the accompanying LICENSE file in root directory for terms.
#########################################################################################

param scale = 100.0;
param lbl = 1.0;
param ubl = 10.0;

var x{0..3}; let x[0] := 7.73; let x[1] := 7.73; let x[3] := 0.0;

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
subject to con {i in 0..1} := 125 : x[i] + 3*x[i+2] = 25; 
subject to qpTest {i in 0..3} : (i - x[i])**2 + 4*(i-1)*x[i] <= 100;

problem Rosenbrock: x, obj1, boxL, boxU;
problem rbrock2:    x, obj1, obj2, con, qpTest, boxL, boxU;

suffix allvarnumeric;           let {i in 0..3} x[i].allvarnumeric := 3.14;
suffix allvarinteger, integer;  let {i in 0..3} x[i].allvarinteger := 7;
suffix allvarbinary,  binary;   let {i in 0..3} x[i].allvarbinary  := i mod 2;
suffix allvarstring,  symbolic; 
option allvarstring_table '\
   0    real \
   1    test ';                 let {i in 0..3} x[i].allvarstring  := "test";

suffix zerovarnumeric;           let {i in 0..3} x[i].zerovarnumeric := 0.0;
suffix zerovarinteger, integer;  let {i in 0..3} x[i].zerovarinteger := 0;
suffix zerovarbinary,  binary;   let {i in 0..3} x[i].zerovarbinary  := 0;
suffix zerovarstring,  symbolic; 
option zerovarstring_table '\
   0    real \
   1    test ';                 let {i in 0..3} x[i].zerovarstring  := "real";

suffix somevarnumeric;          let {i in 0..1} x[i].somevarnumeric := 2.71;
suffix somevarinteger, integer; let {i in 0..1} x[i].somevarinteger := 17;
suffix somevarbinary,  binary;  let {i in 0..1} x[i].somevarbinary  := (i+1) mod 2;
suffix somevarstring,  symbolic;
option somevarstring_table '\
   0    real \
   1    test \
   2     ?   ';                 let {i in 0..1} x[i].somevarstring_num  := 2;

suffix someconnumeric;          let con[0].someconnumeric := 1.4142;
suffix someconinteger, integer; let con[0].someconinteger := 13;
suffix someconbinary,  binary;  let con[0].someconbinary  := 1;
suffix someconstring,  symbolic;
option someconstring_table '\
   0    real \
   1    test ';                 let con[0].someconstring  := "test";

suffix someobjnumeric;          let obj1.someobjnumeric := 2.306;
suffix someobjinteger, integer; let obj1.someobjinteger := 11;
suffix someobjbinary,  binary;  let obj1.someobjbinary  := 1;
suffix someobjstring,  symbolic;
option someobjstring_table '\
   0    real \
   1    test ';                 let obj1.someobjstring  := "test";

suffix someprobnumeric;         let Rosenbrock.someprobnumeric := -1.5;
suffix someprobinteger, integer;let Rosenbrock.someprobinteger := 19;
suffix someprobbinary,  binary; let Rosenbrock.someprobbinary  := 1;
suffix someprobstring,  symbolic;
option someprobstring_table '\
   0    real \
   1    test ';                       let Rosenbrock.someprobstring  := "test";

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
suffix moreobjinteger, integer, OUT;  let obj2.moreobjinteger := 8;
suffix moreobjbinary,  binary, IN;    let obj1.moreobjbinary  := 1;
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
   1    test \
   2    more ';                          let rbrock2.moreprobstring  := "more";

# suffixes are available simultaneously for all problem components; let's test this...

suffix globalnumeric;                    let {i in 0..3}    x[i].globalnumeric := 2.71828*i;
                                         let {i in 0..3} boxU[i].globalnumeric := 3.14154*i;
                                         let                obj1.globalnumeric := 1.73205;
                                         let                obj2.globalnumeric := 3.46411;
                                         let          Rosenbrock.globalnumeric := 0.1101001;

suffix globalinteger, integer;           let {i in 0..3}    x[i].globalinteger := 3*i;
                                         let {i in 0..3} boxU[i].globalinteger := 4*i;
                                         let                obj1.globalinteger := 5;
                                         let                obj2.globalinteger := 6;
                                         let          Rosenbrock.globalinteger := 7;

suffix globalbinary, binary;             let {i in 0..1}    x[i].globalbinary := 1;
                                         let {i in 0..1} boxU[i].globalbinary := 1;
                                         let                obj1.globalbinary := 1;
                                         let          Rosenbrock.globalbinary := 1;

suffix globalsymbolic, symbolic;
option globalsymbolic_table '\
   0    zero \
   1    one  \
   2    two  \
   3    three';                          let {i in 0..3}    x[i].globalsymbolic_num := i;
                                         let {i in 0..1} boxU[i].globalsymbolic_num := i;
                                         let                obj1.globalsymbolic_num := 1;
                                         let          Rosenbrock.globalsymbolic_num := 2;

### basis information
let x[1].sstatus_num := 1;
let x[2].sstatus := "sup";
let qpTest[1].sstatus_num := 5;
let qpTest[2].sstatus := "btw";

# option sstatus_table '\
# 0	none	no status assigned\
# 1	bas	basic\
# 2	sup	superbasic\
# 3	low	nonbasic <= (normally =) lower bound\
# 4	upp	nonbasic >= (normally =) upper bound\
# 5	equ	nonbasic at equal lower and upper bounds\
# 6	btw	nonbasic between bounds\
# ';
