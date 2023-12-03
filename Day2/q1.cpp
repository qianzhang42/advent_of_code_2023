#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <unordered_map>

bool isvaliddraw(const std::string &s, int begin, int end)
{
  int end_pos = s.find(",", begin);
  while (end_pos != -1 && end_pos < end)
  {
    int space_pos = s.find(" ", begin + 1);
    int count = std::stoi(s.substr(begin + 1, space_pos - begin - 1));
    std::string color = s.substr(space_pos + 1, end_pos - 1 - space_pos);
    std::cout << count << std::endl;
    std::cout << color << std::endl;
    std::cout << space_pos + 1 << "|" << end_pos - 1 - space_pos << "|" << std::endl;
    if (color != "red" && color != "green" && color != "blue")
    {
      return false;
    }
    if (color == "red" && count > 12)
    {
      return false;
    }
    if (color == "green" && count > 13)
    {
      return false;
    }
    if (color == "blue" && count > 14)
    {
      return false;
    }
    begin = end_pos + 1;
    end_pos = s.find(",", begin);
  }
  // process last color
  int space_pos = s.find(" ", begin + 1);
  int count = std::stoi(s.substr(begin + 1, space_pos - begin - 1));
  std::string color = s.substr(space_pos + 1, end - 1 - space_pos);
  std::cout << count << std::endl;
  std::cout << color << std::endl;
  if (color != "red" && color != "green" && color != "blue")
  {
    return false;
  }
  if (color == "red" && count > 12)
  {
    return false;
  }
  if (color == "green" && count > 13)
  {
    return false;
  }
  if (color == "blue" && count > 14)
  {
    return false;
  }

  return true;
}

bool isvalidgame(const std::string &s)
{
  int begin_pos = s.find(":") + 1;
  while (s.find(";", begin_pos) != -1)
  {
    int end_pos = s.find(";", begin_pos);
    std::cout << "isvalidgame" << s.substr(begin_pos, end_pos - begin_pos);
    std::cout << std::endl;
    if (!isvaliddraw(s, begin_pos, end_pos))
    {
      return false;
    }
    begin_pos = end_pos + 1;
  }
  // process last draw
  std::cout << "isvalidgame" << s.substr(begin_pos, s.size() - begin_pos);
  std::cout << std::endl;
  return isvaliddraw(s, begin_pos, s.size());
}

int getid(const std::string &s)
{
  int begin_pos = s.find(" ") + 1;
  int end_pos = s.find(":");
  return std::stoi(s.substr(begin_pos, end_pos - begin_pos));
}

int sumup(std::ifstream &f)
{
  int res = 0;
  std::string line;
  while (std::getline(f, line))
  {
    std::cout << line << std::endl;
    if (isvalidgame(line))
    {
      std::cout << "getid" << getid(line) << std::endl;
      res += getid(line);
    }
  }
  return res;
}

int main()
{
  std::ifstream myfile;
  myfile.open("day2_input.txt");
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