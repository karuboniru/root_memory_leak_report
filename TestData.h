#pragma once

#include "Rtypes.h"
#include <ROOT/RVec.hxx>
#include <TLorentzVector.h>
#include <TObject.h>

class a_member;

class TestData : public TObject {
public:
  TestData();
  TestData(const TestData &);
  ~TestData() override;

  [[nodiscard]] double Mag() const;

private:
  void Init();
  a_member *sm;

  ClassDefOverride(TestData, 2)
};
