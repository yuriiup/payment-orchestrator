#include "PaymentTransaction.hpp"
#include <stdexcept>

PaymentTransaction::PaymentTransaction(const std::string& p_id,
                                       long long p_amount,
                                       const std::string& p_currency,
                                       const std::string& p_idempotency_key)
    : m_id(p_id),
      m_amount(p_amount),
      m_currency(p_currency),
      m_idempotency_key(p_idempotency_key),
      m_status(TransactionStatus::CREATED) {
  if (m_amount <= 0) {
    throw std::invalid_argument("Amount must be positive!");
  }
  if (m_id.empty()) {
    throw std::invalid_argument("ID connot be empty!");
  }
}
std::string PaymentTransaction::getId() const {
  return m_id;
}

long long PaymentTransaction::getAmount() const {
  return m_amount;
}

std::string PaymentTransaction::getCurrency() const {
  return m_currency;
}

std::string PaymentTransaction::getIdempotencyKey() const {
  return m_idempotency_key;
}

TransactionStatus PaymentTransaction::getStatus() const {
  return m_status;
}

void PaymentTransaction::setStatus(TransactionStatus p_status) {
  if (m_status == TransactionStatus::DONE ||
      m_status == TransactionStatus::FAILED) {
    throw std::logic_error("Status cannot be changed!");
  }
  m_status = p_status;
}