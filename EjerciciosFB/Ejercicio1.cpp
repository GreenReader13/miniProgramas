#include<iostream>
#include<string>
#include<regex>

void LeerNumero(double *const n, std::string Id);
void IngresarTres(double *const a, double *const b, double *const c);
double SumarTres(const double a, const double b, const double c);
double MultiplicaTres(const double a, const double b, const double c);
double DividirEsp(const double a, const double b, const double c);
long long Factorial(const int n);

double OpcionUno(const double a, const double b, const double c);
double OpcionDos(const double a, const double b, const double c);
double OpcionTres(const double a, const double b, const double c);

int OpMenu();

int main(){
    
    double a;
    double b;
    double c;
    double resultado = 0;
    int opcion;

    IngresarTres(&a, &b, &c);

    do{
        opcion = OpMenu();
    
        switch (opcion){
            case 0:
                IngresarTres(&a, &b, &c);
                break;
            case 1:
                resultado = OpcionUno(a, b, c);
                break;

            case 2:
                resultado = OpcionDos(a, b, c);
                break;

            case 3:
                resultado = OpcionTres(a, b, c);
                opcion = c;
                break;
            case 4:
                break;
            
            default:
                std::cout << "Opcion no válida\n";
                opcion = 0;
                break;
        }
    } while (opcion == 0);

    std::cout << "Se seleccionó la opción: " << opcion << std::endl;
    std::cout << "El resultado fue: " << resultado << std::endl;
}

int OpMenu(){

    int opcion = 0;

        std::cout << "Seleccione la operación a realizar\n\n\n";

        std::cout << "Opcion 0: Volver a ingresar los números\n\n";

        std::cout << "Opción 1: Sumar los 3 valores y ";
        std::cout << "calcular el factorial del resultado\n\n";

        std::cout << "Opción 2: Multiplicar los 3 valores e ";
        std::cout << "indicar si el resultado es mayor a 50\n\n";

        std::cout << "Opción 3: Dividir A entre C y multiplicarlo por B\n\n";

        std::cout << "Opcion 4: Salir";

        std::cin >> opcion;

    return opcion;

}

void LeerNumero(double *const n, std::string Id){

    bool ok = false;
    std::string aux = "";
    std::regex number("-?[0-9]+(.[0-9]+)?");

    std::cout << "Ingrese el número: " << Id << std::endl;
    
    do
    {
        try
        {
            std::cin >> aux;
            if(std::regex_match(aux, number)){
                ok = true;
            }else   aux = "";
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            std::cout << e.what() << std::endl;
        }
        
    } while (!ok);
    
    *n = std::stod(aux);
}

void IngresarTres(double *const a, double *const b, double *const c){

    std::cout << "==    Operaciones con números     ==" << std::endl;
    std::cout << "==    Ingrese 3 números A, B y C  ==" << std::endl;
    LeerNumero(a, "A");
    LeerNumero(b, "B");
    LeerNumero(c, "C");
}

double SumarTres(const double a, const double b, const double c){
    return a + b + c;
}

long long Factorial(const int n){

    std::cout << n << std::endl;
    long long f = 1;
    if (n < 0) return 0;
    if (n == 0) return 1;
    
    try
    {
        for(int i = 1; i <= n; i++){
            f = f * i;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return f;
}

int FactorialRecursivo(const int n){
    
    if (n < 0) return 0;
    if (n > 1) return n * FactorialRecursivo(n-1);
    return 1;

}


double MultiplicaTres(const double a, const double b, const double c){
    return a * b * c;
}


double DividirEsp(const double a, const double b, const double c){
    if(c == 0){
        std::cout << "El número 3 no puede ser cero\n";
        return 0;
    }
    return a * b / c;
}


double OpcionUno(const double a, const double b, const double c){
    return Factorial((int)SumarTres(a, b, c));
}

double OpcionDos(const double a, const double b, const double c){
    double res = 0;
    res = MultiplicaTres(a, b, c);

    std::cout << "La operación: " << a << "*"<< b << "*"<< c ;
    std::cout << " = " << res << std::endl;
    if (res > 50){
        std::cout << "Es mayor que 50\n";
    }else{
        std::cout << "No es mayor que 50\n";
    }
    return res;
}

double OpcionTres(const double a, const double b, const double c){

    if(c != 0)  return DividirEsp(a, b, c);
    std::cout << "C no puede ser cero\n";
    return 0;
}