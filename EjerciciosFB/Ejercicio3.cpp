#include<iostream>

int main(){
    int n;
    const int materias = 4;
    double ** notas;
    double * alumno;
    double suma = 0;

    std::cout << "Ingrese el número de alumnos: ";
    std::cin >> n;

    notas = (double **)malloc(n * sizeof(double *));

    for(int i = 0; i < n; i++){
        alumno = (double *)malloc(materias * sizeof(double));
        * (notas + i) = alumno;
    }

    //Leer notas
    for(int i = 0; i < n; i++){
        alumno = * (notas + i);
        std::cout << "\nAlumno # " << i + 1 << ": \n";

        for(int j = 0; j < materias; j++){
            std::cout << "Ingrese la calificación " << j + 1 << ": ";
            std::cin >> *(alumno + j);
        }
    }

    //Notas y promedio
    for(int i = 0; i < n; i++){
        alumno = * (notas + i);
        std::cout << "\nAlumno # " << i + 1 << ": \n";

        suma = 0;

        for(int j = 0; j < materias; j++){
            std::cout << "Calificación " << j + 1 << ": ";
            std::cout << *(alumno + j) << std::endl;
            suma += *(alumno + j);
        }
        suma = suma / materias;
        std::cout << "\nPromedio: " << suma << std::endl;
        std::cout << "El alumno: " << i+1 << " fue ";
        if(suma < 50){
            std::cout << "aplazado\n";
        }else std::cout << "aprobado\n";
    }
}