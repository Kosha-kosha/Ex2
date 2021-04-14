// ConsoleApplication9(2_3).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "stdio.h"
#include "windows.h"
#include "time.h"
#include<iomanip> 
#include <string>
#include <string.h>
#include <fstream>

using namespace std;




class MineException : public std::exception
{
private:
    string m_error;

public:
    MineException(string error)
        : m_error(error)
    {
    }

    // Возвращаем std::string в качестве константной строки C-style
//	const char* what() const { return m_error.c_str(); } // до C++11
    const char* what() const noexcept { return m_error.c_str(); } // C++11 и выше
};


class Color {
    int d;
public:
    string color = "red";
    string getColor() {
        return color;
    }
    void setColor(string color) {
        this->color = color;
    }
    friend ostream& operator<<(ostream& os, const Color& color);
    friend istream& operator>>(istream& is, Color& color);
    Color& operator=(const Color &obj) {
        color = obj.color;
        return *this;
    }
protected:
    
};

class View {

public:
    string view;
    string getView() {
        return view;
    }
    void setView(string view) {
        this->view = view;
    }
    friend ostream& operator<<(ostream& os, const View& view);
    friend istream& operator>>(istream& is, View& view);
    View& operator=(const View& obj) {
        view = obj.view;
        return *this;
    }
protected:
    
};

class PreView {

public:
    string preView;
    string getPreView() {
        return preView;
    }
    void setPreView(string preView) {
        this->preView = preView;
    }
    friend ostream& operator<<(ostream& os, const PreView& preView);
    friend istream& operator>>(istream& is, PreView& preView);
    PreView& operator=(const PreView& obj) {
        preView = obj.preView;
        return *this;
    }
protected:
    
};



void termFunc();

class Animal {
    string name;
  
public:

    Animal(string name)
    {
        try {
            this->name = name;
            cout << "Constructor of Animal" << endl;
            if (name == "") throw 1;
        }
        catch (...) { cout << "string exception handler"; }

        //}
    }
    ~Animal()
    {
        cout << "Destructor of Animal" << endl;
    }

    string getName() {
        return name;
    }
    /*void Ex8LW() {
        try { Animal ob(); }
        catch (...) { cout << "int exception handler"; }
    }*/

    void setName(string name) {
        set_terminate(termFunc);
        this->name = name;
        //try {
        if (name == "  ") throw "Ничего не введено";
        //}
        //catch (string) {
           // cout << "Обработка исключения типа String" << endl;
        //1}
    }


    void getData() {
        cout << "Животное " << name << " цвета " << color.getColor() << endl;
    }

    void getFullData() {
        cout << view.getView() << endl;
        cout << preView.getPreView() << endl;
        cout << getName() << endl;
        cout << color.getColor() << endl;
    }
    void setData(string enterView, string enterPreView, string enterName, string enterColor) {

        view.setView(enterView);
        preView.setPreView(enterPreView);
        setName(enterName);
        color.setColor(enterColor);
    }
    void inFile(const Animal& animal) {
        string fileBase = "Base.txt";
        fstream fs;

        fs.open(fileBase, fstream::in | fstream::out | fstream::app);

        if (!fs.is_open()) {
            cout << "Файл не открыт!" << endl;

        }
        else {
            cout << "Запись добавлена..." << endl;
            fs << animal << "\n";
        }
        fs.close();
    }
    
