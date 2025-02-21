#include "Source.h"







a8 InitArrayZero() {
    int width = 384;
    int height = 216;
    int state = 0;

    a8 arr;
    for (int i = 0; i < width; i++)
    {
        std::vector <int> tab1D;
        for (int j = 0; j < height; j++) {
            tab1D.push_back(state);
        }

        arr.push_back(tab1D);
    }
    return arr;
}

a8 InitArrayRate() {                          // 1/10 cells is alive 
    std::srand(std::time(nullptr));

    int width = 384;
    int height = 216;
    int state = 0;

    a8 arr;
    for (int i = 0; i < width; i++)
    {
        std::vector <int> tab1D;
        for (int j = 0; j < height; j++) {
            state = std::rand() % 10;
            tab1D.push_back(state);
        }

        arr.push_back(tab1D);
    }
    return arr;
}

c16 InitCells() {
    std::srand(std::time(nullptr));

    int width = 384;
    int height = 216;
    int random50 = 0;
    a8 state = InitArrayRate();
    a8 temp_state = InitArrayZero();


    c16 cell(width, c8(height));                                      // initialisation de cell
    for (int i = 0; i < cell.size() - 1; i++) {
        for (int j = 0; j < cell[i].size() - 1; j++) {
            if (state[i][j] == 1) {
                temp_state[i][j] = 1;
            }
            else {
                temp_state[i][j] = 0;
            }
            state[i][j] = temp_state[i][j];
            cell[i][j].SetState(state[i][j]);
        }
    }

    return cell;
}

a8 InitArray() {
    
    std::srand(std::time(nullptr));

    int width = 384;
    int height = 216;
    int state = 0;

    a8 arr;
    for (int i = 0; i < width; i++)
    {
        std::vector <int> tab1D;
        for (int j = 0; j < height; j++) {
            state = std::rand() % 2;
            tab1D.push_back(state);
        }

        arr.push_back(tab1D);
    }
    return arr;
}




a8 InitBloc() {

    int width = 384;
    int height = 216;
    int state = 0;

    a8 arr;
    for (int i = 0; i < width; i++)
    {
        std::vector <int> tab1D;
        for (int j = 0; j < height; j++) {

            if (j == 20 || j == 21) {
                switch (i) {
                    case 20:
                        state = 1;
                        break;
                    case 21:
                        state = 1;
                        break;
                }
            }
            else state = 0;

            tab1D.push_back(state);
        }

        arr.push_back(tab1D);
    }
    return arr;
}


a8 InitGlider() {

    int state = 0;

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

c16 MakeCellSick(c16 cell) {
    std::srand(std::time(nullptr));
    int rate1;
    for (int i = 1; i < cell.size() - 1; i++) {
        for (int j = 1; j < cell[i].size() - 1; j++) {
            rate1 = std::rand() % 100;
            if (rate1 == 1) {
                cell[i][j].SetSickness("Sick");
            }
            if (cell[i][j].GetState() == 0) cell[i][j].SetSickness("Nothing");
            if (cell[i][j].GetSickness() == "Nothing") cell[i][j].ResetNeighbors();
            if (cell[i][j].GetSickness() == "Sick") {
                cell[i][j].SetMaxNeighbors(1);
                cell[i][j].SetMinNeighbors(3);
            }
        }
    }
    return cell;
}

c16 UpdateArray(c16 cell) {
    a8 array_temp = InitArrayZero();

    for (int i = 1; i < cell.size() - 1; i++)
    {
        std::vector <int> tab1D;
        for (int j = 1; j < cell[i].size() - 1; j++) {
            int neighbors = cell[i - 1][j - 1].GetState() + cell[i - 1][j].GetState() + cell[i - 1][j + 1].GetState()
                + cell[i][j - 1].GetState() + cell[i][j + 1].GetState()
                + cell[i + 1][j - 1].GetState() + cell[i + 1][j].GetState() + cell[i + 1][j + 1].GetState();

           
            if (cell[i][j].GetState() == 1) {
                if (neighbors < cell[i][j].GetMinNeighbors() || neighbors > cell[i][j].GetMaxNeighbors()) {
                    array_temp[i][j] = 0; 
                }
                else {
                    array_temp[i][j] = 1;
                }
            }
            else { 
                if (neighbors == cell[i][j].GetMaxNeighbors()) {
                    array_temp[i][j] = 1;
                }
                else {
                    array_temp[i][j] = 0;
                }
            }
        }
    }

    for (int i = 1; i < cell.size() - 1; i++) {
        for (int j = 1; j < cell[i].size() - 1; j++) {
            cell[i][j].SetState(array_temp[i][j]);
            if (array_temp[i][j] == 0) cell[i][j].SetSickness("Nothing");
        }
    }

    cell = MakeCellSick(cell);
    return cell;
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