#include <iostream>
#include <fstream>
#include <string> 

using std::ofstream;
using std::ifstream;
using std::getline;
using std::string;
using std::cout;
using std::endl;

void substitute_str (string& iostring, const string& before, const string& after){
    size_t pos = 0;
    //find: Find content in string (public member function)
    while ((pos = iostring.find(before, pos)) != string::npos) {
        iostring.replace(pos, before.length(), after);
        pos += after.length();
    }
}

string readFileContent(string filename){
    ifstream inputFile(filename);
    string content;
    getline(inputFile, content);
    return content;
}

int main(int argc, char* argv[]) {

    //read files
    string input = readFileContent("input.txt");
    string before = readFileContent("before.txt");
    string after = readFileContent("after.txt");

    //process input
    substitute_str(input, before, after);

    //write result
    ofstream resultFile("result.txt");
    resultFile << input;
    resultFile.close();

    cout <<  "Done" << endl;

    return 0;
}