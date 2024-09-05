#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

// the missing "+" in TestData is 
// the key to the problem
#pragma link C++ class TestData;
#pragma link C++ class a_member+;

#endif
