#ifndef BOARD_H
#define BOARD_H


class Board
{
    private:
        int width;
        int height;
        float cof;
        double g;

    public:
        Board();
        int getWidth();
        int getHeight();
        void setHeight(int height);
        void setWidth(int width);
        void setCof(int cof);
        void setG(double g);
        double getG();
		int getCof();

};

#endif // BOARD_H
