#include <string>
#include "exercise3.hpp"

std::vector<std::string> split_by(const char c, const std::string& str)
{
      std::vector<std::string> out = {};
      std::string tmp = "";
      auto pos = 0;
      while(str[pos] != 0) {
          if(str[pos] != c) {
              tmp += str[pos];
          } else {
              out.push_back(std::string(tmp));
              tmp = "";
          }
          pos++;
      }
      if(tmp != "") {
        out.push_back(std::string(tmp));
      }
      return out;
}
// Requirements:
//   -- Given a string containing elements separated by commas, return a
//      vector of strings containing each element
// For example
//    split("a,b,c") -> vector<string>("a", "b", "c");
std::vector<std::string> split(const std::string& str)
{
    return split_by(',', str);
}

// An element which is enclosed in double quotes should be treated as a single element,
// even if it contains a comma. For example,
//
//  ""a, b",c,d" contains three elements
//
// Requirements:
//   -- Split the given string into its component elements, treating quoted
//      elements as a single unit
std::vector<std::string> quoted_split(const std::string& str)
{
    std::vector<std::string> out = {};
    std::string tmp = "";
    auto pos = 0;
    auto in_dblquotes = false;
    while(str[pos] != 0) {
        if(str[pos] == '"') {
          in_dblquotes = !in_dblquotes;
        } else if((str[pos] != ',') || in_dblquotes) {
            tmp += str[pos];
        } else {
            out.push_back(std::string(tmp));
            tmp = "";
        }
        pos++;
    }
    if(tmp != "") {
      out.push_back(std::string(tmp));
    }
    return out;
}

// A CSV file consists of multiple lines, each of which should be split
// according to the above rules. Given an input stream istream, return
// a `csv_file` containing each line of the input, split correctly
csv_file parse_csv(std::istream& istream)
{
    std::string line = "";
    csv_file out = {};
    while(std::getline(istream, line)) {
        out.lines.push_back(quoted_split(line));
    }
    return out;
}
