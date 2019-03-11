#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

procesos *OrdenarTL(procesos *pro, int a, int b);

//Algoritmo de planificación First Come First Servered
void FCFS(procesos *pro, int cont){
    printf("\nALgoritmo First Come First Servered\n");
    double tp, tf = 0;
    for(int b = 2; b < cont - 1; b++){
        for(int c = 0; c < cont - b; c++){
            if(pro[c].TLlegada > pro[c+1].TLlegada){
                pro = OrdenarTL(pro, c, c);
	    }
	}
    }

    for(int j = 0; j < cont - 1; j++){   
        tf += pro[j].TEjecucion;
	tp = tp + tf;
    	printf("\nCliente %s, terminó su diligencia en %2.1f segundos", pro[j].proceso, tf);
    }

    printf("\n\nLa suma de los tiempos es: %2.1f segundos", tp);
    tp = tp / (cont-1);
    printf("\nTiempo promedio en FCFS fue de: %2.2f segundos\n", tp);
    printf("---------------------------------------------------------");
}
//Algoritmo de planificación Shortest Job First
void SJF(procesos *pro, int cont){
    printf("\nAlgoritmo Shortest Job First\n");
    double tp, tf = 0;

    for(int d = 2; d < cont - 1; d++){
	tf = 0;
        for(int e = 1; e < cont - d; e++){
            tf += pro[e-1].TEjecucion;
	    if(pro[e].TEjecucion > pro[e+1].TEjecucion){
		if(tf > pro[e+1].TLlegada){
                    pro = OrdenarTL(pro, e, e);
	        }
	    }
	}
    }

    tf = 0;

    for(int j = 0; j < cont - 1; j++){   
        tf += pro[j].TEjecucion;
	tp = tp + tf;
    	printf("\nCliente %s, terminó su diligencia en %2.1f segundos", pro[j].proceso, tf);
    }

    printf("\n\nLa suma de los tiempos es: %2.1f segundos", tp);
    tp = tp / (cont-1);
    printf("\nTiempo promedio en SJF fue de: %2.2f segundos\n", tp);
    printf("---------------------------------------------------------\n");
}
//ALgoritmo de planificación basado en prioridades.
void ABP(procesos *pro, int cont){
    printf("\nAlgoritmo basado en prioridades\n");
    double tp, tf = 0;

    for(int f = 2; f < cont - 1; f++){
	tf = 0;
        for(int g = 1; g < cont - f; g++){
	    tf += pro[g-1].TEjecucion;
            if(pro[g].Tipo > pro[g+1].Tipo){
	        if(tf > pro[g+1].TLlegada){
		    pro = OrdenarTL(pro, g, g);
		}
	    }else if(pro[g].Tipo == pro[g+1].Tipo){
	        if(pro[g].TLlegada > pro[g+1].TLlegada){
		    pro = OrdenarTL(pro, g, g);
		}
	    }
	    
	}
    }

    tf = 0;

    for(int a = 0; a < cont - 1; a++){
        tf += pro[a].TEjecucion;
        tp = tp + tf;
        printf("\nCliente %s, terminó su diligencia en %2.1f segundos",pro[a].proceso, tf);	
    }

    printf("\n\nLa suma de los tiempos es: %2.1f segundos", tp);
    tp = tp / (cont - 1);
    printf("\nTiempo promedio en ABP fue de: %2.2f segundos\n", tp);
    printf("---------------------------------------------------------\n");
}

procesos *OrdenarTL(procesos *pro, int d, int e){
    int aux;
    int aux1;
    char aux2;
    char *aux3;
    char *aux4;
    aux = proc[d].TLlegada;
    aux1 = pro[d].TEjecucion;
    aux3 = pro[d].proceso;
    aux2 = pro[d].Tipo;
    aux4 = pro[d].Type;
    pro[d].TLlegada = pro[e+1].TLlegada;
    pro[d].TEjecucion = pro[e+1].TEjecucion;
    pro[d].proceso = pro[e+1].proceso;
    pro[d].Tipo = pro[e+1].Tipo;
    pro[d].Type = pro[e+1].Type;
    pro[e+1].TLlegada = aux;
    pro[e+1].TEjecucion = aux1;
    pro[e+1].proceso = aux3;
    pro[e+1].Tipo = aux2;
    pro[e+1].Type = aux4;
    return pro;
}
