//  Created by Yu Yang on 9/10/20.
//  Copyright © 2020 Yu Yang. All rights reserved.

#ifndef CMTVRPTW_EXT_H
#define CMTVRPTW_EXT_H
#include <sys/time.h>
#include <string>
#include "gurobi_c.h"


class CMTVRPTW;
class CMTVRPTW_LT;
class CMTVRPTW_LD;
class CMTVRPTW_R;
class DRP;



class CMTVRPTW_EXT
{
	std::string ProbType;
	CMTVRPTW* cmtvrp;
	CMTVRPTW_LT* cmtvrp_lt;
	CMTVRPTW_LD* cmtvrp_ld;
	CMTVRPTW_R* cmtvrp_r;
	DRP* drp;

	
public:
	
    CMTVRPTW_EXT(GRBenv* env1, GRBenv* env2, bool verbose,
				 std::string foldername, std::string filename,
				 std::string problemtype = "CMTVRPTW",
				 int numcsts = 25, int numvehs = 2, int capacity = 100,
				 double loadfactor = 0.2, int duration = 250);
	
	void Change_number_threads(int );
	void Change_time_limit(double );
	void Set_NUM_RC(int );
	void Skip(std::string );
	
	~CMTVRPTW_EXT();
	void Solve();
};


double get_wall_time();
std::string getFileName(const std::string& s);
std::string addcomma(int);


#endif
