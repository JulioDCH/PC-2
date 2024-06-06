#include<iostream>
using namespace std;
int main(){
    int matriz[3][3], sumafilas[3]= {0,0,0}, sumacolumnas[3]={0,0,0}, i, j;
    
    cout<<"Introduzca los elementos de la matriz: "<<endl;
    
    for(i = 0; i<3; i++){
        for(j = 0; j<3; j++){
            cout<<"El Elemento ["<<i<<"]["<<j<<"] sera: "; cin>>matriz[i][j];
        }
    }
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            sumafilas[i] += matriz[i][j];
            sumacolumnas[j] += matriz[i][j];
        }
    }

    cout<<"\nSuma de filas: "<<endl;
    for(i = 0; i < 3; i++){
        cout << "Fila " << i << ": " << sumafilas[i] << endl;
    }
    
    cout<<"\nSuma de columnas: "<<endl;
    for(j = 0; j < 3; j++){ // Corregido el bucle aquí
        cout << "Columna " << j << ": " << sumacolumnas[j] << endl;
    }
    
    return 0;
}  
