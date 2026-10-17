g3 2 1 0	# problem nltrans
 24 10 1 0 7	# vars, constraints, objectives, ranges, eqns
 0 1	# nonlinear constraints, objectives
 0 0 	# network constraints: nonlinear, linear
 0 21 0	# nonlinear vars in constraints, objectives, both
 0 0 0 1	# linear network variables; functions; arith, flags
 3 0 0 0 0	# discrete variables: binary, integer, nonlinear (b,c,o)
 45 24	# nonzeros in Jacobian, gradients
 0 0	# max name lengths: constraints, variables
 0 0 0 0 0	# common exprs: b,c,o,c1,o1
C0	#Supply['GARY']
n0
C1	#Supply['CLEV']
n0
C2	#Supply['PITT']
n0
C3	#Demand['FRA']
n0
C4	#Demand['DET']
n0
C5	#Demand['LAN']
n0
C6	#Demand['WIN']
n0
C7	#Demand['STL']
n0
C8	#Demand['FRE']
n0
C9	#Demand['LAF']
n0
O0 0	#Total_Cost
o54	#sumlist
21
o3	#/
o2	#*
n39
v0	#Trans['GARY','FRA']
o1	# - 
n1
o3	#/
v0	#Trans['GARY','FRA']
n1300
o3	#/
o2	#*
n14
v1	#Trans['GARY','DET']
o1	# - 
n1
o3	#/
v1	#Trans['GARY','DET']
n2500
o3	#/
o2	#*
n11
v2	#Trans['GARY','LAN']
o1	# - 
n1
o3	#/
v2	#Trans['GARY','LAN']
n1500
o3	#/
o2	#*
n14
v3	#Trans['GARY','WIN']
o1	# - 
n1
o3	#/
v3	#Trans['GARY','WIN']
n1500
o3	#/
o2	#*
n16
v4	#Trans['GARY','STL']
o1	# - 
n1
o3	#/
v4	#Trans['GARY','STL']
n1900
o3	#/
o2	#*
n82
v5	#Trans['GARY','FRE']
o1	# - 
n1
o3	#/
v5	#Trans['GARY','FRE']
n1700
o3	#/
o2	#*
n8
v6	#Trans['GARY','LAF']
o1	# - 
n1
o3	#/
v6	#Trans['GARY','LAF']
n1700
o3	#/
o2	#*
n27
v7	#Trans['CLEV','FRA']
o1	# - 
n1
o3	#/
v7	#Trans['CLEV','FRA']
n800
o3	#/
o2	#*
n9
v8	#Trans['CLEV','DET']
o1	# - 
n1
o3	#/
v8	#Trans['CLEV','DET']
n900
o3	#/
o2	#*
n12
v9	#Trans['CLEV','LAN']
o1	# - 
n1
o3	#/
v9	#Trans['CLEV','LAN']
n800
o3	#/
o2	#*
n9
v10	#Trans['CLEV','WIN']
o1	# - 
n1
o3	#/
v10	#Trans['CLEV','WIN']
n800
o3	#/
o2	#*
n26
v11	#Trans['CLEV','STL']
o1	# - 
n1
o3	#/
v11	#Trans['CLEV','STL']
n500
o3	#/
o2	#*
n95
v12	#Trans['CLEV','FRE']
o1	# - 
n1
o3	#/
v12	#Trans['CLEV','FRE']
n700
o3	#/
o2	#*
n17
v13	#Trans['CLEV','LAF']
o1	# - 
n1
o3	#/
v13	#Trans['CLEV','LAF']
n1700
o3	#/
o2	#*
n24
v14	#Trans['PITT','FRA']
o1	# - 
n1
o3	#/
v14	#Trans['PITT','FRA']
n2600
o3	#/
o2	#*
n14
v15	#Trans['PITT','DET']
o1	# - 
n1
o3	#/
v15	#Trans['PITT','DET']
n1700
o3	#/
o2	#*
n17
v16	#Trans['PITT','LAN']
o1	# - 
n1
o3	#/
v16	#Trans['PITT','LAN']
n2600
o3	#/
o2	#*
n13
v17	#Trans['PITT','WIN']
o1	# - 
n1
o3	#/
v17	#Trans['PITT','WIN']
n2700
o3	#/
o2	#*
n28
v18	#Trans['PITT','STL']
o1	# - 
n1
o3	#/
v18	#Trans['PITT','STL']
n1700
o3	#/
o2	#*
n99
v19	#Trans['PITT','FRE']
o1	# - 
n1
o3	#/
v19	#Trans['PITT','FRE']
n1900
o3	#/
o2	#*
n20
v20	#Trans['PITT','LAF']
o1	# - 
n1
o3	#/
v20	#Trans['PITT','LAF']
n2700
d10	# initial dual guess
0 -76.26529869687859
1 -162.77152360753644
2 -63.793103448275865
3 117.57433163708215
4 99.58981303787263
5 89.30598814190641
6 81.70803728570502
7 146.17881975886664
8 257.77152360753644
9 93.13240981096592
x24	# initial guess
0 36.85519063300813
1 563.1422680151106
2 122.35498413191941
3 0
4 991.0646279225928
5 557.3582574161516
6 529.2246718812603
7 0
8 0
9 0
10 0
11 0
12 0
13 0
14 863.1448093670035
15 636.8577319848923
16 477.64501586808046
17 400.00000000000256
18 708.9353720774179
19 542.6417425838775
20 470.775328118757
21 1
22 0
23 0.7068965517241451
r	#10 ranges (rhs's)
1 0
1 0
1 0
4 900
4 1200
4 600
4 400
4 1700
4 1100
4 1000
b	#24 bounds (on variables)
2 0
2 0
2 0
2 0
2 0
2 0
2 0
2 0
2 0
2 0
2 0
2 0
2 0
2 0
2 0
2 0
2 0
2 0
2 0
2 0
2 0
0 0 1
0 0 1
0 0 1
k23	#intermediate Jacobian column lengths
2
4
6
8
10
12
14
16
18
20
22
24
26
28
30
32
34
36
38
40
42
43
44
J0 8
0 1
1 1
2 1
3 1
4 1
5 1
6 1
21 -2800
J1 8
7 1
8 1
9 1
10 1
11 1
12 1
13 1
22 -5200
J2 8
14 1
15 1
16 1
17 1
18 1
19 1
20 1
23 -5800
J3 3
0 1
7 1
14 1
J4 3
1 1
8 1
15 1
J5 3
2 1
9 1
16 1
J6 3
3 1
10 1
17 1
J7 3
4 1
11 1
18 1
J8 3
5 1
12 1
19 1
J9 3
6 1
13 1
20 1
G0 24
0 0
1 0
2 0
3 0
4 0
5 0
6 0
7 0
8 0
9 0
10 0
11 0
12 0
13 0
14 0
15 0
16 0
17 0
18 0
19 0
20 0
21 50000
22 3940000
23 370000
