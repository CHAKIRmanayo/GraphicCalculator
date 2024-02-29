#include "my_lexems1.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h> 
#include "my_stack1.h"
#include "my_queue1.h"

using namespace System;
using namespace System::Data;

bool testBrackets(char*s) {
	int t = 0;
	if (testInBrcks(s))
		return true;
	if (testInBrcksM(s))
		return true;
	while (*s) {
		if (*s == '(' && *(s + 1) != 0 && (*(s + 1) == ')' || testNmbInBr(s + 1) || findSgn1(*(s + 1))))
			return true;
		if ((findSgn1(*s) && t == 0) || (findSgn(*s) && *(s + 1) == 0))
			return true;
		s++;
		t++;
	}
	return false;
}

bool testInBrcks(char* s) {
	int k = 0;
	while (*s) {
		if (*s == '(')
			k++;
		if (*s == ')')
			k--;
		s++;
	}
	if (k != 0)
		return true;
	return false;
}

bool testInBrcksM(char* s) {
	while (*s) {
		if (*s == '|')
			return true;
		s++;
	}
	return false;
}

bool testNmbInBr(char* s) {
	while (*s != ')' && *s) {
		if (findNmb(*s) || findLtr(*s))
			return false;
		s++;
	}
	return true;
}

int testStr(char* s, char* w, int* i, int* f) {
	int t = -1;
	t=testFind5(s,w,i,f);
	if (t == -1)
		t = testFind1(s, i, f);
	if (t == -1)
		t = testFind2(s, i, f);
	if (t == -1)
		t = testFind3(s, i, f);
	if (t == -1)
		t = testFind4(s, i, f);
	if (t == -1)
		t = findMtp(s, i, f);
	if (t == -1)
		t = testFindHL(s, i, f);
	return t;
}

int testFind1(char* s, int* i, int* f) {
	int t = 0;
	while (*s) {
		if (s == isSin(s) || s == isCos(s)) {
			if ((*(s + 3) != 0 && *(s + 3) != ')') || *(s + 3) == 0) {
				*i = 4; *f = 4; return t;
			}
		}
		if (s == isLn(s) || s == isTg(s)) {
			if ((*(s + 2) != 0 && *(s + 2) != ')') || *(s + 2) == 0) {
				*i = 3; *f = 3; return t;
			}
		}
		if (*s == ' ' || strpS(*s)) {
			*i = 5; *f = 0; return t;
		}
		s++;
		t++;
	}
	return -1;
}

int testFindHL(char* s, int* i, int* f) {
	int t = 0;
	char*r = "QWERTYUIOPASDFGHJKLZXCVBNM";
	char*c = "qwertyuiopasdfghjklzxcvbnm";
	int j = strlen(r);
	while (*s)
	{
		while (*r)
		{
			if (*r == *s) {
				*i = 8;
				*f = 1;
				s = s - t;
				return t;
			}
			r++;
			c++;
		}
		r = r - j;
		c = c - j;
		s++;
		t++;
	}
	s = s - t;
	return -1;
}

int testFind2(char* s, int* i, int* f) {
	int t = 0; int a = strlen(s);
	char*s1 = new char[a];
	strcpy(s1, s);
	while (*s) {

		if (*s == ',') {
			if (t == 0) {
				*i = 7; *f = 2; return t;
			}
			else if ((*(s - 1) == ')') || (*(s - 1) == '(') || findLtr(*(s - 1)) || findSgn(*(s - 1))) {
				*i = 7; *f = 2; return t;
			}
			else if (getDot(s1, t)) {
				*i = 5; *f = 0; return t;
			}
		}
		s++;
		t++;
	}
	return -1;
}

int testFind3(char* s, int* i, int* f) {
	int t = 0;
	while (*s) {

		if ((*s == '.') || ((*s == ',') && (*(s + 1) != 0) && (*(s + 1) == ','))) {
			*i = 5; *f = 1; return t;
		}
		if (findSgn(*s) && *(s + 1) != 0 && findSgn(*(s + 1))) {
			*i = 5; *f = 1; return t;
		}
		s++;
		t++;
	}
	return -1;
}

