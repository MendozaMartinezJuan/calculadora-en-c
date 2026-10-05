#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(){
    setlocale(LC_ALL, "");

    int option, fraccionOption;
    float num1,num2,result;
    int salirPrincipal = 7;
    int salirFraccion = 5;
    char simplificar;
    //----------------------Struct------------------------
    struct Fraccion{
        int numerador,denominador;
    };

    struct Fraccion fraccion1, fraccion2, resultado;
    //----------------------Funcion Pusar------------------------
    void pausar(){
        printf("\nPresiona Enter para continuar...\n");
        getchar();
        getchar();
    };
    //----------------------Apuntadores------------------------
    char menu[] = "\t    Menu Principal\n1.- Suma\n2.- Resta\n3.- Multiplicacion\n4.- Division\n5.- Fracciones\n6.- Elevar \n7.- Salir\n";
    char *questions[] = {"Ingresa el numerador de la primera fracción: ",    //posicion 0 
                        "Ingresa el denominador de la primera fracción: ",   //posicion 1
                        "Ingresa el numerador de la segunda fraccióm: ",     //posicion 2 
                        "Ingresa el denominador de la segunda fracción: ",   //posicion 3
                        "Ingresa el primer numero: ",                        //posicion 4
                        "Ingresa el segundo numero: ",                       //posicion 5
                        "El resultado es: "
                        }; 
    //----------------------Bienvenida------------------------
    printf("\tBienvenido a la calculadora.");
    printf("\n%s", menu);

    do {
        printf("\nTeclee una opcion valida: ");
        scanf("%d", &option);
        system("clear");

        switch(option){

            case 1:
                printf("----------------------------------------------------");
                printf("\tSeleccionaste Suma   ");
                printf("----------------------------------------------------\n");
                printf("%s", questions[4]);
                scanf("%f",&num1);
                printf("%s", questions[5]);
                scanf("%f",&num2);
                result = num1 + num2;
                printf("%.2f + %.2f =  %.2f" ,num1, num2, result);
                pausar();
                system("clear");
                printf("%s", menu);
                break;

            case 2:
                printf("----------------------------------------------------");
                printf("\tSeleccionaste Resta   ");
                printf("----------------------------------------------------\n");
                printf("%s", questions[4]);
                scanf("%f",&num1);
                printf("%s", questions[5]);
                scanf("%f",&num2);
                result = num1 - num2;
                printf("%.2f - %.2f = %.2f" , num1, num2, result);
                pausar();
                system("clear");
                printf("%s", menu);
                break;

            case 3:
                printf("----------------------------------------------------");
                printf("\tSeleccionaste Multiplicacion   ");
                printf("----------------------------------------------------\n");
                printf("%s", questions[4]);
                scanf("%f",&num1);
                printf("%s", questions[5]);
                scanf("%f",&num2);
                result = num1 * num2;
                printf("%.2f * %.2f = %.2f" , num1, num2, result);
                pausar();
                system("clear");
                break;

            case 4:
                printf("----------------------------------------------------");
                printf("\tSeleccionaste División   ");
                printf("----------------------------------------------------\n");
                printf("%s", questions[4]);
                scanf("%f",&num1);
                printf("%s", questions[5]);
                scanf("%f",&num2);
                if(num2 != 0){
                    result = num1 / num2;
                    printf("%.2f / %.2f = %.2f" , num1, num2, result);
                    pausar();
                    system("clear");
                    printf("\n%s", menu);
                }else{
                    printf("Error: Division por cero no permitida.");
                    pausar();
                    system("clear");
                    printf("\n%s", menu);
                }
                break;

            case 5:
                printf("----------------------------------------------------");
                printf("\tSeleccionaste Fracciones   ");
                printf("----------------------------------------------------\n");

                do {
                    char menuFracction[] = "\t\tMenu Fracciones\n1.- Suma\n2.- Resta\n3.- Multiplicacion\n4.- Division\n5.- Salir\n";
                    printf("%s", menuFracction);
                    printf("Teclee una opcion valida: ");
                    scanf("%d", &fraccionOption);

                    switch(fraccionOption){

                        case 1:
                            printf("\tSuma de Fracciones\n");
                            printf("%s", question[0]);
                            scanf("%d",&fraccion1.numerador);
                            printf("%s", questions[1]);
                            scanf("%d",&fraccion1.denominador);
                            printf("\nTu primera fraccion es: %d/%d", fraccion1.numerador, fraccion1.denominador);
                            printf("\nIngresa el numerador de la segunda fracción: ");
                            scanf("%d",&fraccion2.numerador);
                            printf("\nIngresa el denominador de la segunda fracción: ");
                            scanf("%d", &fraccion2.denominador);
                            printf("\nTu segunda fracción es: %d/%d", fraccion2.numerador, fraccion2.denominador);
                              if(fraccion1.denominador == fraccion2.denominador){
                                resultado.denominador = fraccion1.denominador;
                                resultado.numerador = fraccion1.numerador + fraccion2.numerador;
                              }
                              else{
                            resultado.numerador = fraccion1.numerador + fraccion2.numerador;
                            resultado.denominador = fraccion1.denominador + fraccion2.denominador;
                              }
                            printf("\nEl resultado de la suma es: %d/%d", resultado.numerador, resultado.denominador);
                            printf("\n¿Quieres simplificar el resultado? (s/n): ");
                            scanf(" %c", &simplificar);
                                    if(simplificar == 's' || simplificar == 'S'){
                                        printf("\nSimplificando fraccion...\n");
                                        
                                        if(resultado.numerador <=1 || resultado.denominador <=1){
                                            printf("\nNo se puede simplificar el resultado. Los valores son menores a 1\n"); 
                                        }
                                        else{
                                            int a,b,resuido;
                                            a = resultado.numerador;
                                            b = resultado.denominador;
                                            while(b != 0){
                                                resuido = a % b;
                                                a = b;
                                                b = resuido;
                                            }
                                            if(a < 0){
                                                a = -a;
                                            }
                                            if(a != 0){
                                                resultado.numerador = resultado.numerador / a;
                                                resultado.denominador = resultado.denominador / a;
                                            }
                                            printf("El resultado simplifacdo es: %d/%d", resultado.numerador, resultado.denominador);
                                        }
                                        
                                    }
                            break;

                        case 2:
                            printf("----------------------------------------------------");
                            printf("\tResta de Fracciones");
                            printf("----------------------------------------------------\n");
                            printf("%s", questions[0]);
                            scanf("%d", &fraccion1.numerador);
                            printf("%s", questions[1]);
                            scanf("%d", &fraccion1.denominador);
                            printf("segunda fraccion num: ");
                            scanf("%d", &fraccion2.numerador);
                            printf("Fraccion 2 denominador: ");
                            scanf("%d", &fraccion2.denominador);
                            printf("Las fracciones son: %d/%d y %d/%d", fraccion1.numerador, fraccion1.denominador,
                                    fraccion2.numerador, fraccion2.denominador);
                                    int x,y,resul1,resul2;
                                    x = fraccion1.denominador;
                                    y = fraccion2.denominador;
                                    if(x==y){
                                        //resul1 = fraccion1.numerador + fraccion2.numerador;
                                        resul1 = fraccion1.numerador - fraccion2.numerador;
                                        printf("El resultado es: %d/%d", resul1, y);
                                    }
                                    system("clear");
                                    printf("\n%s", menu);
                            break;

                        case 3:
                            printf("----------------------------------------------------");
                            printf("\tMultiplicacion de Fracciones");
                            printf("----------------------------------------------------\n");
                            printf("%s", questions[0]);
                            scanf("%d", &fraccion1.numerador);
                            printf("%s", questions[1]);
                            scanf("%d", &fraccion1.denominador);
                            system("clear");
                            printf("%s", questions[2]);
                            scanf("%d", &fraccion2.numerador);
                            printf("%s", questions[3]);
                            scanf("%d", &fraccion2.denominador);
                            system("clear");
                            printf("Las fracciones son: %d/%d  y  %d/%d", fraccion1.numerador, fraccion1.denominador,
                                   fraccion2.numerador, fraccion2.denominador, "\n");

                            break;

                        case 4:
                            printf("----------------------------------------------------");
                            printf("\tDivisión de Fracciones");
                            printf("----------------------------------------------------\n");
                            printf("%s", questions[0]);
                            scanf("%d", &fraccion1.numerador);
                            printf("%s", questions[1]);
                            scanf("%d", &fraccion1.denominador);
                            system("clear");
                            printf("%s", questions[2]);
                            scanf("%d", &fraccion2.numerador);
                            printf("%s", questions[3]);
                            scanf("%d", &fraccion2.denominador);
                            system("clear");
                            printf("Las fracciones son: %d/%d  y  %d/%d", fraccion1.numerador, fraccion1.denominador,
                                   fraccion2.numerador, fraccion2.denominador);
                                   int a,b;
                                   a = fraccion1.numerador * fraccion2.denominador;
                                   b = fraccion1.denominador * fraccion2.numerador;
                                      printf("\nEl resultado de la division es: %d/%d", a, b, "\n");
                                      system("clear");
                                      printf("%s", menu);

                            break;

                        case 5:
                            printf("----------------------------------------------------");
                            printf("\tRegresando al menu principal...");
                            printf("----------------------------------------------------\n");
                            printf("%s", menu);
                            break;

                        default:
                            printf("\nOpcion no valida\n");
                            printf("%s", menuFracction);
                            system("clear");
                    }

                } while(fraccionOption != salirFraccion);

                break;

            case 6:
                int numero,veces,resultado;
                printf("Ingrese el numero que quiere elevar: ");
                scanf("%d",&numero);
                printf("Cuántas veces quiere elevar %d?: ", numero);
                scanf("%d",&veces);
                resultado = numero;
                    for(int i=0; i < veces; i++){
                        resultado = numero * numero;
                    }
                    printf("%d \n", resultado);
                    printf("%s", menu);
                    system("clear");
                break;

            case 7: 
                printf("----------------------------------------------------");
                printf("\tSaliendo de la calculadora...");
                printf("----------------------------------------------------\n");
                
                break;

            default:
                printf("----------------------------------------------------");
                printf("\tOpcion no valida\n\n");
                printf("----------------------------------------------------\n");
                printf("%s", menu);
                system("clear");

    } while(option != salirPrincipal);

    return 0;
}