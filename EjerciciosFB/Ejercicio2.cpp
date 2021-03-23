#include<iostream>
#include<regex>
#include<vector>

int LeerEntero();
void LeerAltura(const int n, std::vector<double>alturas);
double Media(std::vector<double> alturas);
int DatosMayorQue(std::vector<double> alturas, double ref);
int DatosMenorQue(std::vector<double> alturas, double ref);

int main(){
    std::vector<double> alturas;
    int n = LeerEntero();
    double alt = 0;
    double media = 0;
    double numeroMay = 0;
    double numeroMen = 0;

    for(int i = 0; i<n; i++){
        std::cout << "Altura # " << i + 1 << ": ";
        std::cin >>alt;
        alturas.push_back(alt);
    }

    media = Media(alturas);
    numeroMay = DatosMayorQue(alturas, media);
    numeroMen = DatosMenorQue(alturas, media);

    std::cout << "Altura media: " << media << std::endl;
    std::cout << "Personas con altura mayor a la media: " << numeroMay << std::endl;
    std::cout << "Personas con altura menor a la media: " << numeroMen << std::endl;
}

int LeerEntero(){
    int aux;
    do{
        std::cout << "Ingrese el número de personas: ";
        std::cin >> aux;
        if (aux > 0) return aux;
        std::cout << "Se debe ingresar un número entero positivo\n";
    }while (true);
}

double Media(std::vector<double> alturas){
    double sum = 0;
    for(double alt: alturas){
        sum += alt;
    }
    return sum / alturas.size();
}

int DatosMayorQue(std::vector<double> alturas, double ref){
    int sum = 0;
    for(double alt : alturas){
        sum += (alt > ref)? 1 : 0;
    }
    return sum;
}
int DatosMenorQue(std::vector<double> alturas, double ref){
    int sum = 0;
    for(double alt : alturas){
        sum += (alt < ref)? 1 : 0;
    }
    return sum;
}