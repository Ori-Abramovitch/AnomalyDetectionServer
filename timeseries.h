// Ori Abramovitch 315598664


#ifndef TIMESERIES_H_
#define TIMESERIES_H_

#include <map>
#include <vector>

using namespace std;

class TimeSeries {

private:
    vector<string> _headers_vec;
    map<string, vector<float >> _my_map;


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
    void insert_headers(const string &line_headers);

    /**
     * insert_line
     *
     * helper to Constructor by csv file:
     * gets a row, and puts any value into the correct column
     *
     * @param line
     */
    void insert_line(const string &line);

public:

    TimeSeries() = default;

    // Constructor by csv file
    TimeSeries(const char *CSVfileName);

    // Constructor by map
    TimeSeries(const map<string, vector<float >> &new_map);

    // Copy Constructor
    TimeSeries(const TimeSeries &other);

    //Copy assignment operator
    TimeSeries &operator=(const TimeSeries &other);

    // Move Constructor
    TimeSeries(TimeSeries &&other) noexcept;

    // Move assignment operator
    TimeSeries &operator=(TimeSeries &&other) noexcept;

//    const map<string, vector<float >> &get_map() const {
//        return _my_map;
//    }


    // returns the vector of the headers
    const vector<string> &get_headers() const;

    // gets a header, and returns the appropriate column
    const vector<float> &get_vector(const string &header) const;

    // gets an header and line number, and returns the value
    float get_value(const string &header, long timeStep) const;

    // returns the number of rows
    int num_of_steps() const;

    // returns the number of headers
    int num_of_headers() const;


    ~TimeSeries() = default;

};


#endif /* TIMESERIES_H_ */
