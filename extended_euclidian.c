#include <stdio.h>

// Function to perform the Extended Euclidean Algorithm
int extended_gcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extended_gcd(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

// Function to display the table with intermediate values
void display_table(int a, int b) {
    printf("\nEuclidean Algorithm Table\n");
    printf("|  Step  |   a   |   b   |   a/b  |  a %% b |   x   |   y   |\n");
    printf("-------------------------------------------------------------\n");

    int x = 0, y = 1, x_prev = 1, y_prev = 0;
    int step = 1;
    
    while (b != 0) {
        int quotient = a / b;
        int remainder = a % b;
        
        printf("|  %4d  | %5d | %5d | %6d | %6d | %5d | %5d |\n", 
                step++, a, b, quotient, remainder, x_prev, y_prev);

        // Update values using the recursive relations
        int temp_x = x_prev - quotient * x;
        int temp_y = y_prev - quotient * y;

        x_prev = x;
        y_prev = y;
        x = temp_x;
        y = temp_y;
        
        a = b;
        b = remainder;
    }

    printf("|  %4d  | %5d | %5d |        |        | %5d | %5d |\n", 
            step, a, b, x_prev, y_prev);
    printf("-------------------------------------------------------------\n");
}

int main() {
    int num1, num2;
    int x, y;

    // Input two numbers
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Calculate GCD and Extended coefficients
    int gcd = extended_gcd(num1, num2, &x, &y);

    // Output the GCD and linear combination
    printf("\nThe GCD of %d and %d is: %d\n", num1, num2, gcd);
    printf("Linear Combination: %d = %d * (%d) + %d * (%d)\n", gcd, num1, x, num2, y);

    // Display intermediate steps in a table
    display_table(num1, num2);

    return 0;
}
