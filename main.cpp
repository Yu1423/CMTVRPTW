//  Created by Yu Yang on 9/10/20.
//  Copyright © 2020 Yu Yang. All rights reserved.

#include <iostream>
#include <iomanip>
#include "CMTVRPTW_EXT.hpp"

#define PRINTDEC 1



using namespace std;


int main(){

	cout  << setprecision(PRINTDEC) << std::fixed;
	GRBenv* env1;
	GRBenv* env2;
	GRBloadenv(&env1, NULL);
	GRBloadenv(&env2, NULL);
	cout << "\n" << endl;
	
	
	// use this constructor if it's a CMTVRPTW instance
	CMTVRPTW_EXT  mtvrp(env1, env2, false, "./Solomon/", "C201.txt", "CMTVRPTW", 25, 2, 100);
	
	
//	// use this constructor if it's a CMTVRPTW-LT instance
//	CMTVRPTW_EXT  mtvrp(env1, env2, false, "./Solomon/", "C201.txt", "CMTVRPTW-LT", 25, 2, 100, 0.2);
//
//
//	// use this constructor if it's a CMTVRPTW-LD instance
//	//capacity = 700 for group C and 1000 for groups R and RC
//	CMTVRPTW_EXT  mtvrp(env1, env2, false, "./Solomon/", "C201.txt", "CMTVRPTW-LD", 25, 2, 700, 0.2, 220);
//
//
//	// use this constructor if it's a CMTVRPTW-R instance
//	CMTVRPTW_EXT  mtvrp(env1, env2, false, "./Release/", "C201R0.25.txt", "CMTVRPTW-R", 25,  2, 100);
//
//
//	// use this constructor if it's a DRP (type A) instance
//	CMTVRPTW_EXT  mtvrp(env1, env2, true, "./Drones_A/", "Set_A1_Cust_10_1.txt", "DRP-A");
//
//	// use this constructor if it's a DRP (type B) instance
//	CMTVRPTW_EXT  mtvrp(env1, env2, false, "./Solomon/", "C201.txt", "DRP-B", 25);
	
	// default is 3h, i.e, 10800s, change if you would like to use a different time limit
//	mtvrp.Change_time_limit(7200);
	
	// default is 8 threads for solving MIPs, change if you would like to use more or fewer threads
//	mtvrp.Change_number_threads(1);
	
	// call this method function to solve the instance
	mtvrp.Solve();
	
	
	GRBfreeenv(env1);
	GRBfreeenv(env2);
	return 0;
}
