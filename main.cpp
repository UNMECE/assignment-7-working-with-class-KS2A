#include <stdio.h>
#include <math.h>

class Electric_Field
{
private:
    double* E;
public:
    // default constructor
    Electric_Field() {
        E = new double[3] {0.0, 0.0, 0.0};
    }

    // parametized unit
    Electric_Field(double a, double b, double c) {
        E = new double[3] {a, b, c};
    }

    // deconstructor
    ~Electric_Field() {
        delete[] E;
    }

    // getter
    double geta() const { return E[0]; }
    double getb() const { return E[1]; }
    double getc() const { return E[2]; }

    // setter
    void electric_setter(double a, double b, double c) {
        E[0] = a;
        E[1] = b;
        E[2] = c;
    }

    // calculate magnitude
    double calculateMagnitude() {
        return sqrt(E[0] * E[0] + E[1] * E[1] + E[2] + E[2]);
    }

    // inner product
    double inner_product() {
        return E[0] * E[0] + E[1] * E[1] + E[2] + E[2];
    }
};

class Magnetic_Field
{
private:
    double* M;
public:
    // default constructor
    Magnetic_Field() {
        M = new double[3] {0.0, 0.0, 0.0};
    }

    // parametized unit
    Magnetic_Field(double x, double y, double z) {
        M = new double[3] {x, y, z};
    }

    // deconstructor
    ~Magnetic_Field() {
        delete[] M;
    }

    // getter
    double getx() const { return M[0]; }
    double gety() const { return M[1]; }
    double getz() const { return M[2]; }

    // setter
    void magnetic_setter(double x, double y, double z) {
        M[0] = x;
        M[1] = y;
        M[2] = z;
    }

    // calculate magnitude
    double calculateMagnitude() {
        return sqrt(M[0] * M[0] + M[1] * M[1] + M[2] + M[2]);
    }

    // unit vector
    void unit_vector() {
        double magnitude = calculateMagnitude();

        printf("%e, ", M[0] / magnitude);
        printf("%e, ", M[1] / magnitude);
        printf("%e", M[2] / magnitude);
    }
};

int main() {
    Electric_Field E_default;
    Electric_Field E_components(1e5, 10.9, 1.7e2);
    Magnetic_Field M_default;
    Magnetic_Field M_components(2.0, 4.0, 6.0);

    E_default.electric_setter(1.0, 3.0, 5.0);
    M_default.magnetic_setter(1.0, 0.0, 0.0);

    printf("Magnitudes:\n");
    printf("Default Electric: %e\n", E_default.calculateMagnitude());
    printf("Electric with Components: %e\n", E_components.calculateMagnitude());
    printf("Default Magnetic: %e\n", M_default.calculateMagnitude());
    printf("Magnetic with Components: %e\n", M_components.calculateMagnitude());

    printf("\nElectric Field Inner Products:\n");
    printf("Default: %e\n", E_default.inner_product());
    printf("With Components: %e\n", E_components.inner_product());

    printf("\nMagnetic Field Unit Vectors:\n");
    printf("Default: ");
    M_default.unit_vector();
    printf("\nWith Components: ");
    M_components.unit_vector();


    return 0;
}
