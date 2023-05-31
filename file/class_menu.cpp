#include <iostream>
#include "class_data_base.cpp"

class Menu_action
{
    public:
    void menu_action_db()
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
            case 1:
                DB_insert var3;
                var3.create_event();
                break;
            case 2:
                DB_select var4;
                var4.select_event_all();
                break;
            case 3:
                DB_select var5;
                var5.select_event();
                break;
            case 4:
                DB_update var6;
                var6.update_event();
                break;
            case 5:
                DB_delete var7;
                var7.delete_event();
                break;
            case 6:
                exit(1);
            default: std::cout<<"Неверное действие!"<<std::endl;
        }
    }
}

    void menu_action_arr()
    {
        for(;;)
        {
        std::cout<<"Введите действие: "<<std::endl;
        int num;
        std::cin>>num;
        switch(num)
        {
            case 1:
                std::cout<<1;
                break;
            case 2:
                std::cout<<2;
                break;
            case 3:
                std::cout<<3;
                break;
            case 4:
                std::cout<<4;
                break;
            case 5:
                exit(1);

            default: std::cout<<"Неверное действие!"<<std::endl;
        }
    }
    }

};



class Menu: Menu_action
{
public:
    void menu_txt()
    {   int num;
        std::cout<<"Для работы через базу данных нажмите 1, через массив 2"<<std::endl;
        std::cin>>num;

            if(num == 2)
            {
                for(int i = 0; i<=30; i++)
                {
                    std::cout<<"*";
                }
                std::cout<<"\n";
                std::cout<<"Вас приветствует ежедневник!"<<std::endl;
                std::cout<<"1.Создать событие"<<std::endl;
                std::cout<<"2.Просмотреть все события"<<std::endl;
                std::cout<<"3.Просмотреть событие"<<std::endl;
                std::cout<<"4.Редактировать событие"<<std::endl;
                std::cout<<"5.Удалить событие"<<std::endl;
                std::cout<<"6.Выход"<<std::endl;
                for(int i = 0; i<=30; i++)
                {
                    std::cout<<"*";
                }
                std::cout<<"\n";
                Menu_action::menu_action_arr();

            }

            else
            {
                for(int i = 0; i<=30; i++)
                {
                    std::cout<<"*";
                }
                std::cout<<"\n";
                std::cout<<"Вас приветствует ежедневник!"<<std::endl;
                std::cout<<"1.Создать событие"<<std::endl;
                std::cout<<"2.Просмотреть все события"<<std::endl;
                std::cout<<"3.Просмотреть событие"<<std::endl;
                std::cout<<"4.Редактировать событие"<<std::endl;
                std::cout<<"5.Удалить событие"<<std::endl;
                std::cout<<"6.Выход"<<std::endl;
              //  std::cout<<"99.Создать базу программы (обязательно и единократно при первом запуске!)"<<std::endl;

                for(int i = 0; i<=30; i++)
                {
                    std::cout<<"*";
                }
                std::cout<<"\n";
                Menu_action::menu_action_db();
            }

    }

};
