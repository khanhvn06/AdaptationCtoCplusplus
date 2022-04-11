#include "ModelIP.h"
#include <iostream>

ModelIP::ModelIP() {
	std::cout << "Construct Model IP" << std::endl;
}
ModelIP::~ModelIP() {
	std::cout << "Destruct Model IP" << std::endl;

	if (env != NULL) delete env;
	env = NULL;
	if (lp != NULL) delete lp;
	lp = NULL;



}
int ModelIP::InitEnvironment() {
	int status;
	env = CPXopenCPLEX(status);
	if (env == NULL)  return -1;
	else return 0;
}

int ModelIP::InitModelIP() {
	int status;
	lp = CPXcreateprob(env, status, "");
	if (lp == NULL)  return -1;
	else return 0;
}

long int ModelIP::CreateNewCol(int nbVar, const std::vector<double>& obj, const std::vector<double>& lb, const std::vector<double>& ub,
	const std::vector<char>&  pVarType, const std::vector<std::string>& pVarName) {


	return CPXnewcols(env, lp, nbVar, obj, lb, ub, pVarType, pVarName);
}

