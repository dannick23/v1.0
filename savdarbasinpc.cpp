
#include "stud.h"
using namespace std;

bool operator==(student& stud1, student& stud2) { return stud1.isEqual(stud2); }
ostream& operator<<(ostream& o, student& const stud) { return o << stud.soutptstud(); }
void readfile(vector<student>& swstud, const string &fn) {
    string tempfname, templname, temp;
    vector<short int> ivgrades;
    short int tempfeg,tempgrade;
    static short int count = 0;
    ifstream inpt;
    inpt.open(fn);
    inpt >> templname;
    inpt >> tempfname;
    vector<student>::iterator a;
    cout << "read of file "<< fn << " start" << endl;
    auto start = chrono::steady_clock::now();
    if (templname == "Pavarde" && tempfname == "Vardas")
    {
            while (temp != "Egzaminas") {
                inpt >> temp;
                count += (temp != "Egzaminas") ? 1 : 0;
            }
    }
    while(true){
        inpt >> templname;
        inpt >> tempfname;
        for (int j = 0;j < count;j++){inpt >> tempgrade;ivgrades.push_back(tempgrade);}
        inpt >> tempfeg;
        swstud.push_back(student::student(tempfname, templname, ivgrades, tempfeg));
        ivgrades.clear();
        if (swstud.size() > 2) {
            a = swstud.end();--a;--a;
            if (*a == swstud.back()) break;
        }
            
    }
    count = 0;
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "read of file"<<fn<<"end, elapsed time: "<< elapsed_seconds.count()<<"s" << endl;
    inpt.close();
};
void writefile(vector<student>& stud, const string& name)
{
    ofstream out;
    out.open(name);
    auto start = chrono::steady_clock::now();
    cout << "write file " << name << " started" << endl;
    out << "Pavarde     Vardas       Galutinis (Vid.) Galutinis (Med.)" << endl << "--------------------------------------------------" << endl;
    for (auto i = stud.begin();i != stud.end();i++) out << *i << endl;
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "write file " << name << " ended, elapsed time: " << elapsed_seconds.count() << "s" << endl;
    out.close();
}
void sortstudsone(vector<student>& stud) {
    vector<student> cool, lame;
    cout << "Sort of students by avg grades start" << endl;
    auto start = chrono::steady_clock::now();
    for (vector<student>::iterator i = stud.begin();i != stud.end();i++) {
        if (i->sortvar())lame.push_back(*i);
        else cool.push_back(*i);
    }
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "sort of students by avg grades end, elapsed time: " << elapsed_seconds.count() << "s" << endl;
    writefile(lame,"vargsiukai.txt");
    writefile(cool,"kietekai.txt");
}
//void sortstudstwo(vector<student>& stud) {
//    vector<student>  lame;
//    cout << "Sort of students by avg grades start" << endl;
//    auto start = chrono::steady_clock::now();
//    for (vector<student>::iterator i = stud.begin();i != stud.end();i++) {
//        if (i->sortvar()) { lame.push_back(*i); stud.erase(i); }
//    }
//    auto end = chrono::steady_clock::now();
//    chrono::duration<double> elapsed_seconds = end - start;
//    cout << "sort of students by avg grades end, elapsed time: " << elapsed_seconds.count() << "s" << endl;
//    writefile(lame, "vargsiukai.txt");
//    writefile(stud, "kietekai.txt");
//}
void generatefile(int setnd,int setsc, const string &name) {
    ofstream out(name);
    cout << "generation of file " << name << " started" << endl;
    auto start = chrono::steady_clock::now();
    out << "Pavarde Vardas";
    for (int i = 1;i <= setnd;i++)out  << " ND" << i;
    out<<" Egzaminas" << endl;
    for (int i = 1;i <= setsc;i++)
    {
        out << "Pavarde" << i << " Vardas" << i;
        for (int j = 0;j < setnd;j++)out << " " << rand() % 10 + 1;
        out << " " << rand() % 10 + 1 << endl;
    }
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "generation of file " << name << " ended, time elapsed: " << elapsed_seconds.count() << "s" << endl;
    out.close();
}
int main()
{
    vector<student> stud,stud1,stud2,stud3,stud4,stud5;
    int a,b;
    short int csys;
    cout << "1-readfile(); \n2-writefile(); \n3-generatefile; \n4-vid; \n5-med; \n6-generate 5 files; \n7-read 5 files;\n8-sort students by grade strategy 1;\n9-sort students by grade strategy 2;" << endl;
    vector<student>::iterator it;
    do
    {
        cin >> csys;
        switch (csys)
        {
        case 1:
            readfile(stud,"kursiokai.txt");
            break;
        case 2:
            writefile(stud,"outpt.txt");
            break;
        case 3:
            cin >> a >> b;
            generatefile(a,b,"kursiokai.txt");
            break;
        case 4:
            cout << "stud: " << endl;
            for (auto i = stud.begin();i != stud.end();i++)
                i->outptstud(csys);
            csys = 4;
            cout << "stud1: " << endl;
            for (auto i = stud1.begin();i != stud1.end();i++)
                i->outptstud(csys);
            csys = 4;
            cout << "stud2: " << endl;
            for (auto i = stud2.begin();i != stud2.end();i++)
                i->outptstud(csys);
            csys = 4;
            cout << "stud3: " << endl;
            for (auto i = stud3.begin();i != stud3.end();i++)
                i->outptstud(csys);
            csys = 4;
            cout << "stud4: " << endl;
            for (auto i = stud4.begin();i != stud4.end();i++)
                i->outptstud(csys);
            csys = 4;
            cout << "stud5: " << endl;
            for (auto i = stud5.begin();i != stud5.end();i++)
                i->outptstud(csys);
            csys = 2;
            break;
        case 5:
            for (auto i = stud.begin();i != stud.end();i++)
                i->outptstud(csys);
            csys = 2;
            break;
        case 6:
            /*generatefile(5, 1000,"kursiokai1.txt");
            generatefile(5, 10000, "kursiokai2.txt");
            generatefile(5, 100000, "kursiokai3.txt");*/
            generatefile(5, 1000000, "kursiokai4.txt");
            /*generatefile(5, 10000000, "kursiokai5.txt");*/
            break;
        case 7:
            /*readfile(stud, "kursiokai1.txt");
            readfile(stud, "kursiokai2.txt");
            readfile(stud, "kursiokai3.txt");*/
            readfile(stud, "kursiokai4.txt");
            //readfile(stud, "kursiokai5.txt");
            break;
        case 8:
            sortstudsone(stud);
            break;
        case 9:
            /*sortstudstwo(stud);*/
            break;
        case 0:
            return 0;
        default:
            cout << "No such Option!" << endl;
            break;
        }
    } while(true);
}
//auto start = std::chrono::steady_clock::now();
//std::cout << "f(42) = " << fibonacci(42) << '\n';
//auto end = std::chrono::steady_clock::now();
//std::chrono::duration<double> elapsed_seconds = end - start;