#include <iostream>

class Menu
{
public:
    void menu_txt()
    {   int num;
        std::cout<<"Для работы через базу данных нажмите 1, через массив 2"<<std::endl;
        std::cin>>num;

            if(num == 2)
            {
                std::cout<<"Вас приветствует ежедневник!"<<std::endl;
                std::cout<<"1.Создать событие"<<std::endl;
                std::cout<<"2.Просмотреть события"<<std::endl;
                std::cout<<"3.Редактировать событие"<<std::endl;
                std::cout<<"4.Удалить событие"<<std::endl;
                std::cout<<"5.Выход"<<std::endl;
            }
            else
            {
                std::cout<<"Вас приветствует ежедневник!"<<std::endl;
                std::cout<<"11.Создать событие"<<std::endl;
                std::cout<<"12.Просмотреть события"<<std::endl;
                std::cout<<"13.Редактировать событие"<<std::endl;
                std::cout<<"14.Удалить событие"<<std::endl;
                std::cout<<"15.Выход"<<std::endl;
              //  std::cout<<"99.Создать базу программы (обязательно и единократно при первом запуске!)"<<std::endl;
            }

    }

};
