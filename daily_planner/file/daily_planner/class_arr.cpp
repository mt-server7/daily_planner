#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
class General_base_class
{
    public:
        std::ofstream myfile;
        char name[24];
        char txt[255];
        std::vector<char>output;
      //  General_base_class(){}
        virtual void action_function(){};
      //  ~General_base_class(){}
};

class Create_update_event: public General_base_class
{
    public:
        void action_function() override
        {
            std::cout<<"Введите имя события: ";
            std::cin>>name;
            myfile.open(name);
            std::cout<<"Введите событие: ";
            std::cin.getline(txt, 255, ';');
            myfile<<txt;
            myfile.close();
        }

};

class Select_event: public General_base_class
{
    public:
        void action_function() override
        {
            std::cout<<"Введите имя события: ";
            std::cin>>name;
            std::ifstream myfile(name);
            if(!myfile.is_open())
            {
                std::cout<<"Ошибка открытия файла!"<<std::endl;
            }
            else
            {
                for(txt;myfile>>txt;)
                {
                    std::cout<<txt;
                    output.push_back(*txt);
                }
                std::cout<<std::endl;
            }
            myfile.close();
        }

};

class Delete_event: public General_base_class
{
    public:
        void action_function() override
        {
            std::cout<<"Введите имя события: ";
            std::cin>>name;
            remove(name);
        }
};
