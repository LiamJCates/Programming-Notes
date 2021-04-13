// Splitting a function into another file

/*
void DrawLine()

int main()
{
	DrawLine();
}

void DrawLine()
{
	//implementation
}

*/


//--------------------------------
//main.cpp

#include "Drawline.h"

int main()
{
	DrawLine();
}


//--------------------------------
//Drawline.h
void DrawLine();


//--------------------------------
//Drawline.cpp

#include "DrawLine.h"

void DrawLine()
{
	//implementation
}
