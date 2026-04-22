#include <chrono>
#include <string>

enum class TransactionStatus { CREATED, PENDING, FAILED, DONE };

class PaymentTransaction {
 private:
  long long m_amount;
  std::chrono::system_clock::time_point m_createdAt;
  std::string m_id;
  std::string m_currency;
  std::string m_idempotency_key;
  TransactionStatus m_status;

 public:
  PaymentTransaction(const std::string& p_id, long long p_amount, const std::string& p_currency,
                     const std::string& p_idempotency_key);
  std::string getId() const;
  long long getAmount() const;
  std::string getCurrency() const;
  std::string getIdempotencyKey() const;
  TransactionStatus getStatus() const;
  std::string getCreatedAt() const;
  void setStatus(TransactionStatus p_status);
};