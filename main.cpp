#include <iostream>
#include <string>
#include <map>

using namespace std;

class Environment {
public:
    map<string, int>symbolTable;

    Environment() {
        symbolTable = map<string, int>();
    }
    void insert(const string& variableEnv, int value) {
        if (!isVariableDefined(variableEnv)) {
            setVariable(variableEnv, value);
        } else {
            cout << "Error, El simbolo '" << variableEnv << "' ya esta definida en la tabla de simbolos. " << endl;
        }
    }
    int lookup(const string& variableEnv, int defaultValue = 0) const {
        auto it = symbolTable.find(variableEnv);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            throw runtime_error("Error: El simbolo '" + variableEnv + "' no esta definido en la tabla de simbolos. ");
        }
    }

private:
    void setVariable(const string& variableEnv, int value) {
        symbolTable[variableEnv] = value;
    }
    bool isVariableDefined(const string& variableEnv) const{
        return symbolTable.find(variableEnv) != symbolTable.end();
    }
};
int main() {
    Environment env;
    env.insert("x", 10);
    env.insert("y", 20);
    env.insert("x", 30);

    try {
        int valueX = env.lookup("x");
        int valueY = env.lookup("y");
        int valueZ = env.lookup("z");

        cout << "El valor de x es: " << valueX << endl;
        cout << "El valor de y es: " << valueY << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    return 0;
}
