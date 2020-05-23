#include <iostream>

// struct A {
//     A(void);
//     void a(void);
//     void b(void);
//     void make(void);
//     float c[2];
// };

// A::A() {
//     make();
// }

// void A::make() {
//     // float c[2] = {0, 0};
// }


// void A::a() {
//     std::cout << 'a' << std::endl;
// }
// void A::b() {
//     a();
//     std::cout << c[0] << c[1] << std::endl;
// }


// struct SandBox {
//     void fillRandomColors(void);
//     void fillMatrices(void);
//     SandBox();
//     // SandBox(glm::mat3 mat[], float colors[]);
//     // ~SandBox();
//     float colors[n];
//     glm::mat3 mat[n];
// };

// SandBox::SandBox() {
//     fillRandomColors();
//     fillMatrices();
// }


// void SandBox::fillRandomColors(void) {
//     for (int i=0; i<n; i++) {
//         colors[i] = (float(rand())/RAND_MAX+1)/2;
//     }
// }


// void SandBox::fillMatrices(void) {
//     for (int i=0; i<n; i++) {
//         for (int j=0; j<3; j++) {
//             mat[i][0][j] = float((rand()%200)-100);
//             mat[i][1][j] = 0;
//             mat[i][2][j] = 0;
//         }
//     }
// }

// #include "SandBox.cpp"
#include "glm/glm.hpp"

int main(int argc, char **argv)
{
    // glm::vec3 v1(2.5, 0.2, -2.9);
    // glm::vec3 v2(2, 0, -2);
    // glm::vec3 v = v1*v2;
    // std::cout << v1[0] << "," << v1[1] << "," << v2[2] << std::endl;
    // std::cout << v2[0] << "," << v2[1] << "," << v2[2] << std::endl;

    // std::cout << v[0] << "," << v[1] << "," << v[2] << std::endl;

    glm::fmat3 m=glm::fmat3(0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9);
    std::cout << m[0][0] << std::endl;


    // SandBox sandBox;
    // std::cout << sandBox.matrices[23][0][1] << std::endl;
    // A a;
    // a.b();
    return 0;
}
