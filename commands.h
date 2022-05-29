// Ori Abramovitch 315598664


#ifndef COMMANDS_H_
#define COMMANDS_H_

#include<iostream>
#include <string.h>

#include <fstream>
#include <vector>
#include <sstream>
#include "HybridAnomalyDetector.h"
#include <sys/socket.h>


#define THRESHOLD 0.9

using namespace std;

class DefaultIO {
public:
    virtual string read() = 0;

    virtual void write(string text) = 0;

    virtual void write(float f) = 0;

    virtual void read(float *f) = 0;

//    virtual void write_new_line() = 0;

    virtual ~DefaultIO() {}

    // you may add additional methods here
};

class SocketIO : public DefaultIO {

    int clientID;
public:
    SocketIO(int clientID) : clientID(clientID) {}

    virtual string read() {
        string input = "";
        char c = 0;
        recv(clientID, &c, sizeof(char), 0);
        while (c != '\n') {
            input += c;
            recv(clientID, &c, sizeof(char), 0);
        }
//        cout<<"SocketIO: read"<<endl;
        return input;
    }

    virtual void write(string text) {
        send(clientID, text.c_str(), text.length(), 0);
//        cout << "SocketIO: write-string: " << text;

    }

    virtual void write(float f) {
        string input = "";
        stringstream ss(input);
        ss << f;
        send(clientID, ss.str().c_str(), ss.str().size(), 0);

//        send(clientID, to_string(f).c_str(), 1, 0);
//        cout << "SocketIO: write-float: " << f;
    }

    virtual void read(float *f) {
        string input = "";
        char c = 0;
        recv(clientID, &c, sizeof(char), 0);
        while (c != '\n') {
            input += c;
            recv(clientID, &c, sizeof(char), 0);
        }
        stringstream ss(input);
        ss >> *f;


    }
};

class StandardIO : public DefaultIO {
public:
    StandardIO() : DefaultIO() {}


    virtual string read() {
        string str;
        cin >> str;
        return str;

    }

    virtual void write(string text) {
        cout << text;

    }

    virtual void write(float f) {
        cout << f;

    }

    virtual void read(float *f) {
        cin >> *f;

    }

    virtual void write_new_line() {
        cout << endl;
    }
};


struct CommandsData {
//    string str;
//    TimeSeries timeSeries;
    HybridAnomalyDetector hybridAnomalyDetector;
    float threshold = THRESHOLD;
    const char *trainFileName = "anomalyTrain.csv";
    const char *testFileName = "anomalyTest.csv";
    vector<AnomalyReport> reportsVec;
    long numOfTestSteps;
};

// you may add here helper classes


// you may edit this class
class Command {
protected:
    string description;
    DefaultIO *dio;
    CommandsData *data;

    virtual void upload_file(const char *outputFile) {

        ofstream out;
        out.open(outputFile);
        string line;
        while ((line = dio->read()) != "done") {
            out << line << endl;
        }
        out.close();
    }

    virtual string read() {
        return this->dio->read();
    }

    virtual void write(string text) {
        this->dio->write(text);
    }

    virtual void write_line(string text) {
        this->dio->write(text + "\n");
    }

    virtual void write_line(string text, float &f) {
        this->dio->write(text);
        this->write(f);
        this->write_new_line();
    }

    virtual void write(float f) {
        this->dio->write(f);
    }

    virtual void read(float &f) {
        this->dio->read(&f);
    }

    virtual void write_new_line() {
//        this->dio->write_new_line();
        string str;
        stringstream ss(str);
        ss << endl;

        this->dio->write(ss.str());
//        write("\n");
    }

    virtual void detect() {


    }


public:
    Command(DefaultIO *dio) : dio(dio) {}

    Command(DefaultIO *dio, CommandsData *data) : dio(dio), data(data) {}

    virtual void execute() = 0;

    virtual string get_description() {
        return this->description;
    }

    virtual ~Command() {}
};