    void change(Animal& animal) {
        string fileBase = "Base.txt";
        string fileBaseTemp = "BaseTemp.txt";
        fstream fs;
        fstream fsT;
        fs.open(fileBase, fstream::in | fstream::out | fstream::app);

        if (!fs.is_open()) {
            cout << "Файл не открыт!" << endl;

        }
        else {
            // fs >> book;
        }


        fsT.open(fileBaseTemp, fstream::in | fstream::out | fstream::trunc);

        if (!fsT.is_open()) {
            cout << "Файл не открыт!" << endl;

        }

        cout.width(15);
        cout << "Вид|";
        cout.width(15);
        cout << "Подвид|";
        cout.width(15);
        cout << "Название|";
        cout.width(15);
        cout << "Цвет"<<"\n";
        
        
        cout << "--------------|--------------|--------------|--------------\n";
        while (!fs.eof()) {

            fs >> animal;

            cout.width(13);
            cout << animal.view << " | ";
            cout.width(12);
            cout << animal.preView << " | ";
            cout.width(12);
            cout << animal.name << " | ";
            cout.width(12);
            cout << animal.color << "\n";
            
            animal.setData("", "", "", "");
          /*
            animal.view = "";
            blous.quantity = "";
            blous.price = "";
            blous.ID = "";
            blous.country = "";
            blous.clasp = "";*/
        }
        fs.close();

        fs.open(fileBase, fstream::in | fstream::out | fstream::app);

        if (!fs.is_open()) {
            cout << "Файл не открыт!" << endl;

        }
        else {
            // fs >> book;
        }

        cout << "Введите название животного, данные которого хотите редактировать:" << endl;
        string nameDel;
        cin >> nameDel;
        int i = 0;
        int j = 0;
        int unic = 0;
        j = 0;
        unic = 0;
        while (!fs.eof()) {
            animal.setData("", "", "", "");
            /*blous.name = "";
            blous.quantity = "";
            blous.price = "";
            blous.ID = "";
            blous.country = "";
            blous.clasp = "";*/
            fs >> animal;

            for (int i = 0; i < animal.name.size() && i < nameDel.size(); i++) {       //
                if (nameDel[i] == animal.name[i]) {
                    j++;
                    unic = 11;
                }

            }
            if (j == animal.name.size() && unic == 11) {

                while (true) {
                    int count = 0;
                    cout << "Выберите поле, которое хотите редактировать:\n"
                        << "1 - Вид\n"
                        << "2 - Подвид\n"
                        << "3 - Навзвание\n"
                        << "4 - Цвет\n" << endl;
                        
                    cin >> count;

                    if (count == 1) {
                        cout << "Введите новое название вида: " << endl;
                       // blous.name = "";
                        cin >> animal.view;
                    }
                    if (count == 2) {
                        cout << "Введите новое название подвида: " << endl;
                        //animal.preView = "";
                        cin >> animal.preView;
                    }
                    if (count == 3) {
                        cout << "Введите новое название: " << endl;
                        //animal.name = "";
                        cin >> animal.name;
                    }
                    if (count == 4) {
                        cout << "Введите новый цвет: " << endl;
                        //blous.ID = "";
                        cin >> animal.color;
                    }
                    

                    fsT << animal;
                    fsT << "\n";

                    ///////
                    int red = 0;
                    cout << "Продолжить редактирование?\n"
                        << "1 - Продолжить.\n"
                        << "2 - Закончить." << endl;
                    cin >> red;
                    if (red == 2) {
                        break;
                    }
                    else {}

                }

            }
            else {
                fsT << animal;
                fsT << "\n";
            }
            j = 0;
            unic = 0;
        }



        fs.close();
        fsT.close();

        /////////////

        fsT.open(fileBaseTemp, fstream::in | fstream::out | fstream::app);

        if (!fsT.is_open()) {
            cout << "Файл не открыт!" << endl;

        }


        fs.open(fileBase, fstream::in | fstream::out | ios_base::trunc);

        if (!fs.is_open()) {
            cout << "Файл не открыт!" << endl;

        }

        while (!fsT.eof()) {
            animal.setData("", "", "", "");
            /*
            blous.name = "";
            blous.quantity = "";
            blous.price = "";
            blous.ID = "";
            blous.country = "";
            blous.clasp = "";*/
            fsT >> animal;
            fs << animal;
            fs << "\n";

        }

        cout << "Запись изменена..." << endl;
        //ofstream fout("data_types.txt", ios_base::out | ios_base::trunc);

        fs.close();
        fsT.close();
    }
    void del(Animal& animal) {
        string fileBase = "Base.txt";
        string fileBaseTemp = "BaseTemp.txt";
        fstream fs;
        fstream fsT;
        fs.open(fileBase, fstream::in | fstream::out | fstream::app);

        if (!fs.is_open()) {
            cout << "Файл не открыт!" << endl;

        }
        else {
            // fs >> book;
        }


        fsT.open(fileBaseTemp, fstream::in | fstream::out | fstream::trunc);

        if (!fsT.is_open()) {
            cout << "Файл не открыт!" << endl;

        }
        cout.width(15);
        cout << "Вид|";
        cout.width(15);
        cout << "Подвид|";
        cout.width(15);
        cout << "Название|";
        cout.width(15);
        cout << "Цвет" << "\n";


        cout << "--------------|--------------|--------------|--------------\n";
        while (!fs.eof()) {

            fs >> animal;

            cout.width(13);
            cout << animal.view << " | ";
            cout.width(12);
            cout << animal.preView << " | ";
            cout.width(12);
            cout << animal.name << " | ";
            cout.width(12);
            cout << animal.color << "\n";

            animal.setData("", "", "", "");
            /*
              animal.view = "";
              blous.quantity = "";
              blous.price = "";
              blous.ID = "";
              blous.country = "";
              blous.clasp = "";*/
        }
        fs.close();

        fs.open(fileBase, fstream::in | fstream::out | fstream::app);

        if (!fs.is_open()) {
            cout << "Файл не открыт!" << endl;

        }
        else {
            // fs >> book;
        }

        cout << "Введите название, которое хотете удалить:" << endl;

        string nameDel;
        int j = 0;

        cin >> nameDel;


        j = 0;
        while (!fs.eof()) {
            animal.setData("", "", "", "");
            /*
            blous.name = "";
            blous.quantity = "";
            blous.price = "";
            blous.ID = "";
            blous.country = "";
            blous.clasp = "";*/
            fs >> animal;

            for (int i = 0; i < animal.name.size() && i < nameDel.size(); i++) {       //
                if (nameDel[i] == animal.name[i]) {
                    j++;
                }

            }
            if (j == animal.name.size()) {

            }
            else {
                fsT << animal;
                fsT << "\n";

            }
            j = 0;
        }



        fs.close();
        fsT.close();

        /////////////

        fsT.open(fileBaseTemp, fstream::in | fstream::out | fstream::app);

        if (!fsT.is_open()) {
            cout << "Файл не открыт!" << endl;

        }


        fs.open(fileBase, fstream::in | fstream::out | ios_base::trunc);

        if (!fs.is_open()) {
            cout << "Файл не открыт!" << endl;

        }

        while (!fsT.eof()) {


            /*blous.name = "";
            blous.quantity = "";
            blous.price = "";
            blous.ID = "";
            blous.country = "";
            blous.clasp = "";*/
            fsT >> animal;
            fs << animal;
            fs << "\n";

        }

        cout << "Запись удалена..." << endl;
        //ofstream fout("data_types.txt", ios_base::out | ios_base::trunc);

        fs.close();
        fsT.close();
    }
    void viewDataBase(Animal& animal) {
        string fileBase = "Base.txt";
        
        fstream fs;
        fs.open(fileBase, fstream::in | fstream::out | fstream::app);

        if (!fs.is_open()) {
            cout << "Файл не открыт!" << endl;

        }
        else {
            // fs >> book;
        }


        cout.width(15);
        cout << "Вид|";
        cout.width(15);
        cout << "Подвид|";
        cout.width(15);
        cout << "Название|";
        cout.width(15);
        cout << "Цвет" << "\n";


        cout << "--------------|--------------|--------------|--------------\n";
        while (!fs.eof()) {

            fs >> animal;

            cout.width(13);
            cout << animal.view << " | ";
            cout.width(12);
            cout << animal.preView << " | ";
            cout.width(12);
            cout << animal.name << " | ";
            cout.width(12);
            cout << animal.color << "\n";

            animal.setData("", "", "", "");
            /*
              animal.view = "";
              blous.quantity = "";
              blous.price = "";
              blous.ID = "";
              blous.country = "";
              blous.clasp = "";*/
        }
        fs.close();
    }
    friend ostream& operator<<(ostream& os, const Animal& animal);
    friend istream& operator>>(istream& is, Animal& animal);
    Animal& operator=(const Animal& obj) {
        name = obj.name;
        return *this;
    }



private:
    Color color;
    View view;
    PreView preView;
};


