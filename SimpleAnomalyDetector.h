// Ori Abramovitch 315598664


#ifndef SIMPLEANOMALYDETECTOR_H_
#define SIMPLEANOMALYDETECTOR_H_

#include "anomaly_detection_util.h"
#include "AnomalyDetector.h"
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>


#define THRESHOLD 0.9


struct correlatedFeatures {
    string feature1, feature2;  // names of the correlated insert_features
    float corrlation;
    Line lin_reg;
    float threshold;
    float x;
    float y;
    // you can add feilds
};


class SimpleAnomalyDetector : public TimeSeriesAnomalyDetector {


protected:
    vector<correlatedFeatures> cf;
    float Threshold = THRESHOLD;

    void all_correlations(const TimeSeries &ts, vector<pair<int, float>> &correlations);

    void insert_features(const TimeSeries &ts, vector<pair<int, float>> &correlations);

    Line find_lin_reg(vector<float> &vecA, vector<float> &vecB, int size);

    float find_dev(vector<float> &vecA, vector<float> &vecB, int size, Line reg);

    void detect_helper(const TimeSeries &ts, vector<AnomalyReport> &reportsVec, int step, correlatedFeatures &features);

public:
    SimpleAnomalyDetector() = default;

    virtual ~SimpleAnomalyDetector() = default;

    virtual void learnNormal(const TimeSeries &ts);

    virtual vector<AnomalyReport> detect(const TimeSeries &ts);

    vector<correlatedFeatures> getNormalModel() {
        return cf;
    }

    void set_Threshold(float newThreshold) {
        this->Threshold = newThreshold;
    }


};


#endif /* SIMPLEANOMALYDETECTOR_H_ */
