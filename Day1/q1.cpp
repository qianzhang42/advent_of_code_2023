#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

int getnumber(const std::string &line)
{
  int tmp = 0;
  int res = 0;
  int cnt = 0;
  for (auto c : line)
  {
    if (std::isdigit(static_cast<unsigned char>(c)))
    {
      tmp = tmp * 10 + (c - '0');
      cnt++;
    }
  }
  if (cnt == 1)
  {
    res = tmp * 10 + tmp;
  }
  else
  {
    int last = tmp % 10;
    while (tmp >= 10)
    {
      tmp /= 10;
    }
    res = tmp * 10 + last;
  }
  return res;
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