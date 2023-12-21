# TDDC-301 TDD for Embedded C exercises


**Contents**
- [TDDC-301 TDD for Embedded C exercises](#tddc-301-tdd-for-embedded-c-exercises)
- [Ceedling](#ceedling)
  - [Direct](#direct)
  - [Docker](#docker)
  - [GCov](#gcov)
- [Lizard](#lizard)
- [OCLint](#oclint)
- [Documentation](#documentation)
- [Toolchain setup](#toolchain-setup)
  - [ruby](#ruby)
  - [ceedling](#ceedling-1)
  - [valgrind](#valgrind)
  - [lizard](#lizard-1)
  - [OCLint](#oclint-1)

These exercises require a number of additional development tools to be installed
as described in the Toolchain setup section.

# Ceedling

The projects can be tested locally using either ceedling directly or
through docker.

## Direct

```
$ cd solutions/exercise-N
$ ceedling test:all
```

## Docker

```$ cd solutions/exercise-N
$ docker run -v $(pwd):/usr/project -ti feabhas/ceedling-0.28.2 ceedling test:all
```

## GCov

```
$ cd solutions/exercise-N
$ ceedling gcov:all
$ ceedling utils:gcov
```

# Lizard

```
$ cd solutions/exercise-N/src
$ lizard
```

# OCLint

Make sure you upasked the OClint achive and the `bin` folder to your
search `PATH`. Assuming OCLint 22.02 has been placed in your home directory
run this command to add `oclint` for your current login session:

```
$ PATH="$PATH:$HOME/bin/oclint-22.02/bin"
```

Run the analysis on your workspace sourfce folder:

```
cd solutions/exercise-N
oclint src/*.c -- -c -I vendor/ceedling/vendor/unity/src/
```

# Documentation

To generate the ```Doxygen``` documentation:

```
$ cd solutions/exercise-N/src
$ docker run --rm -it -v $(pwd):/app corentinaltepe/doxygen doxygen Doxyfile
```

The generated html can be found at:

   * `doc/html/index.htm`

e.g.
   * `./solutions/exercise-1/src/doc/html/index.html`

# Toolchain setup

In addition to the standard C/C++ Toolchain the following supporting tools 
disussed during training must be installed for these exercises.

Instructions are for Ubuntu Linux but should work on macOS.

## ruby

```
$ sudo apt install ruby-full
```

## ceedling
 
see http://www.throwtheswitch.org/ceedling

```
$ sudo gem install ceedling
```

## valgrind

```
sudo apt-get install -y valgrind
```

## lizard

```
$ pip3 install lizard
```

## OCLint

Download the appropriate archive from the [OClint](https://oclint.orgOCLint) [releases](https://github.com/oclint/oclint/releases) page.

Assuming this download is OClint v22.02 built for Ubuntu and saved in your
`Downloads` folder you can unpack the download into you home folder using:

```
$ tar xvf ~\Downloads\oclint-22.02-llvm-13.0.1-x86_64-linux-ubuntu-20.04.tar
```

You need to include oclint on your search `PATH` which you can do for the current
terminal session using the command:

```
$ PATH="$PATH:$HOME/oclint-22.02/bin"
```

You can add the following to you login profile (file `~/.profile`) to make 
this change persistent across login sessions:

```
OCLINT_BIN="$HOME/oclint-22.02/bin"
if [[ -x $OCLINT_BIN/oclint ]]; then
  PATH="$PATH:$OCLINT_BIN"
fi
```
