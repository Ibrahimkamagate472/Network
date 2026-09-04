#include <string>
#include <cctype>

std::string lower(std::string string_to_convert_){
  std::string new_string_ = "";
  for(auto& char_ : string_to_convert_){
    new_string_ += std::towlower(char_);
  }
  return new_string_;
}
