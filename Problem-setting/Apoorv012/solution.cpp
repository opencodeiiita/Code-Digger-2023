#include <iostream>
#include <string>

int isValidIPv4(std::string ip) {
    int count = 0;
    int i = 0;
    while (i < ip.size()) {
        int j = i;

        // Find the next dot
        while (j < ip.size() && ip[j] != '.') {
            j++;
        }

        // Checks if the number is empty
        if (j == i) {
            return 0;
        }

        // Checks if the number starts with 0
        if (j - i > 1 && ip[i] == '0') {
            return 0;
        }

        // Checks if the number is greater than 255
        int num = 0;
        for (int k = i; k < j; k++) {
            if (ip[k] < '0' || ip[k] > '9') {
                return 0;
            }
            num = num * 10 + (ip[k] - '0');
        }
        if (num > 255) {
            return 0;
        }

        // Adds the count upto 4
        count++;

        // Sets the next index
        i = j + 1;
    }

    // Checks if the count is 4
    return count == 4;
}

int main() {
    std::string ip;
    std::cin >> ip;
    
    if (isValidIPv4(ip)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}