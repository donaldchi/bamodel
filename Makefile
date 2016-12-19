#!/bin/bash

CXX=g++
CXXFLAGS= -std=c++11

test:
	$(CXX) $(CXXFLAGS) src/ba.cxx -o bin/ba

clean:
	rm bin/*
