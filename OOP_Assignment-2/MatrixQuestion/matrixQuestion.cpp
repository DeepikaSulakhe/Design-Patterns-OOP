#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Matrix {
public:
    Matrix() {}
    Matrix(std::vector<std::vector<T>> &data) {
        matrix_data = data;
    }

    Matrix<T> operator+ (Matrix<T> const &obj) {
        Matrix result;
        int rows = obj.matrix_data.size();
        int cols = obj.matrix_data[0].size();
        result.matrix_data.resize(rows, std::vector<T>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.matrix_data[i][j] = obj.matrix_data[i][j] + this->matrix_data[i][j];
            }
        }
    
        return result;
    }

    template <typename U>
    friend ostream& operator<<(ostream&, const Matrix<U>&);
    void print() {
        int rows = matrix_data.size();
        int cols = matrix_data[0].size();
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                std::cout<<matrix_data[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
private:
    vector<vector<T>> matrix_data;
};

template<typename T>
ostream& operator<<(ostream& os, const Matrix<T>& obj) {
    int rows = obj.matrix_data.size();
    int cols = obj.matrix_data[0].size();
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
           os<<obj.matrix_data[i][j]<<" ";
        }
        os<<std::endl;
    }
    os<<std::endl;
    return os;
}

int main() {
   std::vector<std::vector<int>> a;
   a.push_back({1, 2});
   a.push_back({1, 3});
   a.push_back({1, 4});
  
  std::vector<std::vector<int>> b;
  b.push_back({2, 5});
   b.push_back({2, 6});
   b.push_back({2, 7});
  
  Matrix<int> m1(a);
  Matrix<int> m2(b);

  Matrix<int> m3 = m1 + m2;
 
  std::cout<<"M1 matrix:"<<std::endl;
  std::cout<<m1;
   std::cout<<"M2 matrix:"<<std::endl;
  std::cout<<m2;
   std::cout<<"M3 matrix (m1 + m2):"<<std::endl;
  std::cout<<m3;
   return 0;
}