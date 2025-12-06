#include <bits/stdc++.h>
#define SIZE 100

class Password{
    public:
    int arr[SIZE];
    int counter = 0;
    
    public:

    Password(std::ifstream& input){
        for(int i=0;i<100;i++){
            arr[i] = i;
        }
        int pointer = arr[50];

        std::string code;
        char indicator;
        int value;

        if(input.is_open()){
            while(getline(input, code)){
                indicator = code[0];
                value = std::stoi(code.substr(1));

                if(indicator == 'L'){  
                    pointer = (pointer - value)%100;
                    if(pointer == 0){
                        counter++;   
                    }
                }else if(indicator == 'R'){
                    pointer = (pointer + value)%100;
                    if(pointer == 0){
                        counter++;
                    }
                }
            }
            input.close();
        }
        else{
            std::cerr << "error" << std::endl;
        }
        std::cout << counter << std::endl;
    }

};

// Part2 code

class Password2{
    public:
    int arr[SIZE];
    int counter = 0;
    
    public:

    Password2(std::ifstream& input){
        for(int i=0;i<100;i++){
            arr[i] = i;
        }
        int pointer = arr[50];

        std::string code;
        char indicator;
        int value;

        if(input.is_open()){
            while(getline(input, code)){
                indicator = code[0];
                value = std::stoi(code.substr(1));
                int counter2 = 0;
                if(indicator == 'L'){  
                    int newpointer = (pointer - value)%100;
                    while(counter2 < value){  
                        if(pointer == 0){
                            counter++;
                        }
                        pointer--;
                        if(pointer < 0){
                            pointer = 99;
                        }
                        counter2++;
                    }

                }else if(indicator == 'R'){
                    int newpointer2 = (pointer + value)%100;
                    while (counter2 < value){
                        if(pointer == 0){
                            counter++;
                        }
                        pointer++;
                        if(pointer > 99){
                            pointer = 0;
                        }
                        counter2++;
                    }
                }
            }
            input.close();
        }
        else{
            std::cerr << "error" << std::endl;
        }
        std::cout << counter << std::endl;
    }

};



int main(){
    std::ifstream input("p1input.txt");
    Password2 password2(input);
}

