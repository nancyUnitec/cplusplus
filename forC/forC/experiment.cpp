#include "stdafx.h"

#include <iostream>
#include <string>
using namespace std;

#include "forCPP.h"
#include "experiment.h"

int testBasicType()
{
	char ss = '\0';
	printf("ss = %c \n", ss);

	int x = 0;
	int y = 0;
	char str[10];
	//char str[1];
	x = strlen(str);
	y = sizeof(str);

	return 0;
}

