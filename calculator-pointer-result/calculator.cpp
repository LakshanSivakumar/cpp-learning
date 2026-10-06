#include <iostream>

bool calculate(int x, int y, char c, int *result){
    switch(c){
        case '+':
            *result = x + y;
            return true;
        case 'x' :
        case '*':
            *result = x * y;
            return true;            
        case '/':
            if (y == 0){
                return false;
            }
            *result = x / y;
            return true;
        case '-':
            *result = x - y;
            return true;
    }
    return false;
}

int main(void){

    std::cout << "Enter the first number: ";
    int x{};
    std::cin >> x;
    std::cout << "Enter the second number: ";
    int y{};
    std::cin >> y;
    std::cout << "Enter the operator: ";
    char c {};
    std::cin >> c;

    int result{};
    bool output = calculate(x, y, c, &result);


    if(!output){
        std::cout << "Enter a valid operator!\n";
        return 0;
    }
    
    std::cout << "Your output is " << result << '\n';
    return 0;
    


}