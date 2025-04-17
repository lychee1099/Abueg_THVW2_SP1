#ifndef PROJ_H
#define PROJ_H

class Project {
private:
    // true = 1d; false = 2d
    bool dim;

    bool askDim();
    bool process1D();
    bool process2D();

public:
    void run(bool& flag);
};

#endif