int testFind4(char* s, int* i, int* f) {
	int t = 0;
	while (*s) {

		if ((*s == '0' && *(s + 1) != 0 && findNmb(*(s + 1)) && t == 0) || (*s == '0' && *(s + 1) != 0 && findNmb(*(s + 1)) && !findNmb(*(s - 1)))) {
			*i = 5; *f = 1; return t;
		}
		s++;
		t++;
	}
	return -1;
}

int testFind5(char* s, char* w, int* i, int* f) {
	int t = 0; int a = strlen(s);
	char*s1 = new char[a];
	strcpy(s1, s);
	while (*s) {

		/*if (*s != *w || strlen(w) == 0) {
			if (*s == '(' && testInBrcks(s1)) {
				*i = 1; *f = 1; return t;
			}
		}*/
		if (*s == '|' && testM(s + 1)) {
			*i = 6; *f = 4; return t;
		}
		s++; w++;
		t++;
	}
	return -1;
}

bool testM(char* s) {
	while (*s) {
		if (*s == '|')
			return true;
		s++;
	}
	return false;
}

bool getDot(char* s, int t) {
	for (int i = t - 1; i > 0; i--) {
		if (!findNmb(s[i]) && s[i] != ',')
			break;
		if (s[i] == ',')
			return true;
	}
	return false;
}

char* corrDot(char* s, int n) {
	int t = 0;
	int a = strlen(s);
	char* s1 = new char[a + 1];
	while (*s) {
		if (t == n) {
			*s1 = '0';
			s1++;
		}
		*s1 = *s;
		s++; s1++; t++;
	}
	*s1 = 0;
	return s1 - t - 1;
}

char* corrStr(char* s, int n, int i) {
	if (i == 1)
		return corrStr1(s, n);
	if (i == 3)
		return corrStr3(s, n, 2);
	if (i == 4)
		return corrStr3(s, n, 3);
	if (i == 2)
		return corrMtp(s, n);
	if (i == 5)
		return corrSps(s, n);
	if (i == 7)
		return corrDot(s, n);
	if (i == 6)
		return corrAbs(s, n);
	if (i == 8)
		return corrHL(s, n);
}

char* isSin(char* s) {
	if (strstr(s, "sin("))
		return NULL;
	if (strstr(s, "sin"))
		return strstr(s, "sin");
	return NULL;
}

char* isCos(char* s) {
	if (strstr(s, "cos("))
		return NULL;
	if (strstr(s, "cos"))
		return strstr(s, "cos");
	return NULL;
}

char* isLn(char* s) {
	if (strstr(s, "ln("))
		return NULL;
	if (strstr(s, "ln"))
		return strstr(s, "ln");
	return NULL;
}

char* isTg(char* s) {
	if (strstr(s, "tg("))
		return NULL;
	if (strstr(s, "tg"))
		return strstr(s, "tg");
	return NULL;
}

bool strpS(char dest) {
	char* s = "!@#$%^&_¹;:?~<>";
	while (*s)
	{
		if (*s == dest)
			return true;
		s++;
	}
	return false;
}

bool isCurr(int n) {
	if (n == -1)
		return false;
	return true;
}

int corrBrackets(char* s) {
	int k = 0;
	int t = 0, m;
	while (*s) {

		if (*s == '(') {
			m = t;
			k++;
		}
		if (*s == ')')
			k--;
		s++;
		t++;
	}
	if (k == 1)
		return m;
	return -1;
}

char* corrStr1(char* s, int n) {
	int t = 0; int b = 0;
	int a = strlen(s);
	char* s1 = new char[a + 1];
	while (*s) {
		if (t == n + 1) {
			*s1 = ')'; s1++;
			b++;
		}
		*s1 = *s;
		s++; s1++; t++;
	}
	if (b == 0) {
		*s1 = ')'; s1++;
	}
	*s1 = 0;
	return s1 - a - 1;
}

char* corrHL(char* s, int n) {
	char*r = "QWERTYUIOPASDFGHJKLZXCVBNM";
	char*c = "qwertyuiopasdfghjklzxcvbnm";
	int i = strlen(r); int t = strlen(s);
	while (*s)
	{
		while (*r)
		{
			if (*r == *s)
				*s = *c;
			r++;
			c++;
		}
		r = r - i;
		c = c - i;
		s++;
	}
	return s - t;
}

