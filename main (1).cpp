#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

void pausa()
{
    cout << "Pulsa una tecla para continuar...";
    getwchar();
    getwchar();
}


struct job{
    float inicio;
    int numjob;
    float rafaga;
    int prioridad;
    int q;
    struct job *sgte;
};
typedef struct job *jobs;


void ordenar(jobs &jobs1)
{
    job *aux1 = jobs1;
    while(aux1!=NULL)
    {
        job *aux2 = jobs1->sgte;
        while(aux2!=NULL)
        {
            if(aux1->numjob > aux2->numjob)
            {
                float inicio=aux2->inicio;
                int numjob=aux2->numjob;
                float rafaga=aux2->rafaga;
                int prioridad=aux2->prioridad;
                int q=aux2->q;

                aux2->inicio=aux1->inicio;
                aux2->numjob=aux1->numjob;
                aux2->rafaga=aux1->rafaga;
                aux2->prioridad=aux1->prioridad;
                aux2->q=aux1->q;

                aux1->inicio=inicio;
                aux1->numjob=numjob;
                aux1->rafaga=rafaga;
                aux1->prioridad=prioridad;
                aux1->q=q;
            }
            aux2=aux2->sgte;
        }
        aux1=aux1->sgte;
    }
}

bool repetido(jobs jobs1, int numjob)
{
    job *aux = jobs1;
    while(aux!=NULL)
    {
        if(aux->numjob==numjob)
            return true;
        aux=aux->sgte;
    }
    return false;
}

void agregar(float inicio, float rafaga, int prioridad, int numjob, int q, jobs &jobs1)
{
    jobs aux;
    aux = new(struct job);
    aux->numjob=numjob;
    aux->inicio=inicio;
    aux->rafaga=rafaga;
    aux->prioridad=prioridad;
    aux->q=q;
    aux->sgte=jobs1;

    jobs1=aux;
}

void ingreso_jobs(jobs &jobs1)
{
    int cant_jobs=1;
    float inicio_job, retraso=0;
    clock_t start=clock(), delay=0;
    char letra_aux='1';
    while((int)letra_aux!=13) /** Enter */
    {
        while(!kbhit())
        {
            inicio_job=((float)(clock()-start)/CLK_TCK)-retraso;
            cout <<"Presione tecla Espacio para inicio del Job, para terminar Enter"<<endl<<inicio_job<<endl;
            system("cls");
        }
        delay=clock();
        letra_aux=getch();
        if((int)letra_aux==32)/** Espacio */
        {
            int numjob;
            float rafaga;
            int prioridad;
            int q;
            bool validar;

            cout<<"Ingrese numero del job"<<endl;
            cin>>numjob;
            cout<<"Ingrese rafaga del job"<<endl;
            cin>>rafaga;
            cout<<"Ingrese prioridad del job"<<endl;
            cin>>prioridad;
            cout<<"Ingrese q"<<endl;
            cin>>q;
            cant_jobs++;
            if (numjob > 10 || rafaga > 50 || rafaga < 0 || prioridad < 0 || prioridad > 10)
            {
                cout <<" Datos invalidos, ingrese de nuevo" << endl;

                pausa();
            }
            else
            {
                agregar(inicio_job, numjob, rafaga, prioridad, q, jobs1);
                validar = true;

            }
        }
        delay=clock()-delay;
        retraso+=(float)delay/CLK_TCK;
    }
    cout<<"Terminamos el ingreso del job"<<endl;
    system("pause");
    system("cls");
}

void mostrar(jobs jobs1)
{
    int cant=1;
    job *aux = jobs1;
    while(aux!=NULL)
    {
        cout<<"Numero; "<<aux->numjob<<endl;
        cout<<"Tiempo de llegada: "<<aux->inicio<<endl;
        cout<<"Rafaga: "<<aux->rafaga<<endl;
        cout<<"Prioridad: "<<aux->prioridad<<endl<<endl;
        cout<<"Q: "<<aux->q<<endl;
        aux=aux->sgte;
        cant++;
    }
}

int main()
{
    jobs jobs1=NULL;
    cout << "Sistemas Operativos" << endl ;
    cout << "Agregue Jobs para aplicar los algoritmos correspondientes" << endl;
    cout << ""<< endl;

    pausa();
    ingreso_jobs(jobs1);
    mostrar(jobs1);
        bool validar=false;
    char tecla;

    /*do
    {
        system("cls");
        cin.clear();
        cout << "Sistemas Operativos" << endl;
        cout << "-----------" << endl << endl;
        cout << "\t1 .- FCFS" << endl;
        cout << "\t2 .- SJF (apropiativo)" << endl;
        cout << "\t3 .- SJF (no apropiativo)" << endl;
        cout << "\t4 .- Priority (apropiativo)" << endl;
        cout << "\t5 .- Priority (no apropiativo)" << endl;
        cout << "\t6 .- Round" << endl;
        cout << "\t7 .- Salir" << endl << endl;
        cout << "Elije una opcion: ";

        cin >> tecla;
        clock_t start;
		switch(tecla)
		{
			case '1':
				system("cls");
				cout << "Has elejido FCFS.\n";
				start=clock();

				pausa();
				break;
			case '2':
				system("cls");
				cout << "Has elejido SJF (apropiativo).\n";
				pausa();
				break;

			case '3':
				system("cls");
				cout << "Has elejido SJF (no apropiativo).\n";
				pausa();
				break;

			case '4':
				system("cls");
				cout << "Has elejido Priority (apropiativo).\n";
				pausa();
				break;

			case '5':
				system("cls");
				cout << "Has elejido Priority (no apropiativo).\n";
				pausa();
				break;

            case '6':
				system("cls");
				cout << "Has elejido Round.\n";
				pausa();
				break;

			case '7':
				validar=true;
				//exit(1);
				break;

			default:
				system("cls");
				cout << "Opcion no valida.\a\n";
				pausa();
				break;
		}
    }while(validar!=true); */

    return 0;
    system("pause");
    return 0;
}
