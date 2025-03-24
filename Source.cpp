/** \file Source.cpp
* \brief drawing shapes program.
* \details this program will draw shapes based on the user input.
* \author AVRAMIS KONTOU
* \version 0.1
* \date 24 /3/2025
* \copyright UNIVERSITY OF NICOSIA.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Add the functions prototypes before the main program 
void drawHorizontalLine(int length, char ch);
void drawVerticalLine(int height, char ch);
void drawSquare(int size, char ch);
void drawSquareFilled(int size, char ch);
void drawRectangle(int height, int length, char ch);
void drawRectangleFilled(int height, int length, char ch);
void drawShapes(int numShapes);
/**
* Main function providing a menu for user to draw different shapes.
* @return 0 upon successful execution.
*/
int main() {
    srand(time(NULL)); // for generated random number 
    int option;
    do {
        cout << endl;
        cout << " Menu:" << endl;
        cout << "1) Draw a horizontal line" << endl;
        cout << "2) Draw a vertical line" << endl;
        cout << "3) Draw a square" << endl;
        cout << "4) Draw a rectangle" << endl;
        cout << "5) Draw random shapes" << endl;
        cout << "6) Quit" << endl;
        cout << "choose your Option: ";
        cin >> option;

        int size, height, length;
        char ch;

        switch (option) {
        case 1:
            cout << "Enter length and character: ";
            cin >> size >> ch;
            drawHorizontalLine(size, ch);
            break;
        case 2:
            cout << "Enter height and character: ";
            cin >> height >> ch;
            drawVerticalLine(height, ch);
            break;
        case 3:
            cout << "Enter size and character: ";
            cin >> size >> ch;
            drawSquare(size, ch);
            break;
        case 4:
            cout << "Enter height, length and character: ";
            cin >> height >> length >> ch;
            drawRectangle(height, length, ch);
            break;
        case 5:
            drawShapes(5);
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 6);
    return 0;
}
/**
* Draws a horizontal line.
* @param length The number of characters to print.
* @param ch The character to use for drawing.
*/
void drawHorizontalLine(int length, char ch) {
    for (int i = 0; i < length; i++)
        cout << ch;
    cout << endl;
}
/**
* Draws a vertical line.
* @param height The number of lines to print.
* @param ch The character to use for drawing.
*/
void drawVerticalLine(int height, char ch) {
    for (int i = 0; i < height; i++)
        cout << ch << endl;
}
/**
* Draws an unfilled square.
* @param size The width and height of the square.
* @param ch The character to use for drawing.
*/
void drawSquare(int size, char ch) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << ch;
        cout << endl;
    }
}
/**
* Draws a filled square.
* @param size The width and height of the square.
* @param ch The character to use for drawing.
*/
void drawSquareFilled(int size, char ch) {
    drawSquare(size, ch);
}
/**
* Draws an unfilled rectangle.
* @param height The number of rows.
* @param length The number of columns.
* @param ch The character to use for drawing.
*/
void drawRectangle(int height, int length, char ch) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++)
            cout << ch;
        cout << endl;
    }
}
/**
* Draws a filled rectangle.
* @param height The number of rows.
* @param length The number of columns.
* @param ch The character to use for drawing.
*/
void drawRectangleFilled(int height, int length, char ch) {
    drawRectangle(height, length, ch);
}
/**
* Generates and draws a given number of random shapes.
* @param numShapes The number of shapes to generate.
*/
void drawShapes(int numShapes) {
    const int MAX_SHAPES = 10;
    numShapes = (numShapes > MAX_SHAPES) ? MAX_SHAPES : numShapes;

    for (int i = 0; i < numShapes; i++) {
        int shapeType = rand() % 6 + 1;
        int shapeSize = rand() % 16 + 5; // Size between 5 and 20
        char shapeChar = rand() % (126 - 33 + 1) + 33; // ASCII printable chars 33-126

        cout << "\nGenerating shape " << (i + 1) << "..." << endl;

        switch (shapeType) {
        case 1:
            drawHorizontalLine(shapeSize, shapeChar);
            break;
        case 2:
            drawVerticalLine(shapeSize, shapeChar);
            break;
        case 3:
            drawSquare(shapeSize, shapeChar);
            break;
        case 4:
            drawSquareFilled(shapeSize, shapeChar);
            break;
        case 5:
            drawRectangle(shapeSize, shapeSize * 2, shapeChar);
            break;
        case 6:
            drawRectangleFilled(shapeSize, shapeSize * 2, shapeChar);
            break;
        }
    }
}