class TestCommands : public Command {
public:
    TestCommands(DefaultIO *dio, CommandsData *data) : Command(dio, data) {

    }

    virtual void execute() {}

    void make() {
        this->read();
        this->write(1);
//        dio->write("\n");
        this->write_new_line();
//        this->write(data->str);

    }

};

// Upload a file from the client
class Upload_timeSeries : public Command {

public:
    Upload_timeSeries(DefaultIO *dio, CommandsData *data) : Command(dio, data) {
        this->description = "upload a time series csv file";
    }

    virtual void execute() {
        // Upload the files from the client
        this->write_line("Please upload your local train CSV file.");
        this->upload_file(data->trainFileName);
        this->write_line("Upload complete.");

        this->write_line("Please upload your local test CSV file.");
        this->upload_file(data->testFileName);
        this->write_line("Upload complete.");


    }
};

class Algorithm_settings : public Command {
public:
    Algorithm_settings(DefaultIO *dio, CommandsData *data) : Command(dio, data) {
        this->description = "algorithm settings";

    }

    virtual void execute() {


        float newThreshold = 0;
        this->write_line("The current correlation threshold is ", data->threshold);
        this->write_line("Type a new threshold");
        this->read(newThreshold);

        while (0 >= newThreshold || newThreshold >= 1) {
            this->write_line("please choose a value between 0 and 1.");
            this->write_line("The current correlation threshold is ", data->threshold);
            this->write_line("Type a new threshold");
            this->read(newThreshold);
        }
        this->data->threshold = newThreshold;
    }
};

class Detect_anomalies : public Command {

public:
    Detect_anomalies(DefaultIO *dio, CommandsData *data) : Command(dio, data) {
        this->description = "detect anomalies";

    }

    virtual void execute() {
//        this->detect();


        TimeSeries trainTimeSeries = TimeSeries(data->trainFileName);

        TimeSeries testTimeSeries = TimeSeries(data->testFileName);
        data->numOfTestSteps = testTimeSeries.num_of_steps();
        data->hybridAnomalyDetector.set_Threshold(data->threshold);
        data->hybridAnomalyDetector.learnNormal(trainTimeSeries);
        data->reportsVec = data->hybridAnomalyDetector.detect(testTimeSeries);

        this->write_line("anomaly detection complete.");


    }
};


class Display_results : public Command {
private:

    void write_report(AnomalyReport &report) {
        float timeStep = float(report.timeStep);
        string description = report.description;
        this->write(timeStep);
        this->write_line("\t " + description);
    }


public:
    Display_results(DefaultIO *dio, CommandsData *data) : Command(dio, data) {
        this->description = "display results";

    }

    virtual void execute() {
        vector<AnomalyReport> reportsVec = data->reportsVec;
        for (auto report:reportsVec) {
            this->write_report(report);
        }
        this->write_line("Done.");
    }


};
//


class Anomalies_analyze_results : public Command {

private:
    long convert_string(string str) {
        long x;
        stringstream ss(str);
        ss >> x;
        return x;
    }

    void get_anomaly(vector<pair<long, long>> &anomaliesVec) {
        string line;
        while ((line = dio->read()) != "done") {
            stringstream ss(line);

            string first;
            string second;
            getline(ss, first, ',');
            getline(ss, second, ' ');
//            cout << first << " " << second << endl;

            pair<long, long> anomaly = {convert_string(first), convert_string(second)};
//            cout << anomaly.first << " " << anomaly.second << endl;

            anomaliesVec.push_back(anomaly);
            ss.clear();

        }
    }

    bool isOverlap(pair<long, long> range1, pair<long, long> range2) {
        if (range1.first > range2.second || range2.first > range1.second) {
            return false;
        } else {
            return true;
        }
    }

    bool isOverlap(pair<long, long> range, vector<pair<long, long>> &rangesVec) {
        for (auto itr:rangesVec) {
            if (isOverlap(range, itr)) {
                return true;
            }
        }
        return false;
    }

