#include <iostream>
#include <vector>
#include <string>
#include "ModelIP.h"


void setNameVar1Array(std::vector<std::string>& nameVar, const std::string& name) {
	for (int uiLoop = 0;uiLoop < nameVar.size();uiLoop++) {
		nameVar[uiLoop] = name + std::to_string(uiLoop + 1);
	}
}

void setNameVar2Array(std::vector<std::string>& nameVar, const std::string& name, const int Nb1, const int Nb2) {
	int count = 0;
	for (int uiLoop = 0;uiLoop < Nb1;uiLoop++)
		for (int uiLoop2 = 0;uiLoop2 < Nb2;uiLoop2++) {
			nameVar[count] = name + std::to_string(uiLoop + 1) + "," + std::to_string(uiLoop2 + 1);
			count++;
		}
}
void setNameVar3Array(std::vector<std::string>& nameVar, const std::string& name, const int Nb1, const int Nb2, const int Nb3) {
	int count = 0;
	for (int uiLoop = 0;uiLoop < Nb1;uiLoop++)
		for (int uiLoop2 = 0;uiLoop2 < Nb2;uiLoop2++)
			for (int uiLoop3 = 0;uiLoop3 < Nb3;uiLoop3++) {
				nameVar[count] = name + std::to_string(uiLoop + 1) + "," + std::to_string(uiLoop2 + 1) + "," + std::to_string(uiLoop3 + 1);
				count++;
			}
}
void setTypeVar(std::vector<char>& typeVar, const char type) {
	std::fill(typeVar.begin(), typeVar.end(), type);
}

void setNameTypeVar1Array(std::vector<std::string>& nameVar, std::vector<char>& typeVar, const std::string& name, const char type) {
	setNameVar1Array(nameVar, name);
	setTypeVar(typeVar, type);
}

void setNameTypeVar2Array(std::vector<std::string>& nameVar, std::vector<char>& typeVar, const std::string& name,
	const char type, const int Nb1, const int Nb2) {
	setNameVar2Array(nameVar, name, Nb1, Nb2);
	setTypeVar(typeVar, type);
}

void setNameTypeVar3Array(std::vector<std::string>& nameVar, std::vector<char>& typeVar, const std::string& name,
	const char type, const int Nb1, const int Nb2, const int Nb3) {
	setNameVar3Array(nameVar, name, Nb1, Nb2, Nb3);
	setTypeVar(typeVar, type);
}

int main() {
	std::cout << "Start The Model" << std::endl;

	ModelIP modelIP;
	if (modelIP.InitEnvironment() == -1) {

		std::cout << "Could not open CPLEX environment" << std::endl;

		return -1;
	}

	if (modelIP.InitModelIP() == -1) {

		std::cout << "Failed to create LP" << std::endl;

		return -1;
	}

	//Declare decision variables

	//Allocate resource for names and types of variables

	std::vector<std::string> pVarNameS(Nbl*Nbs);//for variables S^l_s  Nbl*Nbs=size of tableau
	std::vector<char> pVarTypeS(Nbl*Nbs);

	std::vector<std::string> pVarNameC(Nbl*Nbc);//for variables C^l_c
	std::vector<char> pVarTypeC(Nbl*Nbc);

	std::vector<std::string> pVarNameY(Nbl*Nbl*Nbs);//for variables Y^ll_s
	std::vector<char> pVarTypeY(Nbl*Nbl*Nbs);

	std::vector<std::string> pVarNameCan(Nbt);//for variables represent train cancelled
	std::vector<char> pVarTypeCan(Nbt);

	//Allocate and define obj value of variables
	std::vector<double> objS(Nbl*Nbs, 0); //set object value 0 for S
	std::vector<double> objCan(Nbt, 1); //set object value 1 for train cancelled

	//Allocate and define lower bound and upper bound for variables
	std::vector<double> lbS(Nbl*Nbs, 0);//set lower bound 0 for S
	std::vector<double> ubS(Nbl*Nbs, 1);//set upper bound 1 for S

	std::vector<double> lbCan(Nbt, 0);//set lower bound 0 for train Cancelled
	std::vector<double> ubCan(Nbt, 1);//set upper bound 1 for train Cancelled

	//Define names and types of variables
	setNameTypeVar2Array(pVarNameS, pVarTypeS, "S", 'B', Nbl, Nbs);//B for Boolean
	setNameTypeVar2Array(pVarNameC, pVarTypeC, "C", 'B', Nbl, Nbc);
	setNameTypeVar3Array(pVarNameY, pVarTypeY, "Y", 'B', Nbl, Nbl, Nbs);
	setNameTypeVar1Array(pVarNameCan, pVarTypeCan, "Cancel", 'B');

	//Add decision variables to the model


	long int status = modelIP.CreateNewCol(Nbl * Nbs, objS, lbS, ubS, pVarTypeS, pVarNameS); //add variables S to model
	//check status code

	//Add train cancelled variables to model and define the function objective (minimize the number of train cancelled) for the model

	long int status2 = modelIP.CreateNewCol(Nbt, objCan, lbCan, ubCan, pVarTypeCan, pVarNameCan);
	//check status code

	//Add constraints to the model


	return 0;
}