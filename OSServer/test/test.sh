#!/bin/sh

: ${OSSOLVERSERVICE:=../../OSThirdParty/lib/coin-or/OSSolverService}
: ${PORT:=8080}

${OSSOLVERSERVICE} -osil first.osil -serviceMethod solve -serviceLocation http://localhost:${PORT}/OSServer/services/OSSolverService

