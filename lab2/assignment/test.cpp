#include <iostream>

#include <cstdlib>

#include <cstring>

#include <iomanip>



#define RAND_WIDTH 26



extern "C" void student_function();

extern "C" void your_function();



int if_flag, a1, a2;

const char *your_string = "Mr.Chen, students and TAs are the best!\n";

char *while_flag, *random_buffer;



// THE ONLY CODE YOU CAN CHANGE IN THIS FILE!!!

void student_setting() {

    a1 = 24;

    a2 = 14;

}



extern "C" char my_random() {

    char c = rand() % (RAND_WIDTH) + 'a';

    random_buffer[a2 - 12] = c;

    return c;

}



extern "C" void print_a_char(char c) {

    std::cout << c;

}



void test_failed() {

            std::cout << ">>> test failed" << std::endl;

            exit(0);

}



int main() {

    student_setting();



    // init

    std::cout << ">>> begin test" << std::endl;

    if_flag = 0;



    if(a2 >= 12) {

        while_flag = new char[a2 - 12 + 1];

        random_buffer = new char[a2 - 12 + 1];

        if(!while_flag || !random_buffer) {

            std::cout << "test can not run" << std::endl;

            exit(-1);

        }

        memset(while_flag, 0, a2 - 12 + 1);

        memset(random_buffer, 0, a2 - 12 + 1);

    }



    student_function();



    if(a1 < 12) {

        if (if_flag != a1 / 2 + 1) {

            test_failed();

        }

    } else if(a1 < 24) {

        if (if_flag != (24 - a1) * a1) {

            test_failed();

        }

    } else {

        if (if_flag != a1 << 4) {

            test_failed();

        }

    }



    std::cout << ">>> if test pass!" << std::endl;



    if(strcmp(while_flag, random_buffer) == 0 && a2 < 12) {

        std::cout << ">>> while test pass!" << std::endl;

    } else {

        test_failed();

    }

    

    your_function();

}

