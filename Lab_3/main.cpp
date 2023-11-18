#include <iostream>
#include "Array3D.cpp"

int main() {
    int x = 2, y = 3, z = 2;
    Array3D<int> array3D(x, y, z);

    int index = 1;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                array3D(i,j,k) = index;
                index++;
            }
        }
    }

    std::cout<<"Слайс по x(0)"<<std::endl;
    for (int value : array3D.GetValues0(0)) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout<<"Слайс по y(2)"<<std::endl;
    for (int value : array3D.GetValues1(2)) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout<<"Слайс по z(1)"<<std::endl;
    for (int value : array3D.GetValues2(1)) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout<<"--------------------------------------------"<<std::endl;
    array3D.SetValues0(0,{10, 20, 30, 40, 50 ,60});


    std::cout<<"Слайс по x(0)"<<std::endl;
    for (int value : array3D.GetValues0(0)) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout<<std::endl<<"Слайс по x(0) и y(1)"<<std::endl;
    for (int value : array3D.GetValues01(0,1)) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout<<"--------------------------------------------"<<std::endl;
    array3D.SetValues01(0,1,{3,4});

    std::cout<<"Слайс по x(0) и y(1)"<<std::endl;

    for (int value : array3D.GetValues01(0,1)) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout<<"--------------------------------------------"<<std::endl;
    array3D.Fill(3,3,3,5);

    std::cout<<std::endl<<"После заполнения пятерками и размерности(3*3*3)"<<std::endl;

    for (int value : array3D.GetValues1(0)) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    for (int value : array3D.GetValues1(0)) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    for (int value : array3D.GetValues2(0)) {
        std::cout << value << " ";
    }

    std::cout<<std::endl<<"После заполнения нулями"<<std::endl;

    array3D.FillWithZeros(3,3,3);
    for (int value : array3D.GetValues1(0)) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    for (int value : array3D.GetValues1(0)) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    for (int value : array3D.GetValues2(0)) {
        std::cout << value << " ";
    }

    return 0;
}