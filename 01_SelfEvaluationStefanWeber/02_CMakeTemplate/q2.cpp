# include <iostream>

double maxValue(double data[], int len){

    double max = data[0];
    for (int i =1; i<len;i++){
        if (max < data[i]){
            max = data[i];
        };
    };
    return max;
};

double avrageValue(double data[], int len){
    double avrage = 0;
    for(int i = 0; i < len; i++){
        avrage += data[i];
    };
    avrage /= len;
    return avrage;
}

int main() {
    int len = 10;
    double data[]= {2.4, 5.2, 3.7, 1.9, 7.4, 3.4, 4.6, 3.9, 6.4, 5.8};

    double maximum = maxValue(data, len);
    double avrage = avrageValue(data, len);

    std::cout<<"Maximum: "<< maximum << " Avrage: "<< avrage << std::endl;
    return 0;
}