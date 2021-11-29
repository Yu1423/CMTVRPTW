# CMTVRPTW
The libcmtvrptw.a is linkable C++ library compiled for Linux that can be used to reproduce the results reported in [_An Improved Exact Solution Framework for the Capacitated Multi-Trip Vehicle Routing Problem with Time Windows_](http://www.optimization-online.org/DB_FILE/2021/01/8237.pdf). It can also be applied to solve new _capacitated  multi-trip  vehicle  routing  problem  with  time  windows_ (CMTVRPTW) instances and its variants. The third-party commercial MIP solver Gurobi is required. Please cite our paper if you use the library for your research.


An example main.cpp is included to show how to use the library. Depending on which variant you would like to solve, different arguments should be fed into the class constructor. The first 6 arguments are universal for all variants. The first 2 are the two Gurobi environment pointers which should be initialized by the GRBloadenv funtion first. The 3rd is a boolean variable controlling the output, and detailed information in the solution process will be printed out if it's set to _true_. The next two arguments are the folder name that constains the instances to be solved and the file name of the instance. The 6th one is a string that specifies the problem type, whose possible options are "CMTVRPTW", "CMTVRPTW-LT", "CMTVRPTW-LD", "CMTVRPTW-R", "DRP-A" and "DRP-B". For the CMTVRPTW and the CMTVRPTW-R, the 7th to 9th arguments are the number of customers, the number of vehicles, and the vehicle capacity, whose default values are 25, 2, and 100, respectively. For the CMTVRPTW-LT, it has an extra argument, i.e., the 10th, is the loadfactor which is the proportion of the loading time to the service time, and is set to 0.2 by default. For the CMTVRPTW-LD, it has one more argument than the CMTVRPTW-LT, which is the limit on the maximum duration. For the DRP, the type A just needs the first 6 arguments as mentioned while the type B needs the 7th argument that specifies the number of customers to consider.

Once an object is initialized, the problem can be solved by calling the Solve() method. The source code can be compiled by the following g++ command on Linux.

  _g++  -I full/path/to/your/Gurobi/header/folder  main.cpp  CMTVRPTW_EXT.hpp  -L  full/path/to/your/Gurobi/lib/folder -L full/path/to/your/libcmtvrptw.a/folder -lgurobi91 -lcmtvrptw -O3  -std=c++11  -o run_
  
All instances used in the paper are provided here. More specifically, when the problem type is one of "CMTVRPTW", "CMTVRPTW-LT", "CMTVRPTW-LD", and "DRP-B", the corresponding instances are in the folder named "Data/Solomon". When it's "CMTVRPTW-R", the folder named "Data/Release" should be used, while "Data/Drones_A" should be used for the problem type "DRP-A".

