#include "calculator.h"
#include <math.h>
#include <stdio.h>

float *add_1_svc(floatpair *args, struct svc_req *req) {
    static float result;
    result = args->a + args->b;
    return &result;
}

float *sub_1_svc(floatpair *args, struct svc_req *req) {
    static float result;
    result = args->a - args->b;
    return &result;
}

float *mul_1_svc(floatpair *args, struct svc_req *req) {
    static float result;
    result = args->a * args->b;
    return &result;
}

float *div_1_svc(floatpair *args, struct svc_req *req) {
    static float result;
    if (args->b == 0.0) {
        printf("Error: Division by zero\n");
        result = 0.0;
    } else {
        result = args->a / args->b;
    }
    return &result;
}

float *mod_1_svc(floatpair *args, struct svc_req *req) {
    static float result;
    if (args->b == 0.0) {
        printf("Error: Modulo by zero\n");
        result = 0.0;
    } else {
        result = fmod(args->a, args->b);
    }
    return &result;
}

float *puissance_1_svc(floatpair *args, struct svc_req *req) {
    static float result;
    result = pow(args->a, args->b);
    return &result;
}

float *racine_1_svc(floatsingle *args, struct svc_req *req) {
    static float result;
    if (args->a < 0.0) {
        printf("Error: Square root of negative number\n");
        result = 0.0;
    } else {
        result = sqrt(args->a);
    }
    return &result;
}
