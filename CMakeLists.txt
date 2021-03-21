##########################
#	run command
#	cmake . && make
#	from a directory where the all output files should be created
##########################

cmake_minimum_required(VERSION 3.0)
project(NumCpp)

#set(CMAKE_MAJOR_VERSION 1)
#set(CMAKE_MINOR_VERSION 0)
#set(CMAKE_PATCH_VERSION 0)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
	src/flags.h
	src/matrix/matrix.h
	src/matrix/matrix.cpp
	src/matrix/nArray.h
	src/matrix/nArray.cpp
	src/calculus/ode.h
	src/calculus/ode.cpp
	src/calculus/integration.h
	src/calculus/integration.cpp
	src/math/math.h
	src/math/math.cpp
	src/tests/matrix_test.h
	src/tests/ode_test.h
	src/main.cpp
		src/io/data_writer.cpp
		src/io/data_writer.h
		src/io/data_reader.h
		src/io/data_reader.cpp
		src/tests/test_io.cpp src/tests/test_io.h)


#set(EXECUTABLE_OUTPUT_PATH "cmake-build-debug") # adds executables to "cmake-build-debug" directory

# this one is important
# SET(CMAKE_SYSTEM_NAME Windows)
# SET(CMAKE_SYSTEM_NAME Linux)

set(CMAKE_BINARY_DIR ".")

# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(numcpp ${SOURCE_FILES})
