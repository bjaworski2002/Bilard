#ifndef BOARD_H
#define BOARD_H


class Board
{
    private:
        int width;
        int height;
        float cof;

    public:
        Board();
        int getWidth();
        int getHeight();
        void setHeight(int height);
        void setWidth(int width);
        void setCof(int cof);

};

#endif // BOARD_H
