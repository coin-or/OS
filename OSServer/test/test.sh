#!/bin/sh

: ${OSSOLVERSERVICE:=../../OSThirdParty/lib/coin-or/OSSolverService}
: ${PORT:=8080}

echo ${OSSOLVERSERVICE} -osil first.osil -serviceMethod solve -serviceLocation http://localhost:${PORT}/OSServer/services/OSSolverService

${OSSOLVERSERVICE} -osil first.osil -serviceMethod solve -serviceLocation http://localhost:${PORT}/OSServer/services/OSSolverService



