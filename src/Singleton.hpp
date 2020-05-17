/*
 *	Singleton.hpp
 *
 * 	by Vinicius Rodrigues
 *	May 17, 2020
 */


#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__


template<class T> class Singleton {

	static T* m_pSingleton;

public:

	static T* Instance() {
		// Without instance, instance
		if(!m_pSingleton)
			m_pSingleton = new T;

		return m_pSingleton;
	}

	static void Release() {
		delete m_pSingleton;
		m_pSingleton = 0;
	}

};

template<class T>
T* Singleton<T>::m_pSingleton = 0;

#endif
