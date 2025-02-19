#include<iostream>
#include"List.h"

template<typename T>
void summ(T first) {
	return;
}

template <typename T, typename... Args>
void summ(List<T>* first, List<T>* second, Args... args){
	first->addList(second);
	summ(first, args...);
}

int main() {
	List<int> list;
	list.push(20);
	list.push(3);
	list.push(5);
	list.push(14);
	list.push(35);
	list.print();

	List<int> blank;
	blank.push(14);
	blank.push(45);

	List<int> third;
	third.push(666);
	third.push(777);

	try {
		std::cout<<list.getData(5)<<std::endl;
	}
	catch (const char* error) {
		std::cout << error << std::endl;
	}

	/*std::cout << "fourth element is: " << list.getData(3) << std::endl;
	std::cout << "Last element is: " << list.getData(list.getSize() - 1) << std::endl;*/

	summ(&list, &blank, &third);
	try {
		list.print();
	}
	catch (const char* error) {
		std::cout << error << std::endl;
	}
}