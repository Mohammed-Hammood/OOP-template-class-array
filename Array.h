#pragma once
#include <istream>
#include <iostream>

using namespace std;

template <typename T> class Array {
  private:
    T *a;
    int n;
 public:
    Array(int N=5);
    Array(T *, int);
    Array(const Array <T>&x);
    Array <T>& operator = (const Array <T>&x);
     ~Array();
    void Scan(int m=5);
    T & operator [] (int i);
    void Print();
    int FindKey(T key);
     Array <T>& operator += (int key);
     Array <T> operator +(int key);
     Array <T> operator + (Array <T>&X);
     Array <T>& operator +=(Array <T>&x);
     Array <T>& operator -=(T key);
     Array <T> operator -(T key);
     Array <T>& DelPosEq(int pos);
     Array <T>& DelPosNew(int pos);
     bool operator == (Array <T>&x);
     bool operator != (Array <T>&x);
    int Max();
    int Min();
    void Sort();
    template <typename U> friend ostream& operator << (ostream& r, Array <U>& x);
    template <typename U> friend istream& operator >> (istream& r, Array <U>& x);    
 
    void ShiftLeft(int pos);
    int getN();
};


template <typename T> Array<T>::Array(int N){
    a = new T[N];
    n = N;
}
template <typename T> Array<T>::Array(T *b, int m){
  a = new T[m];
  for(int i = 0; i < m; i++){
            a[i] = b[i];
    }
    n = m;
}
template <typename T> Array<T>::Array(const Array &X){
  n = X.n;
  a = new T[n];
  for(int i = 0; i < n; i++){
    a[i] = X.a[i];
  }
}
template <typename T> Array<T> & Array<T>:: operator = (const Array &X){
   if(this!= &X){
     delete []a;
     n = X.n;
     a = new T[n];
     for(int i = 0; i < n; i++){
            a[i] = X.a[i];
     }
   }
   return *this;
}
template <typename T> Array<T>::~Array(){
  delete []a;
}

template <typename T> void Array<T>:: Scan(int m){
    string Number = (m>1)?"numbers":"number";
    string Character = (m>1)?"characters":"character";

    is_same<T, char>::value?(
        cout << "Enter " << m << " " << Character <<" of the array: "
    ):(
        cout << "Enter " << m << " " << Number <<" of the array: "
    );

    srand(time(0));

    if(n == m){
       for(int i  = 0; i < m; i++){
            cin >> a[i];
         //a[i] = rand()%100;
       }
    }else {
      delete []a;
      a = new T[m];
      for(int i = 0; i < m; i++){
          cin>> a[i];
      }
      n = m;
    }
}

template <typename T> T & Array<T>::operator [] (int i){
  if(i < 0){
    cout<<"Incorrect index! "<< i << " is less than 0" << endl;
    return a[0];
  }else if(i > n) {
    cout <<"Incorrect index! "<< i << " is more than "<< n <<endl;
   return a[n-1];
  }
  return a[i];
}

template <typename T> Array<T> & Array<T>::operator += (int key){
   T *temp = new T[n + 1];
   for(int i =0; i < n; i ++){
     temp[i] = a[i];
   }
   temp[n] = key;
   delete []a;
   a = temp;
   n++;
   return *this;
}

template <typename T>Array<T> Array<T>::operator + (int key){
   Array newObj(n+1);
   for(int i = 0; i < n; i++){
       newObj.a[i] = a[i];
   }
   newObj.a[n] = key;
   return newObj;
}

template <typename T>Array<T> Array<T>::operator + (Array &X){
   Array newObj(n+X.n);
   int j = 0;
   for(int i = 0; i < n+X.n; i++){
        if(i < n){
            newObj.a[i] = a[i];
        }else {
            newObj.a[i] = X.a[j++];
        }
   }
   return newObj;
}


template <typename T> void Array<T>:: Print(){
cout <<endl;// << "*******************" <<endl;
 for(int i = 0; i < n; i++){
  cout<< a[i] << ' ';
 }
cout <<endl; // << "******************************" <<endl;
}

template <typename T>int Array<T>::Max(){
 int max_num = 0;
 for(int i = 0; i < n; i++){
   if(a[i] > a[max_num]){
      max_num = i;
   }
 }
 return max_num;
}

