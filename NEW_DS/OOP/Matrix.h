#include<bits/stdc++.h>
using namespace std;
class Matrix{
    int n, m; 
    vector<vector<int>> mat; 
    void resizeHelper(){
        mat.resize(n); 
        for(int i = 0; i < m; i++) mat[i].resize(2, 0); 
    }
    void outOfRangeHelper(int i, int j = 0){
        if(i >= n || j >= m || i < 0 || j < 0){
            cout << "\n[Error] Out of range access."; 
            exit(0); 
        }
    }

    public: 
    
    Matrix(){
        n = m = 2; 
        resizeHelper(); 
        mat[0][0] = mat[1][1] = 1; 
    }
    Matrix(int n, int m){
        this -> n = n; 
        this -> m = m; 
        resizeHelper(); 
    }
    Matrix(vector<vector<int>> b){
        n = b.size(); 
        m = b[0].size(); 
        mat.resize(n); 
        for(int i = 0; i < n; i++){
            mat[i].resize(m); 
            for(int j = 0; j < m; j++){
                mat[i][j]= b[i][j]; 
            }
        }
    }
    Matrix(int n, int m, vector<vector<int>> inp){
        this -> n = n; 
        this -> m = m; 
        mat.resize(n); 
        for(int i = 0; i < n; i++){
            mat[i].resize(m); 
            for(int j = 0; j < m; j++){
                mat[i][j] = inp[i][j]; 
            }
        }
    }
    vector<int>& operator[](int i){
        outOfRangeHelper(i); 
        return mat[i]; 
    }
    int& operator()(int i, int j){
        outOfRangeHelper(i); 
        return mat[i][j]; 
    }
    pair<int, int> getDimension(){
        return make_pair(n, m); 
    }
    void display(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cout << mat[i][j] << " "; 
            cout << endl; 
        }
    }
    Matrix operator+(Matrix b){
        pair<int, int> dim = b.getDimension(); 
        if(n != dim.first || m != dim.second){
            Matrix r; 
            cout << "Dimensions not matched! Matrices can only be added if their dimensions are equal.\n"; 
            return Matrix(); 
        }
        Matrix result(n, m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                result[i][j] = mat[i][j] + b[i][j]; 
            }
        }
        return result;  
    }
    Matrix operator-(Matrix b){
        pair<int, int> dim = b.getDimension(); 
        if(n != dim.first || m != dim.second){
            cout << "Dimensions not matched! Matrices can only be added if their dimensions are equal.\n"; 
            return Matrix(); 
        }
        Matrix result(n, m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                result[i][j] = mat[i][j] - b[i][j]; 
            }
        }
        return result;  
    }
    Matrix operator*(Matrix b){
        pair<int, int> dim = b.getDimension(); 
        if(m != dim.first){
            cerr << "Can not be multiplied because propertis of multiplication are not valid.\n"; 
            exit(0); 
        }
        Matrix result(n, dim.second); 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < dim.second; j++){
                for(int k = 0; k < m; k++){
                    result[i][j] += mat[i][k]*b[k][j]; 
                }
            }
        }
        return result; 
    }
    bool operator==(Matrix b){
        pair<int, int> dim = b.getDimension(); 

        if(n != dim.first || m != dim.second){
            return false; 
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] != b[i][j]) return false; 
            }
        }
        return true; 
    }
    friend ostream& operator<<(ostream& out, Matrix &a); 
    friend istream& operator>>(istream &inp, Matrix &a); 
}; 

ostream& operator<<(ostream& out, Matrix &a){
    int n = a.getDimension().first; 
    int m = a.getDimension().second; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) out << a.mat[i][j] << " "; 
        out << endl; 
    } 
    return out; 
}
istream& operator>>(istream &inp, Matrix &a){
    inp >> a.n >> a.m; 
    a.mat.resize(a.n); 
    for(int i = 0; i < a.n; i++){
        a.mat[i].resize(a.m); 
        for(int j = 0; j < a.m; j++){
            inp >> a.mat[i][j]; 
        }
    }
    return inp; 
}