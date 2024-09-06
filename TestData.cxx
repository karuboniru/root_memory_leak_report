#include "TestData.h"
#include "a_member.h"

#include <TBuffer.h>

ClassImp(TestData);

TestData::~TestData() { delete sm; }

void TestData::Init() { sm = new a_member(); }

TestData::TestData() { Init(); }

TestData::TestData(const TestData &other) = default;

double TestData::Mag() const { return sm->get().Mag(); }

//______________________________________________________________________________
void TestData::Streamer(TBuffer &R__b)
{
   // Stream an object of class TestData.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> sm;
      R__b.CheckByteCount(R__s, R__c, TestData::IsA());
   } else {
      R__c = R__b.WriteVersion(TestData::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << sm;
      R__b.SetByteCount(R__c, kTRUE);
   }
}
