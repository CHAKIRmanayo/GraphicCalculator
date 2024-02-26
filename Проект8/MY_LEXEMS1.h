#ifndef MY_LEXEMS1_H
#define MY_LEXEMS1_H
#include <stdio.h>
#include <string.h>
#include "my_stack1.h"
#include "my_queue1.h"

using namespace System;

struct Point1{

	float x, y;
};

MyQueue sepLexem1(char*, int*);

int getNmb(char*, MyQueue&);

int getLtr(char*, MyQueue&);

MyQueue reRecord(MyQueue);

char* pushStr(char*);

bool getDot(char*, int);

char* corrDot(char*, int);

bool testBrackets(char*);

int testStr(char*, char*, int*, int*);

int testFind1(char*, int*, int*);

int testFind2(char*, int*, int*);

int testFind3(char*, int*, int*);

int testFindHL(char*,  int*,  int*);

int testFind4(char*, int*, int*);

int testFind5(char*, char*, int*, int*);

int corrBrackets(char*);

bool isCurr(int);

char* corrStr(char*, int, int);

char* corrStr1(char*, int);

char* corrHL(char*,  int);

char* corrStr3(char*, int,  int);

char* isSin(char*);

char* isCos(char*);

char* isLn(char*);

char* isTg(char*);

bool strpS(char);

int findMtp(char*, int*, int*);

bool findFunc(char*, int);

int testMtp1(char*, int*);

int testMtp2(char*, int*);

bool findNmb(char);

bool findSgn(char);

bool findSgn1(char);

bool findLtr(char);

char* corrMtp(char*, int);

char* corrSps(char*, int);

bool Funcs(char*);

void pushFromSt(MyQueue&, Stack<char*>&, char*s);

void pushSgn(Stack<char*>&, char*, MyQueue&);

void pushSgnL(MyQueue&, char, int);

int getPrior(char*);

bool testNmbInBr(char*);

void pushFromStFin(MyQueue&, Stack<char*>&);

bool testInBrcks(char*);

bool testInBrcksM(char*);

char* corrAbs(char*, int);

bool testM(char*);

char* strAbs(char*, char*, int);

float calcul(MyQueue, double);

float getFunc(Stack<float>&, char*);

float getSgn(Stack<float>&, char);

Point1* getPoints(double, double, double, MyQueue, int*, float*, float*);

Point1* getScale(Point1*, int, float, float, float, float, float, int, int, int, int);

int getCountX(float, float, float, float);

int getCountY(float, float, float, float);

#endif