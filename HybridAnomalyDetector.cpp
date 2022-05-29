// Ori Abramovitch 315598664

#include "HybridAnomalyDetector.h"


/**
HybridAnomalyDetector::HybridAnomalyDetector() {
	// TODO Auto-generated constructor stub

}
**/
//
//HybridAnomalyDetector::~HybridAnomalyDetector() {
//	// TODO Auto-generated destructor stub
//}
Point **generate_arr(vector<float> &vecA, vector<float> &vecB, int size) {
    Point **arrP = new Point *[size];
    for (size_t i = 0; i < size; i++) {
        float x = vecA[i];
        float y = vecB[i];
        arrP[i] = new Point(x, y);
    }
    return arrP;
}


void HybridAnomalyDetector::insert_additional_features(const TimeSeries &ts, vector<pair<int, float>> &correlations) {
    vector<float> vecA, vecB;
    vector<string> headers_vec = ts.get_headers();
    int vec_size = ts.num_of_steps();
    int i = 0;
    for (auto itr:correlations) {

        if (itr.first == -1 || itr.second >= this->Threshold || itr.second < LOWER_THRESHOLD) {
            i++;
            continue;
        }
        vecA = ts.get_vector(headers_vec[i]);
        vecB = ts.get_vector(headers_vec[itr.first]);
        Point **arrP = generate_arr(vecA, vecB, vec_size);

        if (i < itr.first) {
            Circle circle = findMinCircle(arrP, vec_size);
            float radius = float(1.1) * circle.radius;
            float x = circle.center.x;
            float y = circle.center.y;
            cf.push_back({headers_vec[i], headers_vec[itr.first], itr.second, Line(), radius, x, y});
        } else {
            if (correlations[itr.first].first != i) {
                Circle circle = findMinCircle(arrP, vec_size);
                float radius = float(1.1) * circle.radius;
                float x = circle.center.x;
                float y = circle.center.y;
                cf.push_back({headers_vec[itr.first], headers_vec[i], itr.second, Line(), radius, x, y});
            }
        }
        for (int j = 0; j < vec_size; j++) {
            delete arrP[j];
        }
        delete[] arrP;
        i++;
    }
}


void HybridAnomalyDetector::learnNormal(const TimeSeries &ts) {
    int headers_size = ts.num_of_headers();
    vector<pair<int, float>> correlations(headers_size, pair<int, float>(-1, 0.0));
    all_correlations(ts, correlations);
    insert_features(ts, correlations);
    insert_additional_features(ts, correlations);
}


void HybridAnomalyDetector::detect_Hybrid_helper(const TimeSeries &ts, vector<AnomalyReport> &reportsVec, int step,
                                                 correlatedFeatures &features) {

    string feature1 = features.feature1;
    string feature2 = features.feature2;

    float x = ts.get_value(feature1, step);
    float y = ts.get_value(feature2, step);

    Point point = {x, y};


    Point center = {features.x, features.y};
    float radius = features.threshold;
    Circle circle = Circle(center, radius);


    if (!is_in_circle(point, circle)) {
        string description;
        description = feature1 + "-" + feature2;
        long timeStep = step;
        reportsVec.emplace_back(description, timeStep);

    }

}

vector<AnomalyReport> HybridAnomalyDetector::detect(const TimeSeries &ts) {
    vector<AnomalyReport> reportsVec;





    int num_of_steps = ts.num_of_steps();


    for (auto itr:cf) {
        for (int i = 1; i <= num_of_steps; ++i) {
            if (itr.corrlation >= this->Threshold) {
                detect_helper(ts, reportsVec, i, itr);
            } else {
                detect_Hybrid_helper(ts, reportsVec, i, itr);
            }

        }
    }
//    for(auto myitr:reportsVec){
//        cout<<myitr.timeStep<<"\t"<<myitr.description<<endl;
////        cout<<"Hey!!"<<endl;
//    }


    return reportsVec;
}