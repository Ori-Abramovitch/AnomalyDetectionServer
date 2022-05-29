//
// Created by ori on 07/01/2021.
//
#include <sstream>
#include "commands.h"
#include "CLI.h"


void test1() {
    string str = "1,2,3,4,5,6";
    stringstream ss(str);
    while (ss.good()) {
        string num;
        getline(ss, num, ',');
        cout << num + "\n";
    }
    str = "99,888";
    stringstream ss2(str);
    string num1, num2;
    getline(ss2, num1, ',');
    cout << num1 + "\n";
    getline(ss2, num2, ' ');
    cout << num2 + "\n";


    long x, y;
    stringstream ss3(num1);
    stringstream ss4(num2);

    ss3 >> x;
    ss4 >> y;
    cout << x << endl;
    cout << y << endl;

}


int main() {


    StandardIO standardIo = StandardIO();
    DefaultIO *isd = &standardIo;
    CLI cli(isd);
    cli.start();





//    CommandsData data;
//    data.str = "aaa\n";


//    Upload_timeSeries upload = Upload_timeSeries(&standardIo, &data);
//    upload.execute();
//
//    Algorithm_settings algorithmSettings = Algorithm_settings(&standardIo, &data);
//    algorithmSettings.execute();
//
//    Detect_anomalies detectAnomalies = Detect_anomalies(&standardIo, &data);
//    detectAnomalies.execute();
//
//    Display_results displayResults = Display_results(&standardIo, &data);
//    displayResults.execute();
//
//    Anomalies_analyze_results analyzeResults=Anomalies_analyze_results(&standardIo, &data);
//    analyzeResults.execute();
//
//
//    TestCommands command = TestCommands(isd, &data);
//    Command *command1 = &command;
//    command.make();
}