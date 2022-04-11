#include "cplex.h"


CPXENV* CPXopenCPLEX(int& status) {
	CPXENV* env = new CPXENV();
	status = 0;
	return env;
}

CPXLP* CPXcreateprob(CPXENV* env, int& status, const std::string& str) {
	CPXLP* lp = new CPXLP();
	status = 0;
	return lp;
}

long int CPXnewcols(CPXENV* env, CPXLP* lp, int nbVar, const std::vector<double>& obj, const std::vector<double>& lb, const std::vector<double>& ub,
	const std::vector<char>&  pVarType, const std::vector<std::string>& pVarName) {
	return 0; //simulate to compile
}