// Ori Abramovitch 315598664
#include <iostream>
#include "SimpleAnomalyDetector.h"


// finds all the correlations between the columns in TimeSeries
// For each pair of columns calculate their correlations
void SimpleAnomalyDetector::all_correlations(const TimeSeries &ts, vector<pair<int, float>> &correlations) {
    vector<float> vecA, vecB;
    vector<string> headers_vec = ts.get_headers();
    int headers_size = ts.num_of_headers();
    int vec_size = ts.num_of_steps();


    for (int i = 0; i < headers_size; ++i) {
        for (int j = i + 1; j < headers_size; ++j) {
            vecA = ts.get_vector(headers_vec[i]);
            float *arrA = vecA.data();
            vecB = ts.get_vector(headers_vec[j]);
            float *arrB = vecB.data();

            float pear = pearson(arrA, arrB, vec_size);

            if (pear > correlations[i].second) {
                correlations[i] = pair<int, float>(j, pear);
            }
            if (pear > correlations[j].second) {
                correlations[j] = pair<int, float>(i, pear);
            }
        }
    }
}

// gets two vectors, and creates from them an array of points
// using the array, calculate the regression line
Line SimpleAnomalyDetector::find_lin_reg(vector<float> &vecA, vector<float> &vecB, int size) {
    float *arrA = vecA.data();
    float *arrB = vecB.data();

    Point *points[size];
    for (int i = 0; i < size; ++i) {
        Point *point = new Point(arrA[i], arrB[i]);
        points[i] = point;
    }
    Line reg = linear_reg(points, size);

    for (int i = 0; i < size; ++i) {
        delete points[i];
    }
    return reg;
}

// gets two vectors
// finds the largest deviation
float SimpleAnomalyDetector::find_dev(vector<float> &vecA, vector<float> &vecB, int size, Line reg) {
    float *arrA = vecA.data();
    float *arrB = vecB.data();

    float maxDev = 0;
    float tempDev;
    for (int i = 0; i < size; ++i) {
        Point point = {arrA[i], arrB[i]};
        tempDev = dev(point, reg);
        if (tempDev > maxDev) {
            maxDev = tempDev;
        }
    }
    return maxDev;
}

// gets a vector of all the correlations
// checks if the correlations are large enough
// if so, put the collection in cf with the regression line and the threshold
void SimpleAnomalyDetector::insert_features(const TimeSeries &ts, vector<pair<int, float>> &correlations) {
    vector<float> vecA, vecB;
    vector<string> headers_vec = ts.get_headers();
    int vec_size = ts.num_of_steps();
    int i = 0;
    for (auto itr:correlations) {


        if (itr.first == -1 || itr.second < this->Threshold) {
            i++;
            continue;
        }
        vecA = ts.get_vector(headers_vec[i]);
        vecB = ts.get_vector(headers_vec[itr.first]);

        if (i < itr.first) {
            Line reg = find_lin_reg(vecA, vecB, vec_size);
            float threshold = float(1.1) * find_dev(vecA, vecB, vec_size, reg);
            cf.push_back({headers_vec[i], headers_vec[itr.first], itr.second, reg, threshold});
        } else {
            if (correlations[itr.first].first != i) {
                Line reg = find_lin_reg(vecB, vecA, vec_size);
                float threshold = float(1.1) * find_dev(vecA, vecB, vec_size, reg);
                cf.push_back({headers_vec[itr.first], headers_vec[i], itr.second, reg, threshold});
            }
        }
        i++;
    }
}

void SimpleAnomalyDetector::learnNormal(const TimeSeries &ts) {

    int headers_size = ts.num_of_headers();
    vector<pair<int, float>> correlations(headers_size, pair<int, float>(-1, 0.0));
    all_correlations(ts, correlations);
    insert_features(ts, correlations);

//    for (auto itr:cf) {
//        std::cout << "feature1: " << itr.feature1 << " feature2: " << itr.feature2 << " corrlation: " << itr.corrlation
//                  << " lin_reg: "
//                  << itr.lin_reg.a << " lin_reg: "
//                  << itr.lin_reg.b << " threshold: " << itr.threshold << std::endl;
//    }

}


void SimpleAnomalyDetector::detect_helper(const TimeSeries &ts, vector<AnomalyReport> &reportsVec, int step,
                                          correlatedFeatures &features) {

    string feature1 = features.feature1;
    string feature2 = features.feature2;

    float x = ts.get_value(feature1, step);
    float y = ts.get_value(feature2, step);

    Point point = {x, y};

    float threshold = features.threshold;
    Line reg = features.lin_reg;

    float deve = dev(point, reg);

    if (threshold < deve) {
        string description;
        description = feature1 + "-" + feature2;
        long timeStep = step;
        reportsVec.emplace_back(description, timeStep);

    }

}

vector<AnomalyReport> SimpleAnomalyDetector::detect(const TimeSeries &ts) {
    vector<AnomalyReport> reportsVec;




    int num_of_steps = ts.num_of_steps();
    for (auto itr:cf) {
        for (int i = 1; i <= num_of_steps; ++i) {

            detect_helper(ts, reportsVec, i, itr);


        }
    }
    return reportsVec;
}



