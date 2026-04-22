#include <iostream>
#include <memory>
#include "..\include\PaymentOrchestrator.hpp"

int main() {
    PaymentOrchestrator orchestrator;

    auto tx1 = std::make_unique<PaymentTransaction>("TX-1001", 500, "USD", "SECRET_A");

    orchestrator.addTransaction(std::move(tx1));

    std::cout << "Transactions in system: " << orchestrator.getCount() << std::endl;

    PaymentTransaction* another = orchestrator.findById("TX-1001");
    if (another) {
        another->setStatus(TransactionStatus::DONE);
    }

    std::cout << "Total Successful Amount: " << orchestrator.getTotalDoneTransaction() << std::endl;
    std::cout << "Total Transactions Count: " << orchestrator.getCount() << std::endl;

    return 0;
}