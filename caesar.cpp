#include <iostream>
#include <fstream>

using namespace std;

string lexoTekstin(const string& filename) {
    ifstream file(filename);

    if(!file) {
        cerr << "Nuk mund te hapet fajlli: " << filename << endl;
        return "";
    }

    string text, line;
    while(getline(file, line)) {
        for(char ch : line){
            text += tolower(ch);
        }
    }
    return text;
}

void llogaritFrekuencat(const string& text, double freq[26]){
    int counts[26] = {0};
    int total = 0;
}


int main(){

    return 0;
}