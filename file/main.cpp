#include <iostream>
#include "head.hpp"

void menu_action();

int main()
{
    Menu menu_gen;
    menu_gen.menu_txt();
    menu_action();
    return 0;
}


void menu_action()
    {
    for(;;)
    {
        std::cout<<"Введите действие: "<<std::endl;
        int num;
        std::cin>>num;
        switch(num)
        {
            case 99:
                Data_base var1;
                var1.open_db();
                Data_base var2;
                var2.create_db();
                break;
            case 11:
                DB_insert var3;
                var3.create_event();
                break;
            case 12:
                DB_select var4;
                var4.select_event();
                break;
            case 13:
                DB_update var5;
                var5.update_event();
                break;
            case 14:
                std::cout<<5;
                break;
            case 15:
                exit(1);
            case 1:
                break;
            case 2:
                std::cout<<3;
                break;
            case 3:
                std::cout<<4;
                break;
            case 4:
                std::cout<<5;
                break;
            case 5:
                exit(1);

            default: std::cout<<"Неверное действие!"<<std::endl;
        }
    }
    }
