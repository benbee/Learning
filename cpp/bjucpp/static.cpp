#include <iostream>

using namespace std;

class CRectangle
{
public:
    CRectangle (int w_, int h_);
    ~CRectangle ();
    static void PrintTotal();

private:
    int w, h;
    static int nTotalArea;
    static int nTotalNumber;
};

CRectangle::CRectangle(int w_, int h_)
{
    w = w_;
    h = h_;
    nTotalNumber++;
    nTotalArea += w * h;
}

CRectangle::~CRectangle()
{
    nTotalNumber--;
    nTotalArea -= w*h;
}

CRectangle::CRectangle(CRectangle & r)
{
    w = r.w;
    h = r.h;
    nTotalNumber++;
    nTotalArea += w * h;
}

void CRectangle::PrintTotal()
{
    cout << nTotalNumber << ", " << nTotalArea << endl;
}

int CRectangle::nTotalNumber = 0;
int CRectangle::nTotalArea = 0;

int main(int argc, char *argv[])
{
    CRectangle r1(3, 3), r2(2, 2);
    // cout << CRectangle::nTotalNumber; // wrong, it's private
    CRectangle::PrintTotal();
    r1.PrintTotal();

    return 0;
}
