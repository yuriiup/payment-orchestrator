#include "..\include\PaymentOrchestrator.hpp"
#include <stdexcept>
#include <utility>

size_t PaymentOrchestrator::getCount() const {
  return m_transaction.size();
}

long long PaymentOrchestrator::getTotalDoneTransaction() const {
  long long total = 0;
  for (const auto& transaction : m_transaction) {
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

void PaymentOrchestrator::addTransaction(
    std::unique_ptr<PaymentTransaction> p_transaction) {
  for (const auto& transaction : m_transaction) {
    if (transaction->getIdempotencyKey() ==
        p_transaction->getIdempotencyKey()) {
      return;
    }
  }
  m_transaction.push_back(std::move(p_transaction));
}
