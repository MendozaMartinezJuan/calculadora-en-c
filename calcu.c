
#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");

    int option, fraccionOption;
    float num1,num2,result;
    int salirPrincipal = 6;
    int salirFraccion = 5;
    char simplificar;

    struct Fraccion{
        int numerador,denominador;
    };

    struct Fraccion fraccion1, fraccion2, resultado;

    printf("\tBienvenido a la calculadora\n");
    printf("1.- Suma\n2.- Resta\n3.- Multiplicacion\n4.- Division\n5.- Fracciones\n6.- Salir\n");

    do {
        printf("\nTeclee una opcion valida: ");
        scanf("%d", &option);

        switch(option){

            case 1:
                printf("Seleccionaste Suma\n");
                printf("Ingresa el primer numero: ");
                scanf("%f",&num1);
                printf("\nIngresa el segundo numero: ");
                scanf("%f",&num2);
                result = num1 + num2;
                printf("El resultado es: %.2f",result);
                break;

            case 2:
                printf("Seleccionaste Resta\n");
                printf("Ingresa el primer numero: ");
                scanf("%f",&num1);
                printf("\nIngresa el segundo numero: ");
                scanf("%f",&num2);
                result = num1 - num2;
                printf("El resultado es: %.2f",result);
                break;

            case 3:
                printf("Seleccionaste Multiplicacion\n");
                printf("Ingresa el primer numero: ");
                scanf("%f",&num1);
                printf("\nIngresa el segundo numero: ");
                scanf("%f",&num2);
                result = num1 * num2;
                printf("El resultado es: %.2f",result);
                break;

            case 4:
                printf("Seleccionaste Division\n");
                printf("Ingresa el primer numero: ");
                scanf("%f",&num1);
                printf("\nIngresa el segundo numero: ");
                scanf("%f",&num2);
                if(num2 != 0){
                    result = num1 / num2;
                    printf("El resultado es: %.2f",result);
                }else{
                    printf("Error: Division por cero no permitida.");
                }
                break;

            case 5:
                printf("Seleccionaste Fracciones\n");

                do {
                    printf("\n1.- Suma\n2.- Resta\n3.- Multiplicacion\n4.- Division\n5.- Salir\n");
                    printf("Teclee una opcion valida: ");

                    scanf("%d", &fraccionOption);

                    switch(fraccionOption){

                        case 1:
                            printf("\nSuma de Fracciones\n");
                            printf("\nIngresa el numerador de la primera fracción: ");
                            scanf("%d",&fraccion1.numerador);
                            printf("\nIngresa el denominador de la primera fraccion: ");
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
                            printf("\nResta de Fracciones\n");
                            break;

                        case 3:
                            printf("\nMultiplicacion de Fracciones\n");
                            break;

                        case 4:
                            printf("\nDivision de Fracciones\n");
                            break;

                        case 5:
                            printf("\nRegresando al menu principal...\n");
                            break;

                        default:
                            printf("\nOpcion no valida\n");
                    }

                } while(fraccionOption != salirFraccion);

                break;

            case 6:
                printf("\nSaliendo de la calculadora...\n");
                break;

            default:
                printf("\nOpcion no valida\n");
        }

    } while(option != salirPrincipal);

    return 0;
}
