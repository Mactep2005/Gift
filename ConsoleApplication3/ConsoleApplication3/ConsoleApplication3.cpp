#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

const int para = 3; 
class Chocolate;
class Candy
{
private:

    string name;
    int ves;
    double price;
    string f;
public:
    friend Chocolate;
    Candy()
    {
        cout << name;
    }
    Candy(string name, int ves, double price)
    {
        this->name = name;
        this->ves = ves;
        this->price = price;
    }
    string GetName()
    {
        return name;
    }

    void SetName(string name)
    {
        this->name = name;
    }
    int GetVes()
    {
        return ves;
    }

    void SetVes(int ves)
    {
        this->ves = ves;
    }
    double GetPrice()
    {
        return price;
    }

    void SetName(double price)
    {
        this->price = price;
    }
    bool GetDark();
    virtual void print()
    {
        cout << name << " " << ves << " " << price << " ";
    }

};

class Chocolate : public Candy {
    friend Candy;
public:
    bool dark = true;
    int s;
    string f;
    Chocolate() : Candy("Chocolate", 125 , 40)
    {
        cool();
    }
    void print()
    {
        cout << dark;
    }
    void cool()
    {
        srand(time(NULL));
        s = 1 + rand() % 2;
        switch (s)
        {
        case 1:
            dark = true;
            f = "Шоколад чёрный";
            break;
        case 2:
            dark = false;
            f = "Шоколад белый";
            break;

        }
    }
};
class Jelly : public Candy {
public:
    friend Chocolate;
    string tas = "Томск";
    Jelly() :Candy("Jellybean", 50, 27)
    {
        
    }
    void print()
    {
        cout << tas;
    }

};
class Marmelad : public Candy {
public:
    string tast = "taste";
    Marmelad() :Candy("Marmelad", 100, 35)
    {

    }
    void print()
    {
        cout << tast;
    }
};
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Подарок собран " << "\n" << "\n";
    int pricing = 0, weight = 0;
    Candy* cand[3];
    Chocolate chock;
    cand[0] = new Chocolate;
    Marmelad marm;
    cand[1] = new Marmelad;
    Jelly jel;
    cand[2] = new Jelly;
    Candy gift[para] = { chock, marm, jel};
    for (int i = 0; i < para; i++)
    {
        cout << gift[i].GetName() << "\n" << gift[i].GetVes() << "\n" << gift[i].GetPrice() << "\n";
        auto& o = cand[i];
        o->print();
        cout << "\n" << "\n";
        weight += gift[i].GetVes();
        pricing += gift[i].GetPrice();
    }


    for (int i = 0; i < 3; i++)
    {
        delete cand[i];
    }
    cout << "\n";
    cout << "Итого " << weight << " гр" << "\n";
    cout << "Итого " << pricing << " руб";
}