#ifndef testFramework_h
#define testFramework_h

typedef struct testCase testCase;

testCase* createRequestTestSuite (int* size); 
testCase* createtechnicianTestSuite (int* size);

void compareInt (testCase t, int actual);
void compareChar (testCase t, char actual);

testCase getTest(testCase* suite, int index);

void freeTestSuite(testCase* suite);

#endif