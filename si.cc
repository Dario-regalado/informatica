#include <array>
#include <vector>
#include <iostream>
#include <fstream>
class Racional {
    Racional() = default;
    friend std::ifstream& operator>>(std::ifstream& is, Racional& racional);
    private:
    int numerador_, denominador_;
};
std::ifstream& operator>>(std::ifstream& is, Racional& racional) {
    auto temp{0};
    bool count{false};
    while(is >> temp) {
        if(isdigit(temp)){
            if(count == false){
                racional.numerador_ = temp;
                count = true;
            } else {
                racional.denominador_ = temp;
                break;
            }
        }
    }
}