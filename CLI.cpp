// Ori Abramovitch 315598664

#include "CLI.h"

CLI::CLI(DefaultIO *dio) : dio(dio) {
    this->initial_menu();
}


void CLI::start() {

    float option;
    this->write_menu();
    dio->read(&option);
    while (option != 6.0f) {
        this->menuVec[option - 1]->execute();
        this->write_menu();
        dio->read(&option);
    }

    return;



//    for (auto command: this->menuVec) {
//        command->execute();
//    }
//    this->menuVec[4]->execute();
//    this->menuVec[4]->execute();
//    this->menuVec[4]->execute();
//    this->menuVec[4]->execute();
//    this->menuVec[4]->execute();


}


CLI::~CLI() {
    for (auto command: this->menuVec) {
        delete command;
    }

}

void CLI::initial_menu() {
//    Upload_timeSeries *uploadTimeSeries=new Upload_timeSeries(this->dio, &this->data);
    this->menuVec.push_back(new Upload_timeSeries(this->dio, &this->data));
//
//    Algorithm_settings algorithmSettings(this->dio, &this->data);
    this->menuVec.push_back(new Algorithm_settings(this->dio, &this->data));
//
//    Detect_anomalies detectAnomalies(this->dio, &this->data);
    this->menuVec.push_back(new Detect_anomalies(this->dio, &this->data));
//
//    Display_results displayResults(this->dio, &this->data);
    this->menuVec.push_back(new Display_results(this->dio, &this->data));
//
//    Anomalies_analyze_results anomaliesAnalyzeResults(this->dio, &this->data);
    this->menuVec.push_back(new Anomalies_analyze_results(this->dio, &this->data));

    this->menuVec.push_back(new Exit(this->dio, &this->data));


}

void CLI::write_menu() {
    string str;
    stringstream ss(str);
    ss << endl;
    string end = ss.str();

//    dio->write("Welcome to the Anomaly Detection Server.\r\n");

    dio->write("Welcome to the Anomaly Detection Server." + end);
    dio->write("Please choose an option:" + end);
    float option = 1;
    for (auto command: this->menuVec) {
        dio->write(option);
        dio->write("." + command->get_description() + end);
        option++;

    }

}


