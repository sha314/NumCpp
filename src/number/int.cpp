/*******************************************
Integer class

Author : Shahnoor
Email  : shahnoor3pl@gmail.com

uses an array of integer to represent large number
make good use of every bit available in an int
also the fundamental mathematical operation,
i.e., +, -, *, /, %, +=, -=, *=, /=, %= ,
are also defined


********************************************/

class Integer{
    //  basic parameter
    /**
    * possible value max chunk 
    * 9 or 99 or 999 or 9999 or 99999 or 999999 or 9999999 or 99999999 or 999999999
    * it depends on programmer's choice and side of int in the system
    */
    unsigned max_chunk = 99;
    unsigned divider   = max_chunk + 1;
    unsigned chunk_len = 2;

    //  number storage
    vector<unsigned> num;                       // holds the number
    int sign = 1;

public:
    Integer(int a);
    Integer(std::vector<unsigned>& a, int sign=1);
    Integer(string a);

    
    void set_chunk(unsigned max_chnk){
        max_chunk = max_chnk;
        divider = max_chunk + 1;
        chunk_len = number_of_digit(max_chunk);
    }

  
    // void set_parameter(unsigned chun);   

    void print(){
        cout << "num.size() " << num.size() << endl;
        for(int i=num.size()-1 ; i>=0 ; --i){
            cout << num[i];
        }
        cout << endl;
    }
    friend ostream& operator<<(ostream& os, const Integer & a);

    /******************
    *   Arithmetic operators
    *   + - * / % += -= /= %=
    ***********************************************************/
    Integer operator+(const Integer& a);
    Integer operator-(const Integer& a);
    Integer operator*(const Integer& a);
    Integer operator/(const Integer& a);
    Integer operator%(const Integer& a);

    Integer operator+=(const Integer& a);
    Integer operator-=(const Integer& a);
    Integer operator*=(const Integer& a);
    Integer operator/=(const Integer& a);
    Integer operator%=(const Integer& a);
};

Integer::Integer(int a){
    cout << "Constructor -> Integer::Integer(int) __LINE__ " << __LINE__ << endl;
    sign = (a < 0) ? -1 : 1;
    a *= sign;  // making sure that a is positive
    if(a > max_chunk){
        int remainder= a % divider;
        while(remainder){
            cout << "remainder " << remainder << endl;
            num.push_back(remainder);
            a /= divider;
            remainder= a % divider;
        }
    }
    else num.push_back(a);
}

Integer::Integer(std::vector<unsigned>& a, int sign){
    this->sign = (sign < 0) ? -1 : 1;
    num = a;
}

Integer::Integer(string a){
    int place = 1;
    int len = a.size();
    unsigned chunk_len = number_of_digit(max_chunk); // chunk length or number of digit in a chunk
    // unsigned num_size = a.size() / chunk_len;
    cout << "chunk len " << chunk_len << " __LINE__ : " << __LINE__ << endl;
    // cout << "num_size " << num_size << " __LINE__ : " << __LINE__ << endl;
    int k=0;
    num.resize(1);
    int j=0;
    for(int i=len-1 ; i >=0 ; --i, ++j){
        num[k] += ctoi(a[i]) * place;
        place *= 10;
        if(j % chunk_len==0){
            num.push_back(0);
            ++k;
            place = 1;
        }
    }
}

Integer Integer::operator+(const Integer& a){
    // #exception what if num.size() mismatched
    if(num.size() != a.num.size()){
        cout << "#exception : size mismatched : __LINE__ " << __LINE__ << endl;
    }
    int len = num.size();
    int sum {};
    std::vector<unsigned> b;
    unsigned c=0, remainder=0;
    cout << "operator+ : start " << endl;
    for(int i=0; i < len ; ++i){
        cout << num[i] << " + " << a.num[i] << " + " << c << " = ";
        sum = num[i] + a.num[i] + c;
        remainder = sum % divider;
        cout << remainder << endl;
        c = sum / divider;
        b.push_back(remainder);
        // process sum and assign it to b
    }
    if(c){
        cout << "remainder " << c << endl;
        b.push_back(c);
    }
    cout << endl << "operator+ : end" << endl;
    return Integer(b);
}


ostream& operator<<(ostream& os, const Integer & a){
    // vector<int> n = a.getn();
    // unsigned chunk_len = a.number_of_digit(a.max_chunk);
    for(int i= a.num.size()-1 ; i>=0 ; --i){
        os << a.num[i];
    }
    return os;
}