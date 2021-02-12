/*
Implement a function which convert the given boolean value into its string representation.
*/


std::string boolean_to_string(bool b){
  return b ? "true" : "false";
}

// Remember that the boolean true value implicitly casts to the integer value 1
std::string boolean_to_string(bool b){
  return (b == 1) ? "true": "false";
}
