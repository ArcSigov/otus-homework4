#include <iostream>
#include <vector>
#include <list>
#include <tuple>

#include "print_ip.h"


std::vector<int> _vector{110,111,112,113};              ///< Целочисленный вектор ip-адреса
std::list <int > _list{99,98,97,96};                    ///< Целочисленный лист ip-адреса
std::string _string {"87.88.89.90"};                    ///< Строка с ip-адресом
const int _int = 2130706433;                            ///< ip-адрес в int представлении
const long long _long = 8875824491850138409;            ///< ip-адрес в long представлении 
const short _short = 0;                                 ///< ip-адрес в short представлении
const char _char = -1;                                  ///< ip-адрес в char представлении
auto _tuple = std::make_tuple("121","125","255","254"); ///< однородный кортеж ip-адреса
#ifdef DEBUG
auto _tuple_bad = std::make_tuple("1",'1',2, 4. );      ///< разнородный кортеж ip-адреса (только для debug версии)
#endif


/*!
  Основная функция
*/
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
#ifdef DEBUG
  ip_printer(_tuple_bad);
#endif
  return 0;
}
