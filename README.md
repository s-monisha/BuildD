# BuildD

#Requirements:
- libdxfrw (https://github.com/rvt/libdxfrw)
- cmake and make (https://cmake.org/install, May also use your package manager)
- Open in any CAD software (like Qcad, DraftSight, LibreCad)

#Clone this repository

git clone https://github.com/s-monisha/BuildD

#Edit line 6 accordingly in CMakeLists.txt

set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt5.5.1/5.5/gcc_64)

#Compilation

$ cd BuildD

$ mkdir build && cd build && cmake .. && make

$ ./BuildD
