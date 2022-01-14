#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <chrono>
//#include <deque>
//#include <list>
#include <vector>

using namespace std;
class student {
    string fname;
    string lname;
    vector<short int> vgrades;
    short int feg;
    float avgfg = -1;
    float medfg = -1;
    void calcavgfg();
    //void calcmedfg();
public:
    student();
    student(string ifname, string ilname, vector<short int> ivgrades, short  int ifeg);
    student(const student& stud);
    student& operator = (student& student);
    void inptstud(string ifname, string ilname, vector<short int> ivgrades,short int ifeg);
    void outptstud(short int &csys);
    bool isEqual(student& stud) const;
    string soutptstud();
    bool sortvar();
};