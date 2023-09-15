#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <tuple>
#include <numbers>

// Task 3, Task 4: timesTwo() here
auto timesTwo(auto x){
    return x + x;
}



struct Rectangle {
    double length; // Data member, also known as a field
    double width = 1; // Field can have a default value
    // Fields must be explicitly typed, you cannot use type deduction here

    // Member function, also known as a method
    double calculateArea() {
        return length * width;
    }

    // Member function that modifies the state of an object
    void makeItASquare(double sideLength) {
        length = sideLength;
        width = sideLength;
    }

    // Task 5: calculatePerimeter() here
    double calculatePerimeter(){
        return length * 2 + width * 2;
    }
};

// Task 6: struct Circle here

struct Circle {
    float radius;

    float calculatePerimeter(){
        return 2 * std::numbers::pi * radius;
    }

    float calculateArea() {
        return std::numbers::pi * radius * radius;
    }


};

// Task 7:
void printShape(auto shape) {
    // Your code here
    std::cout << "Area: " << shape.calculateArea() << std::endl;
    std::cout << "Perimeter: " << shape.calculatePerimeter() << std::endl;
}

// Task 9:
void inplaceTimesTwo(auto pointer) {
    // Your code here
    auto value = *pointer;
    value = timesTwo(value);
    *pointer = value;
}

// Task 10:
void doubleEachElement(std::vector<std::string>& container) {
    // Your code here
    for(auto& value:container){
        value = value + value;
    }
}

// Task 11-14:
std::vector<float> generateSequence(int n) {
    std::vector<float> sequence(n);
    auto temp = 0.0;
    for (int i = 0; i < n; i++) {
        temp = 1.0/(i+1); // 1, 1/2, 1/3, ...
        sequence[i] = temp;
    }
    return sequence;
}
void verifySequence(std::vector<float>& seq) {
    // DO NOT TOUCH this function
    for (int i=0; i < seq.size(); i++) {
        if (std::abs(seq[i] -  1.0/(i+1)) > 1e-3) {
            std::cerr << "Output sequence is incorrect! It should be (1, 1/2, 1/3, ..., 1/n)" << std::endl;
            return;
        }
    }
    std::cout << "Output sequence is correct! Congrats on finishing the lab!" << std::endl;
}

int main() {
    // Task 2: write "Hello World!" in an std::cout << "" << std::endl; call
    std::cout << "Hello World!" << std::endl;
    // Task 3:
     std::cout << timesTwo(21) << std::endl;

    // Task 4:
    std::cout << timesTwo(123) << std::endl;
    std::cout << timesTwo(3.14) << std::endl;
    std::cout << timesTwo(std::string{ "abc" }) << std::endl;

    // Task 5:
    std::cout << Rectangle{ 7, 8 }.calculatePerimeter() << std::endl;

    // Task 6: create a few instances of Circle, and call their member functions
    std::cout << Circle{ 5 }.calculatePerimeter() << std::endl;
    // Tip: to use pi, use std::numbers::pi

    // Task 7: call printShape with different Rectangle and Circle objects
    printShape(Rectangle{ 7, 8 });
    printShape(Circle{ 5 });
    // Task 8: create a container of strings, fill the container with some strings
    //         apply timesTwo to each string element in the container, print each string element in the container
    auto str_vector = std::vector<std::string>();
    str_vector.push_back("a");
    str_vector.push_back("b");
    str_vector.push_back("c");
    str_vector.push_back("d");
    for(auto index = 0; index < str_vector.size(); index++){
        std::cout << timesTwo(str_vector[index]) << std::endl;
    }
    // Task 9:
    auto x = 21;
    auto y = std::string{ "abcd" };
    inplaceTimesTwo(&x);
    inplaceTimesTwo(&y);
    std::cout << x << std::endl; // you should see 42 here
    std::cout << y << std::endl; // you should see "abcdabcd" here

    // Task 10: pass different std::array and std::vector objects to doubleEachElement
    //          print the results after doubleEachElement calls
    for(auto index = 0; index < str_vector.size(); index++){
        std::cout << str_vector[index] << std::endl;
    }
    doubleEachElement(str_vector);
    for(auto index = 0; index < str_vector.size(); index++){
        std::cout << str_vector[index] << std::endl;
    }
    // Task 11:
    std::vector<float> sequence = generateSequence(5);
    verifySequence(sequence);
}
