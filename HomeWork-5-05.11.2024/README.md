# Домашнее задание №5

-Написать шаблон класс Array со следующей структурой:
	template <class T>
	class Array
	{
		T array[size];
		public:
			Array() {};
			Array(T* b);
			void show();
			minimum(Array<T>& m);
	};

Запуск программы осуществляется через makefile.