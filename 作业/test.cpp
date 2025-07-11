#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct Account {
    std::string idCard;
    std::string accountNumber;
    double balance;

    Account(std::string ic, std::string an, double b) : idCard(ic), accountNumber(an), balance(b) {}
};

std::vector<Account> readMasterFile(const std::string& filename) {
    std::vector<Account> accounts;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open master file: " << filename << std::endl;
        return accounts;
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string idCard, accountNumber;
        double balance;
        iss >> idCard >> accountNumber >> balance;
        accounts.emplace_back(idCard, accountNumber, balance);
    }
    file.close();
    return accounts;
}

void writeMasterFile(const std::string& filename, const std::vector<Account>& accounts) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open master file for writing: " << filename << std::endl;
        return;
    }

    for (const auto& account : accounts) {
        file << account.idCard << " " << account.accountNumber << " " << account.balance << "\n";
    }
    file.close();
}

void processTransactions(const std::string& transactionsFilename, std::vector<Account>& accounts) {
    std::ifstream file(transactionsFilename);
    if (!file.is_open()) {
        std::cerr << "Failed to open transactions file: " << transactionsFilename << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        int month;
        std::string idCard, accountNumber, type;
        double amount;
        iss >> month >> idCard >> accountNumber >> type >> amount;

        for (auto& account : accounts) {
            if (account.idCard == idCard && account.accountNumber == accountNumber) {
                if (type == "L") {
                    account.balance += amount;
                } else if (type == "D") {
                    account.balance -= amount;
                }
            }
        }
    }
    file.close();
}

void printAccounts(const std::vector<Account>& accounts) {
    for (const auto& account : accounts) {
        std::cout << "ID Card: " << account.idCard << ", Account Number: " << account.accountNumber
                  << ", Balance: " << account.balance << std::endl;
    }
}

int main() {
    std::string masterFilename = "D:\\c++\\作业\\master.txt";
    std::string transactionsFilename = "D:\\c++\\作业\\yearmonthname.txt";

    // Read the master file and get all accounts
    std::vector<Account> accounts = readMasterFile(masterFilename);

    // Process transactions from the transactions file
    processTransactions(transactionsFilename, accounts);

    // Write updated accounts back to the master file
    writeMasterFile(masterFilename, accounts);

    // Print the updated accounts
    printAccounts(accounts);

    return 0;
}



