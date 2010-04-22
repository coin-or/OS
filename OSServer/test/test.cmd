@echo off
set OSSOLVERSERVICE=..\..\OSThirdParty\lib\coin-or\OSSolverService
set OPTIONS=-osil first.osil -serviceMethod solve -serviceLocation http://localhost:8080/OSServer/services/OSSolverService

%OSSOLVERSERVICE%-win32 %OPTIONS%
pause