ostream& operator<<(ostream& os, const Color& color) {

    os << color.color;

    return os;
}
istream& operator>>(istream& is, Color& color) {


    is >> color.color;


    return is;
}

ostream& operator<<(ostream& os, const View& view) {

    os << view.view;

    return os;
}
istream& operator>>(istream& is, View& view) {


    is >> view.view;


    return is;
}

ostream& operator<<(ostream& os, const PreView& preView) {

    os << preView.preView;

    return os;
}
istream& operator>>(istream& is, PreView& preView) {


    is >> preView.preView;


    return is;
}

ostream& operator<<(ostream& os, const Animal& animal) {

    os << animal.view << " " << animal.preView << " " << animal.name << " " << animal.color;

    return os;
}
istream& operator>>(istream& is, Animal& animal) {

   
    is >> animal.view >> animal.preView >> animal.name >> animal.color;
    

    return is;
}



void termFunc() {
    cout << "Функция termFunc() вызвана функцией terminate().\n";
    // операторы освобождения ресурсов
    exit(-1);
}




int menu() {
    int choice;
    do
    {
        cout << endl
            << " 1 - Добавить животное.\n"//
            << " 2 - Редактировать информацию о животном.\n"//
            << " 3 - Удалить информацию о животном.\n"//
            << " 4 - Просмотр зоопарка.\n"
 
            << " Введите Ваш выбор и нажмине Enter: ";
        cin >> choice;
    } while (choice > 4);
    return choice;
}


int main()
{
    setlocale(LC_ALL, "rus");
    Animal animal("***");
    string view;
    string preView;
    string name;
    string color;
    while (true) {
        switch (menu())
        {
        case 1:
            cout << "Вид животного: ";
            cin >> view;
            cout << "\n";
            cout << "Подвид животного: ";
            cin >> preView;
            cout << "\n";
            cout << "Название животного: ";
            cin >> name;
            cout << "\n";
            cout << "Цвет животного: ";
            cin >> color;
            cout << "\n";

            animal.setData(view, preView, name, color);
            animal.inFile(animal);
            break;
        case 2:
            animal.change(animal);
            break;
        case 3:
            animal.del(animal);
            break;
        case 4:
            animal.viewDataBase(animal);
            break;
        }
    }
    
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
