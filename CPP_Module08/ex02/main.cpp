
#include <iostream>
#include <vector>
#include <list>
#include "MutantStack.hpp"

int main_bis(void)
{
    std::list<int>  list1;

    list1.push_back(5);
	std::cout << "Pushing " << 5 << " in the list\n";
	list1.push_back(17);
	std::cout << "Pushing " << 17 << " in the list\n";
	
	std::cout << list1.back() << " is at the top of the list" << std::endl;
	
	list1.pop_back();
	std::cout << "Poping out the last element\n";
	
	std::cout << "list size: " << list1.size() << std::endl;
	
	list1.push_back(3);
	std::cout << "Pushing " << 3 << " in the list\n";
	list1.push_back(5);
	std::cout << "Pushing " << 5 << " in the list\n";
	list1.push_back(737); 
	std::cout << "Pushing " << 737 << " in the list\n";
	// [...]
	list1.push_back(0);
	std::cout << "Pushing " << 0 << " in the list\n";
	
	std::list<int>::iterator it = list1.begin();
	std::list<int>::iterator ite = list1.end();
	
	++it;
	--it;
	while (it != ite) {
    	std::cout << *it << std::endl;
		++it; 
	}
    return 0;
}

int main(void)
{
	MutantStack<int>	mstack;

	mstack.push(5);
	std::cout << "Pushing " << 5 << " in the stack\n";
	mstack.push(17);
	std::cout << "Pushing " << 17 << " in the stack\n";
	
	std::cout << mstack.top() << " is at the top of the stack" << std::endl;
	
	mstack.pop();
	std::cout << "Poping out the last element\n";
	
	std::cout << "Stack size: " << mstack.size() << std::endl;
	
	mstack.push(3);
	std::cout << "Pushing " << 3 << " in the stack\n";
	mstack.push(5);
	std::cout << "Pushing " << 5 << " in the stack\n";
	mstack.push(737); 
	std::cout << "Pushing " << 737 << " in the stack\n";
	// [...]
	mstack.push(0);
	std::cout << "Pushing " << 0 << " in the stack\n";
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	while (it != ite) {
    	std::cout << *it << std::endl;
		++it; 
	}
	std::stack<int> s(mstack);
    main_bis();
	return 0;
}