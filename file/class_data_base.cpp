#include <iostream>
#include <string>
#include <sqlite3.h>

class Data_base
{
    public:

    static int callback(void* data, int argc, char** argv, char** azColName)
    {
    int i;
    fprintf(stderr, "%s: ", (const char*)data);

    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
    }

        void open_db()
        {
            sqlite3* DB;
            int exit = 0;
            exit = sqlite3_open("daily_planner_data_base.db", &DB);
            if(exit)
            {
                std::cerr<<"Error open Data Base: "<<sqlite3_errmsg(DB)<<std::endl;

            }
            else
                std::cout<<"Opened Data Base Successfully!"<<std::endl;

        }

        void create_db()
        {
            sqlite3* DB;
            std::string sql = "CREATE TABLE DAILY_PLANNER("
                                "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                                "DATE DATETIME DEFAULT (datetime('now','localtime')),"
                                "TEXT CHAR(255),"
                                "IMPORTANT CHAR(10));";

            int exit = 0;
            exit = sqlite3_open("daily_planner_data_base.db", &DB);
            char* messagge_error;
            exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messagge_error);

            if(exit != SQLITE_OK)
            {
                std::cerr<<"Error create Data Base: "<<sqlite3_errmsg(DB)<<std::endl;
                sqlite3_free(messagge_error);

            }
            else
                std::cout<<"Created Data Base Successfully!"<<std::endl;
            sqlite3_close(DB);

        }

};

class DB_insert: public Data_base
{
    public:

    void create_event()
    {
        std::string flag;
        char txt[255];
        std::cout<<"Введите событие:";
        std::cin.getline(txt, 255, ';');
        std::cout<<"Флаг важности(до 10 символов):";
        std::cin>>flag;
        sqlite3* DB;
        char* messagge_error;
        int exit = sqlite3_open("daily_planner_data_base.db", &DB);
        std::string query = "SELECT * FROM PERSON;";

        std::string sql = "INSERT INTO DAILY_PLANNER(TEXT, IMPORTANT) VALUES('"+ std::string(txt) +"', '" + flag + "');";

        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messagge_error);
        if(exit != SQLITE_OK )
        {
            std::cout << "error Insert: "<<sqlite3_errmsg(DB);
            sqlite3_free(messagge_error);
        }
        else
        {
            std::cout << "Records created successfully\n";
            sqlite3_exec(DB, query.c_str(), Data_base::callback, NULL, NULL);
            sqlite3_close(DB);
        }
    }
};

class DB_select: public Data_base
{
    public:

    void select_event()
    {
        sqlite3* DB;
        char* messagges_error;
        int exit = sqlite3_open("daily_planner_data_base.db", &DB);
        std::string data("Событие");

        std::string sql("SELECT * FROM DAILY_PLANNER;");

         if (exit)
        {
            std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        }
        else
        {
            std::cout << "Opened Database Successfully!" << std::endl;
        }

       exit = sqlite3_exec(DB, sql.c_str(), Data_base::callback, (void*)data.c_str(), NULL);
            if(exit != SQLITE_OK)
            {
                std::cerr<<"Error SELECT: "<<sqlite3_errmsg(DB)<<std::endl;
                sqlite3_free(messagges_error);

            }
            else
            {
                std::cerr<<"Operation ok "<<std::endl;
            sqlite3_close(DB);
            }

    }
};

class DB_update: public Data_base
{
    public:

    void update_event()
    {
        std::string flag;
        char txt[255];
        int x;
        std::cout<<"Введите ID события: ";
        std::cin>>x;
        std::cout<<"Введите событие: ";
        std::cin.getline(txt, 255, ';');
        std::cout<<"Флаг важности(до 10 символов): ";
        std::cin>>flag;
        sqlite3* DB;
        char* messagges_error;
        int exit = sqlite3_open("daily_planner_data_base.db", &DB);

        if (exit)
        {
            std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        }
        else
        {
            std::cout << "Opened Database Successfully!" << std::endl;
        }


          std::string sql = "UPDATE DAILY_PLANNER SET TEXT = '"+ std::string(txt) +"', IMPORTANT = '" + flag + "' WHERE ID = '" + std::to_string(static_cast<long long>(x)) + "';";

        exit = sqlite3_exec(DB, sql.c_str(), Data_base::callback, NULL, NULL);
        if(exit != SQLITE_OK)
        {
            std::cerr<<"Error UPDATE: "<<sqlite3_errmsg(DB)<<std::endl;
            sqlite3_free(messagges_error);

        }
        else
        {
            std::cerr<<"Operation ok "<<std::endl;
            sqlite3_close(DB);
        }
    }
};

class DB_delete: public Data_base
{
    public:
         void delete_event()
    {
        int x;
        std::cout<<"Введите ID события: ";
        std::cin>>x;

        sqlite3* DB;
        char* messagges_error;
        int exit = sqlite3_open("daily_planner_data_base.db", &DB);

        if (exit)
        {
            std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        }
        else
        {
            std::cout << "Opened Database Successfully!" << std::endl;
        }


          std::string sql = "DELETE FROM DAILY_PLANNER WHERE ID = '" + std::to_string(static_cast<long long>(x)) + "';";

        exit = sqlite3_exec(DB, sql.c_str(), Data_base::callback, NULL, NULL);
        if(exit != SQLITE_OK)
        {
            std::cerr<<"Error DELETE: "<<sqlite3_errmsg(DB)<<std::endl;
            sqlite3_free(messagges_error);

        }
        else
        {
            std::cerr<<"Operation ok "<<std::endl;
            sqlite3_close(DB);
        }
    }
};
