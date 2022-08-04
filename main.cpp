#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Wheels
{


public:
    void setWheel(char p)
    {
        if (p < 'A')
        {
            cerr << "error : " << p << " is number ,not a letter" << endl;
            throw p;
        }
        if (p > 'Z') p -= 32;
        this->point = p;
    }

    void turn()
    {
        if (this->point + 1 > 'Z')
            this->point = 'A';
        else
            this->point++;
    }

    void showPoint() const
    {
        cout << "Now point at '" << point << "' " << endl;
    }

    char getLetter()
    {
        return this->point;
    }

private:
    char point = 'A';
};

class Enigma
{
public:
    void encrypt()
    {

    }

    void decrypt()
    {

    }

    //todo 完善函数,插线板暂未实现
    string getCode()
    {
        return new_code;
    }

    void showWheelsSet()
    {
        for (Wheels w: wh)
        {
            w.showPoint();
        }
    }

    Enigma(string raw_code, int wheels, char p[])
    {
        this->raw_code = raw_code;
        this->wheels = wheels;
        WheelsInit(p);
    }

private:
    string raw_code, new_code;
    int wheels;
    vector<Wheels> wh;

    void WheelsInit(char p[])
    {
        for (int i = 0; i < wheels; i++)
        {
            Wheels temp;
            temp.setWheel(p[i]);
            wh.push_back(temp);
        }
    }
};


int main()
{
    int asa;
    cin >> asa;
    char op[3] = {};
    for (int i = 0; i < asa; i++) cin >> op[i];
    Enigma a("A", 3, op);

    a.showWheelsSet();

    system("pause");

    return 0;
}

