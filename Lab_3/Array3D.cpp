#include <iostream>
#include <vector>

template <typename T>
class Array3D {
private:
    int x;
    int y;
    int z;
    std::vector<T> array3d;
public:
    Array3D(int x, int y, int z)
            : x(x), y(y), z(z) {
        array3d.resize(x * y * z);
    }

    T& operator()(int i, int j, int k) {
        return array3d[i * y * z + j * z + k];
    }

    /***********
     * Getters *
     ***********/

    std::vector<T> GetValues0(int i) {
        std::vector<T> result(y * z);
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                result[j * z + k] = array3d[i * y * z + j * z + k];
            }
        }
        return result;
    }

    std::vector<T> GetValues1(int j) {
        std::vector<T> result(x * z);
        for (int i = 0; i < x; ++i) {
            for (int k = 0; k < z; ++k) {
                result[i * z + k] = array3d[i * y * z + j * z + k];
            }
        }
        return result;
    }

    std::vector<T> GetValues2(int k) {
        std::vector<T> result(x * y);
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                result[i * y + j] = array3d[i * y * z + j * z + k];
            }
        }
        return result;
    }

    std::vector<T> GetValues01(int i, int j) {
        std::vector<T> result(z);
        for (int k = 0; k < z; ++k) {
            result[k] = array3d[i * y * z + j * z + k];
        }
        return result;
    }

    std::vector<T> GetValues02(int i, int k) {
        std::vector<T> result(y);
        for (int j = 0; j < y; ++j) {
            result[k] = array3d[i * y * z + j * z + k];
        }
        return result;
    }

    std::vector<T> GetValues12(int j, int k) {
        std::vector<T> result(x);
        for (int i = 0; i < x; ++i) {
            result[k] = array3d[i * y * z + j * z + k];
        }
        return result;
    }

    /***********
    * Setters *
    ***********/

    void SetValues0(int i, const std::vector<T>& values) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                array3d[i * y * z + j * z + k] = values[j * z + k];
            }
        }
    }

    void SetValues1(int j, const std::vector<T>& values) {
        for (int i = 0; i < x; ++i) {
            for (int k = 0; k < z; ++k) {
                array3d[i * y * z + j * z + k] = values[j * z + k];
            }
        }
    }

    void SetValues2(int k, const std::vector<T>& values) {
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                array3d[i * y * z + j * z + k] = values[j * z + k];
            }
        }
    }

    void SetValues01(int i, int j, const std::vector<T>& values) {
        for (int k = 0; k < z; ++k) {
            array3d[(i * y + j) * z + k] = values[i];
        }
    }

    void SetValues02(int i, int k, const std::vector<T>& values) {
        for (int j = 0; j < y; ++j) {
            array3d[(i * y + j) * z + k] = values[i];
        }
    }

    void SetValues12(int j, int k, const std::vector<T>& values) {
        for (int i = 0; i < x; ++i) {
            array3d[(i * y + j) * z + k] = values[i];
        }
    }

    void Fill(int x, int y, int z, T value){
        this->x = x;
        this->y = y;
        this->z = z;
        array3d.resize(x * y * z);
        for (int i = 0; i < x * y * z; ++i) {
            array3d[i] = value;
        }
    }

    void FillWithZeros(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
        array3d.resize(x * y * z);
        for (int i = 0; i < x * y * z; ++i) {
            array3d[i] = 0;
        }
    }

    void FillWithOnes(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
        array3d.resize(x * y * z);
        for (int i = 0; i < x * y * z; ++i) {
            array3d[i] = 1;
        }
    }

};
