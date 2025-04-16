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
string dekriptoCezar(const string& text, int key) {
    string result;
    for (char ch : text) {
        if (isalpha(ch)) {
            result += (ch - 'a' - key + 26) % 26 + 'a';
        } else {
            result += ch; 
        }
    }
    return result;
}
double ndryshimiTotal(const double f1[26], const double f2[26]) {
    double total = 0.0;
    for (int i = 0; i < 26; i++) {
        total += fabs(f1[i] - f2[i]);
    }
    return total;
}
int main(){

    return 0;
}