#include <TFile.h>
#include <TTree.h>
#include <TestData.h>

int main() {
  TFile file("test.root", "RECREATE");
  TTree tree("T", "T");
  TestData data{};
  tree.Branch("data", &data);
  for (int i = 0; i < 3; ++i) {
    tree.Fill();
  }
  file.Write();
  file.Close();
  return 0;
}