    int range(pair<long, long> rang) {
        return int(rang.second - rang.first) + 1;
    }


public:
    Anomalies_analyze_results(DefaultIO *dio, CommandsData *data) : Command(dio, data) {
        this->description = "upload anomalies and analyze results";

    }

    virtual void execute() {

        // Upload the files from the client
        this->write_line("Please upload your local anomalies file.");

        vector<pair<long, long>> anomaliesRanges;
        vector<pair<long, long>> reportsRanges;

        get_anomaly(anomaliesRanges);
        this->write_line("Upload complete.");
//        data->reportsVec;

        string prevDescription;
        string currentDescription;

//        vector<AnomalyReport>::iterator report;

//        for (report = data->reportsVec.begin(); report != data->reportsVec.end(); report++) {
//        for (auto report:data->reportsVec) {


//        report = data->reportsVec.begin();


//        while (report != data->reportsVec.end()) {

        long prevSteps = data->reportsVec[0].timeStep;
        long currentSteps = data->reportsVec[0].timeStep;
        prevDescription = data->reportsVec[0].description;
        pair<long, long> range = {prevSteps, 0};

        for (auto report:data->reportsVec) {

            currentDescription = report.description;
            currentSteps = report.timeStep;
//            cout << prevDescription << " " << prevSteps << " " << currentDescription << " " << currentSteps << endl;

            if (prevDescription == currentDescription && prevSteps + 1 == currentSteps) {
                range.second = currentSteps;
            } else {
                if (range.first <= range.second) {
//                    cout << range.first << " " << range.second << endl;
                    reportsRanges.push_back(range);
                }
                range = {currentSteps, 0};

            }
            prevDescription = report.description;
            prevSteps = report.timeStep;

        }
        if (range.first <= range.second) {
//            cout << range.first << " " << range.second << endl;
            reportsRanges.push_back(range);
        }

//        cout << endl;
//        for (auto itr:anomaliesRanges) {
//            cout << itr.first << " " << itr.second << endl;
//        }
//        cout << endl;
//        for (auto itr:reportsRanges) {
//            cout << itr.first << " " << itr.second << endl;
//        }

        int numOfAnomaliesInFile; // num of anomalies in the file
        int numOfStepsInReports = 0;    // num of steps with anomalies
        int falsePositive = 0;
        int truePositive = 0;


        // positive
        numOfAnomaliesInFile = anomaliesRanges.size();

        for (auto anomaly:anomaliesRanges) {
            numOfStepsInReports = int(anomaly.second - anomaly.first) + 1;
//            cout << "anomaly: " << numOfStepsInReports << endl;
        }

        // negative
        int N = int(data->numOfTestSteps) - numOfStepsInReports;


        for (auto report:reportsRanges) {
            if (!isOverlap(report, anomaliesRanges)) {
                falsePositive++;
//                falsePositive = falsePositive + int(report.second - report.first) + 1;

            }
        }
        for (auto anomaly:anomaliesRanges) {
            if (isOverlap(anomaly, reportsRanges)) {
//                truePositive = truePositive + int(anomaly.second - anomaly.first) + 1;
                truePositive++;
            }
        }


        float truePositiveRate = float(truePositive) / float(numOfAnomaliesInFile);

        this->write("True Positive Rate: ");
        this->write(floor(truePositiveRate * 1000) / 1000);
        this->write_new_line();


        float falsePositiveRate = float(falsePositive) / float(N);

        this->write("False Positive Rate: ");
        this->write(floor(falsePositiveRate * 1000) / 1000);
        this->write_new_line();

    }

};


class Exit : public Command {
public:
    Exit(DefaultIO *dio, CommandsData *data) : Command(dio, data) {
        this->description = "exit";

    }

    virtual void execute() {}
};



// implement here your command classes



#endif /* COMMANDS_H_ */
