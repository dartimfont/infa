#include <iostream>

struct Vector {
    int dim;
    double* coords;
};

Vector* initVector (const int dim) {
    Vector* newVec = new Vector;
    newVec->dim = dim;
    newVec->coords = new double[dim];
    return newVec;
}

void inputVector (Vector** vec) {
    for (int i = 0; i < (*vec)->dim; i++) {
        std::cin >> (*vec)->coords[i];
    }
}

void outputVector (Vector* vec) {
    for (int i = 0; i < vec->dim; i++) {
        std::cout << vec->coords[i] << " ";
    }
    std::cout << std::endl;
}

void sumVec (Vector** res, Vector* vec_1, Vector* vec_2) {
    for (int i = 0; i < (*res)->dim; i++) {
        (*res)->coords[i] = vec_1->coords[i] + vec_2->coords[i];
    }
}

void raznostVec (Vector** res, Vector* vec_1, Vector* vec_2) {
    for (int i = 0; i < (*res)->dim; i++) {
        (*res)->coords[i] = vec_1->coords[i] - vec_2->coords[i];
    }
}

void multVecForScale (Vector** res, Vector* vec, const double scale) {
    for (int i = 0; i < (*res)->dim; i++) {
        (*res)->coords[i] = scale * vec->coords[i];
    }
}

bool equalVecs (Vector* vec_1, Vector* vec_2) {
    for (int i = 0; i < vec_1->dim; i++) {
        if (vec_1->coords[i] != vec_2->coords[i]) {
            return false;
        }
    }
    return true;
}

void test1() {
    int dim;
    std::cout << "Input dimmension of vectors: ";
    std::cin >> dim;

    Vector* vec_1 = initVector (dim);
    Vector* vec_2 = initVector (dim);
    Vector* vecRes = initVector (dim);

    std::cout << "vec 1 = ";
    inputVector (&vec_1);
 
    std::cout << "vec 2 = ";
    inputVector (&vec_2);

    sumVec (&vecRes, vec_1, vec_2);
    std::cout << "vec 1 + vec 2 = ";
    outputVector (vecRes);

    raznostVec (&vecRes, vec_1, vec_2);
    std::cout << "vec 1 - vec 2 = ";
    outputVector (vecRes);

    multVecForScale (&vecRes, vec_1, 5);
    std::cout << "5 * vec 1 = ";
    outputVector (vecRes);

    if (equalVecs (vec_1, vec_2)) {
        std::cout << "vec 1 equal vec2\n";
    } else {
        std::cout << "vec 1 not equal vec2\n";
    }

}

int main () {
    test1();   

    

    return 0;
}