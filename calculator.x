/* calculator.x : Extended RPC Interface Definition for Calculator */

struct floatpair {
    float a;
    float b;
};

struct floatsingle {
    float a;
};

program CALCULATOR_PROG {
    version CALCULATOR_VERS {
        float ADD(floatpair) = 1;
        float SUB(floatpair) = 2;
        float MUL(floatpair) = 3;
        float DIV(floatpair) = 4;
        float MOD(floatpair) = 5;
        float PUISSANCE(floatpair) = 6;
        float RACINE(floatsingle) = 7;
    } = 1;
} = 0x31234567;