https://github.com/okovtun/SPD_121.git
https://www.youtube.com/watch?v=NItnq6ow4lg&list=PLeqyOOqxeiIPouwvOzxHWVhhwGBpv-FLJ

WinAPI:
https://www.wxwidgets.org/
https://tproger.ru/digest/cpp-best-gui/
https://github.com/okovtun/PS_VS_PU_35/tree/master/WinAPI
1. В проекте ListBox кнопка "Добавить" должна добавлять указанный ползователем текст в ListBox,
   а кнопка "Удалить" должна удалять выбранный элемент из ListBox.
   https://docs.microsoft.com/en-us/windows/win32/controls/list-boxes
2. В поекте ComboBox, при нажатии на кнопку OK должен появляться MessageBox с номером и содержимым
   выбранного элемента.
   https://docs.microsoft.com/en-us/windows/win32/controls/combo-boxes
3. Difference between Class and Struct:
	https://www.youtube.com/watch?v=NgIgJRlZQow
	https://www.youtube.com/watch?v=fLgTtaqqJp0
4. sprintf:
	//https://www.cplusplus.com/reference/cstdio/sprintf/
	//https://www.cplusplus.com/reference/cstdio/printf/

UML:
https://www.codewars.com/kata/578b4f9b7c77f535fc00002f
https://www.codewars.com/kata/578df8f3deaed98fcf0001e9

STL:
http://cplusplus.com/reference/stl/
1. Добавить элемент по указанному индексу в std::list;
2. В отдельном проекте Police,  решить первую задачу из файла:
   https://github.com/okovtun/SPD_121/blob/master/STL/GAI%20DZ_PS_C%2B%2B_nedelya_09.pdf

   https://docs.microsoft.com/en-us/cpp/cpp/argument-passing-and-naming-conventions?view=msvc-170
   https://docs.microsoft.com/en-us/cpp/cpp/stdcall?view=msvc-170

3. Сделать выборку из базы по заданному номеру;
4. Сделать выборку из базы по диапазону номеров;
5. Сделать выборку из базы по заданному правонарушению;
6. Сделать выборку из базы по заданному адресу;
-----------------------------------------------------------
7. Добавить в класс Crime дату и время правонарушения. 
   При добавлении правонарушения в нем должны фиксироваться текущие дата и время.
   https://cplusplus.com/reference/ctime/
8. Сделать выборку из базы по заданным дате/времени;


DONE:
1. Написать деструктор таким образом, чтобы он очищал дерево перед удалением;	DONE
2. Написать метод erase(), который удаляет элемент из дерева по значению;		DONE
3. Tree tree = {50, 25, 75, 16, 32, 64, 80};			DONE
4. CopyMethods; 

DONE:
1. Добить двусвязный список;
------------------------------------------------------------------------
2. В проекте Recusrion написать следующие рекурсивные функции:
	int factorial(int n);	//Возвращает факториал числа
	double power(double a, int n 	//Возвращает число 'a' в степени 'n'

DONE:
Проверочный код в секции HOME_WORK должен заработать:
https://github.com/okovtun/SPD_121/blob/6f192e26d2222a8f6b4f1d4f1529ea39ca9628a8/DataContainers/List2/main.cpp#L219

DONE:
1. В класс ForwardList добавить метод uniqe(), который будет удалять повторяющиеся 
   значения из списка, и таким образом будет делать список уникальным;
2. В класс ForwardList добавить метод reverse(), который будет менять порядок следования
   элементов на противоположный;
   3	5	8	13	21;//list
   21	13	8	5	3;//reverse list
3. Проверочный код должен заработать:
	ForwardList list = { 3, 5, 8, 13, 21 };
	for(int i:list)
	{
		cout << i << tab;
	}
	cout << endl;
	https://cplusplus.com/doc/tutorial/control/#rangefor

DONE:
1. Реализовать метод erase(), который удаляет значение из списка по индексу;	DONE
2. Написать деструктор списка, который будет очищать список перед удалением;	DONE
3. CopyMethods;		DONE
4. MoveMethods;		DONE

DONE:
1. Реализовать проект AbstractGeometry;
2. В иерархию фигур добавить паралеллограмм, ромб, трапецию и т.д.
3. Hardcore: Нарисовать все эти фигуры используя OpenGL, либо DirectX;

DONE:
Реализовать иерархию геометрических фигур: квадрат, прямоугольник, круг, треугольник....
Для каждой фигуры нужно определить ее первичные свойства (квадрат - длина стороны, круг - радиус), 
и вторичные свойства: площадь и периметр. Так же, каждую фигуру нужно нарисовать.
Необходимо сгенерировать фигуры случайным образом, вывести на экран первичные и вторичные 
свойства каждой фигуры, и нарисовать каждую сгенерированную фигуру.

DONE:
Есть 2 типа сотрудников: PermanentEmployee (с постоянной оплатой) и HourlyEmployee (с почасовой оплатой),
Необходимо создать отдел разнотипных сотрудников, и вычислить общую зарплату для этого отдела.

DONE:
Проверочный код должен заработать:
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl;	//HelloWorld

	str1 += str2;
	cout << str1 << endl;	//HelloWorld

DONE:
1. Обеспечить ввод дробей с клавиатуры:		DONE
	Fraction A;
	cout << "Введите простую дробь: ";
	cin >> A;
2. Перегрузить Incremento/Decremento (++/--);
3. Обеспечить инициализацию простых дробей десятичными:	DONE
	Fraction A = 2.75;
	cout << A << endl;	//	2(3/4);

DONE:
В Solution\IntroductionToOOP добавить проект Fraction, и реализовать в нем 
класс Fraction, описывающий простую дробь. В классе должны быть все необходимые методы,
и операторы:
0. Выучить теорию!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
1. Арифметические операторы:	+, -, *, /;
2. Составные присваивания:		+=, -=, *=, /=;
3. Операторы сравнения:			==, !=, >, <, >=, <=
4. Вспомогательные методы:
	- to_proper();		//Переводит дробь в правильную
	- to_improper();	//Переводит дробь в неправильную
	- reduce();			//Сокращает дробь		https://www.webmath.ru/poleznoe/formules_12_7.php

DONE:
1. Выучить теорию!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
2. Написать метод ??? distance(???), который возвращает расстояние ДО УКАЗАННОЙ ТОЧКИ;
3. Написать функцию ??? distance(???), которая возвращает расстояние между двумя точками;