CXX=g++
CXXFLAGS=-std=c++17 -g -pedantic -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer

all: anon_pipes named_pipe_client named_pipe_server

.PHONY: clean

clean:
	rm -rf anon_pipes named_pipe_client named_pipe_server pipe_client2server pipe_server2client