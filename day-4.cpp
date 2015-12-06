#include <openssl/md5.h>
#include <string>
#include <iostream>
#include <stdio.h>
int main(){
    unsigned char result[MD5_DIGEST_LENGTH];
    std::string originalString = "ckczppom";
//    std::string originalString = "abcdef609043";
    std::string string = originalString;
    bool incomplete = true;
    int count = 0;
    while(incomplete){
        MD5((unsigned char*) string.c_str(), string.length() , result);
        if(result[0] == 0 && result[1] == 0 && result[2] == 0){
            std::cout << count << std::endl;
            incomplete = false;
            return 0;
        }
        count++;
        string = originalString + std::to_string(count);
    }
}
