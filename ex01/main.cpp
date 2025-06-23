#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    std::cout << "=== Test basique du sujet ===" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\n=== Test d'exceptions ===" << std::endl;
    try
    {
        Span smallSpan(2);
        smallSpan.addNumber(1);
        std::cout << "Tentative de calcul de span avec un seul élément:" << std::endl;
        std::cout << smallSpan.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Span fullSpan(2);
        fullSpan.addNumber(1);
        fullSpan.addNumber(2);
        std::cout << "Tentative d'ajout dans un span plein:" << std::endl;
        fullSpan.addNumber(3);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test avec range d'itérateurs ===" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
        vec.push_back(i * 2);

    Span rangeSpan(15);
    rangeSpan.addRange(vec.begin(), vec.end());
    rangeSpan.addNumber(100);
    rangeSpan.addNumber(1);

    std::cout << "Shortest span: " << rangeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << rangeSpan.longestSpan() << std::endl;

    std::cout << "\n=== Test avec 10,000 nombres ===" << std::endl;
    srand(time(NULL));
    Span bigSpan(10000);
    
    for (int i = 0; i < 10000; ++i)
    {
        bigSpan.addNumber(rand() % 100000);
    }

    std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;

    return 0;
} 