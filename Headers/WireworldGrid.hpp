#ifndef WIREWORLDGRID_HPP
#define WIREWORLDGRID_HPP

#include <stdexcept>

#include "GridInterface.hpp"

class InvalidGridDimensionsException : std::exception
{
public:
    InvalidGridDimensionsException(int width, int height);

    const char *what() const noexcept override;

private:
    const int width;
    const int height;
};

class InvalidGridCoordinatesException : std::exception
{
public:
    InvalidGridCoordinatesException(int x, int y, int width, int height);

    const char *what() const noexcept override;

private:
    const int x;
    const int y;
    const int width;
    const int height;
};

class WireworldGrid : GridInterface
{
public:
    WireworldGrid(int width, int height);
    WireworldGrid(const WireworldGrid &other);
    virtual ~WireworldGrid();

    const WireworldGrid &operator=(const WireworldGrid &);

    virtual void update() override;

    virtual void setCell(int x, int y, State state) override;
    void setLine(int x1, int y1, int x2, int y2, State state);
    void setRectangle(int x1, int y1, int x2, int y2, State state);
    virtual State getCell(int x, int y);
    bool isOnGrid(int x, int y);
    int getWidth();
    int getHeight();

private:
    State *grid;

    virtual void createGrid(int width, int height);
    virtual void freeGrid();

    int width;
    int height;
};

#endif
