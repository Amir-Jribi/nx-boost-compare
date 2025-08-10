# nx-boost-compare

Compare two graphs, one created with Python’s NetworkX and the other with C++ Boost Graph Library, via nanobind Python bindings

## Overview

This project demonstrates how to create graphs using:

- **NetworkX (Python)** — version 3.2.1  
- **Boost Graph Library (C++)** — version 1.83.0  

It exposes a C++ function to Python (using nanobind) that compares two graphs for equality based on their edge lists, regardless of edge insertion order.

## Features

- Create directed graphs in Python with NetworkX.  
- Create directed graphs in C++ with Boost Graph Library.  
- Transfer graphs between Python and C++ using nanobind bindings.  
- Compare two graphs' edge sets for equality from Python.

## Requirements

- Python 3.11.5 (GCCcore 13.2.0)  
- NetworkX 3.2.1  
- Boost 1.83.0  
- CMake 3.27.6  
- nanobind (included as a git submodule)

## Build Instructions

git clone https://github.com/Amir-Jribi/nx-boost-compare  
cd nx-boost-compare  
git submodule add -f https://github.com/wjakob/nanobind ext/nanobind  
git submodule update --init --recursive  
mkdir build  
cd build  
cmake -S .. -B .  
make

