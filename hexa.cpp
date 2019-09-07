/**
 * @brief Convertidor de texto a display 7 segmentos catodo comun
 * 
 * El resultado se almacena en un archivo llamado hex.dat 
 * que se reescribe con cada ejecucion del programa
 * 
 * @author David Fuentes Bello
 * @version 1.0
 * @date 2019
 * @copyright GNU Public License.
*/

/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include <iostream>
#include <fstream>
#include <limits>

/**
 * @brief Traduce numeros y algunas letras de ascii a hexadecimal para display 7 segmentos
 * @param input texto a traducir
 * @param output hexadecimal traducido para display 7 segmentos
 * @param n numero de bytes(letras) a traducir
*/
void translate (char * input, char * output, int n){
    for(int i=0; i<n; i++){
        if (input[i]==0x0A){
            for(int j = i; j<n ; j++){
                input[j]=0x00;
            }
            i=n;
        }
        switch (input[i])
        {
        case 0x30:
            output [i]= 0xFC;
            //std::cout << "0" << std::endl;
            break;
        case 0x31:
            output [i]= 0x60;
            //std::cout << "1" << std::endl;
            break;
        case 0x32:
            output [i]= 0xDA;
            //std::cout << "2" << std::endl;
            break;
        case 0x33:
            output [i]= 0xF2;
            //std::cout << "3" << std::endl;
            break;
        case 0x34:
            output [i]= 0x66;
            //std::cout << "4" << std::endl;
            break;
        case 0x35:
            output [i]= 0xB6;
            //std::cout << "5" << std::endl;
            break;
        case 0x36:
            output [i]= 0xc1;
            //std::cout << "6" << std::endl;
            break;
        case 0x37:
            output [i]= 0xE2;
            //std::cout << "7" << std::endl;
            break;
        case 0x38:
            output [i]= 0xFE;
            //std::cout << "8" << std::endl;
            break;
        case 0x39:
            output [i]= 0xE6;
            //std::cout << "9" << std::endl;
            break;
        //LETRAS

        case 0x41:
        case 0x61:
            output [i]= 0xEE;
            //std::cout << "A" << std::endl;
            break;
        case 0x42:
        case 0x62:
            output [i]= 0x3E;
            //std::cout << "B" << std::endl;
            break;
        case 0x43:
        case 0x63:
            output [i]= 0x1A;
            //std::cout << "C" << std::endl;
            break;
        case 0x44:
        case 0x64:
            output [i]= 0x7A;
            //std::cout << "D" << std::endl;
            break;
        case 0x45:
        case 0x65:
            output [i]= 0x9E;
            //std::cout << "E" << std::endl;
            break;
        case 0x46:
        case 0x66:
            output [i]= 0x8E;
            //std::cout << "F" << std::endl;
            break;
        case 0x47:
        case 0x67:
            output [i]= 0xBE;
            //std::cout << "G" << std::endl;
            break;
        case 0x48:
        case 0x68:
            output [i]= 0x2E;
            //std::cout << "H" << std::endl;
            break;
        case 0x49:
        case 0x69:
            output [i]= 0x60;
            //std::cout << "I" << std::endl;
            break;
        case 0x4A:
        case 0x6A:
            output [i]= 0x78;
            //std::cout << "J" << std::endl;
            break;
        case 0x4B:
        case 0x6B:
            output [i]= 0x6C;
            //std::cout << "K" << std::endl;
            break;
        case 0x4C:
        case 0x6C:
            output [i]= 0x1C;
            //std::cout << "L" << std::endl;
            break;
        case 0x4D:
        case 0x6D:
            output [i]= 0xF2;
            //std::cout << "M" << std::endl;
            break;
        case 0x4E:
        case 0x6E:
            output [i]= 0x2A;
            //std::cout << "N" << std::endl;
            break;
        case 0x4F:
        case 0x6F:
            output [i]= 0xFC;
            //std::cout << "O" << std::endl;
            break;
        case 0x50:
        case 0x70:
            output [i]= 0xCE;
            //std::cout << "P" << std::endl;
            break;
        case 0x51:
        case 0x71:
            output [i]= 0xEA;
            //std::cout << "Q" << std::endl;
            break;
        case 0x52:
        case 0x72:
            output [i]= 0x0A;
            //std::cout << "R" << std::endl;
            break;
        case 0x53:
        case 0x73:
            output [i]= 0xB6;
            //std::cout << "S" << std::endl;
            break;
        case 0x54:
        case 0x74:
            output [i]= 0xE0;
            //std::cout << "T" << std::endl;
            break;
        case 0x55:
        case 0x75:
            output [i]= 0x38;
            //std::cout << "U" << std::endl;
            break;
        case 0x56:
        case 0x76:
            output [i]= 0x46;
            //std::cout << "V" << std::endl;
            break;
        case 0x57:
        case 0x77:
            output [i]= 0x03;
            //std::cout << "W" << std::endl;
            break;
        case 0x58:
        case 0x78:
            output [i]= 0x6E;
            //std::cout << "X" << std::endl;
            break;
        case 0x59:
        case 0x79:
            output [i]= 0x4E;
            //std::cout << "Y" << std::endl;
            break;
        case 0x5A:
        case 0x7A:
            output [i]= 0xDA;
            //std::cout << "Z" << std::endl;
            break;
        case 0x5F:
            output [i]= 0x10;
            //std::cout << "Z" << std::endl;
            break;
        case 0x2D:
            output [i]= 0x02;
            //std::cout << "Z" << std::endl;
            break;
        default:
            output [i]= 0x00;
            break;
        } 
    }
}

int main (){
    
    int n = 4096;   //valor por defecto

    char archivo[50];   //Almacena el nombre del archivo a traducir
    
    std::ofstream hex;  //Archivo de salida
    std::ifstream data; //Archivo de entrada

    //Solicitud de nombre de archivo
    std::cout << "nombre de archivo\n"<<std::endl;
    std::cin >> archivo;
    
    //Abrir el archivo como binario para cuantifiar la cantidad de bytes
    data.open(archivo, std::ios::binary | std::ios::ate);

    if (data.is_open())
    {   
        n = data.tellg();
        n-=1;   //Se asume que el archivo contiene un caracter de fin de archivo
        std::cout << n << " letras a traducir"<< std::endl;
        data.close();

    }else {

        std::cout << "No se puede leer el archivo " << archivo << std::endl;    
        return -1;
    }

    //Asignacion de memoria
    try{
        char datos[n];
        char hex_buffer[n];

        data.open(archivo);

        //Leer el archivo 
        if(data.is_open()){

            data.read(datos, n);
            std::cout << "Texto a traducir: " << std::endl << datos << std::endl;

        }else {
            
            std::cout << "No se puede leer el archivo " << archivo << std::endl;  
            return -2;
        }


        translate(datos, hex_buffer, n);

        //Escribir archivo exadecimal
        hex.open("hex.dat");

        if(hex.is_open()){

            hex.write(hex_buffer, n);
            hex.close();
        
        }else {
            std::cout << "No se puede escribir el resultado en un archivo" << std::endl;
            return -3;
        }
        std::cout << "resultado escrito en el archivo hex.dat" << std::endl;
    } catch( std::exception& e) {
        std::cout << "No se puede asignar memoria" << e.what() << "'\n";
    }
    return 0;
}