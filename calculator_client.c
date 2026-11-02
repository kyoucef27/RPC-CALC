#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    CLIENT *cl;
    floatpair args;
    floatsingle single_args;
    float *result;
    char op;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server_ip>\n", argv[0]);
        exit(1);
    }

    cl = clnt_create(argv[1], CALCULATOR_PROG, CALCULATOR_VERS, "udp");
    if (cl == NULL) {
        clnt_pcreateerror(argv[1]);
        exit(1);
    }

    printf("Choose operation (+, -, *, /, %%, ^, r for square root): ");
    if (scanf(" %c", &op) != 1) {
        fprintf(stderr, "Failed to read operation.\n");
        clnt_destroy(cl);
        exit(1);
    }

    if (op == 'r') {
        printf("Enter operand: ");
        if (scanf("%f", &single_args.a) != 1) {
            fprintf(stderr, "Invalid operand.\n");
            clnt_destroy(cl);
            exit(1);
        }
        result = racine_1(&single_args, cl);
    } else {
        printf("Enter two operands: ");
        if (scanf("%f %f", &args.a, &args.b) != 2) {
            fprintf(stderr, "Invalid operands.\n");
            clnt_destroy(cl);
            exit(1);
        }
        switch (op) {
            case '+': result = add_1(&args, cl); break;
            case '-': result = sub_1(&args, cl); break;
            case '*': result = mul_1(&args, cl); break;
            case '/': result = div_1(&args, cl); break;
            case '%': result = mod_1(&args, cl); break;
            case '^': result = puissance_1(&args, cl); break;
            default:
                printf("Invalid operation.\n");
                clnt_destroy(cl);
                exit(1);
        }
    }

    if (result == NULL) {
        clnt_perror(cl, "RPC call failed");
    } else {
        printf("Result: %.2f\n", *result);
    }

    clnt_destroy(cl);
    return 0;
}
