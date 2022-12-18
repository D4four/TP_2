#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string line;
    vector<int> a;
    ifstream in("hello.txt"); // окрываем файл для чтения
    ofstream out("out.txt");
    if (in.is_open())
    {
        if (out.is_open()) {
            while (getline(in, line))
            {
                out << line;
            }
        }
        

    }
    in.close();     // закрываем файл
    out.close();

    ifstream res("out.txt");

    if (res.is_open()) {
        getline(res, line);
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '"') {
                a.push_back(i);
            }
        }
    }

    //cout << a.size();

    if (a.size() != 0) {
        if (a.size() % 2 == 0) {
            for (int j = 0; j <= a.size() - 1; j += 2) {

                for (int i = a[j]; i <= a[j + 1]; i++) {
                    cout << line[i];
                }
                cout << endl;
            }
        }
        else {
            cout << "Errors..." << endl;
        }
    }
    
    


    res.close();

    std::cout << "End of program" << std::endl;
    return 0;
}