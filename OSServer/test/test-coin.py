#!/usr/bin/python
import SOAPpy
os=SOAPpy.SOAPProxy("http://webdss.ise.ufl.edu:2646/OSServer/services/OSSolverService")
print os.getJobID();
print os.solve(open("first.osil").read())
