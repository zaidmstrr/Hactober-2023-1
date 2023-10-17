#include <iostream>

bool isPowerOf2(int n) {
    if (n <= 0) {
        return false; // Les nombres négatifs et zéro ne sont pas des puissances de 2.
    }
    return (n & (n - 1)) == 0;
}

int main() {
    int num = 16; // Remplacez 16 par le nombre que vous souhaitez vérifier.
    bool result = isPowerOf2(num);
    if (result) {
        std::cout << num << " est une puissance de 2." << std::endl;
    } else {
        std::cout << num << " n'est pas une puissance de 2." << std::endl;
    }

    return 0;
}
