// --------------------------------------------------------------
//    NETSCORE Version 1
//    solver.cpp -- Implementation of solver functions
//    2009-2010 (c) Eduardo Ib��ez
//    2011-2014 (c) Venkat Krishnan (VK)
// --------------------------------------------------------------

#ifndef _SOLVER_H_
#define _SOLVER_H_

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "global.h"
#include <ilcplex/ilocplex.h>

// Declares a structure to store and manipulate problem information
struct CPLEX {
	IloEnv env;
	IloArray<IloModel> model;
	IloArray<IloCplex> cplex;
	IloArray<IloObjective> obj;
	IloArray<IloNumVarArray> var;
	IloArray<IloRangeArray> rng;
	IloNumArray solution;

	CPLEX() : env(), model(env, 0), cplex(env, 0), obj(env, 0), var(env, 0), rng(env, 0), solution(env, 0) {};
	~CPLEX() {
		// Remove optimization elements from memory
		solution.end(); rng.end(); var.end(); obj.end(); model.end(); cplex.end();
		env.end();
	};
	
	// Loads the problem from MPS files into memory
	void LoadProblem();
	
	// Solves current model
	void SolveIndividual( double *objective, const double events[], string & returnString );
	void SolveIndividual( double *objective, const double events[]);
	
	// Store complete solution vector
	void StoreSolution();
	
	// Function called by the NSGA-II method. It takes the minimum investement (x) and calculates the metrics (objective)
	void SolveProblem(double *x, double *objective, const double events[]);
};


// Apply capacities from master to subproblems
void CapacityConstraints(IloArray<IloRangeArray>& Cuts, const double events[], const int event, const IloNumArray mastersol, const int offset);

// Metrics
double EmissionIndex(const IloNumArray& v, const int start);
vector<double> SumByRow(const IloNumArray& v, Index Idx, const int start);

// Resets models to improve memory management
// void ResetProblem(IloArray<IloModel>& model, IloArray<IloCplex>& cplex);

/*
// Import Minimum investment into the model from file (not tested)
void ImportMin( const char* filename, const int MstartInv );

// Apply values in the arry as LB for investment variables
void ApplyLB( vector<string> StoredLine, int startInv );

// Resets models to improve memory management
void ResetProblem();
*/

#endif  // _SOLVER_H_
