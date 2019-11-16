#include <string>
#include "marking.h"
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	marking obj;
	obj.submitAssignment("2018-CS-31");
	obj.submitAssignment("2018-CS-36");
	obj.submitAssignment("2018-CS-35");
	obj.submitAssignment("2018-CS-22");
	obj.submitAssignment("2018-CS-37");
	obj.submitAssignment("2018-CS-32");
	obj.submitAssignment("Ghous");
	obj.submitAssignment("2018-CS-11");
	obj.submitAssignment("2018-CS-21");
	obj.submitAssignment("2018-CS-1");
	obj.submitAssignment("2018-CS-29");
	obj.submitAssignment("2018-CS-14");
	obj.submitAssignment("2018-CS-10");
	obj.print();

	system("pause");
}