#include <stdio.h> 
#include <stdlib.h>

float* temp_conv(float lower, float upper, float step);

int main() {
    float lower_bound=0;
    float step=20;
    float upper_bound=300;

    int index;

    float *result=malloc(15*sizeof(float));
    result=temp_conv(lower_bound,upper_bound,step);
    printf("The converted series of fahr:\n");
    for(index=0;index<15;++index){
        printf("%f ",result[index]);
    }

    return 0;
}

float* temp_conv(float lower, float upper, float step){
    int index;
    float current_celsius;
    int total=(upper-lower)/step;
    float *fahr_array=malloc(total*sizeof(float));
    for(index=0;index<total;++index){
        current_celsius=lower+index*step;
        fahr_array[index]=5*(current_celsius-32)/9;
    }
    return fahr_array;
}