#include <iostream>
#include <iomanip>

int main() {
    int primer_año{0};
    int segundo_año{0};

    std::cin >> primer_año >> segundo_año;
    if (primer_año > segundo_año){
        return 1;
        if (primer_año < 1800 && segundo_año > 9999){
            return 2;
        }
        
    }
    
    return 0;
}