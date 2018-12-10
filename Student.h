#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student {
private:
	static const int MAX = 5;   // шкала баллов
	static int quantity;        // общее количество учеников
	std::string name;           // имя
	std::string surname;        // фамилия
	int group_number;           // номер группы
	int score[MAX];             // личные оценки за семестр
								// находим средний балл студента по 5-ти бальной системе
	float GPA(int sc[], int size) {
		int i = 0;
		float gpa = 0;
		while (i < size) {
			gpa += sc[i];
			i++;
		}
		return gpa / size;
	}
public:
	Student();
	Student(std::string n, std::string sn, int g, int sc[]);
	void Init(void);
	void PrintStudent(void);
};

#endif