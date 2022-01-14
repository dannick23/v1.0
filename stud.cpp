#include "stud.h"

using namespace std;


    void student::calcavgfg() {
        float answ = 0;
        for (auto i = vgrades.begin();i != vgrades.end();i++) {
            answ += *i;
        }
        answ = answ / vgrades.size() * 0.4f + feg * 0.6f;
        avgfg = answ;
    }
    //void student::calcmedfg()
    //{
    //    size_t size = vgrades.end() - vgrades.begin();
    //    size_t middleIdx = size / 2;
    //    auto target = vgrades.begin() + middleIdx;
    //    nth_element(vgrades.begin(), target, vgrades.end());
    //    if (size % 2 != 0) { //Odd number of elements
    //        medfg = *target * 0.4f + feg * 0.6f;
    //    }
    //    else {            //Even number of elements
    //        double a = *target;
    //        auto targetNeighbor = target - 1;
    //        nth_element(vgrades.begin(), targetNeighbor, vgrades.end());
    //        medfg = (a + *targetNeighbor) / 2.0 * 0.4f + feg * 0.6f;
    //    }
    //}

    student::student() {
        fname = "unset";
        lname = "unset";
        feg = -1;
    }
    student::student(string ifname, string ilname, vector<short int> ivgrades, short int ifeg)
    {
        fname = ifname;
        lname = ilname;
        for (auto i = ivgrades.begin();i != ivgrades.end();i++)
            vgrades.push_back(*i);
        feg = ifeg;
    }
    student::student(const student& stud) {
        fname = stud.fname;
        lname = stud.lname;
        for (auto i = stud.vgrades.begin();i != stud.vgrades.end();i++)
            vgrades.push_back(*i);
        feg = stud.feg;
    }
    student& student::operator = (student& student) { return *this; }
    void student::inptstud(string ifname, string ilname, vector<short int> ivgrades, short  int ifeg) {
        fname = ifname;
        lname = ilname;
        for (auto i = ivgrades.begin();i != ivgrades.end();i++)
            vgrades.push_back(*i);
        feg = ifeg;
    }
    void student::outptstud(short int &csys) {
        if (csys == 4) { csys = 0; cout << "Pavarde     Vardas       Galutinis(Vid.)" << endl << "--------------------------------------------------" << endl; }
        else if (csys == 5) { csys = 1;cout << "Pavarde     Vardas       Galutinis(Med.)" << endl << "--------------------------------------------------" << endl; }
        cout<<setw(12) << lname;
        cout << setw(12) << fname;

        if (csys == 0)
        {
            if (avgfg == -1)this->calcavgfg();
            cout << setprecision(3)<<setw(8) << avgfg << endl;
        }
       /* else
        {
            if (medfg == -1)this->calcmedfg();
            cout << setprecision(3) << setw(8) << medfg << endl;
        }*/
    }
    bool student::isEqual(student& stud) const {
        if (stud.fname == fname && stud.lname == lname) return true;
        else return false;
    }
    string student::soutptstud() {
        ostringstream out;
        out << lname;
        out<<setw(12) << fname;
        if (avgfg == -1)this->calcavgfg();
        /*if (medfg == -1)this->calcmedfg();*/
        out << setprecision(3)<<setw(8) << avgfg;
        out << setprecision(3)<<setw(8) << medfg;
        return out.str();
    }
    bool student::sortvar()
    {
        if (avgfg == -1)this->calcavgfg();
        if (avgfg < 5)return true;
        else return false;
    }