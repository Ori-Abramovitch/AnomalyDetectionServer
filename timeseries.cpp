// Ori Abramovitch 315598664

#include <fstream>
#include <sstream>
#include <assert.h>
#include <iostream>
#include "timeseries.h"

using namespace std;

// Constructor by csv file
TimeSeries::TimeSeries(const char *CSVfileName) {
    fstream my_file;
    my_file.open(CSVfileName);
    string headers, line;
    getline(my_file, headers);

    insert_headers(headers);
    while (getline(my_file, line)) {
        insert_line(line);
    }
    my_file.close();
}


/**
     * insert_headers
     * helper to Constructor by csv file:
     *
     * initializes the vector that contains all the headers from the csv file.
     * initializes the map with all the headers.
     *
     * gets a string with all the headers.
     * in each step in the loop inserts one header into "_headers_vec" and into "_my_map".
     *
     * @param line_headers
     */
void TimeSeries::insert_headers(const string &line_headers) {

    // goes through all the headers in the string
    stringstream ss(line_headers);
    string header;
    while (ss.good()) {
        getline(ss, header, ',');
        // inserts one header into "_headers_vec".
        _headers_vec.push_back((header));
        // inserts one header into "_my_map".
        vector<float> vec;
        _my_map.insert(pair<string, std::vector<float>>(header, vec));
    }
}

/**
 * insert_line
 *
 * helper to Constructor by csv file:
 * gets a row, and puts any value into the correct column
 *
 * @param line
 */
void TimeSeries::insert_line(const string &line) {
    stringstream ss(line);
    string num;


    for (auto &itr : _my_map) {
        getline(ss, num, ',');
        itr.second.push_back(stof(num));
    }

//    map<string, vector<float>>::iterator itr;
//    for (itr = _my_map.begin(); itr != _my_map.end(); itr++) {
//        getline(ss, num, ',');
//        itr->second.push_back(stof(num));
//    }

}

// returns the vector of the headers
const vector<string> &TimeSeries::get_headers() const {
    return _headers_vec;
}

// gets a header, and returns the appropriate column
const vector<float> &TimeSeries::get_vector(const string &header) const {
//    map<string, vector<float>>::iterator itr;
    auto itr = _my_map.find(header);
    if (itr == _my_map.end()) {
        cout << "assert: get_vector" << std::endl;
        assert(0);;
    } else {
        return itr->second;
    }

}

// Constructor by map
TimeSeries::TimeSeries(const map<string, vector<float>> &new_map) {
    this->_my_map = new_map;
    //new_map.insert(pair<string,vector<float>>("ss",{0,1}));
    map<string, vector<float>>::const_iterator itr;
    for (itr = _my_map.begin(); itr != _my_map.end(); itr++) {
        this->_headers_vec.push_back(itr->first);
    }
}

// Copy Constructor
TimeSeries::TimeSeries(const TimeSeries &other) {
    _my_map = other._my_map;
    _headers_vec = other._headers_vec;
}


//Copy assignment operator
TimeSeries &TimeSeries::operator=(const TimeSeries &other) {
    if (this == &other) {
        return *this;
    }
    *this = TimeSeries(other);
    return *this;
}


// Move Constructor
TimeSeries::TimeSeries(TimeSeries &&other) noexcept {
    _my_map = move(other._my_map);
    _headers_vec = move(other._headers_vec);

}

// Move assignment operator
TimeSeries &TimeSeries::operator=(TimeSeries &&other) noexcept {
    if (this == &other) {
        return *this;
    }
    _my_map = move(other._my_map);
    _headers_vec = move(other._headers_vec);

    return *this;
}

// gets an header and line number, and returns the value
float TimeSeries::get_value(const string &header, long timeStep) const {
    map<string, vector<float>>::const_iterator itr;
    itr = _my_map.find(header);
    if (itr == _my_map.end()) {
//        cout << "assert: get_value #1" << std::endl;
//        assert(0);;
    }
    vector<float> vec = itr->second;
    if (timeStep > vec.size()) {
//        cout << "assert: get_value #2" << std::endl;
//        assert(0);;
    }
    return vec[timeStep - 1];
}

// returns the number of rows
int TimeSeries::num_of_steps() const {
    map<string, vector<float>>::const_iterator itr;
    itr = _my_map.begin();
    if (itr == _my_map.end()) {
        return 0;
    }
    return (int) itr->second.size();
}

// returns the number of headers
int TimeSeries::num_of_headers() const {
    return _headers_vec.size();
}


