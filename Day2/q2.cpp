#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

void update_max(const std::string &s, int begin, int end, long &mr, long &mg, long &mb)
{
  int end_pos = s.find(",", begin);
  while (end_pos != -1 && end_pos < end)
  {
    int space_pos = s.find(" ", begin + 1);
    int count = std::stoi(s.substr(begin + 1, space_pos - begin - 1));
    std::string color = s.substr(space_pos + 1, end_pos - 1 - space_pos);
    std::cout << count << std::endl;
    std::cout << color << std::endl;
    // std::cout << space_pos + 1 << "|" << end_pos - 1 - space_pos << "|" << std::endl;
    if (color == "red" && mr < count)
    {
      mr = count;
    }
    if (color == "green" && mg < count)
    {
      mg = count;
    }
    if (color == "blue" && mb < count)
    {
      mb = count;
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
  if (color == "red" && mr < count)
  {
    mr = count;
  }
  if (color == "green" && mg < count)
  {
    mg = count;
  }
  if (color == "blue" && mb < count)
  {
    mb = count;
  }
}

long getpowergame(const std::string &s)
{
  long max_red = 0;
  long max_green = 0;
  long max_blue = 0;

  int begin_pos = s.find(":") + 1;
  while (s.find(";", begin_pos) != -1)
  {
    int end_pos = s.find(";", begin_pos);
    // std::cout << "isvalidgame" << s.substr(begin_pos, end_pos - begin_pos);
    // std::cout << std::endl;
    //  update max red green blue
    update_max(s, begin_pos, end_pos, max_red, max_green, max_blue);
    begin_pos = end_pos + 1;
  }
  // process last draw
  // std::cout << "isvalidgame" << s.substr(begin_pos, s.size() - begin_pos);
  // std::cout << std::endl;
  update_max(s, begin_pos, s.size(), max_red, max_green, max_blue);
  std::cout << "r, g, b : " << max_red << ", " << max_green << ", " << max_blue << std::endl;
  return max_red * max_green * max_blue;
}

long sumup(std::ifstream &f)
{
  long res = 0;
  std::string line;
  while (std::getline(f, line))
  {
    // std::cout << getpowergame(line) << std::endl;
    res += getpowergame(line);
  }
  return res;
}

int main()
{
  std::ifstream myfile;
  myfile.open("day2_input.txt");
  long res = -1;
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