char* corrAbs(char* s, int n) {
	int t = 0; int b = 0;
	int a = strlen(s);
	char* s1 = new char[a + 3];
	while (*s) {
		if (t == n) {
			s1 = s1 - t;
			s1 = strAbs(s1, "abs(", t);
			s1 += t + 4;
			b++; s++;
		}
		if (*s == '|' && b != 0) {
			*s1 = ')';
			s1++; s++;
			if (*s == 0)
				break;
		}
		*s1 = *s;
		s++; s1++; t++;
	}
	*s1 = 0;
	return s1 - a - 3;
}

char* strAbs(char* s1, char* s2, int t) {
	s1 += t;
	while (*s2) {
		*s1 = *s2;
		s1++;
		s2++;
	}
	return s1 - t - 4;
}

char* corrStr3(char* s, int n, int m) {
	int b = 0;
	int t = 0;
	int a = strlen(s);
	char* s1 = new char[a + 2];
	while (*s) {
		if (t - m == n) {
			*s1 = '('; s1++;
			*s1 = ')'; s1++;
			b++;
		}
		*s1 = *s;
		s++; s1++; t++;
	}
	if (b == 0) {
		*s1 = '('; s1++;
		*s1 = ')'; s1++;
	}
	*s1 = 0;
	return s1 - t - 2;
}

int findMtp(char* s, int* i, int* f) {
	int t = -1;
	*i = 2;
	t = testMtp1(s, f);
	if (t == -1)
		t = testMtp2(s, f);
	return t;
}

int testMtp1(char* s, int* f) {
	int t = 0; int a = strlen(s);
	char*s1 = new char[a];
	strcpy(s1, s); *f = 3;
	while (*(s + 1)) {

		if (*s == ')' && *(s + 1) == '(')
			return t;
		if ((*s == ')') && findNmb(*(s + 1))) {
			if (*(s + 2) != 0 && *(s + 2) == ',')
				*f = 4;
			return t;
		}
		if (*(s + 1) == '(' && findNmb(*s)) {
			if (*(s - 1) == ',')
				*f = 1;
			return t;
		}
		if (*(s + 1) == '(' && *s == ',') {
			*f = 1; return t;
		}
		s++;
		t++;
	}
	*f = 0;
	return -1;
}

int testMtp2(char* s, int* f) {
	int t = 0; *f = 3;
	int a = strlen(s);
	char*s1 = new char[a];
	strcpy(s1, s);
	while (*(s + 1)) {
		if ((findNmb(*s) || *s == ')') && Funcs(s + 1)) {
			*f = 1; return t;
		}
		if ((findNmb(*s) || *s == ')') && findLtr(*(s + 1)))
			return t;
		if ((findNmb(*(s + 1)) || *(s + 1) == '(') && findLtr(*s) && findFunc(s1, t))
			return t;
		if (findLtr(*s) && Funcs(s + 1)) {
			*f = 1; return t;
		}
		s++;
		t++;
	}
	*f = 0;
	return -1;
}

bool findFunc(char* s, int t) {
	if (strlen(s) > 2) {
		if (s + t - 1 == strstr(s + t - 1, "tg") || s + t - 1 == strstr(s + t - 1, "ln"))
			return false;
		if (s + t - 2 == strstr(s + t - 2, "sin") || s + t - 2 == strstr(s + t - 2, "cos") || s + t - 2 == strstr(s + t - 2, "abs"))
			return false;
	}
	return true;
}

char* corrMtp(char* s, int n) {
	int t = 0;
	int a = strlen(s);
	char* s1 = new char[a + 1];
	while (*s) {
		if (t - 1 == n) {
			*s1 = '*';
			s1++;
		}
		*s1 = *s;
		s++; s1++; t++;
	}
	*s1 = 0;
	return s1 - a - 1;
}

char* corrSps(char* s, int n) {
	int t = 0;
	int a = strlen(s);
	char* s1 = new char[a];
	while (*s) {
		if (t == n) {
			if (*s == '.') {
				*s1 = ','; s1++; t++;
			}
			s++;
		}
		*s1 = *s;
		s++; s1++; t++;
	}
	*s1 = 0;
	return s1 - t;
}

bool findNmb(char c) {
	char*nmbs = "0123456789";
	if (strchr(nmbs, c))
		return true;
	return false;
}

bool findLtr(char c) {
	char*nmbs = "qwertyuiopasdfghjklzxcvbnm";
	if (strchr(nmbs, c))
		return true;
	return false;
}

