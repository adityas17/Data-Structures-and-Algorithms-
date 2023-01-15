#include<iostream>

using namespace std;

class Diagonal{
    private:
        int *A;
        int n;
    public:
        Diagonal(){
            n=2;
            A = new int[2];
        }
        Diagonal(int n){
            this->n = n;
            A = new int[n];
        }
        ~Diagonal(){delete []A;}
        void set(int i,int j,int x);
        int get(int i,int j);
        void display();
};

void Diagonal::set(int i,int j,int x){
    if(i==j)
        A[i-1] = x;
}

int Diagonal::get(int i,int j){
    if(i==j)
        return A[i-1];
    else
        return 0;
}

void Diagonal::display(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)
                cout<<A[i]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{
    Diagonal ob(4);
    ob.set(1,1,23);
    ob.set(2,2,34);
    ob.set(3,3,44);
    ob.set(4,4,54);

    ob.display();

}