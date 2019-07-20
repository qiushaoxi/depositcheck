
#include <eosiolib/eosio.hpp>
#include <eosiolib/asset.hpp>

using namespace eosio;
using namespace std;

CONTRACT depositcheck : public contract
{
public:
  using contract::contract;
  depositcheck(eosio::name receiver, eosio::name code, datastream<const char *> ds)
      : contract(receiver, code, ds)
  {
  }
  void verify(name from, name to, asset quantity, string memo)
  {
    if (to == get_self())
    {
      eosio::check(memo.length() == 8, "memo format error");
      auto str = memo.c_str();
      for (int i = 0; i < 8; i++)
      {
        eosio::check(str[i] >= '0' && str[i] <= '9', "memo format error");
      }
    }
  }
};

extern "C"
{
  void apply(uint64_t receiver, uint64_t code, uint64_t action)
  {
    if (action == "transfer"_n.value)
    {
      eosio::execute_action(
          name(receiver), name(code), &depositcheck::verify);
    }
  }
}