#include <iostream>
#include "Comporators.hpp"
#include "Person.hpp"
#include "SortedSequence.hpp"

using namespace std;

int main() {
    int s1 = 0;
    cout << endl << "Select an action:" << endl << "1 - create sequence" << endl << "2 - read from file" << endl;
    cin >> s1;
    switch (s1) {
        case 1: {
            SortedSequence<Person> seq(PersonLess);
            int s2 = 0;
            while (s2 != 6) {
                cout << endl << "1 - get" << endl << "2 - add from stream" << endl << "3 - add random" << endl << "4 - remove" << endl << "5 - put in file" << endl << "6 - exit" << endl;
                cin >> s2;
                int idx;
                switch (s2) {
                    case 1: {
                        cin >> idx;
                        cout << seq.get(idx) << endl;
                        break;
                    }
                    case 2: {
                        auto p = getFromStream(cin);
                        seq.add(p);
                        break;
                    }
                    case 3: {
                        auto p = getRandomPerson();
                        cout << p << endl;
                        seq.add(p);
                        break;
                    }
                    case 4: {
                        auto p = getFromStream(cin);
                        seq.remove(p);
                        break;
                    }
                    case 5: {
                        putInTXT(seq.getValues(), R"(D:\CLionProjects\mephi_lab_5\output.txt)");
                        break;
                    }
                    case 6: {
                        break;
                    }
                }
            }
            break;
        }
        case 2 : {
            auto ps = getFromTXT(R"(D:\CLionProjects\mephi_lab_5\input.txt)");
            SortedSequence<Person> seq(ps, PersonLess);
            putInTXT(seq.getValues(), R"(D:\CLionProjects\mephi_lab_5\output.txt)");
            break;
        }
    }
    return 0;
}