#include <iostream>
#include <string>
#include "management.h"

address_book_management::address_book_management()
{
    m_Size = 0;
}

address_book_management::~address_book_management()
{
    for(int i = 0; i < m_Size; ++i)
    {
        delete personArray[i];
    }
}

bool address_book_management::addPerson(const Person & newperson)
{
    if (m_Size == MAX)
        return false;
    personArray[m_Size] = new Person;
    personArray[m_Size]->m_Name = newperson.m_Name;
    personArray[m_Size]->m_Sex = newperson.m_Sex;
    personArray[m_Size]->m_Age = newperson.m_Age;
    personArray[m_Size]->m_Phone = newperson.m_Phone;
    personArray[m_Size]->m_Addr = newperson.m_Addr;
    ++m_Size;
    return true;
}

void address_book_management::showAllPerson()
{
    for(int i = 0; i < m_Size; ++i)
    {
        std::cout << "姓名：" << personArray[i]->m_Name << std::endl;
        std::cout << "性别：" << personArray[i]->m_Sex << std::endl;
        std::cout << "年龄：" << personArray[i]->m_Age << std::endl;
        std::cout << "联系电话：" << personArray[i]->m_Phone << std::endl;
        std::cout << "家庭住址：" << personArray[i]->m_Addr << std::endl;    
    }
}

void address_book_management::showPerson(std::string Name)
{
    int num = searchPerson(Name);
    if (num == m_Size) std::cout << "查无此人。" << std::endl;
    else
    {
        std::cout << "姓名：" << personArray[num]->m_Name << std::endl;
        std::cout << "性别：" << personArray[num]->m_Sex << std::endl;
        std::cout << "年龄：" << personArray[num]->m_Age << std::endl;
        std::cout << "联系电话：" << personArray[num]->m_Phone << std::endl;
        std::cout << "家庭住址：" << personArray[num]->m_Addr << std::endl;    
    }
}

bool address_book_management::deletePerson(std::string Name)
{
    int num = searchPerson(Name);
    if (num == m_Size) return false;
    else
    {
        delete personArray[num];
        for(int i = num+1; i < m_Size; ++i)
        {
            personArray[i-1] = personArray[i];
        }
        --m_Size;
        return true;
    }
}

int address_book_management::searchPerson(std::string Name)
{
    for(int i = 0; i < m_Size; ++i)
    {
        if (personArray[i]->m_Name == Name) return i;
    }
    return m_Size;
}

bool address_book_management::changePerson(int num, Person & newperson)
{
    if (num == m_Size) return false;
    else
    {
        personArray[num]->m_Name = newperson.m_Name;
        personArray[num]->m_Sex = newperson.m_Sex;
        personArray[num]->m_Age = newperson.m_Age;
        personArray[num]->m_Phone = newperson.m_Phone;
        personArray[num]->m_Addr = newperson.m_Addr;
        return true;
    }
}

void address_book_management::deleteAllPerson()
{
    for(int i = 0; i < m_Size; ++i)
    {
        delete personArray[i];
    }
    m_Size = 0;
}

bool address_book_management::isExist(int num)
{
    if (num == m_Size) return false;
    else return true;
}