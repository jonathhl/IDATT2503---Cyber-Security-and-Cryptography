#include <iostream>

std::string replace_sign(std::string input, std::string be_replaced, std::string replace_with){
    std::string temp = input;
    size_t index = 0;
    while(index < temp.length()){
        index = temp.find(be_replaced, index);
        if(index == std::string::npos) index = temp.length(); //breaks while loop condition
        else {
            temp = temp.substr(0, index) + replace_with + temp.substr(be_replaced.length()+index, temp.length());
            index += replace_with.length() - be_replaced.length();
        }
    }
    return temp;
}

std::string convert(std::string input){
    return replace_sign(replace_sign(replace_sign(input, "&", "&amp"), "<", "&lt"), ">", "&gt");
}

int main(){
    std::string input = "&lorem ip&sum < > <zx>";
    std::cout << input << " converted to: " <<  convert(input) << std::endl;

    input = "if 2 < 1 && 3 > 4";
    std::cout << input << " converted to: " <<  convert(input) << std::endl;

    input = "else is 1<10 && 23 > 8";
    std::cout << input << " converted to: " <<  convert(input) << std::endl;
    return 0;
}