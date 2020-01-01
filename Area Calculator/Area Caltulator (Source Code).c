#include <stdio.h>
#include <stdlib.h>

float Circle(){
    float radius, total, pi = 3.1415;
    printf("Please enter a radius: ");
    scanf("%f", &radius);
    total = pi * (radius * radius);
    printf("Area = %.2f\n", total);
    return total;
}

float Square(){
    float side, total;
    printf("Please enter a side: ");
    scanf("%f", &side);
    total = (side * side);
    printf("Area = %.1f\n", total);
    return total;
}

float Rectangle(){
    float side1, side2, total;
    printf("Please enter a side: ");
    scanf("%f", &side1);
    printf("Please enter a second side: ");
    scanf("%f", &side2);
    total = side1 * side2;
    printf("Area = %.2f\n", total);
    return total;
}
float Triangle(){
    float base, height, total;
    printf("Please enter a base: ");
    scanf("%f", &base);
    printf("Please enter a height: ");
    scanf("%f", &height);
    total = .5 * base * height;
    printf("Area = %.2f\n", total);
    return total;
}
float Trapezoid(){
    float base1, base2, height, total;
    printf("Please enter a base: ");
    scanf("%f", &base1);
    printf("Please enter a second base: ");
    scanf("%f", &base2);
    printf("Please enter a height: ");
    scanf("%f", &height);
    total = height/2 * (base1 + base2);
    printf("Area = %.2f\n", total);
    return total;
}
float Parallelogram(){
    float base, height, total;
    printf("Please enter a base: ");
    scanf("%f", &base);
    printf("Please enter a height: ");
    scanf("%f", &height);
    total = base * height;
    printf("Area = %.2f\n", total);
    return total;
}

float Polygon(){
    float perimeter, apothem, total;
    printf("Please enter the perimeter: ");
    scanf("%f", &perimeter);
    printf("Please enter the apothem: ");
    scanf("%f", &apothem);
    total = .5 * perimeter * apothem;
    printf("Area = %.2f\n", total);
    return total;
}

float Ellipse(){
    float radius1, radius2, total, pi = 3.1415;
    printf("Please enter a radius: ");
    scanf("%f", &radius1);
    printf("Please enter a second radius: ");
    scanf("%f", &radius2);
    total = pi * radius1 * radius2;
    printf("Area = %.4f\n", total);
    return total;
}

int main()
{

    int shape;
    char repeat;
    intro:
        fflush(stdin);
        printf("Enter make a selection from the list below:\n\n1:\tCircle\n2:\tEllipse\n3:\tParallelogram\n4:\tPolygon\n5:\tRectangle\n6:\tSquare\n7:\tTrapezoid\n8:\tTriangle\n\n");
        scanf("%d", &shape);

    switch(shape){
    case 1:
        Circle();
        break;
    case 2:
        Ellipse();
        break;
    case 3:
        Parallelogram();
        break;
    case 4:
        Polygon();
        break;
    case 5:
        Rectangle();
        break;
    case 6:
        Square();
        break;
    case 7:
        Trapezoid();
        break;
    case 8:
        Triangle();
        break;
    default:
        printf("ERROR: Invalid character or number\n\n");
        goto repeatquery;
        break;
    }

    repeatquery:
        fflush(stdin);
        printf("Would you like to solve another problem?\nEnter y to return to the shapes menu\nOtherwise, press any key to exit\n");
        repeat = getchar();

        if(repeat == 'y' || repeat == 'Y'){
            goto intro;
        }
        else{
            printf("Thanks for using my program!\n");
            system("pause");
            return 0;
        }
}
