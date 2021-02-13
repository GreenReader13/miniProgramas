/**
 * @file p4_act3.cpp
 * @brief Implementación de pila
 */

#include<iostream>
#include<vector>

class Pila
{
private:
    size_t depth;
    std::vector<std::string>statk;
    size_t top{0}; 
public:
    Pila(size_t _depth);
    Pila(const Pila & r);

    void operator=(const Pila & rhs);

    void Push(std::string s);
    std::string Pop();
    std::string Peek();

    bool IsEmpty();
    bool IsFull();
    
    void clear();

    size_t getTop();
    size_t getDepth();

    ~Pila();
};

/**
 * @brief Constructor con número de elementos
 * @param _depth tamaño de la pila
 */
Pila::Pila(size_t _depth):depth(_depth), statk(_depth)
{
}

Pila::Pila(const Pila & r){
    //Implementar copia de vector
    std::cout << "No soportado" << std::endl;
}

/**
 * @brief destructor por defecto
 */
Pila::~Pila()
{
}

/**
 * @brief Obtiene el índice del último elemento
 * @return número de elementos en la pila
 */
size_t Pila::getTop()
{
    return this->top;
}

/**
 * @brief Obtiene el tamaño de la pila
 * @return tamaño de la pila
 */
size_t Pila::getDepth()
{
    return this->depth;
}

/**
 * @brief Indica si la pila esta vacía
 * @return true si la pila esta vacía, false en caso contrario
 */
bool Pila::IsEmpty()
{
    return this->top == 0;
}

/**
 * @brief Indica si la pila esta llena
 * @return True si la pila esta llena, false en otro caso
 */
bool Pila::IsFull()
{
    return this->top == this->depth;
}

/**
 * @brief Limpia la pila
 * Se apunta al inicio de la pila
 */
void Pila::clear()
{
    this->top = 0;
}

/**
 * @brief Agrega un elemento al final de la pila
 */
void Pila::Push(std::string s)
{
    this->top++;
    this->statk[this->top -1] = s;
}

/**
 * @brief Extrae el último elemento de la pila
 * El elemento quitado de la pila
 * @return Elemento extraido
 */
std::string Pila::Pop()
{
    if(this->top > 0)
    {
        this->top-=1;
        return this->statk[this->top];
    }
    return "false";
}

/**
 * @brief Obtiene el último elemento de la pila
 * El elemento recuperado se mantiene en la pila
 * @return Ultimo elemento de la pila
 */
std::string Pila::Peek()
{
    return this->statk[this->top -1];
}

/**
 * @brief Implementación de la pila
 */
int main()
{
    Pila p(5);
    std::cout << ".depth = " << p.getDepth() << std::endl;
    std::cout << ".top = " << p.getTop() << std::endl;

    for (size_t i {0}; !p.IsFull(); i++)
    {
        std::string s;
        std::cout << i << ":";
        std::cin >> s;;
        p.Push(s);
        std::cout << ".top = " << p.getTop() << std::endl;
    }

    std::cout << "==========================" << std::endl;

    while(!p.IsEmpty())
    {
        std::cout << p.Pop() << std::endl;
        std::cout << ".top = " << p.getTop() << std::endl;
    }

    return 0;
}