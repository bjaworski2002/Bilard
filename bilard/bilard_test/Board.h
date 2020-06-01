#ifndef BOARD_H
#define BOARD_H


class Board
{
    private:
        double width;
        double height;
        double cof;
        double g;

    public:
        Board();
        double getWidth();
        double getHeight();
        void setHeight(double height);
        void setWidth(double width);
        void setCof(double cof);
        void setG(double g);
        double getG();
		double getCof();

};

#endif // BOARD_H
