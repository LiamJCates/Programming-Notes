### Chunking Separators
C++14 adds support for chunking separators, a single quotation mark:

  int moneyInBank = -70'000; // -70000
  long populationChange = -85'000; // -85000
  long long countryGDPChange = -70'000'000'000; //
  -70 billion
  double pi = 3.141'592'653'59; // 3.14159265359

Integer and Floating Point literals can contain any number of single quotes (') for readability.  These are completely ignored by the compiler.
