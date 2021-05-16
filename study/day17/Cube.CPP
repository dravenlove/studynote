#include<iostream>

using namespace std;

class Cube {
    public:



    int Cube_V(int L,int W,int H)
    {
        m_V=(m_L*m_W*m_H);
        return m_V;
    }

    int Cube_C(int L,int W,int H)
    {
        m_C=(2*m_L*m_W+m_L*m_H*2+m_H*m_W*2);
        return m_C;
    }

    
    int m_H;
    int m_L;
    int m_W;
    int m_V;
    int m_C;
};



int main()
{
    Cube a;
    Cube b;
    a.m_H=1;
    b.m_H=2;
    a.m_L=1;
    b.m_L=2;
    a.m_W=1;
    b.m_W=2;
    
    cout<<a.Cube_V(a.m_L,a.m_W,a.m_H)<<endl;
    cout<<b.Cube_V(b.m_L,b.m_W,b.m_H)<<endl;
    cout<<a.Cube_C(a.m_L,a.m_W,a.m_H)<<endl;
    cout<<b.Cube_C(b.m_L,b.m_W,b.m_H)<<endl;
    return 0;
}