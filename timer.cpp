#include <iostream>
#include <string>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <sstream>
#include <iomanip>

std::string to_format(const int number)
{
  std::stringstream ss;
  ss << std::setw(2) << std::setfill('0') << number;
  return ss.str();
}

int main()
{
  int h, mm, s;
  std::string err = "start";

  while (err.size() != 0)
  {
    system("clear");
    std::cout << "Enter hours (24h time format): " << std::endl;
    std::cin >> h;

    if (h > 23 || h < 0)
    {
      err = "Hour must be between 0 and 23";
      std::cout << "Error: " << err << std::endl;
      std::cout << "Press any key to restart" << std::endl;
      system("read");
      continue;
    }

    std::cout << "Enter minutes: " << std::endl;
    std::cin >> mm;

    if (mm > 59 || mm < 0)
    {
      err = "Minutes must be between 0 and 59";
      std::cout << "Error: " << err << std::endl;
      std::cout << "Press any key to restart" << std::endl;
      system("read");
      continue;
    }

    std::cout << "Enter seconds: " << std::endl;
    std::cin >> s;

    if (s > 59 || s < 0)
    {
      err = "Seconds must be between 0 and 59";
      std::cout << "Error: " << err << std::endl;
      std::cout << "Press any key to restart" << std::endl;
      system("read");
      continue;
    }

    if (h == 0 && mm == 0 && s == 0)
    {
      err = "Timer must be at least 1 second long";
      std::cout << "Error: " << err << std::endl;
      std::cout << "Press any key to restart" << std::endl;
      system("read");
      continue;
    }
    err = "";
  }

  while (h > 0 || mm > 0 || s > 0)
  {
    system("clear");
    std::cout << "**************" << std::endl;
    std::cout << "*  " << to_format(h) << ":" << to_format(mm) << ":" << to_format(s) << "  *" << std::endl;
    std::cout << "**************" << std::endl;
    fflush(stdout);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    if (s > 0)
    {
      s--;
      continue;
    }

    if (mm > 0 && s == 0)
    {
      mm--;
      s = 59;
      continue;
    }

    if (h > 0 && mm == 0)
    {
      h--;
      mm = 59;
      s = 59;
      continue;
    }
  }
  system("clear");
  std::cout << "DONE!" << std::endl;

  return 0;
}