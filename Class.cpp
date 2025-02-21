#include <iostream>

class Cells {
private:

    int state;
    int x;
    int y;
    std::string Sickness = "Nothing";
    int max_neighbors = 3;
    int min_neighbors = 2;

public:

    Cells() : x(0){}

    Cells(int val, int val2) : x(val), y(val2){}

    void SetState(int new_state) {
        state = new_state;
    }

    int GetState() {
        return state;
    }


    void SetSickness(std::string NewSickness) {
        Sickness = NewSickness;
    }

    std::string GetSickness(){
        return Sickness;
    }

    void SetMaxNeighbors(int new_max_neighbors) {
        max_neighbors = new_max_neighbors;
    }

    int GetMaxNeighbors() {
        return max_neighbors;
    }

    void SetMinNeighbors(int new_min_neighbors) {
        min_neighbors = new_min_neighbors;
    }

    int GetMinNeighbors() {
        return min_neighbors;
    }

    void ResetNeighbors() {
        max_neighbors = 3;
        min_neighbors = 2;
    }
};
