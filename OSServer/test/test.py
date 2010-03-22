#!/usr/bin/python
import SOAPpy
os=SOAPpy.SOAPProxy("http://localhost:8080/OSServer/services/OSSolverService")
print os.getJobID();
print os.solve(open("first.osil").read())