bool findSgn(char c) {
	char*nmbs = "*+/-";
	if (strchr(nmbs, c))
		return true;
	return false;
}

bool findSgn1(char c) {
	char*nmbs = "*+/";
	if (strchr(nmbs, c))
		return true;
	return false;
}

bool Funcs(char* s) {
	if (s == strstr(s, "tg") || s == strstr(s, "ln") || s == strstr(s, "sin") || s == strstr(s, "cos") || s == strstr(s, "abs"))
		return true;
	return false;
}

MyQueue sepLexem1(char* s, int* w) {
	int n;
	int b = 0;
	int t = 1;
	MyQueue q = initMyQueue();
	while (*s) {
		b = 0;
		if (*s == '(' && *s != 0) {
			pushBackStr(q, "(");
			s++; b++;
			t = 1;
		}
		if (*s == ')' && *s != 0) {
			pushBackStr(q, ")");
			s++; b++;
			t = 0;
		}
		if (findNmb(*s) && *s != 0) {
			n = getNmb(s, q);
			s += n; b++;
			t = 0;
		}
		if (findSgn(*s) && *s != 0) {
			pushSgnL(q, *s, t);
			s++; b++;
			t = 0;
		}
		if (findLtr(*s) && *s != 0) {
			n = getLtr(s, q);
			s += n;
			t = 0; b++;
		}
		if ((*s == '.' || *s == ',') && *(s + 1) == 0) {
			*w = 1;
			s++;
		}
	}
	return q;
}

void pushSgnL(MyQueue& q, char c, int t) {
	char*s1 = new char[2];
	s1[0] = c;
	s1[1] = 0;
	if (c == '-' && t == 1) {
		pushBackStr(q, "0");
		pushBackStr(q, "-");
	}
	else
		pushBackStr(q, s1);
}

int getNmb(char* s, MyQueue& q) {
	int k = 0;
	char*s1 = new char[k];
	while ((findNmb(*s) || *s == ',') && *s) {
		s1 = pushStr(s1);
		s1[k] = *s;
		s++;
		k++;
	}
	s1[k] = 0;
	pushBackStr(q, s1);
	return k;
}

int getLtr(char* s, MyQueue& q) {
	int k = 0;
	char*s1 = new char[k];
	while (findLtr(*s) && *s) {
		s1 = pushStr(s1);
		s1[k] = *s;
		s++;
		k++;
	}
	s1[k] = 0;
	pushBackStr(q, s1);
	return k;
}

char* pushStr(char* s) {
	char* s1 = new char[strlen(s) + 1];
	strcpy(s1, s);
	delete s;
	return s1;
}

MyQueue reRecord(MyQueue q) {
	Stack<char*> st = initStack<char*>();
	MyQueue newQ = initMyQueue();
	Iterator i = begin(q);
	while (hasCurrent(i)) {

		char* s1 = get(i);
		if (findNmb(*s1))
			pushBackStr(newQ, s1);
		else if (*s1 == '(')
			push(st, s1);
		else if (*s1 == ')')
			pushFromSt(newQ, st, s1);
		else if (findSgn(*s1) || Funcs(s1))
			pushSgn(st, s1, newQ);
		else
			pushBackStr(newQ, s1);
		moveNext(i);
	}
	if (!isEmptyS<char*>(st))
		pushFromStFin(newQ, st);
	return newQ;
}

void pushFromSt(MyQueue& q, Stack<char*>& st, char* s) {
	char*s1 = new char[3];
	int pr = getPrior(s);
	while (!isEmptyS<char*>(st) && (pr <= getPrior(peekS<char*>(st))) && (*(peekS<char*>(st)) != '(')) {
		pop<char*>(st, s1);
		pushBackStr(q, s1);
	}
	if (!isEmptyS<char*>(st) && *(peekS<char*>(st)) == '(') {
		pop<char*>(st, s1);
		if (!isEmptyS<char*>(st) && Funcs(peekS<char*>(st))) {
			pop<char*>(st, s1);
			pushBackStr(q, s1);
		}
	}
}

void pushSgn(Stack<char*>& st, char* s, MyQueue& q) {
	if (isEmptyS<char*>(st) || (getPrior(peekS<char*>(st)) < getPrior(s)))
		push<char*>(st, s);
	else {
		pushFromSt(q, st, s);
		push<char*>(st, s);
	}
}

