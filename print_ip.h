#pragma once


#include <iostream>
#include <vector>
#include <list>
#include <tuple>
#include <type_traits>


void ip_printer(const std::string &str)
{
    std::cout << str << std::endl;
}

template<typename>
struct container : std::false_type{};

template<typename T, typename ... Args>
struct container<std::vector<T,Args...>>:std::true_type{};

template<typename T, typename ... Args>
struct container<std::list<T,Args...>>:std::true_type{};

template<typename __container>
typename std::enable_if_t<container<__container>::value,void>
ip_printer(const __container& t)
{
    for (auto i = t.cbegin(); i != t.cend(); i++ )
    {
        if (i != t.cbegin())
        {
            std::cout << ".";
        }
        std::cout << *i;
    }
    std::cout << std::endl;
}

template<typename _var_arg>
typename std::enable_if_t<std::is_integral_v<_var_arg>,void>
ip_printer(const _var_arg t)
{

    for (auto i = sizeof(_var_arg);i--;)
    {
            std::cout << ((t >> (i<<3)&0xFF));
            if (i>0)
                std::cout << ".";
    }
     std::cout<< std::endl;
}


template<typename T,typename ...tuple_args>
struct is_valid;

template<typename T,typename U, typename ...tuple_args>
struct is_valid<T,U,tuple_args...>:std::false_type{};

template<typename T,typename ...tuple_args>
struct is_valid<T,T,tuple_args...>:is_valid<T,tuple_args...>{};

template<typename T,typename U>
struct is_valid<T,U>:std::false_type{};

template<typename T>
struct is_valid<T,T>:std::true_type{};

template<typename T>
struct is_valid<T>:std::true_type{};

//!< thank's cxx17 standard
template<typename ...ts>
typename std::enable_if_t<is_valid<ts...>::value,void>
ip_printer(const std::tuple<ts ...> &_tuple)
{
	if constexpr (sizeof... (ts) > 0)
	{
		std::apply ([] (const auto &item, const auto &... items) {
						std::cout << item;
						((std::cout << "." << items), ...,(std::cout << std::endl));
					},
					_tuple);
	}
}

#ifdef DEBUG
template<typename ...ts>
typename std::enable_if_t<is_valid<ts...>::value == false,void>
ip_printer(const std::tuple<ts ...> &_tuple)
{
    std::cout << "tuple types not same" << std::endl;
}
#endif


