#include <iostream>
#include <vector>


class car {
    std::string brand;
public:
    car();

    car(const std::string &brand);

    virtual ~car();

};

car::car(const std::string &brand) : brand(brand) {};

car::car() = default;

car::~car() {

};


class hotHatch : public car {
public:
    hotHatch();

    virtual ~hotHatch();
};

hotHatch::hotHatch() {}

hotHatch::~hotHatch() {

}


class cabrio : public car {
public:
    cabrio();

    virtual ~cabrio();
};

cabrio::cabrio() {}

cabrio::~cabrio() {

}

class superSport : public car {
public:
    superSport();

    virtual ~superSport();

};

superSport::superSport() = default;

superSport::~superSport() = default;


template<class T>
class expozitie {
    static int ssNumber; // number of superSport cars;
    static int carsSold;
    std::vector<std::pair<T *, int >> stock, sold;
    static int carNumber;
    std::vector<T *> cars;
public:
    expozitie();

    void addCar(T *car);

    void addSuperSport(T* car);

    void sellCar(T *car, int price);

    int getNumber();

    void operator-=(std::pair<T*,int> a);

    void setPrice(T*a, int price);


};

template<class T>
void expozitie<T>::setPrice(T *a, int price) {
    std::find(stock.begin(), stock.end(), std::make_pair(a,-1) )->second = price;
}


template<class T>
void expozitie<T>::operator-=(std::pair<T *, int> a) {
    ssNumber --;
    carsSold ++;
    std::pair<T *, int> b = std::make_pair(a.first,-1);
    stock.erase(std::find(stock.begin(),stock.end(),b));
    sold.resize(carsSold);
    sold.push_back(a);
}

template<class T>
void expozitie<T>::sellCar(T *car, int price) {
    carNumber--;
    setPrice(car,price);
    *this -= std::make_pair(car,price);
};

template<class T>
int expozitie<T>::ssNumber = 0;

template<class T>
int expozitie<T>::carsSold = 0;

template<class T>
void expozitie<T>::addSuperSport(T *car) {
    ssNumber ++;
    carNumber++;
    stock.resize(ssNumber);
    stock.push_back(std::make_pair(car,-1));
}

template<class T>
int expozitie<T>::carNumber = 0;

template<class T>
expozitie<T>::expozitie() {}

template<class T>
void expozitie<T>::addCar(T *car) {
    cars.push_back(car);
    carNumber++;
}

template<class T>
int expozitie<T>::getNumber() {
    return carNumber;
}


int main() {

    car *a = new cabrio;
    cabrio *b;
    car *c = new superSport;
    expozitie<car> x;
    x.addCar(a);
    x.addCar(b);
    x.addCar(c);
    x.addSuperSport(c);
    x.sellCar(c,100);
    std::cout << x.getNumber();


}
