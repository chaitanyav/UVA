#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <cctype>

std::string integerToString(int n) {
  std::ostringstream stream;
  stream << n;
  return stream.str();
}

int stringToInteger(std::string str) {
  std::istringstream stream(str);
  int value;
  stream >> value >> std::ws;
  if(stream.fail() || !stream.eof()) {
    throw std::invalid_argument("Illegal integer format for (" + str + " )");
  }

  return value;
}

std::string realToString(double value) {
  std::ostringstream stream;
  stream << std::uppercase << value;
  return stream.str();
}

double stringToReal(std::string str) {
  std::istringstream stream(str);
  double value;
  stream >> value >> std::ws;
  if(stream.fail() || !stream.eof()){
    throw std::invalid_argument("Illegal real format for (" + str + " )");
  }

  return value;
}

std::string toUpperCase(std::string str) {
  int len = (int) str.length();
  for(int i = 0; i < len; i++) {
    str[i] = toupper(str[i]);
  }
 return str;
}

std::string toLowerCase(std::string str) {
  int len = (int) str.length();
  for(int i = 0; i < len; i++) {
    str[i] = tolower(str[i]);
  }
 return str;
}

bool equalsIgnoreCase(std::string s1, std::string s2) {
  if(s1.length() != s2.length()) {
    return false;
  } else {
   int nChars = (int) s1.length();
   for(int i = 0; i < nChars; i++) {
     if(tolower(s1[i]) != tolower(s2[i])) {
       return false;
     }
   }
  }

  return true;
}

bool startsWith(std::string str, std::string prefix) {
  if(str.length() < prefix.length()) {
    return false;
  }
  int nChars = (int) prefix.length();
  for(int i = 0; i < nChars; i++) {
    if(str[i] != prefix[i]) {
      return false;
    }
  }

  return true;
}

bool endsWith(std::string str, std::string suffix) {
  int nChars = (int) suffix.length();
  int start = (int)str.length() - nChars;
  if(start < 0) return false;
  for(int i = 0; i < nChars; i++) {
    if(str[start + i] != suffix[i]) {
      return false;
    }
  }

  return true;
}

bool endsWith(std::string str, char suffix) {
  int nChars = (int) str.length();
  return (nChars > 0) && str[nChars - 1] == suffix;
}

std::string trim(std::string str) {
  int finish = (int) str.length() - 1;
  while(finish >= 0 && isspace(str[finish])) {
    finish--;
  }

  int start = 0;
  while(start <= finish && isspace(str[start])) {
    start++;
  }
  return str.substr(start, finish - start + 1);
}

int main(int argc, char *argv[]) {
  assert(stringToInteger("10    ") == 10);
  assert(stringToInteger("10") == 10);
  assert(stringToInteger("-9") == -9);
  assert((integerToString(10)).compare("10") == 0);
  assert((integerToString(1)).compare("1") == 0);
  assert((integerToString(99999)).compare("99999") == 0);
  assert((integerToString(-99999)).compare("-99999") == 0);
  assert((realToString(1e10)).compare("1E+10") == 0);

  assert((realToString(1)).compare("1") == 0);
  assert(stringToReal("1e10") == 1e10);
  assert(stringToReal("1.1") == 1.1);
  assert((toUpperCase("foo").compare("FOO") == 0));
  assert((toLowerCase("FOO").compare("foo") == 0));
  assert(equalsIgnoreCase("foo", "foo"));
  assert(equalsIgnoreCase("foo", "FOO"));
  assert(equalsIgnoreCase("foo", "foO"));
  assert(equalsIgnoreCase("for", "foO") == false);
  assert(equalsIgnoreCase("foo", "fo") == false);
  assert(startsWith("foo", "fo"));
  assert(startsWith("foo", "bar") == false);
  assert(startsWith("foo", "bars") == false);
  assert(endsWith("foo", "o"));
  assert(endsWith("foo", "bar") == false);
  assert(endsWith("foo", "goobar") == false);
  assert(endsWith("foo", 'o'));
  assert(endsWith("foo", 'b') == false);
  assert((trim("foo   ")).compare("foo") == 0);
  assert((trim("   foo   ")).compare("foo") == 0);
  assert((trim("    foo")).compare("foo") == 0);
  assert((trim("foo")).compare("foo") == 0);
  return 0;
}
