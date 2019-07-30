#include <random>
#include <queue>
#include <ctime>
#include <thread>

#include "a.h"
#include "ThreadInfo.h"

// Многопоточная функция
template<class U, class T>
static void generateOnjects(std::shared_ptr<Resource<U>> threads, std::shared_ptr<Resource<T>> resource, std::string name, const int& amount)
{
	using namespace std::chrono_literals;

	threads->enqueue(std::make_shared<U>(name, resource->getIndex(), amount));
#ifdef _DEBUG
	std::cout << name + " thread added\n";
#endif // _DEBUG

	int i = amount;
	while (i--)
	{
		std::cout << "Working...\n";
		// Нагрузка
		resource->enqueue(std::make_shared<T>(resource->getIndex(), name));
#ifdef _DEBUG
		std::cout << name + " Object added\n";
#endif // _DEBUG

		std::this_thread::sleep_for(0.1s);
	}
}

int main()
{
	// Инициализация генератора случайных чисел
	std::srand(std::time(nullptr));

	// Инициализация контейнеров для процессоров и объектов A
	std::shared_ptr<Resource<ThreadInfo>> threads(std::make_shared<Resource<ThreadInfo>>());
	std::shared_ptr<Resource<A>> resource(std::make_shared<Resource<A>>());

	// Применяется генератор случайных значений с равномерным распределением
	std::thread first(generateOnjects<ThreadInfo, A>, threads, resource, std::string("First"), std::rand() % 200);
	std::thread second(generateOnjects<ThreadInfo, A>, threads, resource, std::string("Second"), std::rand() % 200);
	std::thread third(generateOnjects<ThreadInfo, A>, threads, resource, std::string("Third"), std::rand() % 200);

	first.join();
	second.join();
	third.join();
	
#ifdef _DEBUG
	std::cout << "Thread name | Object order" << std::endl;
	while (resource->getSize())
	{
		std::cout << resource->dequeue()->getInfo();
	}
#endif // _DEBUG

	std::cout << "Thread name | Thread order | Created objects" << std::endl;
	while (threads->getSize())
	{
		std::cout << threads->dequeue()->getInfo();
	}

	return 0;
}