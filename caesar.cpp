#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cctype>

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
void sulmoCezarin(const string& trainingFile, const string& encryptedFile){
    string trainingText = lexoTekstin(trainingFile);
    string encryptedText = lexoTekstin(encryptedFile);

    double modelFreq[26];
    llogaritFrekuencat(trainingText, modelFreq);

    int bestKey = 0;
    double minDiff = 1e9;
    string decryptedMessage;

    for(int key = 0; key < 26 ; key++){
        string candidate = dekriptoCezar(encryptedText, key);
        double candidateFreq[26];
        llogaritFrekuencat(candidate, candidateFreq);

        double diff = ndryshimiTotal(modelFreq, candidateFreq);
        if(diff < minDiff){
            minDiff = diff;
            bestKey = key;
            decryptedMessage = candidate;
        }
    }
    cout << "\nÇelësi me më shumë gjasa: " << bestKey << endl;
    cout << "\nMesazhi i dekriptuar: " << decryptedMessage << endl; 
}


int main(){
    string trainingFile = "training.txt";
    string encryptedFile = "secret.txt";
    
    sulmoCezarin(trainingFile, encryptedFile);
    return 0;
}


 int main(){
    string trainingFile = "training.txt";
    string encryptedFile = "secret.txt";
    int choice;
    
 }