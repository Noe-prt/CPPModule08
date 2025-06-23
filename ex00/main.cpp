#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
    std::cout << "=== Test avec std::vector ===" << std::endl;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Trouvé: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Trouvé: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test avec std::list ===" << std::endl;
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Trouvé: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    try
    {
        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "Trouvé: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }
    return 0;
} 