int getPrior(char* s) {
	if (*s == '*' || *s == '/')
		return 2;
	else if (*s == '+' || *s == '-')
		return 1;
	else if (Funcs(s))
		return 3;
	else if (*s == '(')
		return 0;
	else if (*s == ')')
		return 0;
}

void pushFromStFin(MyQueue& q, Stack<char*>& st) {
	char*s1 = new char[3];
	while (!isEmptyS<char*>(st)) {
		pop<char*>(st, s1);
		if (s1 != "(") {
			pushBackStr(q, s1);
		}
	}
}

float getFunc(Stack<float>& st, char* s) {
	float t1;
	pop<float>(st, t1);
	if (strcmp(s, "tg") == 0)
		t1 = Math::Tan(t1);

	if (strcmp(s, "cos") == 0)
		t1 = Math::Cos(t1);

	if (strcmp(s, "sin") == 0)
		t1 = Math::Sin(t1);

	if (strcmp(s, "ln") == 0)
		t1 = Math::Log(t1);

	if (strcmp(s, "abs") == 0)
		t1 = Math::Abs(t1);

	return t1;
}

float getSgn(Stack<float>& st, char c) {
	float t1, t2;
	pop<float>(st, t1);
	pop<float>(st, t2);
	if (c == '+')
		t1 = (t1 + t2);

	if (c == '-')
		t1 = (t2 - t1);

	if (c == '/')
		t1 = (t2 / t1);

	if (c == '*')
		t1 = (t2*t1);
	return t1;
}

Point1* getPoints(double tMax, double tMin, double step, MyQueue q, int* i, float* yMin, float* yMax) {
	int t = int(fabs(tMax - tMin) / step) + 1;
	int len = 0;
	*i = t;
	Point1* points = new Point1[t];
	for (int i = 0; i < t; i++) {

		if (fabs(calcul(q, tMin + i * step)) < 100) {
			len++;
			points->x = tMin + i * step;
			points->y = calcul(q, points->x);
			if (i == 0) {
				*yMin = points->y;
				*yMax = *yMin;
			}
			if (points->y > *yMax)
				*yMax = points->y;
			if (points->y < *yMin)
				*yMin = points->y;
			points++;
		}
	}
	*i = len;
	points = points - len;
	return points;
}

Point1* getScale(Point1* points, int t, float scaleX, float scaleY, float yMax, float xMin, float step, int countX, int countY, int W, int H) {
	Point1* points1 = new Point1[t];
	for (int i = 0; i < t; i++) {
		if (countX == 1)
			points1->x = scaleX * (-xMin + points->x) + 50;
		else if (countX == 2)
			points1->x = scaleX * (-xMin + points->x) + 25;
		if (countY == 3)
			points1->y = H / 2;
		else if (countY == 1)
			points1->y = scaleY * (yMax - points->y) + 50;
		else if (countY == 2)
			points1->y = scaleY * (yMax - points->y) + 50;
		points1++;
		points++;
	}
	points1 = points1 - t;
	points = points - t;
	return points1;
}

int getCountX(float xMin, float xMax, float yMin, float yMax) {
	if ((xMax <= 0 && xMin < 0) || (xMax > 0 && xMin >= 0))
		return 1;
	if (xMax > 0 && xMin < 0)
		return 2;
}

int getCountY(float xMin, float xMax, float yMin, float yMax) {
	if ((yMax >= 0 && yMin >= 0) || (yMax <= 0 && yMin <= 0))
		if (yMax == yMin)
			return 3;
	return 1;
	if (yMax > 0 && yMin < 0)
		return 2;
}

float calcul(MyQueue q, double x) {
	Stack<float> st = initStack<float>();
	Iterator i = begin(q);
	float f;
	while (hasCurrent(i)) {
		double d;
		if (Double::TryParse(gcnew String(get(i)), d))
			push<float>(st, d);
		else if (Funcs(get(i)))
			push<float>(st, getFunc(st, get(i)));
		else if (findSgn(*(get(i))))
			push<float>(st, getSgn(st, *(get(i))));
		else
			push<float>(st, x);
		moveNext(i);
	}
	pop<float>(st, f);
	return f;
}