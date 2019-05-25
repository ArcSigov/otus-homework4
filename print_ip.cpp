#include <iostream>
#include <vector>
#include <list>
#include <tuple>

#include "print_ip.h"


std::vector<int> _vector{110,111,112,113};
std::list <int > _list{99,98,97,96};
std::string _string {"87.88.89.90"};
const int _int = 2130706433;
const long long _long = 8875824491850138409;
const unsigned short _short = 0;
const char _char = -1;
auto _tuple = std::make_tuple("121","125","255","254");
auto _tuple_bad = std::make_tuple("1",'1',2, 4. );




int main()
{
  ip_printer(_char);
  ip_printer(_short);
  ip_printer(_int);
  ip_printer(_long);
  ip_printer(_string);
  ip_printer(_vector);
  ip_printer(_list);
  ip_printer(_tuple);
  //ip_printer(_tuple_bad);
  return 0;
}
