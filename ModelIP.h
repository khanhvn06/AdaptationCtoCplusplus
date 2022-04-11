#ifndef MODEL_IP_H
#define MODEL_IP_H

#include "cplex.h"		//library to solve model
#include <vector>
#include <string>
#define Nbl 3 //for test
#define Nbs 4
#define Nbc 5
#define Nbt 6

class ModelIP
{
public:

	ModelIP();
	~ModelIP();
	int InitEnvironment();
	int InitModelIP();

	long int CreateNewCol(int nbVar, const std::vector<double>& obj, const std::vector<double>& lb, const std::vector<double>& ub,
		const std::vector<char>&  pVarType, const std::vector<std::string>& pVarName);


private:

	CPXENV*     env;
	CPXLP*      lp;


};

#endif