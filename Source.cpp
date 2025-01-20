#include "Source.h"

a8 InitArrayZero() {
    int width = 384;
    int height = 216;
    int etat = 0;

    a8 arr;
    for (int i = 0; i < width; i++)
    {
        std::vector <int> tab1D;
        for (int j = 0; j < height; j++) {
            tab1D.push_back(etat);
        }

        arr.push_back(tab1D);
    }
    return arr;
}

a8 InitArray() {
    
    std::srand(std::time(nullptr));

    int width = 384;
    int height = 216;
    int etat = 0;

    a8 arr;
    for (int i = 0; i < width; i++)
    {
        std::vector <int> tab1D;
        for (int j = 0; j < height; j++) {
            etat = std::rand() % 2;
            tab1D.push_back(etat);
        }

        arr.push_back(tab1D);
    }
    return arr;
}

a8 InitArrayRate() {                          // 1/10 cells is alive 
    std::srand(std::time(nullptr));

    int width = 384;
    int height = 216;
    int etat = 0;

    a8 arr;
    for (int i = 0; i < width; i++)
    {
        std::vector <int> tab1D;
        for (int j = 0; j < height; j++) {
            etat = std::rand() % 10;
            if (etat > 0) etat = 0;
            else etat = 1;
            tab1D.push_back(etat);
        }

        arr.push_back(tab1D);
    }
    return arr;
}


a8 InitBloc() {

    int width = 384;
    int height = 216;
    int etat = 0;

    a8 arr;
    for (int i = 0; i < width; i++)
    {
        std::vector <int> tab1D;
        for (int j = 0; j < height; j++) {

            if (j == 20 || j == 21) {
                switch (i) {
                    case 20:
                        etat = 1;
                        break;
                    case 21:
                        etat = 1;
                        break;
                }
            }
            else etat = 0;

            tab1D.push_back(etat);
        }

        arr.push_back(tab1D);
    }
    return arr;
}


a8 InitGlider() {

    int etat = 0;

    a8 arr = InitArrayZero();
    for (int i = 0; i < arr.size() - 1; i++)
    {
        std::vector <int> tab1D;
        for (int j = 0; j < arr[i].size() - 1; j++) {
            arr[20][22] = 1;
            arr[21][20] = 1;
            arr[21][22] = 1;
            arr[22][21] = 1;
            arr[22][22] = 1;

        }
    }
    return arr;

}

a8 UpdateArray(a8 arr) {

    a8 array_temp = InitArrayZero();

    for (int i = 1; i < arr.size() - 1; i++)
    {
        std::vector <int> tab1D;
        for (int j = 1; j < arr[i].size() - 1; j++) {
            int neighbors = arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1]
                + arr[i][j - 1] + arr[i][j + 1]
                + arr[i + 1][j - 1] + arr[i + 1][j] + arr[i + 1][j + 1];

           
            if (arr[i][j] == 1) { 
                if (neighbors < 2 || neighbors > 3) {
                    array_temp[i][j] = 0; 
                }
                else {
                    array_temp[i][j] = 1;
                }
            }
            else { 
                if (neighbors == 3) {
                    array_temp[i][j] = 1;
                }
                else {
                    array_temp[i][j] = 0;
                }
            }

        }
    }

    for (int i = 1; i < arr.size() - 1; i++) {
        std::vector <int> tab1D;
        for (int j = 1; j < arr[i].size() - 1; j++) {
            arr[i][j] = array_temp[i][j];
        }
    }

    return arr;
}


r16 InitArrayB() {
    r16 square;

    int width = 384;
    int height = 216;

    for (int i = 1; i < width; i++)
    {
        std::vector <r8> tab1D;
        for (int j = 1; j < height; j++) {
            sf::RectangleShape rect(sf::Vector2f(5.f, 5.f));
            tab1D.push_back(rect);
        }
        square.push_back(tab1D);
    }

    return square;
}