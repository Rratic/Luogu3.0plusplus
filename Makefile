compiler = g++
result = luogu++
header = $(shell find ./src -maxdepth 1 -name "*.h")
src = $(shell find ./src -maxdepth 1 -name "*.cpp")
object_code = main.cpp
$(compiler) $(object_code) -std=c++11 -o $(result)
