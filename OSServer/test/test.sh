#!/bin/sh

ARCH="$(uname -s)-$(uname -m)"
: ${OSSOLVERSERVICE:=../../OSThirdParty/lib/coin-or/OSSolverService-${ARCH}}
: ${PORT:=8080}

${OSSOLVERSERVICE} -osil first.osil -serviceMethod solve -serviceLocation http://localhost:${PORT}/OSServer/services/OSSolverService
