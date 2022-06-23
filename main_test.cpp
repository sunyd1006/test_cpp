#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#include <regex>

vector<string> mUrlParamsRequiredVector;

void setUrlParamsRequiredVector(const std::string& path) {
    std::regex reg(std::string("\\{(.+?)\\}"));
    std::sregex_iterator pos(path.cbegin(), path.cend(), reg), end;
    for (; pos != end; ++pos) {
        mUrlParamsRequiredVector.push_back(pos->str(0));
    }
}

// gcc 4.8.5 不支持 regex
void setUrlParamsRequiredVector2(const std::string& path) {
    std::regex match("\\{(.+?)\\}");
    auto non_const_path = const_cast<std::string&>(path);
    std::regex_iterator<std::string::iterator> rit(non_const_path.begin(),
                                                   non_const_path.end(), match);
    std::regex_iterator<std::string::iterator> rend;
    while (rit != rend) {
        mUrlParamsRequiredVector.push_back(rit->str());
        ++rit;
    }
}

void setUrlParamsRequiredVector3(const std::string& path) {
    if (std::count(path.begin(), path.end(), '{') != std::count(path.begin(), path.end(), '}')) {
        throw std::runtime_error("ApiParenthesesAreNotMatched");
    }
    std::string last;
    for (const char& c : path) {
        switch (c) {
            case '{':
                last = "{";
                break;
            case '}':
                last.append({'}'});
                mUrlParamsRequiredVector.push_back(last);
                break;
            default:
                last.append({c});
                break;
        }
    }
}

// g11 main_test.cpp -o main && ./main
int main() {
    map<std::string, std::string> nameMap;
    nameMap.insert({"hello", "world"});
    nameMap.insert({"yes", "or"});

    auto it = nameMap.find("hello");
    if (it != nameMap.end()) {
        std::cout << it->second << std::endl;
    }
    std::string path = "/api/v1/meters/{meterTable}/consumers/{consumerType}";
    setUrlParamsRequiredVector(path);
    for (std::string item : mUrlParamsRequiredVector) {
        std::cout << item << std::endl;
    }

    mUrlParamsRequiredVector.clear();
    std::cout << std::endl;

    std::regex match("\\{(.+?)\\}");
    std::regex_iterator<std::string::iterator> rit(path.begin(), path.end(), match);
    std::regex_iterator<std::string::iterator> rend;
    while (rit != rend) {
        mUrlParamsRequiredVector.push_back(rit->str());
        ++rit;
    }

    setUrlParamsRequiredVector3(path);
    for (std::string item : mUrlParamsRequiredVector) {
        std::cout << item << std::endl;
    }

    return 0;
}