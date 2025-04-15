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

    for (char ch : text){
        if (isalpha(ch)){
            counts[ch - 'a']++;
            total++;
        }
    }

    for(int i = 0; i < 26; i++){
        freq[i] = (total > 0) ? (double)counts[i] / total : 0.0;
    }
}


int main(){

    return 0;
}