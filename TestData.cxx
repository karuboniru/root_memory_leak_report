#include "TestData.h"
#include "a_member.h"

ClassImp(TestData);

TestData::~TestData() { delete sm; }

void TestData::Init() { sm = new a_member(); }

TestData::TestData() { Init(); }

TestData::TestData(const TestData &other) = default;

double TestData::Mag() const { return sm->get().Mag(); }
