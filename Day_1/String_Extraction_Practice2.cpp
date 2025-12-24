/*2025 advent of code: Day 1

Opens file then places first line into array.
Then extracts first character from array and places into variable
Next extracts remaining characters from array and places into a new variable. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//Functiion prototypes
void Safe_decoder(char direction, int &dial, int N, int &pass);

int main() {

    int Dial = 50;
    int password = 0;
    
    // Open the file for reading
    std::ifstream inFile("Day_1.txt");
    if (!inFile.is_open()) {
        std::cerr << "Error opening data.txt" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        if (!line.empty()) {
            // Extract the first letter
            char first_letter = line[0];

            // Grab the rest of the string (from index 1 to the end)
            // The substr() method takes a starting index and an optional length.
            std::string rest_of_string = line.substr(1);

            //call to safe decoder
            Safe_decoder(first_letter, Dial, stoi(rest_of_string), password);

        }
    }

     std::cout << "Password: "<< password << std::endl;

    inFile.close();

    return 0;
}

//Function definitions. 
void Safe_decoder(char direction, int &dial, int N, int &pass){
    //will turn dial left N times if first character in array is L.
    if ( direction == 'L' ){
        for(int i = 0; i < N; i++){
            dial--;
            if (dial < 0){
                dial = 99;
            }
        }

    }

    //will turn dial right N times if first character in array is R. 
    if ( direction == 'R' ){
        for(int i = 0; i < N; i++){
            dial++;
            if (dial > 99){
                dial = 0;
            }
        }

    }

    //count number of times dial stops at zero. 
    if (dial == 0){
        pass++;
    }
}
