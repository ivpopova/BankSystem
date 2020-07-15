#pragma once
#include <string>

class Person {
public:
	Person() = delete;
	Person(std::string name, int age);
	~Person() = default;

	const std::string getName()const;
	const int getAge()const;

	void setName(const std::string name);
	void setAge(const int);

	void validateAge(int age);
	virtual void printInformation() = 0;
private:
	std::string name;
	std::string address;
	int age;
};