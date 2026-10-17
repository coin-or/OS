# OS

[![A COIN-OR Project](https://coin-or.github.io/coin-or-badge.png)](https://www.coin-or.org)

Projects such as this one are maintained by a small group of volunteers under
the auspices of the non-profit [COIN-OR Foundation](https://www.coin-or.org)
and we need your help! Please consider [sponsoring our
activities](https://github.com/sponsors/coin-or) or [volunteering](mailto:volunteer@coin-or.org) to help!

[![Latest Release](https://img.shields.io/github/v/release/coin-or/OS?sort=semver)](https://github.com/coin-or/OS/releases)

_This file is auto-generated from [config.yml](.coin-or/config.yml) using the 
[generate_readme](.coin-or/generate_readme) script.
To make changes, please edit [config.yml](.coin-or/config.yml) or the generation scripts
[here](.coin-or/generate_readme) and [here](https://github.com/coin-or/coinbrew/blob/master/scripts/generate_readme)._

The objective of Optimization Services (OS) is to provide a set of
standards for representing optimization instances, results, solver options,
and communication between clients and solvers in a distributed environment
using Web Services. This COIN-OR project provides source code for libraries
and executable programs that implement OS standards.

OS consists of
 * the library `libOS`, which reads and writes optimization instances
   (OSiL), solver options (OSoL), and results (OSrL) in the OS XML formats,
   converts instances from MPS and AMPL nl files, and provides a common
   interface to the COIN-OR solvers (Clp, Cbc, SYMPHONY, DyLP, Vol, Ipopt,
   Bonmin, Couenne) and to commercial solvers,
 * `OSSolverService`, which solves an instance with a local or remote solver,
 * `OSAmplClient` (if ASL is available), which lets AMPL use the solvers
   through OS.

OS computes derivatives for its interfaces to Ipopt, Bonmin, and Couenne with
[CppAD](https://github.com/coin-or/CppAD), so these interfaces are only built
if CppAD is installed (e.g., `libcppad-dev` on Debian and Ubuntu, `cppad` in
Homebrew).

OS is written in C++ and is released as open source under the [Eclipse Public License 2.0](http://www.opensource.org/licenses/EPL-2.0).

It is distributed under the auspices of the [COIN-OR Foundation](https://www.coin-or.org)

The OS development site is https://github.com/coin-or/OS.

## CURRENT BUILD STATUS

[![Windows Builds](https://github.com/coin-or/OS/actions/workflows/windows-ci.yml/badge.svg?branch=master)](https://github.com/coin-or/OS/actions/workflows/windows-ci.yml?query=branch%3Amaster)

[![Linux and MacOS Builds](https://github.com/coin-or/OS/actions/workflows/linux-ci.yml/badge.svg?branch=master)](https://github.com/coin-or/OS/actions/workflows/linux-ci.yml?query=branch%3Amaster)

## DOWNLOAD

### Docker image

There is a Docker image that provides OS, as well as other projects
in the [COIN-OR Optimization
Suite](https://github.com/coin-or/COIN-OR-OptimizationSuite) [here](https://hub.docker.com/repository/docker/coinor/coin-or-optimization-suite)

### Binaries

For newer releases, binaries will be made available as assets attached to
releases in Github
[here](https://github.com/coin-or/OS/releases). Older binaries
are archived as part of OS
[here](https://www.coin-or.org/download/binary/OS).

Due to license incompatibilities, pre-compiled binaries may lack some
functionality. If binaries are not available for your platform for the latest
version and you would like to request them to be built and posted, feel free
to let us know in the discussion formum.

### Source

Source code can be obtained either by

 * Downloading a snapshot of the source code for the latest release version of OS from the
 [releases](https://github.com/coin-or/OS/releases) page.
 * Cloning this repository from [Github](https://github.com/coin-or/OS) or 
 * Using the [coinbrew](https://github.com/coin-or/coinbrew) script to get the project and all dependencies (recommended, see below).   

Below is a quick start guide for building on common platforms. More detailed
build instructions are
[here](https://coin-or.github.io/user_introduction.html).

### Dependencies

OS has a number of dependencies, which are detailed in
[config.yml](.coin-or/config.yml). Dependencies on other COIN-OR projects are
automatically downloaded when obtaining the source with `coinbrew`. For some
of the remaining third-party dependencies, automatic download scripts and
build wrappers are provided (and will also be automatically run for required
and recommended dependencies), while other libraries that are aeasy to obtain
must be installed using an appropriate package manager (or may come with your
OS by default). 

## BUILDING from source

The quick start assumes you are in a bash shell. 

### Using `coinbrew`

To download and build OS from source, execute the 
following on the command line. 
```
wget https://raw.githubusercontent.com/coin-or/coinbrew/master/coinbrew
chmod u+x coinbrew
./coinbrew fetch OS@master
./coinbrew build OS
```
For more detailed instructions on coinbrew, see https://coin-or.github.io/coinbrew.
The `coinbrew` script will fetch the additional projects specified in the Dependencies section of [config.yml](.coin-or/config.yml).

### Without `coinbrew` (Expert users)

 * Download the source code, e.g., by cloning the git repo https://github.com/coin-or/OS
 * Download and install the source code for the dependencies listed in [config.yml](.coin-or/config.yml)
 * Build the code as follows (make sure to set PKG_CONFIG_PTH to install directory for dependencies).

```
./configure -C
make
make test
make install
```

### Using OS

After building and installing OS, an instance can be solved with, e.g.,
```
OSSolverService -osil data/osilFiles/parincLinear.osil -solver clp
```
Run `OSSolverService -h` for the other options. The unit test is run with
`make test` in the build directory.

## Doxygen Documentation

If you have `Doxygen` available, you can build a HTML documentation by typing

`make doxydoc` 

in the build directory. If OS was built via `coinbrew`, then the build
directory will be `./build/OS/master` by default. The doxygen documentation main file
is found at `<build-dir>/doxydoc/html/index.html`.

If you don't have `doxygen` installed locally, you can use also find the
documentation [here](http://coin-or.github.io/OS/Doxygen).

## Documentation

 * [OS User's Manual](doc/osUsersManual.pdf)
 * [Optimization Services home page](http://www.optimizationservices.org)


## Project Links

 * [Code of Conduct](https://www.coin-or.org/code-of-conduct/)
 * [COIN-OR Web Site](http://www.coin-or.org/)
 * [COIN-OR general discussion forum](https://github.com/orgs/coin-or/discussions)
 * [OS Discussion forum](https://github.com/coin-or/OS/discussions)
 * [Report a bug](https://github.com/coin-or/OS/issues/new)
 * [Doxygen generated documentation](http://coin-or.github.io/OS/Doxygen)

