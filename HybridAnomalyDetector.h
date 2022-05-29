// Ori Abramovitch 315598664


#ifndef HYBRIDANOMALYDETECTOR_H_
#define HYBRIDANOMALYDETECTOR_H_

#include "SimpleAnomalyDetector.h"
#include "minCircle.h"

#define LOWER_THRESHOLD 0.5


class HybridAnomalyDetector : public SimpleAnomalyDetector {


private:
    void insert_additional_features(const TimeSeries &ts, vector<pair<int, float>> &correlations);
    void detect_Hybrid_helper(const TimeSeries &ts, vector<AnomalyReport> &reportsVec, int step,
                              correlatedFeatures &features);
public:
    HybridAnomalyDetector() = default;

    virtual ~HybridAnomalyDetector() = default;

    virtual void learnNormal(const TimeSeries &ts) override;

    virtual vector<AnomalyReport> detect(const TimeSeries &ts) override;


};

#endif /* HYBRIDANOMALYDETECTOR_H_ */