template <typename T> int Array<T>::Min(){
 int min_num = 0;
 for(int i = 0; i < n; i++){
   if(a[i] < a[min_num]){
      min_num = i;
   }
 }
 return min_num;
}

template <typename T>int Array<T>::FindKey (T key){
    for(int i =0; i < n; i++){
        if(a[i] == key)return i;
    }
    return -1;
}

template <typename T>bool Array<T>::operator==(Array &X){
    if(n == X.n){
       for(int i =0; i < n; i++){
        if(a[i] != X.a[i]){return false;}
        }
        return true;
    }else {
        return false;
    }
}
template <typename T> bool Array<T>::operator != (Array &X){
       if(n != X.n){
        return true;
    }else {
       for(int i =0; i < n; i++){
        if(a[i] != X.a[i]){return true;}
        }
        return false;
    }
}

template <typename T> Array<T>& Array<T>::operator-= (T key){
    int i, j = 0, found = 0;
    for(i = 0; i < n; i++){
        if(a[i] != key){
            a[j++] = a[i];
        }else {
            found++;
        }
    }
    if(found == 0){
        cout <<"The number ("<<key<<") does not exist"<<endl;
    }else {
        for(i = found; i > 0; i--){
            a[n - 1] = {};
            n--;
        }
    }
    return *this;
}

template <typename T> Array<T> & Array<T>::operator += (Array <T> &X){
    int i, j = 0;
    T * newArray = new T[n+X.n];
    for(i = 0; i < n + X.n; i++){
        if( i < n ){
            newArray[i] = a[i];
        }else {
            newArray[i] = X.a[j++];
        }
    }
    delete []a;
    n = n+ X.n;
    a = newArray;
    return *this;
}

template <typename T> Array<T> & Array<T>::DelPosEq(int pos){
  int i, j, found = 0;
  for (i =0; i < n; i++){
    if(i == pos){
       for(j = i; j< n-1; j++){
          a[j] = a[j+1];
       }
       found++;
       n--;
       a[n] = {};
       //break;
    }
  }
   if(found == 0){
       cout <<"The number/character with the index ("<< pos <<") does not exist!"<<endl;
    }else {
       cout <<"The number/character with the index ("<< pos <<") deleted successfully."<<endl;
    }
    return *this;
}
template <typename T> Array<T> & Array<T>::DelPosNew(int pos){
    int i, j=0;
    T * b;
    if(pos >=0 && pos < n){
        b = new T[n-1];
        for(i = 0; i < n; i++){
            if(pos != i){ b[j++] = a[i];};
        }
    }else{
        b = new T[n];
        for(i = 0; i < n; i++)b[i] = a[i];
       cout <<"The number with the index ("<< pos <<") does not exist!"<<endl;
    }

    return *this;
}
template <typename T> void Array<T>::Sort(){
   for(int i =0; i < n; i++){
       for(int j = i; j < n; j++){
          if(a[j] < a[i]){
             int temp = a[i];
             a[i] = a[j];
             a[j] = temp;
           //  a[i] = a[j] + (a[j]=a[i]) - a[i] ;
          }
       }
   }
}
template <typename T> ostream & operator << (ostream& r, Array<T>& X){
     for(int i = 0; i < X.n; i++){
            cout<< X.a[i] << ' ';
        }
    cout <<"*****************"<<endl;
    return r;
}

template <typename T> istream & operator >> (istream &r, Array<T> &X){
    int m;
    const string NumbersText = (m>1)?"s":"";
    cout << "Enter the number of the array: ";
    cin >> m;
    cout << "Enter " << m << " number"<< NumbersText <<" of the array: ";
    if(X.n == m){
       for(int i  = 0; i < m; i++){
          cin >> X.a[i];
       }
    }else {
      delete []X.a;
      X.a = new T[m];
      for(int i = 0; i < m; i++){
          cin >> X.a[i];
      }
      X.n = m;
    }
    return r;
}
/*
*/
template <typename T> void Array<T>::ShiftLeft(int pos){
    int temp, i, j;
    for(j  = 0; j< pos; j++){
        temp = a[0];
        for(i = 0; i < n; i++){
            a[i] = a[i+1];
        }
        a[n-1] = temp;
    }
}

template <typename T> int Array<T>::getN(){
    return n;
}
