#pragma once


#include <TLorentzVector.h>

class a_member : public TObject {
public:
  TLorentzVector *prt;
  a_member();
  ~a_member() override;

  [[nodiscard]] const TLorentzVector& get() const;

private:
  ClassDefOverride(a_member, 1)
};
