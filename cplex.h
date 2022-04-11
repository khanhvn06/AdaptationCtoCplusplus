#ifndef CPLEX_H
#define CPLEX_H

#include<string>
#include<vector>
#include<iostream>
class CPXENV
{
public:
	CPXENV() {
		std::cout << "Construct Environement" << std::endl;
	}
};

class CPXLP
{
public:
	CPXLP() {
		std::cout << "Construct LP" << std::endl;
	}
};

CPXENV* CPXopenCPLEX(int& status);


CPXLP* CPXcreateprob(CPXENV* env, int& status, const std::string& str);

long int CPXnewcols(CPXENV* env, CPXLP* lp, int nbVar, const std::vector<double>& obj, const std::vector<double>& lb, const std::vector<double>& ub,
	const std::vector<char>&  pVarType, const std::vector<std::string>& pVarName);


#endif


