#include<iostream>
using namespace std;
int main(){
	int cant_alumnos, cant_asignaturas = 8, i, j;
	cout<<"Cuantos alumnos son: "; cin>>cant_alumnos;
	
	int calificaciones[cant_alumnos][cant_asignaturas], contadorasig[cant_asignaturas] = {0};
	double prom_estudiante[cant_alumnos], prom_asig[cant_asignaturas] = {0.0};
	
    for (i = 0; i < cant_alumnos; i++) {
        cout << "Introduce las calificaciones del alumno " << i + 1 << " (use -1, si es que no se presento):" << endl;
        for (j = 0; j < cant_asignaturas; j++) {
            cout << "Calificacion de la asignatura " << j + 1 << ": ";
            cin >> calificaciones[i][j];
        }
    }

    for (i = 0; i < cant_alumnos; i++) {
        int suma_calificaciones = 0, conteo_calificaciones = 0;
        for (j = 0; j < cant_asignaturas; j++) {
            if (calificaciones[i][j] != -1) {
                suma_calificaciones += calificaciones[i][j];
                conteo_calificaciones++;
            }
        }
        if (conteo_calificaciones > 0) {
            prom_estudiante[i] = suma_calificaciones / (double)conteo_calificaciones;
        } else {
            prom_estudiante[i] = 0.0;
        }
    }
	
	double suma_total_calificaciones = 0.0;
    int conteo_total_calificaciones = 0;
    for (i = 0; i < cant_alumnos; i++) {
        for (j = 0; j < cant_asignaturas; j++) {
            if (calificaciones[i][j] != -1) {
                suma_total_calificaciones += calificaciones[i][j];
                conteo_total_calificaciones++;
            }
        }
    }
    double prom_general_clase = (conteo_total_calificaciones > 0) ? (suma_total_calificaciones / conteo_total_calificaciones) : 0.0;
	
	for (j = 0; j < cant_asignaturas; j++) {
        int suma_calificaciones_asig = 0, conteo_calificaciones_asig = 0;
        for (i = 0; i < cant_alumnos; i++) {
            if (calificaciones[i][j] != -1) {
                suma_calificaciones_asig += calificaciones[i][j];
                conteo_calificaciones_asig++;
            }
        }
        if (conteo_calificaciones_asig > 0) {
            prom_asig[j] = suma_calificaciones_asig / (double)conteo_calificaciones_asig;
        } else {
            prom_asig[j] = 0.0;
        }
    }

    int total_faltas = 0, total_calificaciones_esperadas = cant_alumnos * cant_asignaturas;
    for (i = 0; i < cant_alumnos; i++) {
        for (j = 0; j < cant_asignaturas; j++) {
            if (calificaciones[i][j] == -1) {
                total_faltas++;
            }
        }
    }
    double porcentaje_faltas = (total_faltas / (double)total_calificaciones_esperadas) * 100;

    cout << "\nPromedio de cada estudiante:" << endl;
    for (i = 0; i < cant_alumnos; i++) {
        cout << "Estudiante " << i + 1 << ": " << prom_estudiante[i] << endl;
    }

	cout<<"\nPromedio general de la clase: "<< prom_general_clase << endl;
	
	cout<<"\nPromedio de la clase en cada asignatura: " << endl;
	for(j=0; j<cant_asignaturas; j++){
		cout<<"Asignatura "<< j+1 << ":" <<prom_asig[j] <<endl;
	}
	
	cout<<"\nPorcentaje de faltas: "<< porcentaje_faltas <<" % "<< endl;
	
	return 0;
}
