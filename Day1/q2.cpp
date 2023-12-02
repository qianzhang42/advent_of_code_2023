#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>

static std::vector<std::string> valid_digits{"1", "2", "3", "4", "5", "6", "7", "8", "9", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int convert(const std::string &digit)
{
  if (digit.size() == 1)
  {
    return std::stoi(digit);
  }
  else
  {
    if (digit == "zero")
    {
      return 0;
    }
    else if (digit == "one")
    {
      return 1;
    }
    else if (digit == "two")
    {
      return 2;
    }
    else if (digit == "three")
    {
      return 3;
    }
    else if (digit == "four")
    {
      return 4;
    }
    else if (digit == "five")
    {
      return 5;
    }
    else if (digit == "six")
    {
      return 6;
    }
    else if (digit == "seven")
    {
      return 7;
    }
    else if (digit == "eight")
    {
      return 8;
    }
    else if (digit == "nine")
    {
      return 9;
    }
    else
    {
      throw std::runtime_error("non valid digit");
    }
  }
}

int getnumber(const std::string &line)
{
  int first_pos = line.size();
  std::string first_digit;
  // find first valid digit (word or digit)
  for (auto d : valid_digits)
  {
    int curr_pos = line.find(d);
    // not found will return -1. thus need to check `curr_pos` is greater than -1.
    if (curr_pos != std::string::npos && curr_pos < first_pos)
    {
      first_pos = curr_pos;
      first_digit = d;
      // std::cout << first_pos << ", " << first_digit << std::endl;
    }
  }
  // find last valid digit (word or digit)
  int last_pos = -1;
  std::string last_digit;
  for (auto d : valid_digits)
  {
    int curr_pos = line.rfind(d);
    if (curr_pos != std::string::npos && curr_pos > last_pos)
    {
      last_pos = curr_pos;
      last_digit = d;
    }
  }
  // std::cout << "=========" << std::endl;
  // std::cout << first_digit << "," << last_digit << std::endl;
  return convert(first_digit) * 10 + convert(last_digit);
}

int sumup(std::ifstream &f)
{
  int res = 0;
  std::string line;
  while (std::getline(f, line))
  {
    res += getnumber(line);
  }
  return res;
}

int main()
{
  std::ifstream myfile;
  myfile.open("day1_input.txt");
  int res = -1;
  if (myfile.is_open())
  {
    std::cout << "open successfully." << std::endl;
    res = sumup(myfile);
  }
  std::cout << "result is " << res << std::endl;
  myfile.close();
  std::cout << "close successfully." << std::endl;
  return 0;
}