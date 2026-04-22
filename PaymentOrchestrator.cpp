#include "PaymentOrchestrator.hpp"
#include <stdexcept>
#include <utility>

size_t PaymentOrchestrator::getCount() const {
  return m_transaction.size();
}

void PaymentOrchestrator::addTransaction(std::unique_ptr<PaymentTransaction> p_transaction) {
  m_transaction.push_back(std::move(p_transaction));
}

long long PaymentOrchestrator::getTotalDoneTransaction() const {
  long long total = 0;
  for (auto& transaction : m_transaction) {
    if (transaction->getStatus() == TransactionStatus::DONE) {
      total += transaction->getAmount();
    }
  }
  return total;
}

PaymentTransaction* PaymentOrchestrator::findById(const std::string& p_id) {
  for (auto& transaction : m_transaction) {
    if (transaction->getId() == p_id) {
      return transaction.get();
    }
  }
  return nullptr;
}