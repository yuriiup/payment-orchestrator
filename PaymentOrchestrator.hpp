#pragma once
#include <memory>
#include <string>
#include <vector>
#include "PaymentTransaction.hpp"

class PaymentOrchestrator {
 private:
  std::vector<std::unique_ptr<PaymentTransaction>> m_transaction;

 public:
  PaymentOrchestrator() = default;
  size_t getCount() const;
  void addTransaction(std::unique_ptr<PaymentTransaction> p_transacion);
  long long getTotalDoneTransaction() const;
  PaymentTransaction* findById(const std::string& p_id);
};