#include "a_member.h"
#include <iostream>

ClassImp(a_member);

a_member::~a_member() {
  delete prt;
  std::cout << "a_member::~a_member() at " << this << std::endl;
}

a_member::a_member() {
  prt = new TLorentzVector();
  std::cout << "a_member::a_member()  at " << this << std::endl;
}

const TLorentzVector &a_member::get() const { return *prt; }