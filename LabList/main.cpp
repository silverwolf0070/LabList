#include<iostream>
#include<limits>
#include"List.h"
#include "main.h"
#include "sstream"



static void inputInt(int* var) {
	while (!(std::cin >> *var).good())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Should input digit" << std::endl;
	}
}

template<typename T>
void summ(List<T>* first) {
	return;
}


//Рекусивная функция для склеивания списков
template <typename T, typename... Args>
void summ(List<T>* first, List<T>* second, Args... args){
	first->addList(second);
	summ(first, args...);
}

int main() {
	//List<int> list;
	//list.push(20);
	//list.push(3);
	//list.push(5);
	//list.push(14);
	//list.push(35);
	//list.print();

	//List<int> blank;
	//blank.push(14);
	//blank.push(45);

	//List<int> third;
	//third.push(666);
	//third.push(777);

	//try {
	//	std::cout<<list.getData(5)<<std::endl;
	//}
	//catch (const char* error) {
	//	std::cout << error << std::endl;
	//}

	///*std::cout << "fourth element is: " << list.getData(3) << std::endl;
	//std::cout << "Last element is: " << list.getData(list.getSize() - 1) << std::endl;*/

	//summ(&list, &blank, &third);
	//try {
	//	list.print();
	//}
	//catch (const char* error) {
	//	std::cout << error << std::endl;
//}

	List<List<int>*> list;

	int key = NULL;


	bool work = true;

	while (work) {
		std::cout << "1- make new int List, 2-Show all int lists, 3-Paste togeher lists, 4-exit" << std::endl;
		inputInt(&key);
		switch (key) {
		case 1: {
			List<int>* temp = new List<int>;
			int count = 0;
			std::cout << "Input count elements of this list: ";
			inputInt(&count);
			for (int i = 0; i < count; i++) {
				int input = 0;
				inputInt(&input);
				temp->push(input);
			}
			list.push(temp);
			std::cout << "Your list is:" << std::endl;
			std::cout << *temp << std::endl;;
			break;
		}
			  
		case 2: {
			if (list.getSize() == 0) {
				std::cout << "List is empty" << std::endl;
				break;
			}
			printLists(list);
			break;
		}
		case 3: {
			printLists(list);
			std::cout << "Input id`s of lists" << std::endl;
			std::string input;

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, input);
			std::istringstream stream(input);


			List<int> listToGlue;
			int id;
			while (stream >> id) {
				listToGlue.push(id);
			}
			
			if (!stream.eof()) {
				std::cout << "Error with input" << std::endl;
				break;
			}

			bool er = false;
			List<int> uniqId;
			

			for (int i = 0; i < listToGlue.getSize(); i++) {
				if (listToGlue.getData(i) >= list.getSize()) {//Проверка на валидность введеных значений
					std::cout << listToGlue.getData(i) << " is bigger then size of list with int lists" << std::endl;
					er = true;
					break;
				}
				else if (!uniqId.inside(listToGlue.getData(i))){//создание списка с уникальными значениями
					uniqId.push(listToGlue.getData(i));
				}
			}

			if (er) break;

			for (int i = 1; i < uniqId.getSize(); i++) { 
				summ(list.getData(uniqId.getData(0)), list.getData(uniqId.getData(i)));
			}
			for (int i = 1; i < uniqId.getSize(); i++) { //Удаление списка из общего списка
				list.pop(uniqId.getData(i)-(i-1));//После каждого удаления элемента все элементы общего списка будут сдивгаться на i-1 влево
			}
			break;
		}
		case 4: { //Завершение работы программы
			work = false;
			break;
		}
		}
	}
}


void printLists(List<List<int>*>& list)
{
	for (unsigned long i = 0; i < list.getSize(); i++) {
		std::cout << i << " list" << std::endl;
		list.getData(i)->print();
	}
}
