#include <TFile.h>
#include <TTree.h>
#include <TestData.h>

int main() {
  TFile file("test.root", "READONLY");
  auto tree = file.Get<TTree>("T");
  TestData *data{};
  tree->SetBranchAddress("data", &data);
  for (int i = 0; i < 3; ++i) {
    tree->GetEntry(i);
  }
  file.Close();
  return 0;
}