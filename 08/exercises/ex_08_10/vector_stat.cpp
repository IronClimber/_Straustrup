#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

struct VectorStat {
    double min;
    double max;
    double avarage;
    double median;
};
//What if v is empty?
VectorStat get_vector_stat(vector<double>& v) {
    VectorStat vs;
    vs.min = v[0];
    vs.max = v[0];
    float sum = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i]>vs.max) {
            vs.max = v[i];
        }
        if (v[i]<vs.min) {
            vs.min = v[i];
        }
        sum += v[i];
    }
    vs.avarage = sum/v.size();
    sort(v.begin(), v.end());
    
    if (v.size()%2 == 1) {
        vs.median = v[v.size()/2];
    }
    else {
        vs.median = (v[v.size()/2] + v[v.size()/2-1])/2.0;
    }
    //If I sort vector I change it. Is it OK?
    return vs;
}

vector<double> price{5.4, -5.2, 7.2, 3.7, 2.1, 2.7, 10.912};

int main() {
    VectorStat stat;
    stat = get_vector_stat(price);
	cout<<"Max: "<<stat.max<<endl;
    cout<<"Min: "<<stat.min<<endl;
    cout<<"Avarage: "<<stat.avarage<<endl;
    cout<<"Median: "<<stat.median<<endl;	
    return 0;
}
