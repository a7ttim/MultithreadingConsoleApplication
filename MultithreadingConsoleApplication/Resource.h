#pragma once

#include <memory>
#include <mutex>
#include <queue>

template<class T>
class Resource
{
	int m_index = 0;
	std::queue<std::shared_ptr<T>> m_queue;
	// В некоторой литературе рекомендуется объявлять mutex снаружи, 
	// однако есть и такой способ
	mutable std::mutex m_mutex;

public:
	std::shared_ptr<T> dequeue();
	std::shared_ptr<T> first();
	void enqueue(std::shared_ptr<T> object);
	const int getIndex();
	const int getSize() const;
};

template<class T>
inline std::shared_ptr<T> Resource<T>::dequeue()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	const std::shared_ptr<T> object = m_queue.front();
	m_queue.pop();
	return object;
}

template<class T>
inline std::shared_ptr<T> Resource<T>::first()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	return m_queue.front();
}

template<class T>
inline void Resource<T>::enqueue(std::shared_ptr<T> object)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_queue.push(object);
}

template<class T>
inline const int Resource<T>::getIndex()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	return m_index++;
}

template<class T>
inline const int Resource<T>::getSize() const
{
	std::lock_guard<std::mutex> guard(m_mutex);
	return m_queue.size();
}
