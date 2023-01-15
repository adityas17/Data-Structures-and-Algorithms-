#include<iostream>

using namespace std;

class Elements{
    public:
        int i;
        int j;
        int x;
};

class Sparse{
    private:
        int m;
        int n;
        int num;
        Elements *e;
    public:
        Sparse(int m,int n,int num)
        {
            this->m = m;
            this->n = n;
            this->num=num;
        }
        void create();

};

int main()
{
    return 0;
}