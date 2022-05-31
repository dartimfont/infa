#include <iostream>

struct Vector {
    int dim = 0;
    double* coords;
};

Vector* initVector(const int dim) {
    Vector* newVec = new Vector;
    newVec->dim = dim;
    newVec->coords = new double[dim];
    return newVec;
}

void inputVector(Vector** vec) {
    for (int i = 0; i < (*vec)->dim; i++) {
        std::cin >> (*vec)->coords[i];
    }
}

void outputVector(Vector* vec) {
    for (int i = 0; i < vec->dim; i++) {
        std::cout << vec->coords[i] << " ";
    }
    std::cout << std::endl;
}

void sumVec(Vector* vec_1, Vector* vec_2) {
    Vector* vecRes = initVector(vec_1->dim);
    for (int i = 0; i < vecRes->dim; i++) {
        vecRes->coords[i] = vec_1->coords[i] + vec_2->coords[i];
    }
    std::cout << "vec 1 + vec 2 = ";
    outputVector(vecRes);
}

void raznostVec(Vector* vec_1, Vector* vec_2) {
    Vector* vecRes = initVector(vec_1->dim);
    for (int i = 0; i < vecRes->dim; i++) {
        vecRes->coords[i] = vec_1->coords[i] - vec_2->coords[i];
    }
    std::cout << "vec 1 - vec 2 = ";
    outputVector(vecRes);
}

void multVecForScale(Vector* vec, const double scale) {
    Vector* vecRes = initVector(vec->dim);
    for (int i = 0; i < vecRes->dim; i++) {
        vecRes->coords[i] = scale * vec->coords[i];
    }
    std::cout << "vec * " << scale << " = ";
    outputVector(vecRes);
}

void equalVecs(Vector* vec_1, Vector* vec_2) {
    bool flag = true;
    for (int i = 0; i < vec_1->dim; i++) {
        if (vec_1->coords[i] != vec_2->coords[i]) {
            flag = false;
        }
    }

    if (flag) {
        std::cout << "vec 1 equal vec2\n";
    }
    else {
        std::cout << "vec 1 not equal vec2\n";
    }
}

void deleteVector(Vector** vec) {
    if (*vec != NULL) {
        delete[](*vec)->coords;
        (*vec)->dim = 0;
    }
}

void init(Vector** vec_1, Vector** vec_2) {
    int dim;
    deleteVector(vec_1);
    deleteVector(vec_2);
    std::cout << "Input dimmension of vectors: ";
    std::cin >> dim;
    *vec_1 = initVector(dim);
    *vec_2 = initVector(dim);
    std::cout << "vec 1 = ";
    inputVector(vec_1);
    std::cout << "vec 2 = ";
    inputVector(vec_2);
}

void forScale(Vector** vec) {
    int dim, scale;
    deleteVector(vec);
    std::cout << "Input dimmension of vectors: ";
    std::cin >> dim;
    *vec = initVector(dim);
    std::cout << "vec = ";
    inputVector(vec);
    std::cout << "Input scalar: ";
    std::cin >> scale;
    multVecForScale(*vec, scale);
}

void printMenu() {
    std::cout   << "1. Input Vectors."              << std::endl
                << "2. Sum."                        << std::endl
                << "3. Raznost."                    << std::endl
                << "4. Mult Vec For Scale."         << std::endl
                << "5. Equal Vecs."                 << std::endl
                << "6. Clear."                      << std::endl
                << "7. Exit."                       << std::endl
                << std::endl;
}

int main() {
    int ch = -1;
    Vector* vec_1 = NULL;
    Vector* vec_2 = NULL;
    Vector* vec = NULL;

    printMenu();

    while (ch != 7) {
        std::cout << "Choose: ";
        std::cin >> ch;
        switch (ch) {
            case 1: {
                init(&vec_1, &vec_2);
            } break;
            case 2: {
                sumVec(vec_1, vec_2);
            } break;
            case 3: {
                raznostVec(vec_1, vec_2);
            } break;
            case 4: {
                forScale(&vec);
            } break;
            case 5: {
                equalVecs(vec_1, vec_2);
            } break;
            case 6: {
                system("cls");
                printMenu();
            } break;
        }
    }

    deleteVector(&vec_1);
    deleteVector(&vec_2);
    deleteVector(&vec);
    system("pause");
    return 0;
}