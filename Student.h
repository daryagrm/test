#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student {
private:
	static const int MAX = 5;   // ����� ������
	static int quantity;        // ����� ���������� ��������
	std::string name;           // ���
	std::string surname;        // �������
	int group_number;           // ����� ������
	int score[MAX];             // ������ ������ �� �������
								// ������� ������� ���� �������� �� 5-�� ������� �������
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