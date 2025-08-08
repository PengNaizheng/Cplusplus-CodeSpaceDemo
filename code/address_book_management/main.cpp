#include <iostream>
#include "management.h"

void showMenu();
void readperson(Person &newperson);

int main()
{
    address_book_management management;

    int select = 0;
    Person newperson;
    std::string Name;
    bool flag;
    int num = 0;

    while(true)
    {
        showMenu();

        std::cin >> select;

        switch(select)
        {
            case 1:
                
                readperson(newperson);
                flag = management.addPerson(newperson);
                if (flag == false) std::cout <<"通讯录已满，插入失败。" << std::endl;
                else std::cout <<"插入成功。" << std::endl;
                break;
            case 2:
                management.showAllPerson();
                break;
            case 3:
                std::cout << "请输入要删除的联系人姓名：";
                std::cin >> Name;
                flag = management.deletePerson(Name);
                if (flag == false) std::cout <<"查无此人，删除失败。" << std::endl;
                else std::cout <<"删除成功。" << std::endl;
                break;
            case 4:
                std::cout << "请输入要查找的联系人姓名：";
                std::cin >> Name;
                management.showPerson(Name);
                break;
            case 5:
                std::cout << "请输入要修改的联系人姓名：";
                std::cin >> Name;
                num = management.searchPerson(Name);
                flag = management.isExist(num);
                if (flag == false) std::cout <<"要修改的联系人不存在，修改失败。" << std::endl;
                else 
                {
                    readperson(newperson);
                    management.changePerson(num, newperson);
                    std::cout <<"修改成功。" << std::endl;
                }
                break;
            case 6:
                management.deleteAllPerson();
                break;
            case 0:
                std::cout << "欢迎下次使用。" << std::endl;
                return 0;
                break;
            default:
                break;
        }
    }
}

void showMenu()
{
    std::cout << "**************************" << std::endl;
    std::cout << "*****  1.添加联系人  *****" << std::endl;
    std::cout << "*****  2.显示联系人  *****" << std::endl;
    std::cout << "*****  3.删除联系人  *****" << std::endl;
    std::cout << "*****  4.查找联系人  *****" << std::endl;
    std::cout << "*****  5.修改联系人  *****" << std::endl;
    std::cout << "*****  6.清空联系人  *****" << std::endl;
    std::cout << "*****  0.退出通讯录  *****" << std::endl;    
    std::cout << "**************************" << std::endl;

    std::cout << "请输入选项：";
}


void readperson(Person &newperson)
{
    std::cout << "请输入姓名：";
    std::cin >> newperson.m_Name;    
    std::cout << "请输入性别：";
    std::cin >> newperson.m_Sex;
    std::cout << "请输入年龄：";
    std::cin >> newperson.m_Age;
    std::cout << "请输入联系电话：";
    std::cin >> newperson.m_Phone;
    std::cout << "请输入家庭住址：";
    std::cin >> newperson.m_Addr;
}