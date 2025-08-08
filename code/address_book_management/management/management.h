#ifndef test_H_20250804
#define test_H_20250804

#define MAX 1000

#include <iostream>
#include <string>

struct Person
{
    std::string m_Name;
    std::string m_Sex;
    int m_Age;
    std::string m_Phone;
    std::string m_Addr;
};


class address_book_management
{
    private:
        Person* personArray[MAX];
        int m_Size;
    public:
        address_book_management();
        ~address_book_management();
        bool addPerson(const Person & newperson);
        void showAllPerson();
        void showPerson(std::string Name);
        bool deletePerson(std::string Name);
        int searchPerson(std::string Name);
        bool changePerson(int num, Person & newperson);
        void deleteAllPerson();
        bool isExist(int num);
};

#endif