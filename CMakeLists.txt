cmake_minimum_required(VERSION 3.8)

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

set(CMAKE_CXX_STANDARD 11)

project(epsilon)


set(CMAKE_C_FLAGS "-std=c99 \
-I/Users/adriweb/Documents/epsilon \
-I/Users/adriweb/Documents/epsilon/escher/include \
-I/Users/adriweb/Documents/epsilon/ion/include \
-I/Users/adriweb/Documents/epsilon/kandinsky/include \
-I/Users/adriweb/Documents/epsilon/liba/include \
-I/Users/adriweb/Documents/epsilon/liba/src/external/openbsd/include \
-I/Users/adriweb/Documents/epsilon/liba/src/external/softfloat/include \
-I/Users/adriweb/Documents/epsilon/libaxx/include \
-I/Users/adriweb/Documents/epsilon/poincare/include \
-I/Users/adriweb/Documents/epsilon/python/port \
-I/Users/adriweb/Documents/epsilon/python/src \
-I/Users/adriweb/Documents/epsilon/python/src/py/include \
-I/Users/adriweb/Documents/epsilon/quiz/include \
-I/usr/local/Cellar/freetype/2.8.1/include/freetype2")

set(CMAKE_CXX_FLAGS "-fno-exceptions -fno-rtti -fno-threadsafe-statics \
-I/Users/adriweb/Documents/epsilon \
-I/Users/adriweb/Documents/epsilon/escher/include \
-I/Users/adriweb/Documents/epsilon/ion/include \
-I/Users/adriweb/Documents/epsilon/kandinsky/include \
-I/Users/adriweb/Documents/epsilon/liba/include \
-I/Users/adriweb/Documents/epsilon/liba/src/external/openbsd/include \
-I/Users/adriweb/Documents/epsilon/liba/src/external/softfloat/include \
-I/Users/adriweb/Documents/epsilon/libaxx/include \
-I/Users/adriweb/Documents/epsilon/poincare/include \
-I/Users/adriweb/Documents/epsilon/python/port \
-I/Users/adriweb/Documents/epsilon/python/src \
-I/Users/adriweb/Documents/epsilon/python/src/py/include \
-I/Users/adriweb/Documents/epsilon/quiz/include \
-I/usr/local/Cellar/freetype/2.8.1/include/freetype2")

file(GLOB_RECURSE SOURCE_FILES   .  false   *.h *.c *.cpp)

add_executable(epsilon ${SOURCE_FILES})