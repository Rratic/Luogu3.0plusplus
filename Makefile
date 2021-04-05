compiler = g++
result = luogu++
header = $(shell find ./src -maxdepth 1 -name "*.h")
src = $(shell find ./src -maxdepth 1 -name "*.cpp")
object_code = main.cpp
$(result): $(object_code)
	$(compiler) -o $(result) $(object_code)
$(object_code): $(header) $(src)
	cat $(header) $(src) > $(object_code)
