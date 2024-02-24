//2023F_CSCI221_VB Computer Science II
//Steve Valles Quiroz
//Project 7

#include <iostream>
#include <string>
#include <regex>

using std::cout;
using std::cin;
using std::string;

string civiTime(string miliTime);

class TimeFormatMistake : public std::exception {
public:
    const char* what() const throw() {
        return "\nError. Wrong time input\n";
    }
};

int main() {
  string miliTime;
  char newTry;
 do {
  cout << "\nEnter time in 24-hour notation: ";
  cin >> miliTime;

  try {
    cout << "\nThat is the same as: " << civiTime(miliTime) << " in civilian time.\n";
  } catch (TimeFormatMistake& wrongTime) {
      cout << wrongTime.what() << std::endl;
  }

  cout << "Again?(y/n): ";
  cin >> newTry;
 } while (newTry == 'y');
 return 0;
}


string civiTime(string miliTime) {
  if (!std::regex_match(miliTime, std::regex("\\d{2}:\\d{2}"))) throw TimeFormatMistake();
  int hour = std::stoi(miliTime.substr(0, 2));
  int minute = std::stoi(miliTime.substr(3, 2));
  if (hour < 0 || hour > 24 || minute < 0 || minute > 59) throw TimeFormatMistake();
  std::string period = hour < 12 ? "AM" : "PM";
  if (hour == 0) hour = 12;
  if (hour > 12) hour -= 12;
  return std::to_string(hour) + ":" + (minute < 10 ? "0" : "") + std::to_string(minute) + " " + period;
}