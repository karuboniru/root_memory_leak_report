#include <ROOT/RDF/InterfaceUtils.hxx>
#include <ROOT/RDF/RInterface.hxx>
#include <ROOT/RDFHelpers.hxx>
#include <ROOT/RDataFrame.hxx>


#include <TestData.h>

int main() {
  ROOT::RDataFrame rdf("T", "test.root");
  auto mag = rdf.Define("mag", [](const TestData &data) { return data.Mag(); },
                        {"data"})
                 .Mean("mag");
  *mag;
  return 0;
}
