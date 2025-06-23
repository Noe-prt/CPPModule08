#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << "=== Test MutantStack (comme dans le sujet) ===" << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);

    std::cout << "\n=== Test avec std::list pour comparaison ===" << std::endl;
    std::list<int> lst;
    
    lst.push_back(5);
    lst.push_back(17);
    
    std::cout << lst.back() << std::endl;
    
    lst.pop_back();
    
    std::cout << lst.size() << std::endl;
    
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    
    ++lit;
    --lit;
    
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    std::cout << "\n=== Tests supplémentaires ===" << std::endl;
    MutantStack<int> mstack2;
    
    for (int i = 0; i < 10; ++i)
        mstack2.push(i);
    
    std::cout << "Parcours normal:" << std::endl;
    for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    std::cout << "Parcours inverse:" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack2.rbegin(); rit != mstack2.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;

    std::cout << "Test de copie:" << std::endl;
    MutantStack<int> mstack3(mstack2);
    std::cout << "Taille de la copie: " << mstack3.size() << std::endl;
    std::cout << "Top de la copie: " << mstack3.top() << std::endl;

    return 0;
} 