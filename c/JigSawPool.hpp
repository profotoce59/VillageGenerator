#include "VillagePools.hpp"


struct JigSawPool {
  std::vector<std::string> names;
  std::vector<uint32_t>    index_flat;
};
JigSawPool make_pool(const std::vector<TemplateEntry>& tpl);