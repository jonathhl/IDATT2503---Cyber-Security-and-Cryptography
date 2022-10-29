#include <iomanip>
#include <iostream>
#include <openssl/evp.h>
#include <string>

void brute_force(size_t max, std::string hash, std::string salt);

int main() {
    const std::string hash = "ab29d7b5c589e18b52261ecba1d3a7e7cbf212c6";
    const std::string salt = "Saltet til Ola";
    brute_force(4, hash, salt);
    return 0;
}

// ------------- Functions --------------
std::string hex(const std::string &input) {
    std::stringstream hex_stream;
    hex_stream << std::hex << std::internal << std::setfill('0');
    for (auto &byte : input)
        hex_stream << std::setw(2) << (int)(unsigned char)byte;
    return hex_stream.str();
}

std::string pbkdf2(const std::string &password, const std::string &salt) {
    std::string hash;
    hash.resize(20);
    PKCS5_PBKDF2_HMAC_SHA1((const char *)&password[0], password.size(),
                           (const unsigned char *)&salt[0], salt.size(),
                           2048, 20, (unsigned char *)&hash[0]);
    return hash;
}

void brute_force_recurisvely(std::string pwd, std::string hash, std::string salt, int pos, int size) {
    if (pos < size) {
        for (int i = 63; i < 122; ++i) {
            pwd[pos] = char(i);
            std::string res = hex(pbkdf2(pwd, salt));
            if (res == hash) {
                std::cout << "Password is: " << pwd << std::endl;
            }
            brute_force_recurisvely(pwd, hash, salt, pos + 1, size);
        }
    }
}

void brute_force(size_t max, std::string hash, std::string salt) {
    std::string pwd = "";

    for (size_t i = 0; i < max; ++i) {
        brute_force_recurisvely(pwd, hash, salt, 0, i);
        pwd.append("a");
    }
}