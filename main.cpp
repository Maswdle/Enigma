#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Plugboard
{
public:
    void Init(map<char, char> a)
    {
        for (pair<char, char> it: a)
        {
            int key = it.first >= 'a' && it.first <= 'z' ? it.first - 32 : it.first;
            int value = it.second >= 'a' && it.second <= 'z' ? it.second - 32 : it.second;
            this->pb[key] = value;

        }
    }

    char getLetter(char p)
    {
        return p >= 'a' && p <= 'z' ? pb[p - 32] : pb[p];
    }

private:
    map<char, char> pb;
};

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

    //todo write functions
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

    void resetWheel(int index, char p)
    {
        this->wh[index].setWheel(p);
    }

    Enigma(string r_code, int wheels, char p[], map<char, char> p_point)
    {
        this->raw_code = r_code;
        this->wheels = wheels;
        for (int i = 0; i < wheels; i++)
        {
            Wheels temp;
            temp.setWheel(p[i]);
            this->wh.push_back(temp);
        }
        this->Pb.Init(p_point);
    }

private:
    string raw_code, new_code;
    int wheels;
    vector<Wheels> wh;
    Plugboard Pb;


};


int main()
{
//    int asa;
//    cin >> asa;
//    char op[3] = {};
//    for (int i = 0; i < asa; i++) cin >> op[i];
//    Enigma a("A", 3, op,p_op);
//
//    a.showWheelsSet();

    map<char, char> p_op;
    p_op.insert(pair<char, char>('a', 'b'));
    Plugboard a;
    a.Init(p_op);
    cout << a.getLetter('a') << endl;


    system("pause");

    return 0;
}

